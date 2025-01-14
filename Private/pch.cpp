#include "pch.h"

int CreateRandomValue(int first, int second)
{
	random_device rd; //랜덤 생성 클래스 선언
	mt19937 gen(rd()); // 난수
	uniform_int_distribution<> dist(first, second);

	return dist(gen);
}