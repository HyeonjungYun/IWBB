#ifndef _MAP_MANAGER_H_
#define _MAP_MANAGER_H_

#include "pch.h"

typedef struct
{
	int x;
	int y;
}Pos;

class MapManager
{
private:
	vector<vector<char>> _map;
	int _mapLevel;
	Pos _characterPos;
	Pos _endPos;
	const int _width = 2;
public:
	MapManager(int mapLevel);
	void MapPrint() const;
	void SetCharacterPosition(int x, int y);
	const Pos RandomPos() const;
	bool IsClear() const;
	~MapManager();
};

#endif
