#include "StoreManager.h"

StoreManager::StoreManager(Character* Character)
{
	_Character = Character;
}

void StoreManager::VisitStore()
{
	while (1)
	{
		cout << "����" << endl;
		cout << "��ǰ ����" << endl;
		cout << "1. HP����\n2.��������\n3.����� �ڽ�\n4.���� ������" << endl;
		cout << "���Ͻô� ��ȣ�� �Է��ϼ���. :";
		string choice;
		getline(cin, choice);

		if (choice == "1")
		{
			_Character->AddItemToInventory(ItemList::POTION);
			cout << "HP������ �����Ͽ����ϴ�." << endl;
			continue;
		}
		if (choice == "2")
		{
			_Character->CharacterLevelUp();
			cout << "�������� �Ϸ�Ǿ����ϴ�." << endl;
			continue;
		}
		if (choice == "3")
		{
			_Character->AddItemToInventory(ItemList::BB_BOX);
			cout << "����� �ڽ��� �����Ͽ����ϴ�." << endl;
			continue;
		}
		if (choice == "4")
		{
			break;
		}

		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}


}

StoreManager::~StoreManager()
{
	delete this;
}