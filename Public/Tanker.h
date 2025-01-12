#pragma once
#include "Monster.h"

class Tanker : public Monster
{
public:
    Tanker(string Monstername, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack) // 생성자 호출 순서: 부모 생성자 호출 -> 부모 생성자에서 멤버변수 초기화 -> 부모 생성자 호출 종료 -> 자식 생성자 호출  -> 자식 생성자 호출 종료
        :Monster(Monstername, MonsterHP, MonsterEXP, MonsterGold, MonsterAttack), reflectionRate(0.2f), reflectionDamage(0)
    {
        //기타 초기 필요 초기화 
    }
    ~Tanker() {}

public:
    void printNothingHappened(); //반사스킬 사용-> 반사 데미지가 0일 경우 로그매니저를 이용해 출력할 문자열 출력 함수
    int getReflectionDamage() { return reflectionDamage; }

protected:
    void takeDamage(int damage) override;
    void skill() override;
    bool Canskill() override;

private:
    bool CanReflection(int damage); //탱커 고유 스킬, 반사데미지 줌, 스킬 성공 여부를 반환
    void decreaseDamage();

private:
    float reflectionRate;
    int reflectionDamage;
};