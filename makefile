
CXX = g++

COPTIONS = -O2 -g
CWARN = -Wall -Wextra

CFLAGS = $(COPTIONS) $(CWARN)



game: createdir main player inventory goblin adventure getch slot armorset armor item tool
	$(CXX) -o game build/* 

createdir:
	mkdir -p build

main: main.cpp
	$(CXX) -c ./main.cpp -o build/main.o $(CFLAGS)

player: Entity/Player/Player.cpp
	$(CXX) -c Entity/Player/Player.cpp -o build/player.o $(CFLAGS)

inventory: Inventory.cpp
	$(CXX) -c ./Inventory.cpp -o build/inventory.o $(CFLAGS)

goblin: Entity/Goblin/Goblin.cpp
	$(CXX) -c Entity/Goblin/Goblin.cpp -o build/goblin.o $(CFLAGS)

adventure: Adventure.cpp
	$(CXX) -c ./Adventure.cpp -o build/adventure.o $(CFLAGS)

getch: getch.cpp
	$(CXX) -c ./getch.cpp -o build/getch.o $(CFLAGS)

slot: Slot.cpp
	$(CXX) -c ./Slot.cpp -o build/slot.o $(CFLAGS)

armorset: Armor/ArmorSet/ArmorSet.cpp
	$(CXX) -c Armor/ArmorSet/ArmorSet.cpp -o build/armorset.o $(CFLAGS)

armor: Armor/Armor.cpp
	$(CXX) -c Armor/Armor.cpp -o build/armor.o $(CFLAGS)

item: Item/Item.cpp
	$(CXX) -c Item/Item.cpp -o build/item.o $(CFLAGS)

tool: Item/Tool/Tool.cpp
	$(CXX) -c Item/Tool/Tool.cpp -o build/tool.o $(CFLAGS)

clean:
	rm build/*
	rm game

r: clean game
