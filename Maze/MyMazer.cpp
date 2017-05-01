#include "MyMazer.h"
#include <Windows.h>
#include <iostream>

MyMazer::MyMazer(int x, int y, speed s, direction d, char Person_Char) :m_sPosition{ x,y }, m_sSpeed(s), m_dDirection(d), m_cPerson(Person_Char)
{ //��ʼ��
	m_sLastPosition = m_sPosition;
	m_pcMap = NULL;
	m_iSteps = 0;
}

void MyMazer::setPersonPosition(int x, int y)
{ //���������λ��
	m_sPosition.x = x;
	m_sPosition.y = y;
}

void MyMazer::setEndingPosition(int x, int y)
{
	m_sEndPosition.x = x;
	m_sEndPosition.y = y;
}

void MyMazer::setPersonDirection(direction d)
{ //��������ĳ���
	m_dDirection = d;
}

void MyMazer::setPersonSpeed(speed s)
{ //����������ٶ�
	m_sSpeed = s;
}

void MyMazer::setPersonChar(char c)
{ //���������ַ�
	m_cPerson = c;
}

void MyMazer::setMap(MyMazeMap * m)
{ //���õ�ͼ����
	m_pcMap = m;
}

void MyMazer::start()
{ //��Ϸ��ʼ��ʹ�����ֹ������Թ�
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
	std::cout << "���سɹ�������" << std::endl << "�ܹ�����" << m_iSteps << "��" << std::endl;
}

void MyMazer::turn(int d)
{
	if (d == 0) { //˳ʱ��ת��
		if (m_dDirection == direction::up) m_dDirection = direction::right;
		else if (m_dDirection == direction::right) m_dDirection = direction::down;
		else if (m_dDirection == direction::down) m_dDirection = direction::left;
		else m_dDirection = direction::up;
	}
	else { //��ʱ��ת��
		if (m_dDirection == direction::up) m_dDirection = direction::left;
		else if (m_dDirection == direction::left) m_dDirection = direction::down;
		else if (m_dDirection == direction::down) m_dDirection = direction::right;
		else m_dDirection = direction::up;
	}
}

void MyMazer::gotoxy(int x, int y)
{ //������ƶ���(x,y)
	if (x < 0 || y < 0) return;
	COORD cd;
	cd.X = x;
	cd.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, cd);
}

void MyMazer::move()
{ //��ǰ�ƶ�һ��
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
{ //��ʾ����
	Sleep(m_sSpeed);
	gotoxy(m_sLastPosition.x, m_sLastPosition.y);
	std::cout << " ";
	gotoxy(m_sPosition.x, m_sPosition.y);
	std::cout << m_cPerson;
	gotoxy(0, m_pcMap->getR());
	std::cout << "�Ѿ�����" << m_iSteps << "����" << std::endl;
}

direction MyMazer::getManRightSide()
{ //��ȡ���ﳯ���Ҳ�ķ���
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


