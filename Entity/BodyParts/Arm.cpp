#include "Arm.h"

Arm::Arm()
    :BodyPart(60) {}

Arm::Arm(int hp)
    :BodyPart(hp) {}

std::string Arm::status()
{
    double ratio = (double(this->getHealth()) / 60.0) * 100;
    return ratio > 70.0 ? "Good" :
        (ratio >= 50.0 ? "Hurt" :
         (ratio >= 30.0 ? "Badly Hurt" : "Very Hurt" ));
    // TODO "very hurt"
}
