#include "pch.h"
#include "MapManager.h"
#include "Character.h"
#include "DungeonManager.h"

int main()
{
	MapManager* map = new MapManager(3);

	map->MapPrint();
	
	//로그매니저 생성
	//캐릭터 생성
	Character* player = new Character("젤다", 1000, 0, 1, 5, 10);
	DungeonManager* DM = new DungeonManager();
	DM->EnterDungeon(player, map); //던전 입장

	return 0;
}