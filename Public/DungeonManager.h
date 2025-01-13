#pragma once
class Character;
class Monster;
class MapManager;

enum FightResult { PLAYERWIN, PLAYERLOSE, FIGHTEND};

class DungeonManager
{
public:
	DungeonManager():isDungeonEnd(false), monster(nullptr), eFightResult(FIGHTEND){}
	~DungeonManager(){}

public:
	void EnterDungeon(Character* Player, MapManager* MM); // 전체 던전 클리어하면 종료
	FightResult Fight(Character* Player, MapManager* MM);
private:
	Monster* monster;
	bool isDungeonEnd;
	FightResult eFightResult;
};
