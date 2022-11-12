
CXX = g++

COPTIONS = -O2 -g
CWARN = -Wall -Wextra

CFLAGS = $(COPTIONS) $(CWARN)



game: createdir getch goblin main player entity inventory adventure slot armorset armor item tool stats battle bodypart head chest arm leg
	$(CXX) -o game build/* 

createdir:
	mkdir -p build

getch: getch.cpp
	$(CXX) -c ./getch.cpp -o build/getch.o $(CFLAGS)

stats: Stats.cpp
	$(CXX) -c ./Stats.cpp -o build/stats.o $(CFLAGS)

battle: Battle.cpp
	$(CXX) -c ./Battle.cpp -o build/battle.o $(CFLAGS)

main: main.cpp
	$(CXX) -c ./main.cpp -o build/main.o $(CFLAGS)

entity: Entity/Entity.cpp
	$(CXX) -c Entity/Entity.cpp -o build/entity.o $(CFLAGS)

player: Entity/Player/Player.cpp
	$(CXX) -c Entity/Player/Player.cpp -o build/player.o $(CFLAGS)

inventory: Inventory.cpp
	$(CXX) -c ./Inventory.cpp -o build/inventory.o $(CFLAGS)

goblin: Entity/Goblin/Goblin.cpp
	$(CXX) -c Entity/Goblin/Goblin.cpp -o build/goblin.o $(CFLAGS)

adventure: Adventure.cpp
	$(CXX) -c ./Adventure.cpp -o build/adventure.o $(CFLAGS)

slot: Slot.cpp
	$(CXX) -c ./Slot.cpp -o build/slot.o $(CFLAGS)

armorset: Item/Armor/ArmorSet/ArmorSet.cpp
	$(CXX) -c Item/Armor/ArmorSet/ArmorSet.cpp -o build/armorset.o $(CFLAGS)

armor: Item/Armor/Armor.cpp
	$(CXX) -c Item/Armor/Armor.cpp -o build/armor.o $(CFLAGS)

item: Item/Item.cpp
	$(CXX) -c Item/Item.cpp -o build/item.o $(CFLAGS)

tool: Item/Tool/Tool.cpp
	$(CXX) -c Item/Tool/Tool.cpp -o build/tool.o $(CFLAGS)

bodypart: Entity/BodyParts/BodyPart.cpp
	$(CXX) -c Entity/BodyParts/BodyPart.cpp -o build/bodypart.o $(CFLAGS)

head: Entity/BodyParts/Head.cpp
	$(CXX) -c Entity/BodyParts/Head.cpp -o build/head.o $(CFLAGS)

chest: Entity/BodyParts/Chest.cpp
	$(CXX) -c Entity/BodyParts/Chest.cpp -o build/chest.o $(CFLAGS)

arm: Entity/BodyParts/Arm.cpp
	$(CXX) -c Entity/BodyParts/Arm.cpp -o build/arm.o $(CFLAGS)

leg: Entity/BodyParts/Leg.cpp
	$(CXX) -c Entity/BodyParts/Leg.cpp -o build/leg.o $(CFLAGS)

clean:
	rm build/*
	rm game

r: clean game
