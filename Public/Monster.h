#pragma once
#include <iostream>
#include <string>
using namespace std;

class Monster
{
public:
    Monster(string Monstername, int MonsterMaxHP, int MonsterHP, int MonsterEXP, int MonsterGold, int MonsterAttack)
        :_Monstername(Monstername), _MonsterMaxHP(MonsterMaxHP), _MonsterHP(MonsterHP), _MonsterEXP(MonsterEXP), _MonsterGold(MonsterGold), _MonsterAttack(MonsterAttack), _Damage(0) //생성자의 매개변수로 멤버변수 초기화
    {
        //기타 초기 필요 초기화 
    }
    virtual ~Monster() {}

public: // 부모 클래스에서 정의 해서 자식 객체에서 사용하는 함수들
    string GetName() { return _Monstername; }
     int GetHp() { return _MonsterHP; }
     int GetAttack() { return _MonsterAttack; }
    
public:
    virtual void TakeDamage(int damage) = 0;
    virtual void Skill() = 0; //부모 클래스에서 선언하고 자식 몬스터가 고유 스킬을 사용할 때 호출할 함수
    virtual bool Canskill() = 0; //부모 클래스에서 선언하고 자식 몬스터가 고유 스킬을 사용할 때 호출할 함수, 반환값이 성공여부라 bool을 반환하는 경우

public: //테스트를 위한
    virtual void PrintMonster() const
    {
        cout << " 몬스터 이름 : " << _Monstername << endl;
        cout << " 몬스터 이름 : " << _MonsterHP << endl;
        cout << " 몬스터 이름 : " << _MonsterEXP << endl;
        cout << " 몬스터 이름 : " << _MonsterGold << endl;
        cout << " 몬스터 이름 : " << _MonsterAttack << endl;
        cout << endl;
    }

protected: //부모 클래스에서 정의하고 자식 클래스에서 공통으로 사용하는 멤버변수들(탱커의 HP, 어택커의 HP, 힐러의 HP..)
    string  _Monstername;
    int _MonsterMaxHP;
    int _MonsterHP;
    int _MonsterEXP;
    int _MonsterGold;
    int _MonsterAttack;
    int _Damage; //받은 데미지 저장을 위한 변수
};