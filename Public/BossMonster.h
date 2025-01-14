#ifndef _BOSS_MONSTER_H_
#define _BOSS_MONSTER_H_

#include "pch.h"
#include "Monster.h"

class BossMonster
{
public:
	BossMonster();
	int GetBossHP() const;
	int GetBossMaxHP() const;
	void AttackedBoss(int CharacterAttack);
	bool AttackBoss();
	~BossMonster();

private:
	string _BossName;
	int _BossHP;
	int _BossMaxHP;
	int _BossAttack;
	int _AttackCount;
};

#endif