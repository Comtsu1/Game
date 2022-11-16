#include "Leg.h"

Leg::Leg()
    :BodyPart(65) {}

Leg::Leg(int hp)
    :BodyPart(hp) {}

std::string Leg::status()
{
    double ratio = (double(this->getHealth()) / 65.0) * 100;
    return ratio > 70.0 ? "Good" :
        (ratio >= 50.0 ? "Hurt" :
         (ratio >= 30.0 ? "Badly Hurt" : "Very Hurt" ));
    // TODO "very hurt"
}
