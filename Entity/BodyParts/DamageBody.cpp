#include "DamageBody.h"

void DamageBody::damageBodyPart(BodyPart *part, int amount)
{
    part->damage(amount);
}
