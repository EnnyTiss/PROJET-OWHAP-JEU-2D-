EXEC_NAME = bin/txt bin/sdl

OBJ3 =  obj/main_txt.o obj/Vaisseau.o obj/txtJeuO.o  obj/winTxtO.o obj/Jeu.o obj/Perso.o obj/Evenement.o obj/Objet.o obj/Vec2D.o obj/Timer.o obj/BarreProg.o obj/Etape.o obj/Tache.o
OBJ4 = 	obj/main_graph.o obj/Vaisseau.o obj/graphJeuO.o obj/Jeu.o obj/Perso.o obj/Evenement.o obj/Objet.o obj/Vec2D.o obj/Timer.o obj/BarreProg.o obj/Etape.o obj/Tache.o
CFLAGS = -Wall -ggdb
INCLUDES= -I./include/SDL2 
LIBS = -lSDL2 -lSDL2_image 
	
all: $(EXEC_NAME) 


bin/txt: $(OBJ3)
	g++ $(OBJ3) -o bin/txt

bin/sdl: $(OBJ4)
	g++ $(OBJ4) -o bin/sdl $(LIBS) 

obj/main_txt.o: src/main_txt.cpp src/Jeu.h src/winTxtO.h src/txtJeuO.h
	g++ $(CFLAGS)  -c src/main_txt.cpp -o obj/main_txt.o

obj/main_graph.o: src/main_graph.cpp src/Jeu.h src/graphJeuO.h
	g++ $(CFLAGS) $(INCLUDES) -c src/main_graph.cpp -o obj/main_graph.o

obj/txtJeuO.o: src/txtJeuO.cpp src/txtJeuO.h src/Jeu.h
	g++ $(CFLAGS)  -c src/txtJeuO.cpp -o obj/txtJeuO.o

obj/Jeu.o: src/Jeu.cpp src/Jeu.h 
	g++ $(CFLAGS) -c src/Jeu.cpp -o obj/Jeu.o

obj/Vaisseau.o: src/Vaisseau.cpp src/Vaisseau.h src/Perso.h src/Objet.h
	g++ $(CFLAGS)  -c src/Vaisseau.cpp -o obj/Vaisseau.o

obj/Perso.o: src/Perso.cpp src/Perso.h src/Vec2D.h
	g++ $(CFLAGS)  -c src/Perso.cpp -o obj/Perso.o

obj/Objet.o: src/Objet.cpp src/Objet.h src/Vec2D.h
	g++ $(CFLAGS)  -c src/Objet.cpp -o obj/Objet.o

obj/Evenement.o: src/Evenement.cpp src/Evenement.h 
	g++ $(CFLAGS)  -c src/Evenement.cpp -o obj/Evenement.o

obj/winTxtO.o: src/winTxtO.cpp src/winTxtO.h 
	g++ $(CFLAGS)  -c src/winTxtO.cpp -o obj/winTxtO.o

obj/Timer.o: src/Timer.cpp src/Timer.h 
	g++ $(CFLAGS)  -c src/Timer.cpp -o obj/Timer.o

obj/Etape.o: src/Etape.cpp src/Etape.h 
	g++ $(CFLAGS)  -c src/Etape.cpp -o obj/Etape.o

obj/Tache.o: src/Tache.cpp src/Tache.h 
	g++ $(CFLAGS)  -c src/Tache.cpp -o obj/Tache.o

obj/BarreProg.o: src/BarreProg.cpp src/BarreProg.h 
	g++ $(CFLAGS)  -c src/BarreProg.cpp -o obj/BarreProg.o

obj/Vec2D.o: src/Vec2D.cpp src/Vec2D.h 
	g++ $(CFLAGS)  -c src/Vec2D.cpp -o obj/Vec2D.o

obj/graphJeuO.o: src/graphJeuO.cpp src/graphJeuO.h 
	g++ $(CFLAGS) $(INCLUDES) -c src/graphJeuO.cpp -o obj/graphJeuO.o

clean:
	rm  obj/*  bin/* 