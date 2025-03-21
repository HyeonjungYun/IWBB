﻿
#include "MapManager.h"

MapManager::MapManager(int mapLevel)	// 맵 생성자, 맵을 기본적인 맵을 생성, 시작 좌표와 끝 좌표를 생성 후 할당
{
	_MapLevel = mapLevel;

	vector<vector<char>> tempMap(_MapLevel + 2, vector<char>(_MapLevel + 2, ' '));
	vector<vector<char>> tempClearedMap(_MapLevel + 2, vector<char>(_MapLevel + 2, ' '));

	_CharacterPos = RandomPos();
	_EndPos = RandomPos();

	tempMap[_EndPos.y][_EndPos.x] = 'E';
	tempMap[_CharacterPos.y][_CharacterPos.x] = '!';
	tempClearedMap[_EndPos.y][_EndPos.x] = 'C';
	tempClearedMap[_CharacterPos.y][_CharacterPos.x] = 'C';

	_Map = tempMap;
	_ClearedMap = tempClearedMap;
}

void MapManager::MapPrint() const	// 현재 맵을 프린트
{
	cout << endl << "! : 현재 나의 위치 E : 탈출구 C : 몬스터가 나타나지 않음" << endl;
	cout << "-";

	for (vector<char> row : _Map)
		cout << "----";
	cout << endl;

	for (vector<char> row : _Map)
	{
		cout << "|";
		for (char room : row)
			cout << " " << room << " |";

		cout << endl << "-";
		for (vector<char> row : _Map)
			cout << "----";
		cout << endl;
	}
}

void MapManager::SetCharacterPosition(int x, int y)	// 현재 캐릭터가 위치한 곳을 수정 
{
	_CharacterPos.x = x;
	_CharacterPos.y = y;

	_Map[_EndPos.y][_EndPos.x] = 'E';
	_Map[_CharacterPos.y][_CharacterPos.x] = '!';
}

Pos MapManager::GetCharacterPosition() const
{
	return _CharacterPos;
}

void MapManager::RenewDungeonStatus()
{
	_Map = _ClearedMap;
  
	_Map[_EndPos.y][_EndPos.x] = 'E';
	_Map[_CharacterPos.y][_CharacterPos.x] = '!';
}

const Pos MapManager::RandomPos() const	// 랜덤한 좌표를 생성하는 함수
{
	Pos temp;

	CreateRandomValue(0, _MapLevel + _Width - 1);

	temp.x = CreateRandomValue(0, _MapLevel + _Width - 1);
	temp.y = CreateRandomValue(0, _MapLevel + _Width - 1);

	return temp;
}

bool MapManager::IsDungeonClear() const	// 현재 캐릭터 위치와 끝 지점의 위치가 동일한지 확인
{
	if (_CharacterPos.x == _EndPos.x && _CharacterPos.y == _EndPos.y) return true;
	return false;
}

void MapManager::RoomClear()
{
	_ClearedMap[_CharacterPos.y][_CharacterPos.x] = 'C';

}

const bool MapManager::IsClearRoom() const		// 현재 있는 방이 클리어된 방인지, 몬스터가 나와야 하는 방인지 확인
{
	if (_ClearedMap[_CharacterPos.y][_CharacterPos.x] == 'C') return true;
	return false;
}

MapManager::~MapManager()	// 소멸자
{
	delete this;
}