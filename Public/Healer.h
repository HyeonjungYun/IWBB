#pragma once
#include "Monster.h"

class Healer : public Monster
{
public:
    Healer();
    Healer(int MapLevel);
    void PrintNothingHappened(); // 고유 스킬 : 무시 사용 -> 로그매니저를 이용해 출력할 문자열 출력 함수
    void SetIgnoreDamage(int damage); // 데미지 무시 값 = 피해 받은 데미지
    float GetIgnoreRate() const; // 무시 확률 1/2 고정
    void TakeDamage(int damage) override;
    bool CanIgnore(); // 힐러 고유 스킬 : 무시, 받는 공격을 무시함
    void IncreaseHP(); // 힐러 기본 스킬 : 힐, 체력을 회복함. 회복량은 1로 고정
    ~Healer() { delete this; }

private:
    float IgnoreRate; // 공격 무시 스킬 실행 확률
    int IgnoreDamage; // 무시한 데미지 값
};