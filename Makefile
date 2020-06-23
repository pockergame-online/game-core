libgamecore.dylib: gameplay.cpp
	g++ --verbose -dynamiclib -o  libgamecore.dylib gameplay.cpp

test_game: test_gameplay.cpp libgamecore.dylib
	g++ -std=c++0x test_gameplay.cpp -L./ -lgamecore -o test_game

all: libgamecore.dylib test_game 

clean:
	rm *.dylib test_game