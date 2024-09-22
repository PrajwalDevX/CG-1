#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include<dos.h>
#include <process.h>

void bfill(int x, int y, int fill, int bd)
{
    int current;
    current = getpixel(x, y);

    if ((current != bd) && (current != fill))
    {
        putpixel(x, y, fill);
        delay(10);

        bfill(x + 1, y, fill, bd);
        bfill(x - 1, y, fill, bd);
        bfill(x, y + 1, fill, bd);
        bfill(x, y - 1, fill, bd);
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");  // Adjust the path as per your system

    rectangle(50, 50, 100, 100);
    bfill(52, 55, 2, 15);

    getch();
    closegraph();
}
