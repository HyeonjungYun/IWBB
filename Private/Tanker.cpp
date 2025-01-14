#include "Tanker.h"
Tanker::Tanker()
{
}
Tanker::Tanker(int MapLevel) : Monster(MapLevel)
{
	random_device rd; //랜덤 생성 클래스 선언
	mt19937 gen(rd()); // 난수
	uniform_int_distribution<> dist(0, 1);
	int randomValue = dist(gen); // 0,1;
	if (randomValue == 1)
		_Monstername = "그라가스";
	else
		_Monstername = "라인하르트";
}

void Tanker::Reflection(int damage)
{
	random_device rd; //랜덤 생성 클래스 선언
	mt19937 gen(rd()); // 난수
	uniform_int_distribution<> dist(0, 1);
	int randomValue = dist(gen); // 0,1;
	if (randomValue == 0)
	{
		int ReflectionDamage = CalReflectionDamage(damage);

		cout << _Monstername << "가 스킬을 사용했다!!" << endl;
		cout << _Monstername << "가 데미지 " << damage << "를 입고 " << ReflectionDamage << "를 반사했다." << endl;
		_MonsterHP -= damage;

	}
	if (randomValue == 1)
	{
		cout << _Monstername << "가 스킬 사용에 실패했다!!" << endl;
		cout << _Monstername << "가 데미지 " << damage << "를 입었다 " << endl;

	}
}

void Tanker::TakeDamage(int damage)
{
	int Damage = damage;
	Reflection(damage);
	_MonsterHP -= Damage;

	if (_MonsterHP <= 0) { _MonsterHP = 0; return; }
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