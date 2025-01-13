#include "StoreManager.h"

StoreManager::StoreManager(Character* Character)		// ������
{
	_Character = Character;
}

void StoreManager::VisitStore()		// ���� ���Ÿ� �����ϴ� �Լ�
{
	while (1)
	{
		cout << "����" << endl;
		cout << "��ǰ ����" << endl;
		cout << "1. HP����, 100Gold\n2.��������, 1000Gold\n3.����� �ڽ�, 500Gold\n4.���� ������" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "���� ���������� �����Ͻø� " << (_Character->_CharacterEXP / 100) << "������ �����մϴ�." << endl;
		cout << "HP�� " << (_Character->_CharacterEXP / 100) << " x 20��ŭ �����մϴ�." << endl;
		cout << "���ݷ��� " << (_Character->_CharacterEXP / 100) << " x 20��ŭ �����մϴ�." << endl;
		cout << "-------------------------------------------" << endl;
		cout << "���Ͻô� ��ȣ�� �Է��ϼ���. :";
		string choice;
		getline(cin, choice);
		system("cls");

		if (choice == "1")	
		{
			BuyHPPotion();
			continue;
		}
		if (choice == "2")
		{
			BuyLevelUpCoupon();
			continue;
		}
		if (choice == "3")
		{
			BuyBB_Box();
			continue;
		}
		if (choice == "4")
		{
			break;
		}

		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}


}

void StoreManager::BuyHPPotion()		// ������ �����ϰ� ���� ��带 �����ϴ� �Լ�
{
	if (_Character->_CharacterGold > POTION_GOLD)
	{
		_Character->_CharacterGold -= POTION_GOLD;
		_Character->AddItemToInventory(ItemList::POTION);
		cout << "HP������ �����Ͽ����ϴ�." << endl;
		return;
	}

	cout << "��尡 �����մϴ�." << endl;
}

void StoreManager::BuyLevelUpCoupon()		// ���������� �����ϰ� ���� ��带 �����ϴ� �Լ�
{
	if (_Character->_CharacterGold > LEVEL_COUPON_GOLD)
	{
		_Character->_CharacterGold -= LEVEL_COUPON_GOLD;
		_Character->CharacterLevelUp();
		cout << "�������� �Ϸ�Ǿ����ϴ�." << endl;
		return;
	}

	cout << "��尡 �����մϴ�." << endl;
}

void StoreManager::BuyBB_Box()		// ����� ���ڸ� �����ϰ� ���� ��带 �����ϴ� �Լ�
{
	if (_Character->_CharacterGold > BB_BOX_GOLD)
	{
		_Character->_CharacterGold -= BB_BOX_GOLD;
		_Character->AddItemToInventory(ItemList::POTION);
		cout << "�����ڽ��� �����Ͽ����ϴ�." << endl;
		return;
	}

	cout << "��尡 �����մϴ�." << endl;
}

StoreManager::~StoreManager()		// �Ҹ���
{
	delete this;
}