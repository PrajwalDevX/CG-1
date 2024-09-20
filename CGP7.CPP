#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

void EightWaySymmetricPlot(int xc, int yc, int x, int y)
 {
    putpixel(x + xc, y + yc, RED);
    putpixel(x + xc, -y + yc, YELLOW);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc, y + yc, YELLOW);
    putpixel(y + xc, x + yc, CYAN);
    putpixel(y + xc, -x + yc, BLUE);
    putpixel(-y + xc, -x + yc, MAGENTA);
    putpixel(-y + xc, x + yc, WHITE);
}

void BresenhamCircle(int xc, int yc, int r) 

{
    int x = 0, y = r;
    int d = 3 - 2 * r; // Initial decision parameter

    EightWaySymmetricPlot(xc, yc, x, y); // Initial plot of points

    while (x <= y)
    {
	if (d <= 0)
	 {
	    d = d + 4 * x + 6; // Update d when choosing the next point
	}
	else
	{
	    d = d + 4 * (x - y) + 10; // Update d when y decreases
	    y--;
	}
	x++;

	EightWaySymmetricPlot(xc, yc, x, y); // Plot symmetric points
	delay(100);
    }
}

void main()
{
    int xc, yc, r;
    int gd = DETECT, gm;
   
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cout << "Enter the values of center (xc, yc): ";
    cin >> xc >> yc;

    cout << "Enter the value of radius: ";
    cin >> r;

    BresenhamCircle(xc, yc, r); // Draw the circle

    getch();
    closegraph();
}
