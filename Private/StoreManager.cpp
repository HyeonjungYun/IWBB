#include "StoreManager.h"

StoreManager::StoreManager(Character* Character)
{
	_Character = Character;
}

void StoreManager::VisitStore()
{
	while (1)
	{
		cout << "상점" << endl;
		cout << "상품 구매" << endl;
		cout << "1. HP포션, 100Gold\n2.레벨업권, 1000Gold\n3.용기의 박스, 500Gold\n4.상점 나가기" << endl;
		cout << "-------------------------------------------" << endl;
		cout << "현재 레벨업권을 구매하시면 " << (_Character->_CharacterEXP / 100) << "레벨업 가능합니다." << endl;
		cout << "HP가 " << (_Character->_CharacterEXP / 100) << " x 20만큼 증가합니다." << endl;
		cout << "공격력이 " << (_Character->_CharacterEXP / 100) << " x 20만큼 증가합니다." << endl;
		cout << "-------------------------------------------" << endl;
		cout << "원하시는 번호를 입력하세요. :";
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

		cout << "잘못 입력하셨습니다." << endl;
	}


}

void StoreManager::BuyHPPotion()
{
	if (_Character->_CharacterGold > POTION_GOLD)
	{
		_Character->_CharacterGold -= POTION_GOLD;
		_Character->AddItemToInventory(ItemList::POTION);
		cout << "HP포션을 구매하였습니다." << endl;
		return;
	}

	cout << "골드가 부족합니다." << endl;
}

void StoreManager::BuyLevelUpCoupon()
{
	if (_Character->_CharacterGold > LEVEL_COUPON_GOLD)
	{
		_Character->_CharacterGold -= LEVEL_COUPON_GOLD;
		_Character->CharacterLevelUp();
		cout << "레벨업이 완료되었습니다." << endl;
		return;
	}

	cout << "골드가 부족합니다." << endl;
}

void StoreManager::BuyBB_Box()
{
	if (_Character->_CharacterGold > BB_BOX_GOLD)
	{
		_Character->_CharacterGold -= BB_BOX_GOLD;
		_Character->AddItemToInventory(ItemList::POTION);
		cout << "랜덤박스를 구매하였습니다." << endl;
		return;
	}

	cout << "골드가 부족합니다." << endl;
}

StoreManager::~StoreManager()
{
	delete this;
}