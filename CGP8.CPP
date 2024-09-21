#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

//void circle(int, int, int, int);
//void circlepoints(int, int, int, int, int);

void circlepoints(int x0, int x, int y0, int y, int xc) {
    putpixel((x0 + x), (y0 + y), xc);
    putpixel((x0 + x), (y0 - y), xc);
    putpixel((x0 - x), (y0 - y), xc);
    putpixel((x0 - x), (y0 + y), xc);
    putpixel((x0 + y), (y0 + x), xc);
    putpixel((x0 + y), (y0 - x), xc);
    putpixel((x0 - y), (y0 + x), xc);
    putpixel((x0 - y), (y0 - x), xc);
}

void circle(int x0, int y0, int r, int xc) {
    int x = 0;
    int y = r;
    double d = 1 - r;  // Use a semicolon instead of a colon
    int gd = DETECT, gm;


  initgraph(&gd, &gm, "C:\\TC\\BGI");

    circlepoints(x0, x, y0, y, xc);

    while (y > x) {
	if (d < 0) {
	    d += 2 * x + 3;
	} else {
	    d += 2 * (x - y) + 5;
	    y--;
	}
	x++;
	circlepoints(x0, x, y0, y, xc);
    }

    getch();
    closegraph();
}

void main() {
  //  int m[16] = {BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY, LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW, WHITE};
    int x0, y0, r, xc;

    cout << "Enter the value of x0 and y0: ";
    cin >> x0 >> y0;

    cout << "Enter the value of radius: ";
    cin >> r;

    cout << "Enter the color (0-15): ";
    cin >> xc;

    circle(x0, y0, r, xc);
}
