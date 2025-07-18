#include "Rwindows.h"
#include<iostream>


//宏： “ SRCAND ” 做与运算
//宏： “SRCPAINT” 做或运算



Rwindows::Rwindows(int w, int h, int flag)
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
	loadimage(&img, L"\Back.jpg", w, h, true);		//载入图片
	putimage(0, 0, &img);	//显示图片
	
}

Rwindows::~Rwindows()
{

	//退出窗口

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
