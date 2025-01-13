#include "Monster.h"
#include "Tanker.h"
#include "Healer.h"
#include "Character.h"
#include "DungeonManager.h"
#include "MapManager.h"

int main()
{
	/*
	Monster* mon = new Tanker("탱커", 100, 0, 5, 10);
	cout << mon->getName() << "의 공격력: " << mon->getAttack() << endl;
	delete mon;
	*/
	
	//로그매니저 생성
	//캐릭터 생성
	Character player("젤다", 1000, 0, 5, 10);
	//맵 매니저 생성
	MapManager* MM = new MapManager(1);
	DungeonManager DM;
	DM.EnterDungeon(&player, MM); //던전 입장

	return 0;
}