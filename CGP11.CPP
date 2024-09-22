#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include<dos.h>
#include <process.h> 

void ffill(int x, int y, int old, int fill)
{
    int current;
    current = getpixel(x, y);

    if (current == old)
    {
        putpixel(x, y, fill);
        delay(10);
        
        ffill(x + 1, y, old, fill);
        ffill(x - 1, y, old, fill);
        ffill(x, y + 1, old, fill);
        ffill(x, y - 1, old, fill);
        ffill(x + 1, y + 1, old, fill);
        ffill(x + 1, y - 1, old, fill);
        ffill(x - 1, y + 1, old, fill);
        ffill(x - 1, y - 1, old, fill);
    }
}

void main()
{
    int gd = DETECT, gm;
    int od = 0;

    initgraph(&gd, &gm, "C:\\TC\\BGI"); // Adjust the path as per your system
    rectangle(100, 100, 150, 150);
    ffill(125, 125, od, 4);

    getch();
    closegraph();
}
