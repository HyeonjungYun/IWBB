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
public:
	MapManager(int mapLevel);
	void MapPrint();
	void SetCharacterPosition(int x, int y);
	bool IsClear();
	~MapManager();
};

MapManager::MapManager(int mapLevel)	// 맵 생성자 맵을 기본적인 맵을 생성
{
	_mapLevel = mapLevel;

	vector<vector<char>> temp(_mapLevel + 2, vector<char>(_mapLevel + 2, ' '));

	_map = temp;
}

void MapManager::MapPrint()	// 현재 맵을 프린트
{
	cout << "-";

	for (vector<char> row : _map)
		cout << "----";
	cout << endl;

	for (vector<char> row : _map)
	{
		cout << "|";
		for (char room : row)
			cout << " " << room << " |";

		cout << endl << "-";
		for (vector<char> row : _map)
			cout << "----";
		cout << endl;
	}
}

void MapManager::SetCharacterPosition(int x, int y)	// 현재 캐릭터가 위치한 곳을 수정
{
	_characterPos.x = x;
	_characterPos.y = y;
}

bool MapManager::IsClear()	// 현재 캐릭터 위치와 끝 지점의 위치가 동일한지 확인
{
	if (_characterPos.x == _endPos.x && _characterPos.y == _endPos.y) return true;
	return false;
}

MapManager::~MapManager()	// 소멸자
{
	delete this;
}

#endif
