#include "GameManager.h"

GameManager::GameManager()
{
	string name;
	cout << "ĳ���� �̸��� �Է��ϼ���. : ";
	getline(cin, name);

	cout << "BB ������ �����Ͻ� ���� ȯ���մϴ�." << endl;

	_Character = new Character(name);
	_StoreManager = new StoreManager(_Character);
	_MapManager = new MapManager(3);
	_DungeonManager = new DungeonManager(_Character, _MapManager);
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
		cout << "3. �κ��丮�� �����." << endl;
		cout << "4. ������ �����Ѵ�." << endl;
		cout << "�Է� : ";
		getline(cin, choice);
		system("cls");

		if (choice == "1")
		{
			_DungeonManager->EnterDungeon(_Character, _MapManager);
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
			continue;
		}
		if (choice == "4")
		{
			break;
		}
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
}

GameManager::~GameManager()
{
	delete this;
}