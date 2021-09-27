mainFile = wordJumble.cpp

wordJumble.o: $(mainFile)
	g++ -c $(mainFile)

build: wordJumble.o
	g++ wordJumble.o -o wordJumble

clean:
	rm wordJumble.o wordJumble