#include "GameManager.h"

GameManager::GameManager()
{
	string name;
	cout << "캐릭터 이름을 입력하세요. : ";
	getline(cin, name);

	cout << "BB 던전에 입장하신 것을 환영합니다." << endl;

	_MapLevel = 1;
	_Character = new Character(name);
	_StoreManager = new StoreManager(_Character);
}

void GameManager::GamePlaying()
{
	while (1)
	{
		string choice;

		cout << "-------------------------------------------" << endl;
		_Character->PrintCharacter();
		cout << "-------------------------------------------" << endl;
		cout << endl << "아래로 내려가는 계단이 보인다." << endl;
		cout << "1. 계단을 내려간다." << endl;
		cout << "2. 상점을 이용한다." << endl;
		cout << "3. 인벤토리를 열어본다." << endl;
		cout << "4. 게임을 종료한다." << endl;
		cout << "입력 : ";
		getline(cin, choice);
		system("cls");

		if (choice == "1")
		{
			DungeonManager* _DungeonManager = new DungeonManager(_Character, _MapLevel);
			_DungeonManager->EnterDungeon();
			continue;
		}
		if (choice == "2")
		{
			_StoreManager->VisitStore();
			continue;
		}
		if (choice == "3")
		{
			_Character->PrintInventory();
			_Character->UseItem();
			continue;
		}
		if (choice == "4")
		{
			break;
		}
		cout << "잘못 입력하셨습니다." << endl;
	}
}

int GameManager::GetMapLevel() const
{
	return _MapLevel;
}

void GameManager::SetMapLevel()
{
	_MapLevel++;
}

GameManager::~GameManager()
{
	delete this;
}