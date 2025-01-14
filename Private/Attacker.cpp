#include "Attacker.h"

Attacker::Attacker(int MapLevel) : Monster(MapLevel)
{
	int randomValue = CreateRandomValue(0, 1);
	if ( randomValue == 1 )
		_Monstername = "에키드나";
	else
		_Monstername = "키류 카즈마";

	_AttackCount = 0;
}

void Attacker::TakeDamage(int damage)
{
	int Damage = damage;
	_MonsterHP -= Damage;

	if ( _MonsterHP <= 0 ) { _MonsterHP = 0; return; }
}

int Attacker::Attack()
{
	if (_AttackCount % 3 == 0)
		return _MonsterAttack * 2;

	_AttackCount++;
	return _MonsterAttack;
}

Attacker::~Attacker()
{
	delete this;
}