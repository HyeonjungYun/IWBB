﻿#pragma once
#include "Monster.h"

class Healer : public Monster
{
public:
    Healer(string Monstername, int MonsterMaxHP, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack) // 생성자 호출 순서: 부모 생성자 호출 -> 부모 생성자에서 멤버변수 초기화 -> 부모 생성자 호출 종료 -> 자식 생성자 호출  -> 자식 생성자 호출 종료
        :Monster(Monstername, MonsterMaxHP, MonsterHP, MonsterEXP, MonsterGold, MonsterAttack), IgnoreDamage(0), IgnoreRate(0.5f)
    {
        //기타 초기 필요 초기화 
    }
    ~Healer() { delete this; }

public:
    void PrintNothingHappened(); // 고유 스킬 : 무시 사용 -> 로그매니저를 이용해 출력할 문자열 출력 함수
    void SetIgnoreDamage(int damage); // 데미지 무시 값 = 피해 받은 데미지
    float GetIgnoreRate() const; // 무시 확률 1/2 고정

public:
    void TakeDamage(int damage) override;
    void Skill() override;
    bool Canskill() override;

private:
    bool CanIgnore(); // 힐러 고유 스킬 : 무시, 받는 공격을 무시함
    void IncreaseHP(); // 힐러 기본 스킬 : 힐, 체력을 회복함. 회복량은 1로 고정

private:
    float IgnoreRate; // 공격 무시 스킬 실행 확률
    int IgnoreDamage; // 무시한 데미지 값
};