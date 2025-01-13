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
	cout << "ĳ���� �̸��� �Է��ϼ���. : ";
	getline(cin, name);

	cout << "BB ������ �����Ͻ� ���� ȯ���մϴ�." << endl;

	_Character = new Character(name);
	//_DungeonManager = new DungeonManager;
	_StoreManager = new StoreManager(_Character);
}

void GameManager::GamePlaying()
{
	while (1)
	{
		string choice;

		cout << "�Ʒ��� �������� ����� ���δ�." << endl;
		cout << "-------------------------------------------" << endl;
		_Character->PrintCharacter();
		cout << "-------------------------------------------" << endl;
		cout << "1. ����� ��������." << endl;
		cout << "2. ������ �̿��Ѵ�." << endl;
		cout << "3. ������ �����Ѵ�." << endl;
		cout << "�Է� : ";
		getline(cin, choice);

		if (choice == "1")
		{
			// ���� ����
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