#pragma once

#include "BodyPart.h"
#include <string>

// TODO same with head

class Arm : public BodyPart
{
    public:
        Arm();
        Arm(int hp);

        std::string status();
};
