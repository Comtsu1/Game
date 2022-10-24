game: build/main.cpp build/player.cpp build/inventory.cpp build/goblin.cpp build/adventure.cpp build/getch.cpp build/slot.cpp build/armorset.cpp build/item.cpp build/armor.cpp build/tool.cpp
	# g++ -o game build/main.o build/player.o build/inventory.o build/goblin.o build/adventure.o build/getch.o build/sl
	g++ -o game build/* -Wall

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

build/slot.cpp: Slot.cpp
	g++ -c ./Slot.cpp -o build/slot.o

build/armorset.cpp: Armor/ArmorSet/ArmorSet.cpp
	g++ -c Armor/ArmorSet/ArmorSet.cpp -o build/armorset.o

build/armor.cpp: Armor/Armor.cpp
	g++ -c Armor/Armor.cpp -o build/armor.o

build/item.cpp: Item/Item.h
	g++ -c Item/Item.cpp -o build/item.o

build/tool.cpp: Item/Tool/Tool.h
	g++ -c Item/Tool/Tool.cpp -o build/tool.o

clean:
	rm build/*
	rm game

r: clean game
