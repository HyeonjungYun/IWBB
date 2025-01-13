#include "Character.h"

Character::Character()		// 생성자
{
	_CharacterName = "BBman";
	_CharacterHP = 200;
	_CharacterEXP = 0;
	_CharacterLevel = 1;
	_CharacterGold = 0;
	_CharacterAttack = 10;
	_mapLevel = 1;
	_CurrentInventory[ItemList::POTION] = 0;
	_CurrentInventory[ItemList::BB_BOX] = 0;
}

Character::Character(string CharacterName)		// 생성자
{
	_CharacterName = CharacterName;
	_CharacterHP = 200;
	_CharacterEXP = 0;
	_CharacterLevel = 1;
	_CharacterGold = 0;
	_CharacterAttack = 10;
	_mapLevel = 1;
	_CurrentInventory[ItemList::POTION] = 0;
	_CurrentInventory[ItemList::BB_BOX] = 0;
}

string Character::GetName() 
{ 
	return _CharacterName; 
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

void Character::IncreaseEXP(int TempEXP)	// 경험치 획득 시 경험치 증가
{
	_CharacterEXP += TempEXP;

	if (_CharacterEXP > 1000) _CharacterEXP = 1000;
}

int Character::GetGold() const	
{
	return _CharacterGold;
}

void Character::IncreaseGold(int TempGold)	// 골드 획득 시 골드 증가
{
	_CharacterGold += TempGold;
}

void Character::TakeDamage(int damage)		// 대미지 입을 시 HP감소
{
    _CharacterHP -= damage;
    if (_CharacterHP <= 0) { _CharacterHP = 0; return; } //피격 당한 후 hp 체크 -> 몬스터 죽으면 삭제
    //삭제 추가 필요
}

void Character::CharacterLevelUp()		// 캐릭터 레벨업 시 스탯 증가 및 경험치 감소
{
	_CharacterHP += ((_CharacterEXP / 100) * 2) * 20;
	_CharacterAttack += ((_CharacterEXP / 100) * 2) * 20;
	_CharacterLevel += (_CharacterEXP / 100);
	_CharacterEXP %= 100;
}

void Character::PrintCharacter() const	// 현재 캐릭터 스탯 출력
{
	cout << "(" << _CharacterName << ")"  << " Level : "  << _CharacterLevel << endl;
	cout << " 보유 골드 : " << _CharacterGold << endl;
	cout << " HP : " << _CharacterHP << ", ";
	cout << " Attack : " << _CharacterAttack << ", ";
	cout << " EXP : " << _CharacterEXP << endl;
}

void Character::AddItemToInventory(ItemList::Item TempItem)		// 인벤토리에 아이템 추가
{
	_CurrentInventory[TempItem]++;
}

void Character::PrintInventory()		// 현재 인벤토리 현황 출력
{
	cout << "HP포션 수량 : " << _CurrentInventory[ItemList::POTION] << endl;
	cout << "용기의 상자 수량 : " << _CurrentInventory[ItemList::BB_BOX] << endl;
}

Character::~Character()		// 소멸자
{
	delete this;
}
