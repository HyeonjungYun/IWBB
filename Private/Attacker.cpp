#include "Attacker.h"

Attacker::Attacker(int MapLevel, MonsterList::Monster MonsterType) : Monster(MapLevel, MonsterType)
{
	int randomValue = CreateRandomValue(0, 1);

	if (randomValue == 1)
	{
		_Monstername = "에키드나";
	}
	else
	{
		_Monstername = "키류 카즈마";
	}


	_AttackCount = 0;
}

void Attacker::TakeDamage(int damage)
{
	_MonsterHP -= damage;

	if ( _MonsterHP <= 0 ) { _MonsterHP = 0; return; }
}

void Attacker::MonsterAction()
{
}

int Attacker::GetAttack()
{
	int AttackDamage = CreateRandomValue(_MonsterAttack - _DungeonMapLevel * 2, _MonsterAttack + _DungeonMapLevel * 2);
	_AttackCount++;

	if (_AttackCount % 3 == 0)
	{
		cout << _Monstername << "이(가) 더 강한 공격을 합니다." << endl;
		return AttackDamage * 2;
	}

	return AttackDamage;
}

Attacker::~Attacker()
{
	delete this;
}