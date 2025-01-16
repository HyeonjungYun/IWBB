#pragma once
#include "Monster.h"

class Tanker : public Monster
{
public:
    Tanker(int MapLevel, MonsterList::Monster MonsterType);
    ~Tanker() { delete this; }
    void TakeDamage(int damage) override;
    void MonsterAction() override;
    int Reflection(int damage);
    int CalReflectionDamage(int damage);
    int Attack();
};