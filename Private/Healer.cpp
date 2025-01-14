#include "Healer.h"

Healer::Healer(int MapLevel)
{
	int randomValue = CreateRandomValue(0, 1); // 0,1;
	if (randomValue == 1)
		_Monstername = "메르시";
	else
		_Monstername = "소나";
}

bool Healer::CanIgnore()
{
	int randomValue = rand() % 2;
	if (randomValue == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Healer::TakeDamage(int damage)
{
	if (int randomValue = CreateRandomValue(1, 10) < 4)
	{
		cout << _Monstername << "이(가) 공격을 무시했다." << endl;
	}
	else
	{
		_MonsterHP -= damage; // 현재 체력 -= 데미지
	}
}

void Healer::IncreaseHP() // 상위클래스에서 currentHP, maxHP 필요
{
	if (_MonsterHP >= _MonsterMaxHP)
	{
		return;
	}

	int increaseHPAmount = _MonsterHP / 10; // 고정된 회복량 1
	_MonsterHP += increaseHPAmount; // 체력 증가

	if (_MonsterHP > _MonsterMaxHP)
	{
		_MonsterHP = _MonsterMaxHP;
	}

	cout << _Monstername << "이(가) 체력을 " << increaseHPAmount << "만큼 회복했다." << endl;
}