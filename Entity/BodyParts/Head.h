#pragma once

#include "BodyPart.h"

// TODO if a creature has more than one head you can put more healmets on it

class Head : public BodyPart
{
    int m_health;

    public:
        Head();
        Head(int initial_hp);
};
