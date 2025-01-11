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

MapManager::MapManager(int mapLevel)	// �� ������ ���� �⺻���� ���� ����
{
	_mapLevel = mapLevel;

	vector<vector<char>> temp(_mapLevel + 2, vector<char>(_mapLevel + 2, ' '));

	_map = temp;
}

void MapManager::MapPrint()	// ���� ���� ����Ʈ
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

void MapManager::SetCharacterPosition(int x, int y)	// ���� ĳ���Ͱ� ��ġ�� ���� ����
{
	_characterPos.x = x;
	_characterPos.y = y;
}

bool MapManager::IsClear()	// ���� ĳ���� ��ġ�� �� ������ ��ġ�� �������� Ȯ��
{
	if (_characterPos.x == _endPos.x && _characterPos.y == _endPos.y) return true;
	return false;
}

MapManager::~MapManager()	// �Ҹ���
{
	delete this;
}

#endif
