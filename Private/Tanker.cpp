#include "Tanker.h"

void Tanker::printNothingHappened()
{
	cout << "상대의 공격이 너무 약해서 아무 일도 일어나지 않았다." << endl;
}

void Tanker::takeDamage(int damage)
{
	_damage = damage;
	
	//일정확률로 발동
	decreaseDamage();
	
	//스킬 발동 후 감소된 데미지로 피해 입음
	_MonsterHP -= _damage;
	if (_MonsterHP <= 0) { _MonsterHP = 0; return; } //피격 당한 후 hp 체크 -> 몬스터 죽으면 삭제
	//삭제 추가 필요

}

void Tanker::skill() //반환값이 없는 고유 스킬 호출하는 곳
{
	//dosome
}

bool Tanker::Canskill() //반환값이 bool인 고유 스킬 호출한는 곳
{

	return CanReflection(_damage); //탱커 고유 스킬 호출
}

/*
	배틀매니저 클래스에서 Monster* Tanker 를 들고있을 때
	오버라이드를 이용한 자식몬스터 고유 함수 호출

	플레이어->attack();
	Tanker->takeDamage();

	일정확률로 탱커 반사뎀 스킬 발동

	if(Tanker->Canskill())  //스킬이 성공하면
	{
		//플레이어에게 데미지를 돌려줌
		플레이어->takeDamage(Tanker->getReflectionDamage());
	}
	else //스킬이 실패하면
		Tanker->printNothingHappened();
*/

/*
	탱커가 데미지 받으면 일정 데미지를 즉시 플레이어에게 돌려줌
	필요한 변수
	-몬스터가 받는 데미지
	-몬스터가 돌려줄 데미지 정할 비율 변수 float
	필요한 기능
	-플레이어에게 데미지를 줌 -> 배틀 매니저 이용
*/

bool Tanker::CanReflection(int damage) //반사데미지
{
	reflectionDamage = static_cast <int>(round(damage * reflectionRate)); // (받은 데미지 * 0.2) 의 값에 반올림으로 반사 데미지를 정함 
	
	if (reflectionDamage < 1) // 반사데미지가 0이라 아무 일도 일어나지 않은 경우
	{
		return false;
	}
	else
		return true;
}

void Tanker::decreaseDamage()
{
	if (_damage > 2) // 피해 감소량보다 입는 피해량이 더 클때만
	{
		_damage -= 2;
	}
}
