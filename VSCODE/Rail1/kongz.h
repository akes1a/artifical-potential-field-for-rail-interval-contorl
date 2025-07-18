#pragma once
#include<iostream>
#include<easyx.h>
#include<string.h>
#include"Rwindows.h"

class kongz
{

public:

	kongz(kongz* parent=nullptr);
	~kongz(); 

	//void init(int x, int y, int w, int h,title"kongz");
	void move(int x, int y);
	void setsize(int w, int h);
	void setcolor(DWORD c);
	void write(const wchar_t* str1, const wchar_t* str2, int x, int y, int w, int h);
	//�ӿ��࣬���������
	virtual void show()=0;
	//virtual void show() = 0;
	virtual void event(const ExMessage& msg);

	//
	void showpage1( );
	//virtual void showpage2( )=0;
	//virtual void showpage3( )=0;
	void plotapf();
protected:

	//�ؼ�����
	int m_x; 
	int m_y;
	//�ؼ��ߴ�
	int m_w;
	int m_h;
	//�ؼ���ɫ
	DWORD m_color;
	//����
	std::string m_title;

};

