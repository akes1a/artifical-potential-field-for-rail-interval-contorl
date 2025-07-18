#include"kongz.h"
#include "button.h"
#include"Rwindows.h"
#include<graphics.h>
#include"apft.h"
#include"line.h"

button::button(kongz* parent)
	:kongz (parent)
{
	m_title = "button.h";

}

//��Ļ 1280*720��
double	R = 0;
double S_V[6];
int flagp1end = 0;
int flagp2end = 0;


void button::showpage1()
{
	draw1();

	wchar_t setting[10];//���뻺����
	double* r = &R;
	
	while (flagp1end == 0)
	{
		BeginBatchDraw();
		//��ť����
		ExMessage msg;
		while (peekmessage(&msg, EM_MOUSE))
		{
			event(msg);
			if (1 == click(0, 0, 955, 500, 250, 100))
			{
				printf("exit is clicked\n");
				flagp1end = 1;
				exit;
			}
			if (1 == click( 0,0,955, 50, 250, 100))
			{
				printf("setting is clicked\n");
				// �����ַ������������������û�����
				InputBox(setting, 10, L"�������г���ʼ��ࣺ");
				// ���û�����ת��Ϊ����
				*r = _wtoi(setting);
			}
			if (1 == click(0, 0, 955, 200, 250, 100))
			{
				if (R !=0 )
				{
					plotapf();
					printf("plotapf is over\n");
				}
			}
		}
		EndBatchDraw();
	}
	flagp1end = 0;
	cleardevice();
	Rwindows win0(1280, 720);
	show();
	return;
}

void button::plotapf()
{
	draw2();
	//����ͼ�����
	double* apfSV;//apfSV[S0,S1,S2,V0,V1,V2]
	apft apf;
	S_V[0] = 0; S_V[1] = 0-R; S_V[2] = 0-2*R; S_V[3] = 0; S_V[4] = 0; S_V[5] = 0;
	
	for (int i = 0; i < 8229; i++) {
		apfSV = apf.apfcss(S_V[0], S_V[1], S_V[2], S_V[3], S_V[4], S_V[5],i);
		S_V[0] = *apfSV; S_V[1] = *(apfSV+1); S_V[2] = *(apfSV+2); 
		S_V[3] = *(apfSV+3); S_V[4] = *(apfSV+4); S_V[5] = *(apfSV+5);

		putpixel(-415+i*0.1 , 0.4*(S_V[1]-S_V[0]), BLACK);
		putpixel(-415 + i * 0.1, 0.4 * (S_V[2] - S_V[1]), BLUE);

		putpixel(-415 + i * 0.1, 5*(S_V[4]-S_V[3])+77.5, BLACK);
		putpixel(-415 + i * 0.1, 5*(S_V[5] - S_V[4])+77.5, BLUE);

		putpixel(-415 + 0.024*(S_V[0]+2*R), -2*S_V[3] + 310, BLACK);
		putpixel(-415 + 0.024*(S_V[1]+2*R), -2*S_V[4] + 310, BLUE);
		putpixel(-415 + 0.024*(S_V[2]+2*R), -2*S_V[5] + 310, GREEN);
		//Sleep(1);
	}
	setorigin(0, 0);
	while (0==flagp2end&0==flagp1end) {
		BeginBatchDraw();
		//��ť����
		ExMessage msg1;
		while (peekmessage(&msg1, EM_MOUSE))
		{
			event(msg1);
			if (1 == click(0, 0, 955, 500, 250, 100))
			{
				printf("exit of run is clicked\n");
				flagp1end = 1;
				exit;
			}
			if (1 == click(0, 0, 955, 350, 250, 100))
			{
				flagp2end = 1;
				
				exit;
			}
		}
		EndBatchDraw();
	}
	flagp2end = 0;
	cleardevice();
	Rwindows win0(1280, 720);
	draw1();
	return;
}

void button::draw1()
{
	//������
	cleardevice();
	Rwindows win(1280, 720);
	//����
	setcolor(WHITE);       //����m_color
	setfillcolor(m_color);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("΢���ź�"));

	//button1������
	m_x = 50;   m_y = 50;   m_w = 830;   m_h = 620;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	wchar_t wstr1[] = L"page1.gif.";
	wchar_t wstr2[] = L"�г�����";
	write(wstr1, wstr2, m_x, m_y, m_w, m_h);

	wchar_t* str1 = (wchar_t*)&wstr1;
	wchar_t* str2 = (wchar_t*)&wstr2;

	setcolor(RGB(211, 211, 211));
	setfillcolor(m_color);
	//btn1���ò���
	m_x = 955;   m_y = 50;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"���ò���";
	str2 = (wchar_t*)L"SETTING";
	write(str1, str2, m_x, m_y, m_w, m_h);

	//����
	m_x = 955;   m_y = 200;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"����";
	str2 = (wchar_t*)L"RUN";
	write(str1, str2, m_x, m_y, m_w, m_h);

	//����
	m_x = 955;   m_y = 350;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"����";
	str2 = (wchar_t*)L"CLEAR";
	write(str1, str2, m_x, m_y, m_w, m_h);

	//���ò���
	m_x = 955;   m_y = 500;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"�˳�";
	str2 = (wchar_t*)L"EXIT";
	write(str1, str2, m_x, m_y, m_w, m_h);

	printf("draw1 is running\n");
	return;
}

void button::draw2()
{
	cleardevice();
	Rwindows win(1280, 720);

	setcolor(WHITE);       //����m_color
	setfillcolor(m_color);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("΢���ź�"));
	//button1����ť
	m_x = 50;   m_y = 50;   m_w = 830;   m_h = 620;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	wchar_t wstr1[] = L"page1.gif.";
	wchar_t wstr2[] = L"׷��ͼ��";
	//write(wstr1, wstr2, m_x, m_y, m_w, m_h);

	wchar_t* str1 = (wchar_t*)&wstr1;
	wchar_t* str2 = (wchar_t*)&wstr2;

	setcolor(RGB(211, 211, 211));
	setfillcolor(m_color);
	//btn1���ò���
	m_x = 955;   m_y = 50;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"���ò���";
	str2 = (wchar_t*)L"SETTING";
	write(str1, str2, m_x, m_y, m_w, m_h);

	//����
	m_x = 955;   m_y = 200;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"��������";
	str2 = (wchar_t*)L"RUN";
	write(str1, str2, m_x, m_y, m_w, m_h);

	//����
	m_x = 955;   m_y = 350;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"����";
	str2 = (wchar_t*)L"CLEAR";
	write(str1, str2, m_x, m_y, m_w, m_h);

	//���ò���
	m_x = 955;   m_y = 500;   m_w = 250;   m_h = 100;
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	str1 = (wchar_t*)L"�˳�";
	str2 = (wchar_t*)L"EXIT";
	write(str1, str2, m_x, m_y, m_w, m_h);

	lineoftrain lin(515, 105);

	setlinecolor(BLACK);
	setorigin(465, 360);
	//setaspectratio(1, -1);
	line(-415, -155, 415, -155);//xzhou��ʾ��ͼ
	line(-415, 0, 415, 0);//xzhou��׷�ټ��
	line(-415, 155, 415, 155);//xzhou���ٶȲ�
	line(-415, 310, 415, 310);//xzhou��λ���ٶ�
	setlinecolor(RED);
	setlinestyle(PS_DOT);
	line(-415, 77.5, 415, 77.5);//xzhou���ٶȲ�0��
	//line(0, -310, 0, 310);yzhou
	//PLOT TITLE
	m_x = 315;   m_y = -310;   m_w = 70;   m_h = 25;
	str1 = (wchar_t*)L"ʾ��ͼ";
	outtextxy(m_x + (m_w - textwidth(str1)) / 2, m_y, str1);//+ (-m_h + textwidth(str1)) / 2
	m_x = 315;   m_y = -155;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"׷�ټ��(m)";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);//int vspace1 = (w - textwidth(str1)) / 2;
	m_x = 315;   m_y = 0;   m_w = 70;   m_h = 25;
	str1 = (wchar_t*)L"�ٶȲ�(m/s)";
	outtextxy(m_x + (m_w - textwidth(str1)) / 2, m_y, str1);
	m_x = 315;   m_y = 155;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"�ٶ�-λ��";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	setlinecolor(BLACK);
	setlinestyle(PS_SOLID);
	
	//д���ֽ���
	settextstyle(15, 0, _T("����"));
	m_x = -455;   m_y = -155;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"400";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -455;   m_y = -120;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"300";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -455;   m_y = -85;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"200";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -455;   m_y = -50;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"100";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -450;   m_y = -15;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"0";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
   //
	m_x = -453;   m_y = 0;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"10";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -450;   m_y = 32.5;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"5";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -450;   m_y = 69.5;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"0";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -452;   m_y = 102.5;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"-5";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -456;   m_y = 140;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"-10";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	//
	m_x = -458;   m_y = 155;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"77";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -458;   m_y = 210;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"50";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -458;   m_y = 260;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"25";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);
	m_x = -458;   m_y = 305;   m_w = 70;   m_h = 25;
	str2 = (wchar_t*)L"0";
	outtextxy(m_x + (m_w - textwidth(str2)) / 2, m_y, str2);

	return;
}

/*void button::showpage2()
{
	cleardevice();
	Rwindows win(1280, 720);
	//����

	setcolor(GREEN);       //����m_color
	setfillcolor(m_color);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("΢���ź�"));

	m_x = 50;   m_y = 50;   m_w = 830;   m_h = 620;
	//button1����ť
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	//дtitle
	wchar_t wstr1[] = L"page2.gif";
	wchar_t wstr2[] = L"��������";
	write(wstr1, wstr2, m_x, m_y, m_w, m_h);
	wchar_t* str1 = (wchar_t*)&wstr1;
	wchar_t* str2 = (wchar_t*)&wstr2;

	//exit
	m_x = 955;   m_y = 50;   m_w = 250;   m_h = 100;
	//����ť
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	//дtitle
	str1 = (wchar_t*)L"�˳�";
	str2 = (wchar_t*)L"EXIT";
	write(str1, str2, m_x, m_y, m_w, m_h);

	int flagp1end = 0;
	while (flagp1end == 0)
	{
		BeginBatchDraw();
		//��ť����
		ExMessage msg;
		while (peekmessage(&msg, EM_MOUSE))
		{
			event(msg);
			if (1 == click(0, 0, 955, 50, 250, 100))
			{
				printf("exit is clicked\n");
				flagp1end = 1;
				exit;
			}
			
		}
		EndBatchDraw();
	}
	cleardevice();
	Rwindows win0(1280, 720);
	show();
	return;
}

void button::showpage3()
{
	cleardevice();
	Rwindows win(1280, 720);
	//����

	setcolor(GREEN);       //����m_color
	setfillcolor(m_color);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("΢���ź�"));

	m_x = 50;   m_y = 50;   m_w = 830;   m_h = 620;
	//button1����ť
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	//дtitle
	wchar_t wstr1[] = L"page3.gif.";
	wchar_t wstr2[] = L"�г����";
	write(wstr1, wstr2, m_x, m_y, m_w, m_h);
	wchar_t* str1 = (wchar_t*)&wstr1;
	wchar_t* str2 = (wchar_t*)&wstr2;

	//exit
	m_x = 955;   m_y = 50;   m_w = 250;   m_h = 100;
	//����ť
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	//дtitle
	str1 = (wchar_t*)L"�˳�";
	str2 = (wchar_t*)L"EXIT";
	write(str1, str2, m_x, m_y, m_w, m_h);

	int flagp1end = 0;
	while (flagp1end == 0)
	{
		BeginBatchDraw();
		//��ť����
		ExMessage msg;
		while (peekmessage(&msg, EM_MOUSE))
		{
			event(msg);
			if (1 == click(0, 0, 955, 50, 250, 100))
			{
				printf("exit is clicked\n");
				flagp1end = 1;
				exit;
			}
		}
		EndBatchDraw();
	}
	cleardevice();
	Rwindows win0(1280, 720);
	show();
	return;
}*/

void button::show()
{
	//����
	//��������
	setcolor(RGB(0,148,212));
	setfillcolor(m_color);
	setbkmode(TRANSPARENT);
	settextcolor(WHITE);
	settextstyle(40, 0, _T("΢���ź�"));

	m_x = 520;   m_y = 320;   m_w = 240;   m_h = 80; 
	//button1����ť
	fillrectangle(m_x,m_y,m_x + m_w,m_y + m_h); 
	 //дtitle
	wchar_t wstr1[] = L"�г���������";
	wchar_t wstr2[] = L"��ʼ����";
	write( wstr1, wstr2, m_x, m_y, m_w, m_h);

	wchar_t* str1 = (wchar_t*)&wstr1;
	wchar_t* str2 = (wchar_t*)&wstr2;

	setcolor(RED);       //����m_color
	setfillcolor(m_color);
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	settextstyle(30, 0, _T("΢���ź�"));

	//exit
	m_x = 1050;   m_y = 580;   m_w = 120;   m_h = 60;
	//����ť
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);
	//дtitle
	str1 = (wchar_t*)L"�˳�";
	str2 = (wchar_t*)L"EXIT";
	write(str1, str2, m_x, m_y, m_w, m_h);
	return;
}


void button::event(const ExMessage& msg)
{
	//���������
	m_msg = &msg;


}


bool button::click(int x, int y, int left, int top, int w, int h)
{
	//�ж��Ƿ���

	if (m_msg->message == WM_LBUTTONDOWN && m_msg->x >= left && m_msg->x <= left + w && m_msg->y >= top && m_msg->y <= top + h)
	{
		return true;
	}

	return false;
}









