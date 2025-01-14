#pragma once
#include "pch.h"

class Monster
{
public:
    Monster(int MapLevel, MonsterList::Monster MonsterType);

    string GetName();
    int GetHp();
    int GetGold();
    int GetEXP();
    int GetAttack();
    MonsterList::Monster GetMonsterTypeID();
    virtual void MonsterAction() = 0;

    virtual void TakeDamage(int damage) = 0;
    virtual void PrintMonster() const;
    virtual ~Monster();

protected:
    string  _Monstername;
    int _MonsterMaxHP;
    int _MonsterHP;
    int _MonsterEXP;
    int _MonsterGold;
    int _MonsterAttack;
    MonsterList::Monster _TypeID;

};