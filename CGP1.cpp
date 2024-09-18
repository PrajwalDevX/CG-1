#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void main() {
    int gd = DETECT, gm;

    // Initialize graphics mode
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw a Line
    line(80, 90, 350, 90);

    // Draw a Rectangle
    line(50, 110, 290, 110);
    line(290, 110, 290, 260);
    line(290, 260, 50, 260);
    line(50, 260, 50, 110);

    // Draw a Triangle
    line(185, 295, 280, 395);
    line(280, 395, 80, 395);
    line(80, 395, 185, 295);

    // Draw a Pentagon
    line(495, 55, 570, 100);
    line(570, 100, 535, 170);
    line(535, 170, 445, 170);
    line(445, 170, 415, 100);
    line(415, 100, 495, 55);

    // Draw a Square
    line(430, 280, 580, 280);
    line(580, 280, 580, 390);
    line(580, 390, 430, 390);
    line(430, 390, 430, 280);

    // Wait for a key press
    getch();

    // Close graphics mode
    closegraph();
}
