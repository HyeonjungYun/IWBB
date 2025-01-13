
#pragma once
#include "Monster.h"
#include <iostream>
#include <string>
using namespace std;


class Dealer : public Monster
{
public:
    Dealer(string Monstername, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack) // 생성자 호출 순서: 부모 생성자 호출 -> 부모 생성자에서 멤버변수 초기화 -> 부모 생성자 호출 종료 -> 자식 생성자 호출  -> 자식 생성자 호출 종료
        :Monster(Monstername, MonsterHP, MonsterEXP, MonsterGold, MonsterAttack)
    {
        //기타 초기 필요 초기화 
    }
    ~Dealer() {
    }

protected:
    void takeDamage(int damage) override {
        _damage += damage;
        _MonsterHP -= damage;
        cout << getName() << " takes " << damage << " damage. Remaining HP: " << _MonsterHP << endl;
    }

    void skill() override {
        cout << getName() << " uses a powerful attack skill!" << endl;
    }

    bool Canskill() override {
        return _MonsterHP > 20; // 체력이 20 이상일 때 스킬 사용 가능
    }
};


