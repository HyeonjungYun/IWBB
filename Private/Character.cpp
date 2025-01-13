#include "Character.h"

Character::Character() : _Charactername("BBman"), _CharacterHP(200), _CharacterEXP(0), _CharacterLevel(1), _CharacterGold(0), _CharacterAttack(10), _mapLevel(1)
{
	_CurrentInventory[ItemList::POTION] = 0;
	_CurrentInventory[ItemList::BB_BOX] = 0;
}

Character::Character(string Charactername)
	:_Charactername(Charactername), _CharacterHP(200), _CharacterEXP(0), _CharacterLevel(1), _CharacterGold(0), _CharacterAttack(10), _mapLevel(1) 
{
	_CurrentInventory[ItemList::POTION] = 0;
	_CurrentInventory[ItemList::BB_BOX] = 0;
}

string Character::GetName() 
{ 
	return _Charactername; 
}

int Character::GetHp() const
{ 
	return _CharacterHP; 
}

void Character::SetHP(int HP)
{
	_CharacterHP = HP;
}

int Character::GetAttack() const 
{ 
	return _CharacterAttack; 
}

void Character::SetAttack(int Attack)
{
	_CharacterAttack = Attack;
}

int Character::GetEXP() const
{
	return _CharacterEXP;
}

void Character::IncreaseEXP(int TempEXP)
{
	_CharacterEXP += TempEXP;

	if (_CharacterEXP > 1000) _CharacterEXP = 1000;
}

int Character::GetGold() const
{
	return _CharacterGold;
}

void Character::IncreaseGold(int TempGold)
{
	_CharacterGold += TempGold;
}

void Character::TakeDamage(int damage)
{
    _CharacterHP -= damage;
    if (_CharacterHP <= 0) { _CharacterHP = 0; return; } //피격 당한 후 hp 체크 -> 몬스터 죽으면 삭제
    //삭제 추가 필요
}

void Character::CharacterLevelUp()
{
	_CharacterHP += ((_CharacterEXP / 100) * 2) * 20;
	_CharacterAttack += ((_CharacterEXP / 100) * 2) * 20;
	_CharacterEXP %= 100;
}

void Character::PrintCharacter() const
{
	cout << "(" << _Charactername << ")" <<endl;
	cout << " 보유 골드 : " << _CharacterGold << endl;
	cout << " HP : " << _CharacterHP << ", ";
	cout << " Attack : " << _CharacterAttack << ", ";
	cout << " EXP : " << _CharacterEXP << endl;
}

void Character::AddItemToInventory(ItemList::Item TempItem)
{
	_CurrentInventory[TempItem]++;
}

Character::~Character()
{
	delete this;
}
