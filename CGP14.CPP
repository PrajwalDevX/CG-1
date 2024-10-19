#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <process.h>

class POLY
{
    int ax[10], ay[10], DF_PEN_X, DF_PEN_Y, n, i, tx, ty;

public:
    POLY() {} // Constructor

    void poly();
    void translate();
};

void POLY::poly()
{
    cout << "Enter the number of sides of the polygon: ";
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
            lineto(ax[i], ay[i]); // Draw the polygon
        }
    }
}

void POLY::translate()
{
    cout << "Enter value of tx: ";
    cin >> tx;

    cout << "Enter value of ty: ";
    cin >> ty;

    for (i = 1; i <= n; i++)
    {
        ax[i] = ax[i] + tx;
        ay[i] = ay[i] + ty;
    }

    DF_PEN_X = ax[n];
    DF_PEN_Y = ay[n];

    moveto(DF_PEN_X, DF_PEN_Y);

    for (i = 1; i <= n; i++)
    {
        lineto(ax[i], ay[i]); // Draw the translated polygon
    }
}

void main()
{
    POLY p;
    p.poly();
    getch(); // Wait for input
    p.translate();
    getch();      // Wait for input
    closegraph(); // Close the graphics mode
}
