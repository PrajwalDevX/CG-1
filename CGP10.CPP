#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include<dos.h>
#include <process.h>  // For exit function



class POLY {
    int ax[10], ay[10], DF_PEN_X, DF_PEN_Y, n, i;

public:
    POLY() {}

    void poly();
};

void POLY::poly() {
    // Input number of sides of polygon
    cout << "Enter no. of sides of polygon: ";
    cin >> n;

    if (n < 3) {
        cout << "Polygon size error. Exiting..." << endl;
        exit(0);
    } else {
        // Input X coordinates of vertices
        cout << "Enter values for ax: ";
        for (i = 1; i <= n; i++) {
            cin >> ax[i];
        }

        // Input Y coordinates of vertices
        cout << "Enter values for ay: ";
        for (i = 1; i <= n; i++) {
            cin >> ay[i];
        }

        // Initialize graphics mode
        int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");

        // Move to the last vertex
        DF_PEN_X = ax[n];
        DF_PEN_Y = ay[n];
        moveto(DF_PEN_X, DF_PEN_Y);

        // Draw the polygon by connecting all vertices
        for (i = 1; i <= n; i++) {
            lineto(ax[i], ay[i]);
        }

        getch();  // Wait for user input to close the window
        closegraph();  // Close the graphics window
    }
}

void main() {
    POLY p;
    p.poly();
    getch();
}
