#pragma once
#include<easyx.h>

class lineoftrain
{
public:

	lineoftrain(int w, int h, int flag = EX_SHOWCONSOLE);
	~lineoftrain();
	//˫���庯��
	static void beginDraw();
	static void endDraw();
};

