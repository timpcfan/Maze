#pragma once

#include <stack>'
#include <queue>
#include <vector>

enum direction { up, right, down, left }; //����
enum speed { FAST = 100, NORMAL = 300, SLOW = 500 }; //�ٶ�
const int ROAD = 0; //·
const int WALL = 1; //ǽ
struct POX { //����
	int x;
	int y;
	POX():x(0),y(0) {}
	POX(int x, int y) :x(x), y(y) {}

	bool operator==(const POX & other) const {
		return this->x == other.x && this->y == other.y;
	}

	bool operator!=(const POX & other) const {
		return !(*this == other);
	}
};

