#include "Head.h"
#include "BodyPart.h"
#include <string>

Head::Head()
    :BodyPart()
{}

Head::Head(int initial_hp)
    :BodyPart(initial_hp)
{}

std::string Head::status()
{
    int hp = this->getHealth();
    return hp > 7 ? "Good" :
        (hp >= 5 ? "Hurt" :
         (hp >= 3 ? "Badly Hurt" : "Very Hurt" ));
    // TODO change "very hurt"
}
