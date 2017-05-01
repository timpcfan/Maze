#include "MyMazeMap.h"



MyMazeMap::MyMazeMap()
{ //初始化数据成员
	m_c = 0;
	m_r = 0;
	m_cRoad = ' ';
	m_cWall = '*';
}

void MyMazeMap::setMazeMap(int * map, int r, int c)
{ //设置迷宫
	m_piMap = map;
	m_r = r;
	m_c = c;
}

void MyMazeMap::setMazeWall(char wall)
{ //设置表示墙的符号
	m_cWall = wall;
}

void MyMazeMap::drawMap()
{ //绘制地图

	system("cls");
	for (int i = 0; i < m_r; i++) {
		for (int j = 0; j < m_c; j++) {
			if (*(m_piMap + m_c*i + j) == WALL) std::cout << m_cWall;
			else std::cout << m_cRoad;
		}
		std::cout << std::endl;
	}
}


bool MyMazeMap::isBound(int x, int y)
{ //判断(x,y)是不是墙
	if (isOut(x, y) || *(m_piMap + m_c*y + x) == WALL) return true;
	return false;
}

bool MyMazeMap::isOut(int x, int y)
{ //判断是否走出迷宫
	if (x > m_c - 1 ||  x<0 || y> m_r - 1 || y < 0) return true;
	return false;
}

int MyMazeMap::getR()
{ //返回迷宫的行数
	return m_r;
}

int MyMazeMap::getC()
{ //返回迷宫的列数
	return m_c;
}

bool MyMazeMap::getShortestPath(POX start, POX end, vector<POX>& v)
{
	queue<POX> q;
	v.clear();
	bool *visited = new bool[m_r * m_c];
	POX *from = new POX[m_r * m_c];

	for (int i = 0; i < m_r*m_c; i++) { 
		visited[i] = false; 
	}

	q.push(start);
	visited[__prasePOX(start)] = true;
	from[__prasePOX(start)] = POX(start); //开始节点指向开始节点，标志这是第一个节点

	while (!q.empty()) {
		POX p = q.front(); q.pop();
		adjIterator adj(*this, p);
		for (POX it = adj.begin(); !adj.end(); it = adj.next()) {
			if (!visited[__prasePOX(it)]) {
				q.push(it);
				visited[__prasePOX(it)] = true;
				from[__prasePOX(it)] = p;
			}
		}
	}

	if (!visited[__prasePOX(end)]) return false; // 获得最短路径失败，因为起点与终点不连通

	stack<POX> st;
	POX p = end;
	while (p != from[__prasePOX(p)]){
		st.push(p);
		p = from[__prasePOX(p)];
	}

	while (!st.empty()) {
		p = st.top(); st.pop();
		v.push_back(p);
	}
	
	return true; //获得最短路径成功
}

int MyMazeMap::__prasePOX(POX p)
{
	assert(p.x > 0 && p.y > 0);
	return p.y*m_c + p.x;
}



