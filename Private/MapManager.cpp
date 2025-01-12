#include "MapManager.h"

MapManager::MapManager(int mapLevel)	// 맵 생성자, 맵을 기본적인 맵을 생성, 시작 좌표와 끝 좌표를 생성 후 할당
{
	_mapLevel = mapLevel;

	vector<vector<char>> tempMap(_mapLevel + 2, vector<char>(_mapLevel + 2, ' '));
	vector<vector<char>> tempClearedMap(_mapLevel + 2, vector<char>(_mapLevel + 2, ' '));

	_characterPos = RandomPos();
	_endPos = RandomPos();

	tempMap[_endPos.y][_endPos.x] = 'E';
	tempMap[_characterPos.y][_characterPos.x] = '!';
	tempClearedMap[_endPos.y][_endPos.x] = 'C';
	tempClearedMap[_characterPos.y][_characterPos.x] = 'C';

	_map = tempMap;
	_clearedMap = tempClearedMap;
}

void MapManager::MapPrint() const	// 현재 맵을 프린트
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

	_map[_endPos.y][_endPos.x] = 'E';
	_map[_characterPos.y][_characterPos.x] = '!';
}

Pos MapManager::GetCharacterPosition() const
{
	return _characterPos;
}

void MapManager::RenewDungeonStatus()
{
	_map = _clearedMap;
	
	_map[_endPos.x][_endPos.y] = 'E';
	_map[_characterPos.x][_characterPos.y] = '!';
}

const Pos MapManager::RandomPos() const	// 랜덤한 좌표를 생성하는 함수
{
	Pos temp;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, _mapLevel + _width - 1);

	temp.x = dist(gen);
	temp.y = dist(gen);

	return temp;
}

bool MapManager::IsDungeonClear() const	// 현재 캐릭터 위치와 끝 지점의 위치가 동일한지 확인
{
	if (_characterPos.x == _endPos.x && _characterPos.y == _endPos.y) return true;
	return false;
}

void MapManager::RoomClear()
{
	_clearedMap[_characterPos.x][_characterPos.y] = 'C';
}

MapManager::~MapManager()	// 소멸자
{
	delete this;
}