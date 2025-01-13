﻿#include "DungeonManager.h"
#include "MapManager.h"
#include "Character.h"
#include "Tanker.h"
#include "Healer.h"

void DungeonManager::EnterDungeon(Character* Player, MapManager* MM)
{
	system("cls");

	while (!IsDungeonEnd)
	{
		MM->MapPrint();

		if (!MM->IsClearRoom()) //클리어 했던 곳이야?
		{
			if (MM->IsDungeonClear()) //보스 스테이지야?
			{
				//보스생성
				Monster = new Tanker("보스", 100, 100, 0, 5, 10);
				IsBossMonster = true;
				cout << "보스 스테이지입니다. 보스 클리어" << endl;
				IsDungeonEnd = true;
				break;
			}
			else
			{
				IsBossMonster = false;
				Monster = new Tanker("탱커", 100, 100, 0, 5, 10);
			}

			Player->PrintCharacter();
			Monster->PrintMonster();

			//싸움
			while (Player->GetHp() > 0 && Monster->GetHp() > 0)
			{
				Fight(Player, MM); //결과 저장하고 나옴
			}
		}
		else //이미 클리어 했던 곳이면
			eFightResult = VISITED;
		
		//결과에 따라
		if (eFightResult == PLAYERWIN)
		{
			cout << "전투에서 승리했습니다." << endl;
			
			//플레이어 골드, 경험치 획득
			//펫 효과 발동하는 곳
			MM->RoomClear();

			if (IsBossMonster)
			{
				cout << "던전 클리어. 나가시겠습니까 : 1.네" << endl;
				int num = -1;
				cin >> num;
				if (num == 1)
				{
					DeleteMonster(); //던전 빠져나가기 전에 몬스터 삭제
					IsDungeonEnd = true;
					IsBossMonster = false;
					break;
				}
			}
			DeleteMonster(); //다른 칸으로 이동 전에 몬스터 삭제
			Move(MM);
		}
		else if (eFightResult == PLAYERLOSE)
		{
			cout << "전투에서 패배했습니다." << endl;
			DeleteMonster(); //던전 빠져나가기 전에 몬스터 삭제
			IsDungeonEnd = true;
		}
		else if (eFightResult == VISITED)
		{
			system("cls");
			cout << "이미 클리어한 던전입니다" << endl;
			Move(MM);
		}
	}

}

bool DungeonManager::CanMove(MapManager* MM)
{
	//플레이어가 이동할 다음 스테이지 결정
	cout << "이동할 방향을 선택하세요 : 1.위 2.아래 3.왼쪽 4.오른쪽" << endl;
	int dir = -1;
	cin >> dir;
	Pos pos = MM->GetCharacterPosition();

	if (dir == 1)
	{
		if (MM->GetCharacterPosition().y <= 0) //위 이동불가
			return false;
		MM->SetCharacterPosition(pos.x, pos.y - 1);
		return true;
	}
	if (dir == 2)
	{
		if (MM->GetCharacterPosition().y >= MM->GetMapLevel() + 1) //아래 이동불가
			return false;
		MM->SetCharacterPosition(pos.x, pos.y + 1);
		return true;
	}
	if (dir == 3)
	{
		if (MM->GetCharacterPosition().x <= 0) //왼쪽 이동불가
			return false;
		MM->SetCharacterPosition(pos.x - 1, pos.y);
		return true;
	}
	if (dir == 4)
	{
		if (MM->GetCharacterPosition().x >= MM->GetMapLevel() + 1) //오른쪽 이동불가
			return false;
		MM->SetCharacterPosition(pos.x + 1, pos.y);
		return true;
	}

	return false; //잘못누른경우
}

void DungeonManager::Move(MapManager* MM)
{
	MM->MapPrint();
	while (!CanMove(MM)) //이동하면 트루
	{
		cout << "이동할 수 없습니다." << endl;
	}
	
	MM->RenewDungeonStatus();
}


int DungeonManager::GetMonsterGold()
{
	return Monster->GetGold();
}


void DungeonManager::Fight(Character* Player, MapManager* MM)
{
	cout << Player->GetName() << "(이)가 " << Player->GetAttack() << "만큼 " << Monster->GetName() << "(을)를 공격했다!" << endl;
	Monster->TakeDamage(Player->GetAttack());
	cout << Monster->GetName() << "에게 " << Player->GetAttack() << "만큼 피해를 입혔다!" << endl;
	cout << Player->GetName() << " 체력 : " << Player->GetHp() << ", " << Monster->GetName() << " 체력 : " << Monster->GetHp() << endl;

	if (Player->GetHp() <= 0) 
		eFightResult = PLAYERLOSE;
	if(Monster->GetHp() <= 0)
		eFightResult = PLAYERWIN;
}

void DungeonManager::DeleteMonster()
{
	//몬스터 삭제
	delete Monster;
	Monster = nullptr;
}
