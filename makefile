game: build/main.cpp build/player.cpp build/inventory.cpp
	g++ -o game build/main.o build/player.o build/inventory.o

build/main.cpp: main.cpp
	g++ -c ./main.cpp -o build/main.o

build/player.cpp: Player.cpp
	g++ -c ./Player.cpp -o build/player.o

build/inventory.cpp: Inventory.cpp
	g++ -c ./Inventory.cpp -o build/inventory.o

clean:
	rm build/*
	rm game

r: clean game
