#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "pch.h"
#include "Character.h"
#include "DungeonManager.h"
#include "StoreManager.h"

class GameManager
{
public:
	GameManager();
	void GamePlaying();
	~GameManager();
private:
	Character* _Character;
	//DungeonManager* _DungeonManager;
	StoreManager* _StoreManager;
};

GameManager::GameManager()
{
	string name;
	cout << "캐릭터 이름을 입력하세요. : ";
	getline(cin, name);

	cout << "BB 던전에 입장하신 것을 환영합니다." << endl;

	_Character = new Character(name);
	//_DungeonManager = new DungeonManager;
	_StoreManager = new StoreManager(_Character);
}

void GameManager::GamePlaying()
{
	while (1)
	{
		string choice;

		cout << "아래로 내려가는 계단이 보인다." << endl;
		cout << "-------------------------------------------" << endl;
		_Character->PrintCharacter();
		cout << "-------------------------------------------" << endl;
		cout << "1. 계단을 내려간다." << endl;
		cout << "2. 상점을 이용한다." << endl;
		cout << "3. 게임을 종료한다." << endl;
		cout << "입력 : ";
		getline(cin, choice);

		if (choice == "1")
		{
			// 던전 입장
		}
		if (choice == "2")
		{
			_StoreManager->VisitStore();
		}
		if (choice == "3")
		{
			break;
		}
	}
}

GameManager::~GameManager()
{
	delete this;
}

#endif