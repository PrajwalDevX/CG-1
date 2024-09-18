#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void ddaline(int x1, int y1, int x2, int y2)
{
    float x = x1, y = y1, dx, dy;
    int length, i;

    putpixel(x1, y1, RED);

    if (abs(x2 - x1) >= abs(y2 - y1))
    {
	length = abs(x2 - x1);
	}
    else
    {
	length = abs(y2 - y1);  // Fixed: Used `=` instead of `-` in assignment
     }

    dx = (float)(x2 - x1) / length;
    dy = (float)(y2 - y1) / length;

    for (i = 1; i <= length; i++)
     {
	x = x + dx;
	y = y + dy;
	putpixel((int)x, (int)y, RED);
	delay(30);
    }
}

void main() {
    clrscr();

    int x1, x2, y1, y2;
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cout << "Enter the first point of the line (x1 y1):\n";
    cin >> x1 >> y1;

    cout << "Enter the second point of the line (x2 y2):\n";
    cin >> x2 >> y2;

    ddaline(x1, y1, x2, y2);

    getch();  // Fixed: Moved `getch()` inside the `main` function
    closegraph();
}
