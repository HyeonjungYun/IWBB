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
		cout << "-------------------------------------------" << endl;
		cout << "���� ���������� �����Ͻø� " << (_Character->_CharacterEXP / 100) << "������ �����մϴ�." << endl;
		cout << "HP�� " << (_Character->_CharacterEXP / 100) << " x 20��ŭ �����մϴ�." << endl;
		cout << "���ݷ��� " << (_Character->_CharacterEXP / 100) << " x 20��ŭ �����մϴ�." << endl;
			//_CharacterHP += ((_CharacterEXP / 100) * 2) * 20;
			//_CharacterAttack += ((_CharacterEXP / 100) * 2) * 20;
		cout << "-------------------------------------------" << endl;
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