#pragma once
#include "Monster.h"

class Tanker : public Monster
{
public:
    Tanker();
    Tanker(int MapLevel);
    ~Tanker() { delete this; }
    void TakeDamage(int damage) override;
    void Reflection(int damage);
    int CalReflectionDamage(int damage);

};