#ifndef _MAP_MANAGER_H_
#define _MAP_MANAGER_H_

#include "pch.h"

// 맵을 생성하고 캐릭터의 현재 위치를 추적/관리하는 클래스
class MapManager
{
private:
	vector<vector<char>> _Map;
	vector<vector<char>> _ClearedMap;
	int _MapLevel;
	Pos _CharacterPos;
	Pos _EndPos;
	const int _Width = 2;
public:
	MapManager(int mapLevel);
	void MapPrint() const;
	void SetCharacterPosition(int x, int y);
	Pos GetCharacterPosition() const;
	void RenewDungeonStatus();
	const Pos RandomPos() const;
	bool IsDungeonClear() const;
	void RoomClear();
	~MapManager();
};

#endif
