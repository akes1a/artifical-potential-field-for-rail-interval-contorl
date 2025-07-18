#pragma once
#include "kongz.h"
#include"Rwindows.h"
#include<graphics.h>
#include <windows.h>
class button :
    public kongz
{
public:

    button(kongz *parent=nullptr);

    void showpage1();
    void plotapf();
    void draw1();
    void draw2();
    //void showpage2()override;
    //void showpage3()override;
    void show()override;
    void event(const ExMessage &msg)override;

    bool click(int x, int y, int left, int top, int w, int h);
    //bool isin(int x, int y, int left, int top, int w, int h);
   

private:
    const ExMessage* m_msg;

};
