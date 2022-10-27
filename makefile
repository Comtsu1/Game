
CXX = g++

COPTIONS = -O2 
CWARN = -Wall -Wextra

CFLAGS = $(COPTIONS) $(CWARN)



game: createdir main player inventory goblin adventure getch slot armorset armor item tool
	$(CXX) -o game build/* $(CFLAGS)

createdir:
	mkdir -p build

main: main.cpp
	$(CXX) -c ./main.cpp -o build/main.o

player: Entity/Player/Player.cpp
	$(CXX) -c Entity/Player/Player.cpp -o build/player.o

inventory: Inventory.cpp
	$(CXX) -c ./Inventory.cpp -o build/inventory.o

goblin: Entity/Goblin/Goblin.cpp
	$(CXX) -c Entity/Goblin/Goblin.cpp -o build/goblin.o

adventure: Adventure.cpp
	$(CXX) -c ./Adventure.cpp -o build/adventure.o

getch: getch.cpp
	$(CXX) -c ./getch.cpp -o build/getch.o

slot: Slot.cpp
	$(CXX) -c ./Slot.cpp -o build/slot.o

armorset: Armor/ArmorSet/ArmorSet.cpp
	$(CXX) -c Armor/ArmorSet/ArmorSet.cpp -o build/armorset.o

armor: Armor/Armor.cpp
	$(CXX) -c Armor/Armor.cpp -o build/armor.o

item: Item/Item.cpp
	$(CXX) -c Item/Item.cpp -o build/item.o

tool: Item/Tool/Tool.cpp
	$(CXX) -c Item/Tool/Tool.cpp -o build/tool.o

clean:
	rm build/*
	rm game

r: clean game
