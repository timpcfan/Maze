#pragma once
#include "maze.h"
#include  "MyMazer.h"
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

class MyMazeMap
{
public:
	MyMazeMap();									//构造函数，初始化数据成员
	void setMazeMap(int* map, int r, int c);		//设置地图，高，宽
	void setMazeWall(char wall);					//设置墙的符号
	void drawMap();									//绘制地图
	bool isMazeBound(int x, int y, direction d);	//判断(x,y)的d方向上是否是墙
	bool isBound(int x, int y);						//判断(x,y)是否是墙
	bool isOut(int x, int y);						//判断是否走出迷宫
	int getR();										//返回地图高
	int getC();										//返回的图宽
	void getShortestPath(POX start, POX end, vector<POX> &v);

	class adjIterator {
	private:
		MyMazeMap & M;
		POX v;
		int direction;

		//以上左下右(0,1,2,3)的顺序遍历v的所有相邻节点
	public:
		adjIterator(MyMazeMap & map, POX v) :M(map),v(v){
			direction = -1;
		}

		POX begin() {
			direction = -1;
			return next();
		}

		POX next() {

			switch (direction) {
			case -1: direction++;
			case 0:	direction++; if (!M.isBound(v.x, v.y - 1)) return POX(v.x, v.y - 1);
			case 1: direction++; if (!M.isBound(v.x - 1, v.y)) return POX(v.x - 1, v.y);
			case 2: direction++; if (!M.isBound(v.x, v.y + 1)) return POX(v.x, v.y + 1);
			case 3: direction++; if (!M.isBound(v.x + 1, v.y)) return POX(v.x + 1, v.y);
			default: direction++;
			}

			return POX(-1, -1); // NEVER RUN TO THIS LINE

		}

		bool end() {
			return direction > 4;
		}
	};

private:
	char m_cWall;	//墙的符号
	char m_cRoad;	//路的符号
	int m_r;		//高
	int m_c;		//宽
	int* m_piMap;	//地图

	int __prasePOX(POX p);
};

