#include "MyMazer.h"


MyMazer::MyMazer(int x, int y, speed s,  char Person_Char) :m_sPosition{ x,y }, m_sSpeed(s), m_cPerson(Person_Char)
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
{ //��Ϸ��ʼ��������·�����������·���߳��Թ�
	if (!m_pcMap) {
		std::cout << "You haven't set map, please use setMap() to continue" << std::endl;
		return;
	}
	gotoxy(m_sPosition.x, m_sPosition.y);
	std::cout << m_cPerson;

	vector<POX> path;

	if (!(m_pcMap->getShortestPath(m_sPosition, m_sEndPosition, path))) {
		gotoxy(0, m_pcMap->getR());
		std::cout << "û�к��ʵ�·�������������յ��λ��" << std::endl;
		return;
	}

	for (int i = 0; i < path.size(); i++) {
		moveTo(path[i]);
		display();
	}

	gotoxy(0, m_pcMap->getR());
	std::cout << "���سɹ�������" << std::endl << "�ܹ�����" << m_iSteps << "��" << std::endl;
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


void MyMazer::moveTo(POX p)
{
	m_sLastPosition = m_sPosition;
	m_sPosition = p;
	m_iSteps++;
}



