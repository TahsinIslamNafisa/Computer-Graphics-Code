#include <graphics.h>
#include <iostream>
using namespace std;

int main() {
    int xc, yc, r;

    cout << "Enter center coordinates (x y): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> r;

    // Initialize graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    // Set background color (yellow)
    setbkcolor(YELLOW);
    cleardevice();

    // Set drawing color (red)
    setcolor(RED);

    int x = 0;
    int y = r;
    int d = 3 - 2 * r;

    // Bresenham’s Circle Drawing Algorithm
    while (y >= x) {
        // 8-way symmetry
        putpixel(xc + x, yc + y, RED);
        putpixel(xc - x, yc + y, RED);
        putpixel(xc + x, yc - y, RED);
        putpixel(xc - x, yc - y, RED);
        putpixel(xc + y, yc + x, RED);
        putpixel(xc - y, yc + x, RED);
        putpixel(xc + y, yc - x, RED);
        putpixel(xc - y, yc - x, RED);

        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
    }

    getch();  // Wait for a key press
    closegraph(); // Close window
    return 0;
}
