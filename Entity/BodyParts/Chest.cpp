#include "Chest.h"
#include <iostream>
#include <string>

Chest::Chest()
    :BodyPart(85) {}

Chest::Chest(int hp)
    :BodyPart(hp) {}

std::string Chest::status()
{
    double ratio = (double(this->getHealth()) / 85.0) * 100;
    //std::cout << ratio;
    return ratio > 70.0 ? "Good" :
        (ratio >= 50.0 ? "Hurt" :
         (ratio >= 30.0 ? "Badly Hurt" : "Very Hurt" ));
    // TODO "very hurt"
}
