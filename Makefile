EXEC_NAME =   bin/affichage 

OBJ3 =  obj/main_txt.o obj/Vaisseau.o obj/txtJeuO.o obj/winTxtO.o
CFLAGS = -Wall -ggdb


	
all: $(EXEC_NAME)


bin/affichage: $(OBJ3)
	g++ $(OBJ3) -o bin/affichage 


obj/main_txt.o: src/main_txt.cpp src/Vaisseau.h src/winTxtO.h src/txtJeuO.h
	g++ $(CFLAGS)  -c src/main_txt.cpp -o obj/main_txt.o

obj/txtJeuO.o: src/txtJeuO.cpp src/txtJeuO.h src/Vaisseau.h
	g++ $(CFLAGS)  -c src/txtJeuO.cpp -o obj/txtJeuO.o

obj/Vaisseau.o: src/Vaisseau.cpp src/Vaisseau.h 
	g++ $(CFLAGS)  -c src/Vaisseau.cpp -o obj/Vaisseau.o

obj/winTxtO.o: src/winTxtO.cpp src/winTxtO.h 
	g++ $(CFLAGS)  -c src/winTxtO.cpp -o obj/winTxtO.o

clean:
	rm  obj/*  bin/* data/*