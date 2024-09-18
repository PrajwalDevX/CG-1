#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>

void main() {
clrscr();
    int gd = DETECT, gm, i, x1, y1, x2, y2, p, dx, dy;

    initgraph(&gd, &gm, "C:\\TC\\BGI");  // Fixed: Corrected the path

    cout << "Enter point of x1 and y1: ";
    cin >> x1 >> y1;

    cout << "Enter point of x2 and y2: ";
    cin >> x2 >> y2;

    dx = x2 - x1;  // Fixed: Corrected dx calculation
    dy = y2 - y1;  // Fixed: Corrected dy calculation

    // Initial decision parameter for Bresenham's algorithm
    p = 2 * dy - dx;

    i = dx;

    while (i > 0)
    {
	putpixel(x1, y1, WHITE);

	if (p < 0) {
	    x1 = x1 + 1;
	    p = p + 2 * dy;
	} else {
	    x1 = x1 + 1;
	    y1 = y1 + 1;
	    p = p + 2 * dy - 2 * dx;
	}

	i++;
    }

    getch();
    closegraph();
}
