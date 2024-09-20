#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

void EightWaySymmetricPlot(int xc, int yc, int x, int y) {
    putpixel(x + xc, y + yc, RED);
    putpixel(x + xc, -y + yc, YELLOW);
    putpixel(-x + xc, -y + yc, GREEN);
    putpixel(-x + xc, y + yc, YELLOW);
    putpixel(y + xc, x + yc, CYAN);
    putpixel(y + xc, -x + yc, BLUE);
    putpixel(-y + xc, -x + yc, MAGENTA);
    putpixel(-y + xc, x + yc, WHITE);
}

void BresenhamCircle(int xc, int yc, int r) {
    int x = 0, y = r;
    int d = 3 - 2 * r; // Initial decision parameter

    EightWaySymmetricPlot(xc, yc, x, y); // Initial plot of points

    while (x <= y) {
        if (d <= 0) {
            d = d + 4 * x + 6; // Update d when choosing the next point
        } else {
            d = d + 4 * (x - y) + 10; // Update d when y decreases
            y--;
        }
        x++;

        EightWaySymmetricPlot(xc, yc, x, y); // Plot symmetric points
        delay(100);
    }
}

void main() {
    int xc, yc, r;
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, "");

    printf("Enter the values of center (xc, yc): ");
    scanf("%d %d", &xc, &yc);

    printf("Enter the value of radius: ");
    scanf("%d", &r);

    BresenhamCircle(xc, yc, r); // Draw the circle

    getch();
    closegraph();
}
