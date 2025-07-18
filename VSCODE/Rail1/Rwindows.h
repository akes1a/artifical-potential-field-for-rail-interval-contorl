#pragma once
#include<easyx.h>


class Rwindows
{
public:

	Rwindows(int w ,int h ,int flag = EX_SHOWCONSOLE );
	~Rwindows();
	//Ë«»º³åº¯Êý
	static void beginDraw();
	static void endDraw();
};

