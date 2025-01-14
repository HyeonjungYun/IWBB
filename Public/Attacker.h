#ifndef _ATTACKER_H_
#define _ATTACKER_H_

#include "Monster.h"

class Attacker : public Monster
{
public:
    Attacker(int MapLevel);
    ~Attacker();
    int Attack();
    void TakeDamage(int damage) override;

private:
    int _AttackCount;
};

#endif