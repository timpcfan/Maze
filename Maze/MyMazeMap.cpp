#include "MyMazeMap.h"



MyMazeMap::MyMazeMap()
{ //��ʼ�����ݳ�Ա
	m_c = 0;
	m_r = 0;
	m_cRoad = ' ';
	m_cWall = '*';
}

void MyMazeMap::setMazeMap(int * map, int r, int c)
{ //�����Թ�
	m_piMap = map;
	m_r = r;
	m_c = c;
}

void MyMazeMap::setMazeWall(char wall)
{ //���ñ�ʾǽ�ķ���
	m_cWall = wall;
}

void MyMazeMap::drawMap()
{ //���Ƶ�ͼ

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
{ //�ж�(x,y)�ǲ���ǽ
	if (isOut(x, y) || *(m_piMap + m_c*y + x) == WALL) return true;
	return false;
}

bool MyMazeMap::isOut(int x, int y)
{ //�ж��Ƿ��߳��Թ�
	if (x > m_c - 1 ||  x<0 || y> m_r - 1 || y < 0) return true;
	return false;
}

int MyMazeMap::getR()
{ //�����Թ�������
	return m_r;
}

int MyMazeMap::getC()
{ //�����Թ�������
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
	from[__prasePOX(start)] = POX(start); //��ʼ�ڵ�ָ��ʼ�ڵ㣬��־���ǵ�һ���ڵ�

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

	if (!visited[__prasePOX(end)]) return false; // ������·��ʧ�ܣ���Ϊ������յ㲻��ͨ

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
	
	return true; //������·���ɹ�
}

int MyMazeMap::__prasePOX(POX p)
{
	assert(p.x > 0 && p.y > 0);
	return p.y*m_c + p.x;
}



