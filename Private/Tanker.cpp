#include "Tanker.h"

Tanker::Tanker(int MapLevel, MonsterList::Monster MonsterType) : Monster(MapLevel, MonsterType)
{
	int randomValue = CreateRandomValue(0, 1);
	if (randomValue == 1)
		_Monstername = "그라가스";
	else
		_Monstername = "라인하르트";
}

int Tanker::Reflection(int damage)
{
	int randomValue = CreateRandomValue(0, 1);
	if (randomValue == 0)
	{
		int ReflectionDamage = CalReflectionDamage(damage);

		cout << _Monstername << "가 스킬을 사용했다!!" << endl;
		cout << _Monstername << "가 " << ReflectionDamage << "만큼의 대미지를 반사하였다. " << damage - ReflectionDamage << "만큼의 대미지를 입었다. " << endl;
		
		return ReflectionDamage;
	}
	if (randomValue == 1)
	{
		cout << _Monstername << "가 스킬 사용에 실패했다!!" << endl;
		cout << _Monstername << "가 대미지 " << damage << "를 입었다 " << endl;

		return 0;
	}
}

void Tanker::TakeDamage(int damage)
{
	int Damage = damage;
	_MonsterHP -= Damage - Reflection(damage);

	if (_MonsterHP <= 0) { _MonsterHP = 0; return; }
}

void Tanker::MonsterAction()
{
	Attack();
}

int Tanker::CalReflectionDamage(int damage) //반사데미지
{
	int ReflectionDamage = (int)(round(damage * 0.2)); // (받은 데미지 * 0.2) 의 값에 반올림으로 반사 데미지를 정함 

	if (ReflectionDamage < 1) // 반사데미지가 0이라 아무 일도 일어나지 않은 경우
	{
		return 1;
	}
	else
		return ReflectionDamage;
}

int Tanker::Attack()
{
	return _MonsterAttack;
}