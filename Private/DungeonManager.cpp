#include "DungeonManager.h"
#include "Tanker.h"
#include "Attacker.h"
#include "Healer.h"
#include "Monster.h"

bool DungeonManager::EnterDungeon()
{
	system("cls");

	while (1)
	{
		MM->MapPrint();

		if (MM->IsDungeonClear())
			if (IsExitDungeon()) return false;
				 
		if (!MM->IsClearRoom()) //클리어 했던 곳이야?
		{
			Fight(MM); //결과 저장하고 나옴
			Sleep(2100);
		}
		
		//결과에 따라
		if (eFightResult == PLAYERWIN)
		{
			cout << "전투에서 승리했습니다." << endl;
			
			//플레이어 골드, 경험치 획득
			MM->RoomClear();
		}
		if (eFightResult == PLAYERLOSE)
		{
			cout << "전투에서 패배했습니다." << endl;
			cout << "로비로 돌아갑니다." << endl;
			return true;
		}
		if (eFightResult == PLAYERRUN)
		{
			cout << "몬스터에게서 도망쳤습니다." << endl;
		}
		system("cls");
		Move(MM);
	}

}

bool DungeonManager::IsExitDungeon()
{
	cout << "탈출구가 보입니다. 나가시겠습니까 : 1.네 2.아니오" << endl;
	
	string choice;
	getline(cin, choice);
	system("cls");

	if (choice == "1")
	{
		IsDungeonEnd = true;
		IsBossMonster = false;

		cout << "던전 탐험을 마쳤습니다." << endl;
		cout << "던전 탐험 보상으로 " << DungeonMapLevel * 150 << "G를 얻었습니다." << endl;
		cout << "던전 탐험 보상으로 " << DungeonMapLevel * 100 << "EXP를 얻었습니다." << endl;
		Player->IncreaseGold(DungeonMapLevel * 150);
		Player->IncreaseEXP(DungeonMapLevel * 100);

		cout << "던전을 나가는 중입니다";
		Sleep(1000);
		cout << ". ";
		Sleep(1000);
		cout << ". ";
		Sleep(1000);
		cout << ". " << endl;
		Sleep(1000);

		system("cls");
		return true;
	}
	return false;
}

bool DungeonManager::CanMove(MapManager* MM)
{
	MM->MapPrint();
	//플레이어가 이동할 다음 스테이지 결정
	cout << "이동할 방향을 선택하세요 : 1.위 2.아래 3.왼쪽 4.오른쪽" << endl;
	string choice;
	getline(cin, choice);
	
	system("cls");

	Pos CharacterPos = MM->GetCharacterPosition();

	if (choice == "1")
	{
		if (CharacterPos.y <= 0) //위 이동불가
			return false;
		MM->SetCharacterPosition(CharacterPos.x, CharacterPos.y - 1);
		return true;
	}
	if (choice == "2")
	{
		if (CharacterPos.y >= DungeonMapLevel + 1) //아래 이동불가
			return false;
		MM->SetCharacterPosition(CharacterPos.x, CharacterPos.y + 1);
		return true;
	}
	if (choice == "3")
	{
		if (CharacterPos.x <= 0) //왼쪽 이동불가
			return false;
		MM->SetCharacterPosition(CharacterPos.x - 1, CharacterPos.y);
		return true;
	}
	if (choice == "4")
	{
		if (CharacterPos.x >= DungeonMapLevel + 1) //오른쪽 이동불가
			return false;
		MM->SetCharacterPosition(CharacterPos.x + 1, CharacterPos.y);
		return true;
	}

	return false; //잘못누른경우
}

void DungeonManager::Move(MapManager* MM)
{
	while (!CanMove(MM)) //이동하면 트루
	{
		cout << "이동할 수 없습니다." << endl;
	}
	
	MM->RenewDungeonStatus();
}

void DungeonManager::Fight(MapManager* MM)
{
	Monster* monster = CreateRandomMonster();

	while (1)
	{
		monster->PrintMonster();
		cout << "무엇을 하시겠습니까?" << endl;
		cout << "1.공격 2. 아이템 3. 도망친다." << endl;
		cout << "입력 : ";

		string choice;
		getline(cin, choice);
		system("cls");

		if (choice == "1")
		{
			monster->TakeDamage(Player->GetAttack());

			cout << Player->GetName() << "가 " << monster->GetName() << "에게 " << Player->GetAttack() << "만큼 대미지를 입혔습니다." << endl;
			cout << monster->GetName() << "의 HP : " << monster->GetHp() << endl;

			if (monster->GetHp() <= 0)
			{
				cout << "몬스터가 쓰러졌습니다." << endl;
				cout << "골드" << monster->GetGold() << "G를 획득했습니다." << endl;
				cout << "경험치" << monster->GetEXP() << "EXP를 획득했습니다." << endl;
				//플레이어 골드, 경험치 획득
				Player->IncreaseGold(monster->GetGold());
				Player->IncreaseEXP(monster->GetEXP());
				eFightResult = PLAYERWIN;
				return;
			}

		}
		if (choice == "2")
		{
			Player->PrintInventory();
			Player->UseItem();
		}
		if (choice == "3")
		{
			if (CanRun())
				return;
			cout << "도망치지 못 했습니다." << endl;
		}
		

		if (monster->GetMonsterTypeID() == MonsterList::HEALER)
		{
			monster->MonsterAction();
		}
		else
		{
			Player->SetHP(Player->GetHp() - monster->GetAttack());
			cout << monster->GetName() << "가 " << Player->GetName() << "에게 " << Player->GetAttack() << "만큼 대미지를 입혔습니다." << endl;
			cout << monster->GetName() << "의 HP : " << monster->GetHp() << endl;
		}

		if (Player->GetHp() <= 0)
		{
			eFightResult = PLAYERLOSE;
			return;
		}
	}
}

bool DungeonManager::CanRun()
{
	int rate = CreateRandomValue(1, 10);
	
	if (rate < 4)
		return true;
	return false;
}

Monster* DungeonManager::CreateRandomMonster()
{
	int MonsterValue = CreateRandomValue(1,3);
	if (MonsterValue == 1)
	{
		return new Tanker(DungeonMapLevel, MonsterList::TANKER);
	}
	if (MonsterValue == 2)
	{
		return new Attacker(DungeonMapLevel, MonsterList::ATTACKER);
	}
	return new Healer(DungeonMapLevel, MonsterList::HEALER);
}
