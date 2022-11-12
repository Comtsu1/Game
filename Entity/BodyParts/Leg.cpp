#include "Leg.h"

Leg::Leg()
    :BodyPart() {}

Leg::Leg(int hp)
    :BodyPart(hp) {}

std::string Leg::status()
{
    int hp = this->getHealth();
    return hp > 7 ? "Good" :
        (hp >= 5 ? "Hurt" :
         (hp >= 3 ? "Badly Hurt" : "Very Hurt" ));
    // TODO "very hurt"
}
