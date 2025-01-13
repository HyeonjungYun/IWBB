#include "Healer.h"


void Healer::PrintNothingHappened()
{
	cout << "이미 체력이 차 있어 힐을 할 수 없었다." << endl;
}

void Healer::SetIgnoreDamage(int damage)
{
	ignoreDamage = damage;
}

float Healer::GetIgnoreRate() const
{
	return ignoreRate;
}

bool Healer::CanIgnore() //주석
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
	int randomValue = rand() % 2;
	if (randomValue == 1)
	{
		SetIgnoreDamage(damage);
		cout << /*힐러 몬스터 이름*/ "이(가) 공격을 무시했다." << endl;
	}
	else
	{
		_MonsterHP -= damage; // 현재 체력 -=데미지
	}
}


	bool Healer::Canskill() // 반환값이 없는 bool인 고유 스킬 호출하는 곳
	{
		return true;
	}

	void Healer::IncreaseHP() // 상위클래스에서 currentHP, maxHP 필요
	{
		if (_MonsterHP >= _MonsterMaxHP)
		{
			PrintNothingHappened();
			return;
		}

		int increaseHPAmount = 1; // 고정된 회복량 1
		_MonsterHP += increaseHPAmount; // 체력 증가

		if (_MonsterHP > _MonsterMaxHP)
		{
			_MonsterHP = _MonsterMaxHP;
		}

		cout <<  /*힐러 몬스터 이름*/ "이(가) 체력을 " << increaseHPAmount << "만큼 회복했다." << endl;
	}


	void Healer::Skill() // 반환값이 없는 고유 스킬 호출하는 곳
	{
		IncreaseHP(); // 체력 회복 스킬 사용
	}