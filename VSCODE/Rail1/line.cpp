#include "line.h"
#include<iostream>


lineoftrain::lineoftrain(int w, int h, int flag)
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
	loadimage(&img, L"\linejpg.jpg", w, h, true);		//����ͼƬ
	putimage(225, 100, &img);	//��ʾͼƬ
}

lineoftrain::~lineoftrain()
{

	//�˳�����

	//system("pause");
}

void lineoftrain::beginDraw()
{
	BeginBatchDraw();
}

void lineoftrain::endDraw()
{
	EndBatchDraw();
}
