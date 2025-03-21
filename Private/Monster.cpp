﻿#include "Monster.h"

Monster::Monster(int MapLevel, MonsterList::Monster MonsterType)
{
    _DungeonMapLevel = MapLevel;
    if (MonsterType == MonsterList::ATTACKER)
    {
        _Monstername = " ";
        _MonsterMaxHP = 150 + (MapLevel * 10);
        _MonsterHP = _MonsterMaxHP;
        _MonsterEXP = 10 + (MapLevel * 30);
        _MonsterGold = 100 + (MapLevel * 17);
        _MonsterAttack = 15 + (MapLevel * 20);
        _TypeID = MonsterList::ATTACKER;
    }
    if (MonsterType == MonsterList::HEALER)
    {
        _Monstername = " ";
        _MonsterMaxHP = 200 + (MapLevel * 20);
        _MonsterHP = _MonsterMaxHP;
        _MonsterEXP = 10 + (MapLevel * 30);
        _MonsterGold = 100 + (MapLevel * 17);
        _MonsterAttack = 0 + (MapLevel * 0);
        _TypeID = MonsterList::HEALER;
    }
    if (MonsterType == MonsterList::TANKER)
    {
        _Monstername = " ";
        _MonsterMaxHP = 300 + (MapLevel * 30);
        _MonsterHP = _MonsterMaxHP;
        _MonsterEXP = 10 + (MapLevel * 20);
        _MonsterGold = 100 + (MapLevel * 17);
        _MonsterAttack = 10 + (MapLevel * 18);
        _TypeID = MonsterList::TANKER;
    }
    if (MonsterType == MonsterList::BOSS)
    {
        _Monstername = "BigBalls 드래곤";
        _MonsterMaxHP = 1200;
        _MonsterHP = _MonsterMaxHP;
        _MonsterAttack = 999999;
        _MonsterEXP = 0;
        _MonsterGold = 0;
        _TypeID = MonsterList::BOSS;
    }
}

string Monster::GetName()
{
    return _Monstername;
}

int Monster::GetHp() const
{
    if (_MonsterHP < 0) return 0;
    return _MonsterHP;
}

int Monster::GetGold() const
{
    return _MonsterGold;
};

int Monster::GetEXP() const
{
    return _MonsterEXP;
}

int Monster::GetAttack()
{
    int AttackValue = CreateRandomValue(_MonsterAttack - _DungeonMapLevel * 2, _MonsterAttack + _DungeonMapLevel * 2);

    return AttackValue;
}

void Monster::PrintMonster() const
{
    cout << "(" << _Monstername << ")" << endl;
    cout << " HP : " << _MonsterHP << "/" << _MonsterMaxHP << ", ";
    cout << " Attack : " << _MonsterAttack << ", ";
    cout << " EXP : " << _MonsterEXP << ", ";
    cout << endl;
}

MonsterList::Monster Monster::GetMonsterTypeID()
{
    return _TypeID;
}

Monster::~Monster()
{
    delete this;
}