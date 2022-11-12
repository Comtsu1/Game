#pragma once

#include "BodyPart.h"
#include <string>

// TODO head shit

class Leg : public BodyPart
{
    public:
        Leg();
        Leg(int hp);

        std::string status();
};
