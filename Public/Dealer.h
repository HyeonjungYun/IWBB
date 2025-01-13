
#pragma once
#include "Monster.h"
#include <iostream>
#include <string>
using namespace std;


class Dealer : public Monster
{
public:
    Dealer(string Monstername, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack) // ������ ȣ�� ����: �θ� ������ ȣ�� -> �θ� �����ڿ��� ������� �ʱ�ȭ -> �θ� ������ ȣ�� ���� -> �ڽ� ������ ȣ��  -> �ڽ� ������ ȣ�� ����
        :Monster(Monstername, MonsterHP, MonsterEXP, MonsterGold, MonsterAttack)
    {
        //��Ÿ �ʱ� �ʿ� �ʱ�ȭ 
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
        return _MonsterHP > 20; // ü���� 20 �̻��� �� ��ų ��� ����
    }
};


