#include "BossMonster.h"

BossMonster::BossMonster()
{
    _BossName = "BigBalls µå·¡°ï";
    _BossMaxHP = 1300;
    _BossHP = _BossMaxHP;
    _BossAttack = 999999;
    _AttackCount = 0;
}

int BossMonster::GetBossHP() const
{
    return _BossHP;
}

int BossMonster::GetBossMaxHP() const
{
    return _BossMaxHP;
}

void BossMonster::AttackedBoss(int CharacterAttack)
{
    _BossHP -= CharacterAttack;
}

bool BossMonster::AttackBoss()
{
    if (_AttackCount >= 5)
        return true;

    _AttackCount++;
    return false;
}

BossMonster::~BossMonster()
{
    delete this;
}
