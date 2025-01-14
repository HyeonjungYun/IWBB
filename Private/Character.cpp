#include "Character.h"

Character::Character(string CharacterName)		// 생성자
{
	_CharacterName = CharacterName;
	_CharacterMaxHP = 400;
	_CharacterHP = _CharacterMaxHP;
	_CharacterEXP = 0;
	_CharacterLevel = 1;
	_CharacterGold = 0;
	_CharacterAttack = 35;
	_mapLevel = 1;
	_CurrentInventory[ItemList::POTION] = 0;
	_CurrentInventory[ItemList::BB_BOX] = 0;
	_PetTheif = 0;
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

int Character::GetMaxHP() const
{
	return _CharacterMaxHP;
}

void Character::SetMaxHP(int MaxHP)
{
	_CharacterMaxHP = MaxHP;
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

	if (_PetTheif)
	{
		_CharacterGold += TempGold / 10;
		cout << "애완 도둑이 추가 골드를 훔쳐왔습니다!" << endl;
	}
}

void Character::TakeDamage(int damage)		// 대미지 입을 시 HP감소
{
    _CharacterHP -= damage;
    if (_CharacterHP <= 0) { _CharacterHP = 0; return; } //피격 당한 후 hp 체크 -> 몬스터 죽으면 삭제
    //삭제 추가 필요
}

void Character::CharacterLevelUp()		// 캐릭터 레벨업 시 스탯 증가 및 경험치 감소
{
	_CharacterMaxHP += ((_CharacterEXP / 100) * 2) * 20;
	_CharacterHP = _CharacterMaxHP;
	_CharacterAttack += ((_CharacterEXP / 100) * 2) * 20;
	_CharacterLevel += (_CharacterEXP / 100);
	_CharacterEXP %= 100;
}

void Character::PrintCharacter() const	// 현재 캐릭터 스탯 출력
{
	cout << "(" << _CharacterName << ")"  << " Level : "  << _CharacterLevel << endl;
	cout << " 보유 골드 : " << _CharacterGold << endl;
	cout << " HP : " << _CharacterHP << "/" << _CharacterMaxHP << ", ";
	cout << " Attack : " << _CharacterAttack << ", ";
	cout << " EXP : " << _CharacterEXP << ", ";
	cout << "애완도둑 : " << _PetTheif << "명" << endl;
}

void Character::AddItemToInventory(ItemList::Item TempItem)		// 인벤토리에 아이템 추가
{
	_CurrentInventory[TempItem]++;
}

void Character::PrintInventory()		// 현재 인벤토리 현황 출력
{
	system("cls");
	cout << "HP포션 수량 : " << _CurrentInventory[ItemList::POTION] << endl;
	cout << "용기의 상자 수량 : " << _CurrentInventory[ItemList::BB_BOX] << endl;
}

void Character::UseItem()
{
	cout << "아이템을 사용하시겠습니까?" << endl;
	cout << "1.HP포션 사용\n2. 용기의 상자 사용\n그 외. 사용하지 않는다." << endl;

	string choice;
	getline(cin, choice);

	if (choice == "1")
	{
		UseHPPotion();
		return;
	}
	if (choice == "2")
	{
		UseBB_Box();
		return;
	}
}

void Character::UseHPPotion()
{
	if (_CurrentInventory[ItemList::POTION] <= 0)
	{
		system("cls");
		cout << "사용 가능한 HP포션이 없습니다." << endl;
	}

	_CurrentInventory[ItemList::POTION]--;
	_CharacterHP += 100;

	if (_CharacterHP >= _CharacterMaxHP)
		_CharacterHP = _CharacterMaxHP;
}

void Character::UseBB_Box()
{
	if (_CurrentInventory[ItemList::BB_BOX] <= 0)
	{
		system("cls");
		cout << "사용 가능한 용기의 상자가 없습니다." << endl;
	}

	_CurrentInventory[ItemList::BB_BOX]--;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 100);

	int prize = dist(gen);

	system("cls");
	cout << "상자를 여는 중";
	Sleep(1000);
	cout << ". ";
	Sleep(1000);
	cout << ". ";
	Sleep(1000);
	cout << "." << endl;
	Sleep(1000);

	if (prize >= 1 && prize <= 5)
	{
		_PetTheif++;
		cout << "상자에 그려진 소환진에서 애완도둑이 소환되었습니다." << endl;
		cout << "애완 도둑은 모든 상황에서 골드를 습득할 때 10%의 추가 골드를 획득합니다." << endl;
		cout << "현재 애완 도둑이 " << _PetTheif << "명 있습니다." << endl;
	}
	else
	{
		PrizeGarbage();
	}
	
}

void Character::PrizeGarbage() const
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(1, 100);

	int prize = dist(gen);

	if (prize <= 25 && prize >= 1)
	{
		cout << "상자에서 \"아라의 차은우 화보집\"이 발견되었다." << endl;
		cout << "그 분의 용안을 보았더니 마음이 편안해졌다." << endl;
	}
	if (prize <= 50 && prize > 25)
	{
		cout << "상자에서 \"현중의 C++전공서\"가 발견되었다." << endl;
		cout << "전혀 펼친 흔적이 없다..." << endl;
	}
	if (prize <= 75 && prize > 50)
	{
		cout << "상자에서 \"지현의 개껌\"이 발견되었다." << endl;
		cout << "강아지들이 전혀 좋아하지 않을 것 같다..." << endl;
	}
	if (prize <= 100 && prize > 75)
	{
		cout << "상자에서 \"오수의 야구빠다\"가 발견되었다." << endl;
		cout << "피가 묻어있다. 누군가를 때린 것 같다..." << endl;
	}
	cout << "그다지 쓸모는 없어보인다. 던전 구석에 버리자." << endl;
}

Character::~Character()		// 소멸자
{
	delete this;
}
