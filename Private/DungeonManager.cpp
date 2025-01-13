#include "DungeonManager.h"
#include "MapManager.h"
#include "Character.h"
#include "Tanker.h"
#include "Healer.h"

void DungeonManager::EnterDungeon(Character* Player, MapManager* MM)
{
	while (!isDungeonEnd) //플레이어가 죽거나, 던전 클리어하면 종료
	{
		MM->MapPrint();
		monster = new Tanker("탱커", 100, 100, 0, 5, 10);
		//monster = new Healer("힐러", 100, 100, 0, 5, 10);
		Player->PrintCharacter();
		monster->PrintMonster();

			//던전 안에 맵 1칸 단위 싸움
		eFightResult = Fight(Player, MM);

		switch (eFightResult)
		{
		case PLAYERWIN:
		{
			//다음 스테이지로 이동
			cout << "플레이어 승리! 다음 스테이지로 이동!" << endl;
		}
		break;
		case PLAYERLOSE:
		{
			//던전 종료
		}
		break;
		default:
			break;
		}

		//종료시 처리
		isDungeonEnd = true;
		delete monster;
		monster = nullptr;
		//사용했던 던전 vertor 정리 
	}

}

FightResult DungeonManager::Fight(Character* Player, MapManager* MM)
{
	while (true) //플레이어가 죽거나, 던전 클리어하면 종료
	{
		if (Player->GetHp() > 0 && monster->GetHp() > 0)
		{
			cout << Player->GetName()<< "(이)가 " << Player->GetAttack() << "만큼 " << monster->GetName() << "(을)를 공격했다!" << endl;
			monster->TakeDamage(Player->GetAttack());
			cout << monster->GetName() << "에게 " << Player->GetAttack() << "만큼 피해를 입혔다!" << endl;
			cout << Player->GetName() << " 체력 : "<< Player->GetHp()<< ", "<< monster->GetName() << " 체력 : " << monster->GetHp() << endl;
			
		}
		if (monster->GetHp() <= 0)
			return PLAYERWIN;
	}
}
