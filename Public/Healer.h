﻿#ifndef _HEALER_H_
#define _HEALER_H_

#include "Monster.h"

class Healer : public Monster
{
public:
    Healer(int MapLevel, MonsterList::Monster MonsterType);
    void TakeDamage(int damage) override;
    void MonsterAction() override;
    void IncreaseHP(); // 힐러 기본 스킬 : 힐, 체력을 회복함. 회복량은 1로 고정
};

#endif