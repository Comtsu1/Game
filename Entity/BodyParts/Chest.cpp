#include "Chest.h"
#include <string>

Chest::Chest()
    :BodyPart() {}

Chest::Chest(int hp)
    :BodyPart(hp) {}

std::string Chest::status()
{
    int hp = this->getHealth();
    return hp > 7 ? "Good" :
        (hp >= 5 ? "Hurt" :
         (hp >= 3 ? "Badly Hurt" : "Very Hurt" ));
    // TODO "very hurt"
}
