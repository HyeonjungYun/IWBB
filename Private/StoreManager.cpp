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
		cout << "1. HP포션\n2.레벨업권\n3.용기의 박스\n4.상점 나가기" << endl;
		cout << "원하시는 번호를 입력하세요. :";
		string choice;
		getline(cin, choice);

		if (choice == "1")
		{
			_Character->AddItemToInventory(ItemList::POTION);
			cout << "HP포션을 구매하였습니다." << endl;
			continue;
		}
		if (choice == "2")
		{
			_Character->CharacterLevelUp();
			cout << "레벨업이 완료되었습니다." << endl;
			continue;
		}
		if (choice == "3")
		{
			_Character->AddItemToInventory(ItemList::BB_BOX);
			cout << "용기의 박스를 구매하였습니다." << endl;
			continue;
		}
		if (choice == "4")
		{
			break;
		}

		cout << "잘못 입력하셨습니다." << endl;
	}


}

StoreManager::~StoreManager()
{
	delete this;
}