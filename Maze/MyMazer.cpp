#include "MyMazer.h"
#include <Windows.h>
#include <iostream>

MyMazer::MyMazer(int x, int y, speed s, direction d, char Person_Char) :m_sPosition{ x,y }, m_sSpeed(s), m_dDirection(d), m_cPerson(Person_Char)
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

void MyMazer::setPersonDirection(direction d)
{ //设置人物的朝向
	m_dDirection = d;
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
{ //游戏开始，使用右手规则走迷宫
	if (!m_pcMap) {
		std::cout << "You haven't set map, please use setMap() to continue" << std::endl;
		return;
	}
	gotoxy(m_sPosition.x, m_sPosition.y);
	std::cout << m_cPerson;
	while (1) {
		while(m_pcMap->isMazeBound(m_sPosition.x, m_sPosition.y, getManRightSide())) {
			turn(1);
		}
		turn();
		move();
		if (m_pcMap->isOut(m_sPosition.x, m_sPosition.y)) break;
		display();
	}
	gotoxy(0, m_pcMap->getR());
	std::cout << "闯关成功！！！" << std::endl << "总共走了" << m_iSteps << "步" << std::endl;
}

void MyMazer::turn(int d)
{
	if (d == 0) { //顺时针转向
		if (m_dDirection == direction::up) m_dDirection = direction::right;
		else if (m_dDirection == direction::right) m_dDirection = direction::down;
		else if (m_dDirection == direction::down) m_dDirection = direction::left;
		else m_dDirection = direction::up;
	}
	else { //逆时针转向
		if (m_dDirection == direction::up) m_dDirection = direction::left;
		else if (m_dDirection == direction::left) m_dDirection = direction::down;
		else if (m_dDirection == direction::down) m_dDirection = direction::right;
		else m_dDirection = direction::up;
	}
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

void MyMazer::move()
{ //向前移动一步
	m_sLastPosition = m_sPosition;
	switch (m_dDirection) {
	case direction::up: m_sPosition.y--; break;
	case direction::right: m_sPosition.x++; break;
	case direction::down: m_sPosition.y++; break;
	case direction::left: m_sPosition.x--; break;
	}
	m_iSteps++;
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

direction MyMazer::getManRightSide()
{ //读取人物朝向右侧的方向
	direction ret;
	switch (m_dDirection) {
	case direction::up:ret = direction::right; break;
	case direction::right:ret = direction::down; break;
	case direction::down:ret = direction::left; break;
	case direction::left:ret = direction::up; break;
	}
	return ret;
}

void MyMazer::setPathAndGo()
{
	vector<POX> path;

	m_pcMap->getShortestPath(m_sPosition, m_sEndPosition, path);

	for (int i = 0; i < path.size(); i++) {
		moveTo(path[i]);
		display();
	}
}

void MyMazer::moveTo(POX p)
{
	m_sLastPosition = m_sPosition;
	m_sPosition = p;
	m_iSteps++;
}



