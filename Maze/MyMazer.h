#pragma once
#include "maze.h"
#include "MyMazeMap.h"

using namespace std;

class MyMazeMap;
class MyMazer
{
public:
	
	MyMazer(int x = 0, int y = 0, speed s = NORMAL, direction d = direction::right, char Person_Char = 'T');
	//���캯������ʼ�����ݳ�Ա
	void setPersonPosition(int x, int y);	//��������λ��
	void setEndingPosition(int x, int y);
	void setPersonDirection(direction d);	//�������ﳯ��
	void setPersonSpeed(speed s);			//���������ٶ�
	void setPersonChar(char c);				//�����������
	void setMap(MyMazeMap *m);				//���õ�ͼ����
	void start();							//��ʼ��Ϸ
	void turn(int d = 0);					//ת�� d=0˳ʱ�� d=1��ʱ��
	void gotoxy(int x, int y);				//�ƶ���굽(x,y)
	void move();							//��ǰ�ƶ������ƶ�
	void display();							//������������Ļ�ϵ�λ��
	direction getManRightSide();			//����������Ҳ෽��
	void setPathAndGo();
	void moveTo(POX p);

private:
	char m_cPerson;				//�����ַ�
	direction m_dDirection;		//���ﳯ��
	speed m_sSpeed;				//�����ٶ�
	POX m_sPosition;			//���ﵱǰλ��
	POX m_sLastPosition;		//�����ϴε�λ��,Ϊ����������Ч��
	POX m_sEndPosition;
	MyMazeMap *m_pcMap;			//��ͼ����
	int m_iSteps;				//����
};


