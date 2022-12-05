#pragma once

#include "BodyPart.h"
#include <string>

// TODO same with head (idk how you can have more )

class Chest : public BodyPart
{
    public:
        Chest();
        Chest(int hp);

        std::string status();
};
