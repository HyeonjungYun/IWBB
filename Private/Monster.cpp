#include "Monster.h"

Monster::Monster(int MapLevel, MonsterList::Monster MonsterType)
{
    if (MonsterType == MonsterList::ATTACKER)
    {
        _Monstername = " ";
        _MonsterMaxHP = 150 + (MapLevel * 10);
        _MonsterHP = _MonsterMaxHP;
        _MonsterEXP = 10 + (MapLevel * 6);
        _MonsterGold = 100 + (MapLevel * 17);
        _MonsterAttack = 15 + (MapLevel * 10);
        _TypeID = MonsterList::ATTACKER;
    }
    if (MonsterType == MonsterList::HEALER)
    {
        _Monstername = " ";
        _MonsterMaxHP = 200 + (MapLevel * 20);
        _MonsterHP = _MonsterMaxHP;
        _MonsterEXP = 10 + (MapLevel * 6);
        _MonsterGold = 100 + (MapLevel * 17);
        _MonsterAttack = 0 + (MapLevel * 0);
        _TypeID = MonsterList::HEALER;
    }
    if (MonsterType == MonsterList::TANKER)
    {
        _Monstername = " ";
        _MonsterMaxHP = 300 + (MapLevel * 20);
        _MonsterHP = _MonsterMaxHP;
        _MonsterEXP = 10 + (MapLevel * 6);
        _MonsterGold = 100 + (MapLevel * 17);
        _MonsterAttack = 10 + (MapLevel * 5);
        _TypeID = MonsterList::TANKER;
    }
}

string Monster::GetName()
{
    return _Monstername;
}

int Monster::GetHp()
{
    return _MonsterHP;
}

int Monster::GetGold()
{
    return _MonsterGold;
};

int Monster::GetEXP()
{
    return _MonsterEXP;
}

int Monster::GetAttack()
{
    return _MonsterAttack;
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