#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "pch.h"
using namespace std;

class Character
{
public:
    Character() : _Charactername("BBman"), _CharacterHP(200), _CharacterEXP(0), _CharacterLevel(1), _CharacterGold(0), _CharacterAttack(10), _mapLevel(1) {}
    Character(string Charactername)
        :_Charactername(Charactername), _CharacterHP(200), _CharacterEXP(0), _CharacterLevel(1), _CharacterGold(0), _CharacterAttack(10), _mapLevel(1) {}
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
    void AddItemToInventory(ItemList::Item TempItem);

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
    unordered_map<ItemList::Item, int> _CurrentInventory;
};

#endif