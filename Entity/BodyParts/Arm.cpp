#include "Arm.h"

Arm::Arm()
    :BodyPart() {}

Arm::Arm(int hp)
    :BodyPart(hp) {}

std::string Arm::status()
{
    int hp = this->getHealth();
    return hp > 7 ? "Good" :
        (hp >= 5 ? "Hurt" :
         (hp >= 3 ? "Badly Hurt" : "Very Hurt" ));
    // TODO "very hurt"
}
