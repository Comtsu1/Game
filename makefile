game: main player inventory goblin adventure getch slot armorset armor item tool
	# g++ -o game build/main.o build/player.o build/inventory.o build/goblin.o build/adventure.o build/getch.o build/sl
	g++ -o game build/* -Wall

main: main.cpp
	g++ -c ./main.cpp -o build/main.o

player: Entity/Player/Player.cpp
	g++ -c Entity/Player/Player.cpp -o build/player.o

inventory: Inventory.cpp
	g++ -c ./Inventory.cpp -o build/inventory.o

goblin: Entity/Goblin/Goblin.cpp
	g++ -c Entity/Goblin/Goblin.cpp -o build/goblin.o

adventure: Adventure.cpp
	g++ -c ./Adventure.cpp -o build/adventure.o

getch: getch.cpp
	g++ -c ./getch.cpp -o build/getch.o

slot: Slot.cpp
	g++ -c ./Slot.cpp -o build/slot.o

armorset: Armor/ArmorSet/ArmorSet.cpp
	g++ -c Armor/ArmorSet/ArmorSet.cpp -o build/armorset.o

armor: Armor/Armor.cpp
	g++ -c Armor/Armor.cpp -o build/armor.o

item: Item/Item.h
	g++ -c Item/Item.cpp -o build/item.o

tool: Item/Tool/Tool.h
	g++ -c Item/Tool/Tool.cpp -o build/tool.o

clean:
	rm build/*
	rm game

r: clean game
