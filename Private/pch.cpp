#include "pch.h"

int CreateRandomValue(int first, int second)
{
	random_device rd; //���� ���� Ŭ���� ����
	mt19937 gen(rd()); // ����
	uniform_int_distribution<> dist(first, second);

	return dist(gen);
}