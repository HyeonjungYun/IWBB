#pragma once
#include <iostream>
#include <string>
using namespace std;

class Character
{
public:
    Character(string Charactername, int CharacterHP, int CharacterEXP, int CharacterLevel, int CharacterGold, int CharacterAttack)
    :_Charactername(Charactername), _CharacterHP(CharacterHP), _CharacterEXP(CharacterEXP),_CharacterLevel(CharacterLevel), _CharacterGold(CharacterGold), _CharacterAttack(CharacterAttack), _mapLevel(1) {}
    ~Character();

    string GetName();
    int GetHp() const;
    void SetHP(int HP);
    int GetAttack() const;
    void SetAttack(int Attack);
    int GetEXP() const;
    void IncreaseEXP(int TempEXP);
    int GetGold() const;
    void IncreaseGold(int TempGold);
    void TakeDamage(int damage);
    void CharacterLevelUp();

 //테스트를 위한 
    int _mapLevel;
    void CharacterSkill() { cout << "캐릭터 스킬 사용, 아무것도 없음" << endl; }
    void PrintCharacter() const;

public:
    string _Charactername;
    int _CharacterHP;
    int _CharacterEXP;
    int _CharacterLevel;
    int _CharacterGold;
    int _CharacterAttack;
};