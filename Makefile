build:
	g++ -c wordJumble.cpp
	g++ wordJumble.o -o wordJumble
buildSFML:
	g++ -c wordJumble.cpp
	g++ wordJumble.o -o wordJumble -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
