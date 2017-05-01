#include "MyMazer.h"


MyMazer::MyMazer(int x, int y, speed s,  char Person_Char) :m_sPosition{ x,y }, m_sSpeed(s), m_cPerson(Person_Char)
{ //初始化
	m_sLastPosition = m_sPosition;
	m_pcMap = NULL;
	m_iSteps = 0;
}

void MyMazer::setPersonPosition(int x, int y)
{ //设置人物的位置
	m_sPosition.x = x;
	m_sPosition.y = y;
}

void MyMazer::setEndingPosition(int x, int y)
{
	m_sEndPosition.x = x;
	m_sEndPosition.y = y;
}


void MyMazer::setPersonSpeed(speed s)
{ //设置人物的速度
	m_sSpeed = s;
}

void MyMazer::setPersonChar(char c)
{ //设置人物字符
	m_cPerson = c;
}

void MyMazer::setMap(MyMazeMap * m)
{ //设置地图对象
	m_pcMap = m;
}

void MyMazer::start()
{ //游戏开始，获得最短路径，并沿最短路径走出迷宫
	if (!m_pcMap) {
		std::cout << "You haven't set map, please use setMap() to continue" << std::endl;
		return;
	}
	gotoxy(m_sPosition.x, m_sPosition.y);
	std::cout << m_cPerson;

	vector<POX> path;

	if (!(m_pcMap->getShortestPath(m_sPosition, m_sEndPosition, path))) {
		gotoxy(0, m_pcMap->getR());
		std::cout << "没有合适的路径，请检查起点和终点的位置" << std::endl;
		return;
	}

	for (int i = 0; i < path.size(); i++) {
		moveTo(path[i]);
		display();
	}

	gotoxy(0, m_pcMap->getR());
	std::cout << "闯关成功！！！" << std::endl << "总共走了" << m_iSteps << "步" << std::endl;
}

void MyMazer::gotoxy(int x, int y)
{ //将光标移动至(x,y)
	if (x < 0 || y < 0) return;
	COORD cd;
	cd.X = x;
	cd.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, cd);
}

void MyMazer::display()
{ //显示函数
	Sleep(m_sSpeed);
	gotoxy(m_sLastPosition.x, m_sLastPosition.y);
	std::cout << " ";
	gotoxy(m_sPosition.x, m_sPosition.y);
	std::cout << m_cPerson;
	gotoxy(0, m_pcMap->getR());
	std::cout << "已经走了" << m_iSteps << "步了" << std::endl;
}


void MyMazer::moveTo(POX p)
{
	m_sLastPosition = m_sPosition;
	m_sPosition = p;
	m_iSteps++;
}



