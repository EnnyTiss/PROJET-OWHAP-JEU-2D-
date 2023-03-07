EXEC_NAME =  bin/test bin/affichage bin/exemple
OBJ1 =  obj/mainExemple.o  obj/Image.o obj/Pixel.o 
OBJ2 =  obj/mainTest.o obj/Image.o obj/Pixel.o
OBJ3 =  obj/mainAffichage.o  obj/Image.o obj/Pixel.o
OBJall= obj/mainAffichage.o  obj/Image.o obj/Pixel.o obj/mainTest.o obj/mainExemple.o
CFLAGS = -Wall -ggdb
INCLUDES= -I./extern/SDL2
LIBS = -lSDL2 -lSDL2_image
	
all: $(EXEC_NAME)

bin/test: $(OBJ2) 
	g++ $(OBJ2) -o bin/test $(LIBS) 

bin/affichage: $(OBJ3)
	g++ $(OBJ3) -o bin/affichage $(LIBS)

bin/exemple: $(OBJ1)
	g++ $(OBJ1) -o bin/exemple $(LIBS)
		
obj/mainExemple.o: src/mainExemple.cpp src/Image.h
	g++ $(CFLAGS) $(INCLUDES) -c src/mainExemple.cpp -o obj/mainExemple.o

obj/mainTest.o: src/mainTest.cpp src/Image.h
	g++ $(CFLAGS) $(INCLUDES) -c src/mainTest.cpp -o obj/mainTest.o 

obj/mainAffichage.o: src/mainAffichage.cpp src/Image.h
	g++ $(CFLAGS) $(INCLUDES) -c src/mainAffichage.cpp -o obj/mainAffichage.o
	
obj/Pixel.o: src/Pixel.cpp src/Pixel.h
	g++ $(CFLAGS) -c src/Pixel.cpp -o obj/Pixel.o

obj/Image.o: src/Image.cpp src/Image.h src/Pixel.h
	g++ $(CFLAGS) $(INCLUDES) -c src/Image.cpp -o obj/Image.o

clean:
	rm  obj/*  bin/* data/*