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
	maze.setMazeMap(&map[0][0], 10, 18); //设置地图
	maze.drawMap(); //绘制地图
	MyMazer mazer;
	mazer.setPersonPosition(16, 2); //设置开始时人物位置
	mazer.setEndingPosition(4, 8);
	mazer.setPersonDirection(direction::up); //设置开始时人物朝向 up right down left
	mazer.setPersonSpeed(FAST); //设置速度 FAST NORMAL SLOW
	mazer.setPersonChar('#'); //设置表示人的字符
	mazer.setMap(&maze); //设置人物所在地图
	//mazer.start(); //游戏开始
	mazer.setPathAndGo();
	system("pause");
	return SUCCESS;
}
