#include "DungeonManager.h"
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
			Fight(Player, MM); //결과 저장하고 나옴
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
				if (IsDungeonClear())
					break;
			}
			Move(MM);
		}
		else if (eFightResult == PLAYERLOSE)
		{
			cout << "전투에서 패배했습니다." << endl;
			cout << "로비로 돌아갑니다." << endl;
			Player->PrintCharacter();
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

bool DungeonManager::IsDungeonClear()
{
		cout << "던전 클리어. 나가시겠습니까 : 1.네 2.아니오" << endl;
		int num = -1;
		cin >> num;
		cin.ignore();
		if (num == 1)
		{
			IsDungeonEnd = true;
			IsBossMonster = false;
			system("cls");
			return true;
		}
		return false;
}

bool DungeonManager::CanMove(MapManager* MM)
{
	//플레이어가 이동할 다음 스테이지 결정
	cout << "이동할 방향을 선택하세요 : 1.위 2.아래 3.왼쪽 4.오른쪽" << endl;
	int dir = -1;
	cin >> dir;
	cin.ignore();
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
	if (MM->IsDungeonClear()) //보스 스테이지야?
	{
		//보스생성
		Monster = new Tanker("보스", 100, 100, 0, 5, 10);
		IsBossMonster = true;
		IsDungeonEnd = true;
	}
	else
	{
		IsBossMonster = false;
		Monster = new Tanker("탱커", 100, 100, 0, 5, 10);
	}
	
	int turn = 0; //0:플레이어턴, 1:
	//싸움
	while (Player->GetHp() > 0 && Monster->GetHp() > 0)
	{
		if(turn == 0)
		{ 
			cout << Player->GetName() << "(이)가 " << Player->GetAttack() << "만큼 " << Monster->GetName() << "(을)를 공격했다!" << endl;
			Monster->TakeDamage(Player->GetAttack());
			cout << Player->GetName() << " 체력 : " << Player->GetHp() << ", " << Monster->GetName() << " 체력 : " << Monster->GetHp() << endl;
			
			turn = 1;
		}
		else
		{
			cout << Monster->GetName() << "(이)가 " << Monster->GetAttack() << "만큼 " << Player->GetName() << "(을)를 공격했다!" << endl;
			Player->TakeDamage(Monster->GetAttack());
			cout << Player->GetName() << " 체력 : " << Player->GetHp() << ", " << Monster->GetName() << " 체력 : " << Monster->GetHp() << endl;

			turn = 0;
		}


		if (Player->GetHp() <= 0)
			eFightResult = PLAYERLOSE;
		if (Monster->GetHp() <= 0)
			eFightResult = PLAYERWIN;
	}
}
