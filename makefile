game: build/main.cpp build/player.cpp build/inventory.cpp build/goblin.cpp build/adventure.cpp build/getch.cpp
	g++ -o game build/main.o build/player.o build/inventory.o build/goblin.o build/adventure.o build/getch.o

build/main.cpp: main.cpp
	g++ -c ./main.cpp -o build/main.o

build/player.cpp: Entity/Player/Player.cpp
	g++ -c Entity/Player/Player.cpp -o build/player.o

build/inventory.cpp: Inventory.cpp
	g++ -c ./Inventory.cpp -o build/inventory.o

build/goblin.cpp: Entity/Goblin/Goblin.cpp
	g++ -c Entity/Goblin/Goblin.cpp -o build/goblin.o

build/adventure.cpp: Adventure.cpp
	g++ -c ./Adventure.cpp -o build/adventure.o

build/getch.cpp: getch.cpp
	g++ -c ./getch.cpp -o build/getch.o

clean:
	rm build/*
	rm game

r: clean game
