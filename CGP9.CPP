#include <iostream.h>
#include <graphics.h>
#include <math.h> // For sqrt and abs
#include<graphics.h>
#include<dos.h>
#include<conio.h>

void main() {
    int rx, ry, gd = DETECT, gm;
    float x, y;

    // Input radius for X and Y axis
    cout << "Enter Ellipse Radius Along X Axis: ";
    cin >> rx;

    cout << "Enter Ellipse Radius Along Y Axis: ";
    cin >> ry;

    // Initialize the graphics mode
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Clear the device (window)
    cleardevice();

    // Draw the X and Y axes
    line(120, 240, 520, 240); // X-axis
    line(320, 40, 320, 440);  // Y-axis

    // Start plotting the ellipse
    x = rx;
    do {
	// Calculate the y value based on the ellipse equation
	y = abs(ry * sqrt(1 - (x * x) / (rx * rx)));

	// Plot the ellipse points symmetrically
	putpixel(320 + x, 240 - y, 10); // Quadrant 1
	putpixel(320 - x, 240 - y, 10); // Quadrant 2
	putpixel(320 - x, 240 + y, 10); // Quadrant 3
	putpixel(320 + x, 240 + y, 10); // Quadrant 4

	// Update x value for next point
	x -= 0.01;

	// Small delay for visualization
	delay(2);
    } while (x >= 0);

    // Wait for a keypress
    getch();

    // Close the graphics mode
    closegraph();

}
