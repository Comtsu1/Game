#include "Head.h"
#include "BodyPart.h"
#include <string>

Head::Head()
    :BodyPart(35)
{}

Head::Head(int initial_hp)
    :BodyPart(initial_hp)
{}

std::string Head::status()
{
    double ratio = (double(this->getHealth()) / 35.0) * 100;
    return ratio > 70.0 ? "Good" :
        (ratio >= 50.0 ? "Hurt" :
         (ratio >= 30.0 ? "Badly Hurt" : "Very Hurt" ));
    // TODO "very hurt"
}
