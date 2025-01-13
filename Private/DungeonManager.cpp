#include "DungeonManager.h"
#include "MapManager.h"
#include "Character.h"
#include "Tanker.h"
#include "Healer.h"

void DungeonManager::EnterDungeon(Character* Player, MapManager* MM)
{
	//시작시 플레이어 위치와 탈출 위치가 같은 경우 예외처리
	SamePosition(MM);


	vector<Pos> visited; 

	while (!IsDungeonEnd) //플레이어가 죽거나, 던전 클리어하면 종료
	{
		MM->MapPrint();
		Monster = new Tanker("탱커", 100, 100, 0, 5, 10);
		Player->PrintCharacter();
		Monster->PrintMonster();

		VisitCheck(visited, Player, MM);
		Result(visited, MM);
	}

}

void DungeonManager::Move(MapManager* MM)
{
	//플레이어가 이동할 다음 스테이지 결정
	cout << "이동할 방향을 선택하세요 : 1.위 2.아래 3.왼쪽 4.오른쪽" << endl;
	int dir = -1;
	cin >> dir;
	Pos pos = MM->GetCharacterPosition();

	switch (dir)
	{
	case 1:
	{
		if (MM->GetCharacterPosition().y <= 0) //위 이동불가
			cout << "이동할 수 없습니다." << endl;
		else
		{
			MM->SetCharacterPosition(pos.x, pos.y - 1);
		}
	}
	break;
	case 2:
	{
		if (MM->GetCharacterPosition().y >= MM->GetMapLevel() + 1) //아래 이동불가
			cout << "이동할 수 없습니다." << endl;
		else
		{
			MM->SetCharacterPosition(pos.x, pos.y + 1);
		}
	}
	break;
	case 3:
	{
		if (MM->GetCharacterPosition().x <= 0) //왼쪽 이동불가
			cout << "이동할 수 없습니다." << endl;
		else
		{
			MM->SetCharacterPosition(pos.x - 1, pos.y);
		}
	}
	break;
	case 4:
	{
		if (MM->GetCharacterPosition().x >= MM->GetMapLevel() + 1) //오른쪽 이동불가
			cout << "이동할 수 없습니다." << endl;
		else
		{
			MM->SetCharacterPosition(pos.x + 1, pos.y);
		}
	}
	break;
	default:
	{
		cout << "숫자만 입력하세요. 숫자만." << endl;
	}
	break;
	}
}

void DungeonManager::SamePosition(MapManager* MM)
{
	if (MM->IsDungeonClear())
	{
		Pos pos = MM->RandomPos();
		MM->SetCharacterPosition(pos.x, pos.y);
	}
}

void DungeonManager::VisitCheck(vector<Pos>& visited, Character* Player, MapManager* MM)
{
	if (!visited.empty()) //클리어한 곳이 있다면
	{
		for (Pos p : visited)
		{
			if (p.x == MM->GetCharacterPosition().x && p.y == MM->GetCharacterPosition().y) //클리어한 곳에 들어왔다면
			{
				cout << "이미 클리어한 곳입니다." << endl;
				eFightResult = VISITED;
			}
		}
	}
	else //첫 입장
		eFightResult = Fight(Player, MM); //던전 안에 맵 1칸 단위 싸움
}

void DungeonManager::Result(vector<Pos>& visited, MapManager* MM)
{
	switch (eFightResult)
	{
	case PLAYERWIN:
	{
		//다음 스테이지로 이동
		cout << "플레이어 승리! 다음 스테이지로 이동!" << endl;
		visited.push_back(MM->GetCharacterPosition());
		MM->RoomClear();
		Move(MM);
		MM->RenewDungeonStatus();
		MM->MapPrint();

		//이동한 곳이 E라면 보스 스테이지?, 아님 탈출
		EnterBoss(MM);
	}
	break;
	case PLAYERLOSE:
	{
		//던전 종료
		cout << "플레이어 패배!" << endl;
		IsDungeonEnd = true;
	}
	case VISITED:
	{
		cout << "이미 클리어 했습니다!" << endl;
		Move(MM);
	}
	break;
	default:
		break;
	}

}

void DungeonManager::EnterBoss(MapManager* MM)
{
	/*
	보스 스테이지면 보스 구현
	*/
	if (MM->IsDungeonClear())
	{
		cout << "던전을 나가시겠습니까? : 1.네 2.아니오 " << endl;
		int answer = -1;
		cin >> answer;
		if (answer == 1) 
			IsDungeonEnd = true;
	}
}

int DungeonManager::GetMonsterGold()
{
	return Monster->GetGold();
}


FightResult DungeonManager::Fight(Character* Player, MapManager* MM)
{
	bool isend = false;
	while (!isend)
	{	
		MM->MapPrint();
		if (Player->GetHp() > 0 && Monster->GetHp() > 0)
		{
			cout << Player->GetName() << "(이)가 " << Player->GetAttack() << "만큼 " << Monster->GetName() << "(을)를 공격했다!" << endl;
			Monster->TakeDamage(Player->GetAttack());
			cout << Monster->GetName() << "에게 " << Player->GetAttack() << "만큼 피해를 입혔다!" << endl;
			cout << Player->GetName() << " 체력 : " << Player->GetHp() << ", " << Monster->GetName() << " 체력 : " << Monster->GetHp() << endl;

		}
		if (Monster->GetHp() <= 0)
		{
			isend = true;
			return PLAYERWIN;
		}
		if (Player->GetHp() <= 0)
		{
			isend = true;
			return PLAYERLOSE;
		}
	}
}