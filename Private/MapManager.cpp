#include "MapManager.h"

MapManager::MapManager(int mapLevel)	// 맵 생성자, 맵을 기본적인 맵을 생성, 시작 좌표와 끝 좌표를 생성 후 할당
{
	_mapLevel = mapLevel;

	vector<vector<char>> temp(_mapLevel + 2, vector<char>(_mapLevel + 2, ' '));

	_characterPos = RandomPos();
	_endPos = RandomPos();

	temp[_endPos.y][_endPos.x] = 'E';
	temp[_characterPos.y][_characterPos.x] = '!';

	_map = temp;
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

bool MapManager::IsClear() const	// 현재 캐릭터 위치와 끝 지점의 위치가 동일한지 확인
{
	if (_characterPos.x == _endPos.x && _characterPos.y == _endPos.y) return true;
	return false;
}

MapManager::~MapManager()	// 소멸자
{
	delete this;
}