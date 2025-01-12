#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
    Character(string Charactername, int CharacterHP, int CharacterEXP, int CharacterGold, int CharacterAttack)
    :_Charactername(Charactername), _CharacterHP(CharacterHP), _CharacterEXP(CharacterEXP), _CharacterGold(CharacterGold), _CharacterAttack(CharacterAttack), _Damage(0)
    {

    }
	~Character() {}
public: 
    string GetName() { return _Charactername; }
    int GetHp() { return _CharacterHP; }
    int GetAttack() { return _CharacterAttack; }
    void TakeDamage(int damage)
    {
        _Damage = damage;
        _CharacterHP -= _Damage;
        if (_CharacterHP <= 0) { _CharacterHP = 0; return; } //피격 당한 후 hp 체크 -> 몬스터 죽으면 삭제
        //삭제 추가 필요
    }

public: //테스트를 위한 
    void CharacterSkill() { cout << "캐릭터 스킬 사용, 아무것도 없음" << endl; }
    void PrintCharacter() const;

public:
    string _Charactername;
    int _CharacterHP;
    int _CharacterEXP;
    int _CharacterGold;
    int _CharacterAttack;
    int _Damage; //받은 데미지 저장을 위한 변수
};