#ifndef _BOSS_MONSTER_H_
#define _BOSS_MONSTER_H_

#include "pch.h"
#include "Monster.h"

class BossMonster : public Monster
{
public:
	BossMonster();
	int GetBossHP() const;
	int GetBossMaxHP() const;
	int GetAttackCount() const;
	int GetAttack();
	void MonsterAction() override;
	void TakeDamage(int damage) override;
	void EncounterBoss();
	void ClearBoss();
	void LoseBoss();
	~BossMonster();

private:
	int _AttackCount;
};

#endif