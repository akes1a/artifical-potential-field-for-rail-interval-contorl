#pragma once
#include<easyx.h>

class lineoftrain
{
public:

	lineoftrain(int w, int h, int flag = EX_SHOWCONSOLE);
	~lineoftrain();
	//Ë«»º³åº¯Êý
	static void beginDraw();
	static void endDraw();
};

