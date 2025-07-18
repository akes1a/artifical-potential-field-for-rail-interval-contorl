
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include"Rwindows.h"
#include"kongz.h"
#include"button.h"

using namespace std;

//Rwindows:加载背景图片 
//button:放置按钮
//click:判断鼠标点击和（按钮变色）


int main()
{

	/************屏幕part**********/

	initgraph(1280, 720);	//建立窗口
	Rwindows win(1280, 720);

	/************按钮part**********/

	button btn;                           //定义class
	//按钮参数设置                  //设置m_color
	btn.show();

	/***********控制part***********/
	
	//循环
	int flag_end = 0;
	while (flag_end==0)
	{

		win.beginDraw();

		//按钮操作
		ExMessage msg;
		while (peekmessage (&msg, EM_MOUSE))
		{
			btn.event(msg);
			/*if (1 == btn.click(0, 0, 520, 520, 240, 80))
			{
				printf("btn3 is clicked\n");
				btn.showpage3();
			}
			else if (1 == btn.click(0, 0, 520, 420, 240, 80))
			{
				printf("btn2 is clicked\n");
				btn.showpage2();

			}*/
			if (1 == btn.click(0, 0, 520, 320, 240, 80))
			{
				printf("btn1 is clicked\n");
				btn.showpage1();
			}
			else if (1 == btn.click(0, 0, 1050, 580, 120, 60))
			{
				flag_end = 1;
				exit;
			}
		}

		win.endDraw();
	}

	flag_end = 0;
	//delimage(&img);
	closegraph();

	return 0;
}
