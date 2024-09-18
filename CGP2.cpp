#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Base of the house
    line(280, 181, 280, 407); // Left wall
    line(280, 407, 490, 407); // Bottom wall
    line(490, 407, 490, 182); // Right wall
    line(490, 182, 280, 182); // Top wall

    // Roof of the house
    line(280, 182, 330, 90);  // Left side of the roof
    line(330, 90, 535, 90);   // Top side of the roof
    line(535, 90, 490, 182);  // Right side of the roof

    // Extension of the roof
    line(535, 90, 579, 182);  // Right extension top
    line(490, 182, 579, 182); // Right extension bottom
    line(579, 182, 579, 407); // Right extension right wall
    line(579, 407, 490, 407); // Right extension bottom wall

    // Door
    line(520, 407, 520, 300); // Left side of the door
    line(520, 300, 558, 300); // Top side of the door
    line(558, 300, 558, 407); // Right side of the door

    // Window
    line(341, 242, 418, 242); // Top side of the window
    line(418, 242, 418, 298); // Right side of the window
    line(418, 298, 341, 298); // Bottom side of the window
    line(341, 298, 341, 242); // Left side of the window

    getch();
}
