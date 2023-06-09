#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include <cassert>
#include <time.h>
#include "graphJeuO.h"
#include <stdlib.h>
#include <string>
#include "winTxtO.h"


#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 36;

float temps()
{
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC; // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Image::Image() : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false)
{
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;
    m_hasChanged = false;
}

void Image::loadFromFile(const char *filename, SDL_Renderer *renderer)
{
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr)
    {
        string nfn = string("../") + filename;
        cout << "Error: cannot load " << filename << ". Trying " << nfn << endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr)
        {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr)
    {
        cout << "Error: cannot load " << filename << endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface *surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface, SDL_PIXELFORMAT_ARGB8888, 0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer, surfaceCorrectPixelFormat);
    if (m_texture == NULL)
    {
        cout << "Error: problem to create the texture of " << filename << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface(SDL_Renderer *renderer)
{
    m_texture = SDL_CreateTextureFromSurface(renderer, m_surface);
    if (m_texture == nullptr)
    {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw(SDL_Renderer *renderer, int x, int y, int w, int h)
{
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w < 0) ? m_surface->w : w;
    r.h = (h < 0) ? m_surface->h : h;

    if (m_hasChanged)
    {
        ok = SDL_UpdateTexture(m_texture, nullptr, m_surface->pixels, m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer, m_texture, nullptr, &r);
    assert(ok == 0);
}

SDL_Texture *Image::getTexture() const { return m_texture; }

void Image::setSurface(SDL_Surface *surf) { m_surface = surf; }

// ============= CLASS SDLJEU =============== //

SDLSimple::SDLSimple() : jeu()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    if (TTF_Init() != 0) {
            cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
            SDL_Quit();
            exit(1);
        }
    

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }
    /*
        if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
        {
            cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
            cout << "No sound !!!" << endl;
            //SDL_Quit();exit(1);
            withSound = false;
        }
        else withSound = true;
    */
    int dimx, dimy;
    dimx = jeu.getVaisseau().getDimX() + 5; // le +1 pour la dimension de la barre de progression
    dimy = jeu.getVaisseau().getDimY();
    dimx = dimx * TAILLE_SPRITE;
    dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("OPERATION : we have a problem.", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimy, dimx, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr)
    {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_perso.loadFromFile("data/perso.png", renderer);
    im_persoBR.loadFromFile("data/robot.png", renderer);
    im_mur.loadFromFile("data/murVaisseau.png", renderer);
    im_sol.loadFromFile("data/sol.png", renderer);


    im_obj0.loadFromFile("data/obj0.png", renderer);
    im_obj0act.loadFromFile("data/obj0act.png", renderer);

    im_obj2.loadFromFile("data/obj2.png", renderer);
    im_obj2act.loadFromFile("data/obj2act.png", renderer);

    im_obj3.loadFromFile("data/obj3.png", renderer);
    im_obj3act.loadFromFile("data/obj3act.png", renderer);

    im_obj4.loadFromFile("data/obj4.png", renderer);
    im_obj4act.loadFromFile("data/obj4act.png", renderer);

    im_obj5.loadFromFile("data/obj5.png", renderer);
    im_obj5act.loadFromFile("data/obj5act.png", renderer);

    im_obj6.loadFromFile("data/obj6.png", renderer);
    im_obj6act.loadFromFile("data/obj6act.png", renderer);

    im_obj7.loadFromFile("data/obj7.png", renderer);
    
    im_barre.loadFromFile("data/tiret.png", renderer);
    im_etape.loadFromFile("data/rondbleu.png", renderer);
    im_etapeActif.loadFromFile("data/rondrouge.png", renderer);

    // FONTS
    font = TTF_OpenFont("data/DejaVuSansCondensed.ttf",50);
    
    if (font == nullptr) {
            cout << "Failed to load DejaVuSansCondensed.ttf! SDL_TTF Error: " << TTF_GetError() << endl;
            SDL_Quit();
            exit(1);
    }
    font_color.r = 0;font_color.g = 250;font_color.b = 255;
    font_im.setSurface(TTF_RenderText_Solid(font,"OWHAP",font_color));
    font_im.loadFromCurrentSurface(renderer);
    
    


    /*
    // SONS
    if (withSound)
    {
        sound = Mix_LoadWAV("data/son.wav");
        if (sound == nullptr)
            sound = Mix_LoadWAV("../data/son.wav");
        if (sound == nullptr) {
                cout << "Failed to load son.wav! SDL_mixer Error: " << Mix_GetError() << endl;
                SDL_Quit();
                exit(1);
        }
    }*/
}

SDLSimple::~SDLSimple()
{
    //if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void SDLSimple::sdlAff()
{
    // Remplir l'écran de noir
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int x, y;
    const Vaisseau &v = jeu.getVaisseau();

    const Perso &p = jeu.getPerso();

    Objet o[8];
    for (int i = 0; i < 8; i++)
    {
        o[i] = jeu.getObjet(i);
    }
    
    // Afficher les sprites des murs, du sol du vaisseau et des objets
    for (x = 0; x < v.getDimX(); ++x)
        for (y = 0; y < v.getDimY(); ++y)
            if (v.getXY(x, y) == '#')
                im_mur.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            else if (v.getXY(x, y) == '.')
                im_sol.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            else
            {
                for (int i = 0; i < 8; i++)
                { // si on est à la pos de l'objet i et qu'il est non actif, afficher sprite nonactif
                switch (i){//moteur1
                case 0:    
                    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj0.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj0act.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break;//moteur2
                case 7:    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj7.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj7.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break; //energie
                case 1:    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj0.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj0act.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break;//humain
                case 2:    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj2.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj2act.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break;//arme
                case 3:    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj3.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj3act.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break;//bouclier
                case 4:    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj4.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj4act.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break;//pilotage
                case 5:    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj5.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj5act.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break;//bonus
                case 6:    if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && !jeu.getObjet(i).getActifObjet())
                    {im_obj6.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    else if (Vec2D(x, y) == jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
                    { im_obj6act.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                    break;
                default : break;
               
            
               
               
               
               
               
               
               
                }}
            }

    // Afficher le sprite du perso
    im_perso.draw(renderer, p.getPosPerso().y * TAILLE_SPRITE, p.getPosPerso().x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);

    // Afficher la barre de progression 

    im_barre.draw(renderer, y * TAILLE_SPRITE, x * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    for (int i=0; i<jeu.getBarreProg().getTaille();i++)
				{ if (i==jeu.getBarreProg().getNow())
				  {
					  if (jeu.getBarreProg().getC(i)=='0')//les étapes
					  {//changement d'étape
                      im_etapeActif.draw(renderer, i * TAILLE_SPRITE, 11*TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE); }
					  else
					  {//le perso qui bouge
                      im_persoBR.draw(renderer, i * TAILLE_SPRITE, 11*TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}
                 }
				  else
					{
                    if (jeu.getBarreProg().getC(i)=='-')//les étapes
					  {
                        im_barre.draw(renderer, i*TAILLE_SPRITE, 11*TAILLE_SPRITE, TAILLE_SPRITE,  TAILLE_SPRITE);//etape normale 
                      }
					  else
					  {
                      im_etape.draw(renderer,  i*TAILLE_SPRITE, 11*TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);}// les tirets
                    } 
				}
    
    // Ecrire le timer restant
    //font timer
    font_color.r = 255;font_color.g = 250;font_color.b = 255;
    int diff = jeu.getTimer().getValMax()-jeu.getTimer().ecoulementTimer(jeu.getTimer().getdebut());
    string txt = /*"Temps restant" +*/ to_string(diff);
    font_im.setSurface(TTF_RenderText_Solid(font, txt.c_str() ,font_color));
    font_im.loadFromCurrentSurface(renderer);
    //cout<<"temps restant  :"<<jeu.getTimer().getValMax()-jeu.getTimer().ecoulementTimer(jeu.getTimer().getdebut())<<endl;
    //cout<<txt<<endl;

    SDL_Rect positionTimer;
    positionTimer.x = 600 ;
    positionTimer.y = 500;
    positionTimer.w = 100 ;
    positionTimer.h = 30 ;
    SDL_RenderCopy(renderer, font_im.getTexture(), nullptr, &positionTimer);
    

    // Ecrire un titre par dessus
    /*SDL_Rect positionTitre;
    positionTitre.x = 270;
    positionTitre.y = 49;
    positionTitre.w = 100;
    positionTitre.h = 30;
    SDL_RenderCopy(renderer, font_im.getTexture(), nullptr, &positionTitre);
*/
}

void SDLSimple::sdlBoucle()
{
    SDL_Event events;
    bool quit = false;



    // tant que ce n'est pas la fin ...
    while (!quit)
    {
        int Etapedebut = jeu.getEtape().getEtapenum();
        // tant qu'il y a des évenements à traiter (cette boucle n'est pas bloquante)
        while (SDL_PollEvent(&events))
        {   
		    
            if (events.type == SDL_QUIT)
                quit = true; // Si l'utilisateur a clique sur la croix de fermeture
            else if (events.type == SDL_KEYDOWN)
            { // Si une touche est enfoncee
                switch (events.key.keysym.scancode)
                {//ATTENTION: SDL est en QWERTY
                case SDL_SCANCODE_W://haut
                    jeu.actionClavier('z');
                    break;
                case SDL_SCANCODE_S://bas
                    jeu.actionClavier('s');
                    break;
                case SDL_SCANCODE_A://gauche
                    jeu.actionClavier('q');
                    break;
                case SDL_SCANCODE_D://droite
                    jeu.actionClavier('d');
                    break;
                case SDL_SCANCODE_I: //intéragir
                    jeu.actionClavier('i'); 
                   // termClear();
                    if (Etapedebut!=jeu.getEtape().getEtapenum()) {
                        jeu.GameOver(); 
                        
                        font_color.r = 255;font_color.g = 250;font_color.b = 255;
                        font_im.setSurface(TTF_RenderText_Solid(font, "C'est perdu ! :c" ,font_color));
                        font_im.loadFromCurrentSurface(renderer);
                    }
                   // termClear();
                    break;
                case SDL_SCANCODE_ESCAPE:
                case SDL_SCANCODE_M: // menu
                    quit = true;
                    break;
                default:
                    break;
                }

                /*
                if ((withSound) && (mangePastille))
                    Mix_PlayChannel(-1,sound,0);*/
            }
        }

        // on affiche le jeu sur le buffer cach�
        sdlAff();
        jeu.NouvelleEtape();

        // on permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
    }
}
