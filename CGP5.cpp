#include <graphics.h>
#include <math.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>

void main() {
    int x1, y1, x2, y2, dx, dy, sdx, sdy, e, x, y, i, swap, temp, gd = DETECT, gm;
    clrscr();
    
    cout << "Enter values for x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter values for x2 and y2: ";
    cin >> x2 >> y2;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cleardevice();
    line(120, 240, 520, 240); // X-Axis
    line(320, 40, 320, 440);  // Y-Axis

    x = x1;
    y = y1;
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x2 - x1 >= 0)
    {
        sdx = 1;
    } 
    else
     {
        sdx = -1;
    }

    if (y2 - y1 >= 0) 
    {
        sdy = 1;
    }
    
     else 
     {
        sdy = -1;
    }

    if (dy > dx) 
    {
        temp = dx;
        dx = dy;
        dy = temp;
        swap = 1;
    }
     else 
     {
        swap = 0;
    }

    e = 2 * dy - dx;

    for (i = 1; i <= dx; i++) 
    {
        putpixel(x + 320, 240 - y, 10);

        if (e >= 0) 
        {
            if (swap == 0)
             {
                y = y + sdy;
            } 
            else 
            {
                x = x + sdx;
            }
            e = e - 2 * dx;
        }

        if (swap == 0)
         {
            x = x + sdx;
        }
         else 
         {
            y = y + sdy;
        }

        e = e + 2 * dy;
        delay(100);
    }

    getch();
    closegraph();
}
