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
	MyMazeMap();									//���캯������ʼ�����ݳ�Ա
	void setMazeMap(int* map, int r, int c);		//���õ�ͼ���ߣ���
	void setMazeWall(char wall);					//����ǽ�ķ���
	void drawMap();									//���Ƶ�ͼ
	bool isMazeBound(int x, int y, direction d);	//�ж�(x,y)��d�������Ƿ���ǽ
	bool isBound(int x, int y);						//�ж�(x,y)�Ƿ���ǽ
	bool isOut(int x, int y);						//�ж��Ƿ��߳��Թ�
	int getR();										//���ص�ͼ��
	int getC();										//���ص�ͼ��
	void getShortestPath(POX start, POX end, vector<POX> &v);

	class adjIterator {
	private:
		MyMazeMap & M;
		POX v;
		int direction;

		//����������(0,1,2,3)��˳�����v���������ڽڵ�
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
	char m_cWall;	//ǽ�ķ���
	char m_cRoad;	//·�ķ���
	int m_r;		//��
	int m_c;		//��
	int* m_piMap;	//��ͼ

	int __prasePOX(POX p);
};

