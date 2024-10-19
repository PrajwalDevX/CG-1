#include <conio.h>
#include <iostream.h>
#include <graphics.h>
#include <stdlib.h>
#include <dos.h>

class Point
{
public:
    int x, y;
};

class Poly
{
private:
    Point p[20];
    int inter[20], x, y;
    int v, xmin, ymin, xmax, ymax;

public:
    int c;

    void read();
    void calcs();
    void display();
    void ints(float);
    void sort(int);
};

void Poly::read()
{
    int i;
    cout << "THE SCANLINE ALGORITHM\n";
    cout << "Enter the number of vertices of the polygon: ";
    cin >> v;

    if (v > 2)
    {
        for (i = 0; i < v; i++)
        {
            cout << "\nEnter the coordinates of vertex " << i + 1 << ":\n";
            cout << "x = ";
            cin >> p[i].x;
            cout << "y = ";
            cin >> p[i].y;
        }

        // Closing the polygon by making the last vertex the same as the first
        p[i].x = p[0].x;
        p[i].y = p[0].y;

        xmin = xmax = p[0].x;
        ymin = ymax = p[0].y;
    }
    else
    {
        cout << "Enter a valid number of vertices.\n";
        exit(0);
    }
}

void Poly::calcs()
{
    for (int i = 0; i < v; i++)
    {
        if (xmin > p[i].x)
        {                  // Start of the block
            xmin = p[i].x; // Statement inside the block
        } // End of the block

        if (xmax < p[i].x)
        {
            xmax = p[i].x;
        }

        if (ymin > p[i].y)
        {
            ymin = p[i].y;
        }

        if (ymax < p[i].y)
        {
            ymax = p[i].y;
        }
    }
}

void Poly::display()
{
    int color_choice;
    float s;

    cout << "Enter the color (8-15): ";
    cin >> color_choice;
    setcolor(color_choice);

    s = ymin + 0.01;
    delay(100);
    cleardevice();

    while (s <= ymax)
    {
        ints(s);
        sort(s);
        s++;
    }
}

void Poly::ints(float z)
{
    int x1, x2, y1, y2, temp;
    c = 0;

    for (int i = 0; i < v; i++)
    {
        x1 = p[i].x;
        y1 = p[i].y;
        x2 = p[i + 1].x;
        y2 = p[i + 1].y;

        if (y2 < y1)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        if (z <= y2 && z >= y1)
        {
            if ((y1 - y2) == 0)
            {
                x = x1;
            }
            else
            {
                x = ((x2 - x1) * (z - y1)) / (y2 - y1) + x1;
            }

            if (x <= xmax && x >= xmin)
            {
                inter[c++] = x;
            }
        }
    }
}

void Poly::sort(int z)
{
    int temp, j, i;

    for (i = 0; i < v; i++)
    {
        line(p[i].x, p[i].y, p[i + 1].x, p[i + 1].y); // Draw the polygon outline
    }

    delay(100);

    for (i = 0; i < c; i += 2)
    {
        delay(100);
        line(inter[i], z, inter[i + 1], z); // Fill the polygon
    }
}

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    cleardevice();

    Poly polygon;
    polygon.read();
    polygon.calcs();
    polygon.display();

    closegraph();
    getch();
}
