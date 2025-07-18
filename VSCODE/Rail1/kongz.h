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
	//接口类，不定义对象
	virtual void show()=0;
	//virtual void show() = 0;
	virtual void event(const ExMessage& msg);

	//
	void showpage1( );
	//virtual void showpage2( )=0;
	//virtual void showpage3( )=0;
	void plotapf();
protected:

	//控件坐标
	int m_x; 
	int m_y;
	//控件尺寸
	int m_w;
	int m_h;
	//控件颜色
	DWORD m_color;
	//标题
	std::string m_title;

};

