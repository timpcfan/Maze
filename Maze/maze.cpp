#include <iostream>
#include <cstdlib>
#include "maze.h"
#include "MyMazeMap.h"
#include "MyMazer.h"

using namespace std;

const int SUCCESS = 0;
int main()
{
	int map[10][18] = {
					{ WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, },
					{ WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL, },
					{ WALL,ROAD,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,WALL,ROAD,WALL, },
					{ WALL,WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,WALL,ROAD,WALL, },
					{ WALL,WALL,ROAD,ROAD,ROAD,ROAD,ROAD,ROAD,ROAD,ROAD,ROAD,WALL,ROAD,WALL,ROAD,ROAD,ROAD,WALL, },
					{ WALL,WALL,ROAD,WALL,ROAD,WALL,WALL,WALL,ROAD,WALL,ROAD,ROAD,ROAD,WALL,ROAD,WALL,WALL,WALL, },
					{ WALL,ROAD,ROAD,WALL,ROAD,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,WALL, },
					{ WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,WALL, },
					{ WALL,ROAD,WALL,WALL,ROAD,WALL,WALL,WALL,ROAD,WALL,WALL,ROAD,ROAD,ROAD,ROAD,WALL,WALL,WALL, },
					{ WALL,ROAD,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL,WALL, },
	};
	system("pause");
	MyMazeMap maze;
	maze.setMazeMap(&map[0][0], 10, 18); //���õ�ͼ
	maze.drawMap(); //���Ƶ�ͼ
	MyMazer mazer;
	mazer.setPersonPosition(16, 2); //���ÿ�ʼʱ����λ��
	mazer.setEndingPosition(4, 8);
	mazer.setPersonDirection(direction::up); //���ÿ�ʼʱ���ﳯ�� up right down left
	mazer.setPersonSpeed(FAST); //�����ٶ� FAST NORMAL SLOW
	mazer.setPersonChar('#'); //���ñ�ʾ�˵��ַ�
	mazer.setMap(&maze); //�����������ڵ�ͼ
	//mazer.start(); //��Ϸ��ʼ
	mazer.setPathAndGo();
	system("pause");
	return SUCCESS;
}
