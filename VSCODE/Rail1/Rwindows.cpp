#include "Rwindows.h"
#include<iostream>


//�꣺ �� SRCAND �� ��������
//�꣺ ��SRCPAINT�� ��������



Rwindows::Rwindows(int w, int h, int flag)
{
	
	//���ر���ͼƬ
	void loadimage(
		IMAGE * pDstImg,	// ����ͼ��� IMAGE ����ָ��
		LPCTSTR pImgFile,	// ͼƬ�ļ���
		int nWidth,			// ͼƬ��������
		int nHeight,		// ͼƬ������߶�
		bool bResize	// �Ƿ���� IMAGE �Ĵ�С����ӦͼƬ
	);

	//initgraph(w, h, flag);	//��������

	IMAGE img;
	loadimage(&img, L"\Back.jpg", w, h, true);		//����ͼƬ
	putimage(0, 0, &img);	//��ʾͼƬ
	
}

Rwindows::~Rwindows()
{

	//�˳�����

	//system("pause");

}

void Rwindows::beginDraw()
{
	BeginBatchDraw();

}

void Rwindows::endDraw()
{
	EndBatchDraw();

}
