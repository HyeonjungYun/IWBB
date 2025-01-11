#pragma once
#include "Monster.h"

class Tanker : public Monster
{
public:
    Tanker(string Monstername, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack) // 생성자 호출 순서: 부모 생성자 호출 -> 부모 생성자에서 멤버변수 초기화 -> 부모 생성자 호출 종료 -> 자식 생성자 호출  -> 자식 생성자 호출 종료
        :Monster(Monstername, MonsterHP, MonsterEXP, MonsterGold, MonsterAttack)
    {
        //기타 초기 필요 초기화 
    }
    ~Tanker() {}

public:
};