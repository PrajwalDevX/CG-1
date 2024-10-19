#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <math.h>
#include <process.h>

class POLY
{
    int ax[10], ay[10], DF_PEN_X, DF_PEN_Y, n, i;
    float sx, sy, xnew[10], ynew[10];

public:
    POLY()
    {
        sx = 1;
        sy = 1;
    } // Constructor to initialize sx and sy
    void poly();
    void scaling();
};

void POLY::poly()
{
    cout << "Enter number of sides of the polygon: ";
    cin >> n;

    if (n < 3)
    {
        cout << "Polygon size error....";
        exit(0);
    }
    else
    {
        cout << "Enter values for ax: ";
        for (i = 1; i <= n; i++)
        {
            cin >> ax[i];
        }

        cout << "Enter values for ay: ";
        for (i = 1; i <= n; i++)
        {
            cin >> ay[i];
        }

        int gd = DETECT, gm;
        initgraph(&gd, &gm, "C:\\TC\\BGI");

        DF_PEN_X = ax[n];
        DF_PEN_Y = ay[n];
        moveto(DF_PEN_X, DF_PEN_Y);

        for (i = 1; i <= n; i++)
        {
            lineto(ax[i], ay[i]); // Draw original polygon
        }
    }
}

void POLY::scaling()
{
    cout << "\n\n\t\t Enter the scale factor (Sx): ";
    cin >> sx;
    cout << "\n\t\t Enter the scale factor (Sy): ";
    cin >> sy;

    for (i = 1; i <= n; i++)
    {
        xnew[i] = ax[i] * sx;
        ynew[i] = ay[i] * sy;
    }

    cleardevice(); // Clear the previous drawing

    DF_PEN_X = xnew[n];
    DF_PEN_Y = ynew[n];
    moveto(DF_PEN_X, DF_PEN_Y);

    for (i = 1; i <= n; i++)
    {
        lineto(xnew[i], ynew[i]); // Draw scaled polygon
    }
}

void main()
{
    POLY p;

    p.poly();
    getch(); // Wait for user input before scaling

    p.scaling();
    getch(); // Wait for user input to see the scaling result

    closegraph(); // Close the graphics mode
}
