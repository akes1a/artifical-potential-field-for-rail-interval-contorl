#include "line.h"
#include<iostream>


lineoftrain::lineoftrain(int w, int h, int flag)
{
	//加载背景图片
	void loadimage(
		IMAGE * pDstImg,	// 保存图像的 IMAGE 对象指针
		LPCTSTR pImgFile,	// 图片文件名
		int nWidth,			// 图片的拉伸宽度
		int nHeight,		// 图片的拉伸高度
		bool bResize	// 是否调整 IMAGE 的大小以适应图片
	);

	//initgraph(w, h, flag);	//建立窗口

	IMAGE img;
	loadimage(&img, L"\linejpg.jpg", w, h, true);		//载入图片
	putimage(225, 100, &img);	//显示图片
}

lineoftrain::~lineoftrain()
{

	//退出窗口

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
