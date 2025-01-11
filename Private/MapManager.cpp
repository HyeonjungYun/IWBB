#include "MapManager.h"

MapManager::MapManager(int mapLevel)	// �� ������, ���� �⺻���� ���� ����, ���� ��ǥ�� �� ��ǥ�� ���� �� �Ҵ�
{
	_mapLevel = mapLevel;

	vector<vector<char>> temp(_mapLevel + 2, vector<char>(_mapLevel + 2, ' '));

	_characterPos = RandomPos();
	_endPos = RandomPos();

	temp[_endPos.y][_endPos.x] = 'E';
	temp[_characterPos.y][_characterPos.x] = '!';

	_map = temp;
}

void MapManager::MapPrint() const	// ���� ���� ����Ʈ
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

	_map[_endPos.y][_endPos.x] = 'E';
	_map[_characterPos.y][_characterPos.x] = '!';
}

const Pos MapManager::RandomPos() const	// ������ ��ǥ�� �����ϴ� �Լ�
{
	Pos temp;

	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(0, _mapLevel + _width - 1);

	temp.x = dist(gen);
	temp.y = dist(gen);

	return temp;
}

bool MapManager::IsClear() const	// ���� ĳ���� ��ġ�� �� ������ ��ġ�� �������� Ȯ��
{
	if (_characterPos.x == _endPos.x && _characterPos.y == _endPos.y) return true;
	return false;
}

MapManager::~MapManager()	// �Ҹ���
{
	delete this;
}