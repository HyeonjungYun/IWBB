#include "Monster.h"

Monster::Monster(int MapLevel)
{
    _Monstername = " ";
    _MonsterMaxHP = 200 + ( MapLevel * 20 );
    _MonsterHP = _MonsterMaxHP;
    _MonsterEXP = 400 + ( MapLevel * 20 );
    _MonsterGold = 400 + ( MapLevel * 20 );
    _MonsterAttack = 10 + ( MapLevel * 20 );
    _TypeID = MonsterList::ATTACKER;
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