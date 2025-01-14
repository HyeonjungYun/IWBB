#include "GameManager.h"

GameManager::GameManager()
{
	string name;
	cout << "ĳ���� �̸��� �Է��ϼ���. : ";
	getline(cin, name);

	cout << "BB ������ �����Ͻ� ���� ȯ���մϴ�." << endl;

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
		cout << endl << "�Ʒ��� �������� ����� ���δ�." << endl;
		cout << "1. ����� ��������." << endl;
		cout << "2. ������ �̿��Ѵ�." << endl;
		cout << "3. �κ��丮�� �����." << endl;
		cout << "4. ������ �����Ѵ�." << endl;
		cout << "�Է� : ";
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
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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