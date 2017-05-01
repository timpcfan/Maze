#pragma once
#include "maze.h"
#include "MyMazeMap.h"

using namespace std;

class MyMazeMap;
class MyMazer
{
public:
	
	MyMazer(int x = 0, int y = 0, speed s = NORMAL, direction d = direction::right, char Person_Char = 'T');
	//构造函数，初始化数据成员
	void setPersonPosition(int x, int y);	//设置人物位置
	void setEndingPosition(int x, int y);
	void setPersonDirection(direction d);	//设置人物朝向
	void setPersonSpeed(speed s);			//设置人物速度
	void setPersonChar(char c);				//设置人物符号
	void setMap(MyMazeMap *m);				//设置地图对象
	void start();							//开始游戏
	void turn(int d = 0);					//转向 d=0顺时针 d=1逆时针
	void gotoxy(int x, int y);				//移动光标到(x,y)
	void move();							//向前移动人物移动
	void display();							//更新人物在屏幕上的位置
	direction getManRightSide();			//返回人物的右侧方向
	void setPathAndGo();
	void moveTo(POX p);

private:
	char m_cPerson;				//人物字符
	direction m_dDirection;		//人物朝向
	speed m_sSpeed;				//人物速度
	POX m_sPosition;			//人物当前位置
	POX m_sLastPosition;		//人物上次的位置,为了制作动画效果
	POX m_sEndPosition;
	MyMazeMap *m_pcMap;			//地图对象
	int m_iSteps;				//步数
};


