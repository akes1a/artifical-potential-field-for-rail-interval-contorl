
#include<iostream>
#include<graphics.h>
#include<easyx.h>
#include"Rwindows.h"
#include"kongz.h"
#include"button.h"

using namespace std;

//Rwindows:���ر���ͼƬ 
//button:���ð�ť
//click:�ж�������ͣ���ť��ɫ��


int main()
{

	/************��Ļpart**********/

	initgraph(1280, 720);	//��������
	Rwindows win(1280, 720);

	/************��ťpart**********/

	button btn;                           //����class
	//��ť��������                  //����m_color
	btn.show();

	/***********����part***********/
	
	//ѭ��
	int flag_end = 0;
	while (flag_end==0)
	{

		win.beginDraw();

		//��ť����
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
