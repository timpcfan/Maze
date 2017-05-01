#pragma once
#include "maze.h"
#include "MyMazeMap.h"



class MyMazeMap;
class MyMazer
{
public:
	
	MyMazer(int x = 0, int y = 0, speed s = NORMAL,  char Person_Char = 'T');
	//���캯������ʼ�����ݳ�Ա
	void setPersonPosition(int x, int y);	//��������λ��
	void setEndingPosition(int x, int y);	//�����յ�λ��
	void setPersonSpeed(speed s);			//���������ٶ�
	void setPersonChar(char c);				//�����������
	void setMap(MyMazeMap *m);				//���õ�ͼ����
	void start();							//��ʼ��Ϸ
	void gotoxy(int x, int y);				//�ƶ���굽(x,y)
	void display();							//������������Ļ�ϵ�λ��
	void moveTo(POX p);						//�������λ��

private:
	char m_cPerson;				//�����ַ�
	speed m_sSpeed;				//�����ٶ�
	POX m_sPosition;			//���ﵱǰλ��
	POX m_sLastPosition;		//�����ϴε�λ��,Ϊ����������Ч��
	POX m_sEndPosition;			//�յ�λ��
	MyMazeMap *m_pcMap;			//��ͼ����
	int m_iSteps;				//����
};


