#include "kongz.h"
#include"Rwindows.h"


kongz::kongz(kongz* parent)
{

}

kongz::~kongz()
{

}

void kongz::move(int x, int y)
{
	m_x = x;
	m_y = y;
}

void kongz::setsize(int w, int h)
{
	m_w = w;
	m_h = h;
}

void kongz::setcolor(DWORD c)
{
	m_color = c;

}

void kongz::write(const wchar_t* str1, const wchar_t* str2, int x, int y, int w, int h)
{

	int vspace1 = (w - textwidth(str1)) / 2;
	int hspace1 = (h - textheight(str1)) / 2;

	int vspace2 = (w - textwidth(str2)) / 2;
	int hspace2 = (h - textheight(str2)) / 2;

	outtextxy(x + vspace1, y, str1);
	outtextxy(x + vspace2, y + 2 * hspace2, str2);


}

void kongz::event(const ExMessage& msg)
{


}

