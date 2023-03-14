EXEC_NAME =   bin/affichage 

OBJ3 =  obj/main_txt.o obj/Vaisseau.o obj/txtJeuO.o obj/winTxtO.o obj/Jeu.o obj/Perso.o obj/Objet.o
CFLAGS = -Wall -ggdb


	
all: $(EXEC_NAME)


bin/affichage: $(OBJ3)
	g++ $(OBJ3) -o bin/affichage 


obj/main_txt.o: src/main_txt.cpp src/Jeu.h src/winTxtO.h src/txtJeuO.h
	g++ $(CFLAGS)  -c src/main_txt.cpp -o obj/main_txt.o

obj/txtJeuO.o: src/txtJeuO.cpp src/txtJeuO.h src/Jeu.h
	g++ $(CFLAGS)  -c src/txtJeuO.cpp -o obj/txtJeuO.o

obj/Jeu.o: src/Jeu.cpp src/Jeu.h 
	g++ $(CFLAGS)  -c src/Jeu.cpp -o obj/Jeu.o

obj/Vaisseau.o: src/Vaisseau.cpp src/Vaisseau.h src/Perso.h src/Objet.h
	g++ $(CFLAGS)  -c src/Vaisseau.cpp -o obj/Vaisseau.o

obj/Perso.o: src/Perso.cpp src/Perso.h 
	g++ $(CFLAGS)  -c src/Perso.cpp -o obj/Perso.o

obj/Objet.o: src/Objet.cpp src/Objet.h 
	g++ $(CFLAGS)  -c src/Objet.cpp -o obj/Objet.o

obj/winTxtO.o: src/winTxtO.cpp src/winTxtO.h 
	g++ $(CFLAGS)  -c src/winTxtO.cpp -o obj/winTxtO.o

clean:
	rm  obj/*  bin/* data/*