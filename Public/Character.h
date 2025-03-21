﻿#ifndef _CHARACTER_H_
#define _CHARACTER_H_

#include "pch.h"
using namespace std;

// 캐릭터의 정보를 저장하는 클래스
class Character
{
public:
    Character(string Charactername);
    ~Character();

    string GetName();
    int GetHp() const;
    void SetHP(int HP);
    int GetMaxHP() const;
    void SetMaxHP(int MaxHP);
    int GetAttack() const;
    void SetAttack(int Attack);
    int GetEXP() const;
    void IncreaseEXP(int TempEXP);
    int GetGold() const;
    int GetLevel() const;
    void IncreaseGold(int TempGold);
    void TakeDamage(int damage);
    void CharacterLevelUp();
    void AddItemToInventory(ItemList::Item TempItem);
    void PrintCharacter() const;
    void PrintInventory();
    void UseItem();
    void UseHPPotion();
    void UseBB_Box();
    void PrizeGarbage() const;

 //테스트를 위한 
    int _mapLevel;
    void CharacterSkill() { cout << "캐릭터 스킬 사용, 아무것도 없음" << endl; }
    void SetLevel(int Level);

public:
    string _CharacterName;
    int _CharacterHP;
    int _CharacterMaxHP;
    int _CharacterEXP;
    int _CharacterLevel;
    int _CharacterGold;
    int _CharacterAttack;
    unordered_map<ItemList::Item, int> _CurrentInventory;
    int _PetTheif;
};

#endif