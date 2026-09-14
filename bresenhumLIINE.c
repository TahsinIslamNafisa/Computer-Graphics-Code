
#include <iostream>
#include <cmath>
using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

void drawBresenham(int x1, int y1, int x2, int y2) {
    char screen[HEIGHT][WIDTH];

    // Initialize screen with dots
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            screen[i][j] = '.';

    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;

    int x = x1, y = y1;
    while (true) {
        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
            screen[HEIGHT - 1 - y][x] = '*'; // invert y for printing
        if (x == x2 && y == y2) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x += sx; }
        if (e2 < dx) { err += dx; y += sy; }
    }

    // Print the screen
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++)
            cout << screen[i][j];
        cout << endl;
    }
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter start point (x y): ";
    cin >> x1 >> y1;
    cout << "Enter end point (x y): ";
    cin >> x2 >> y2;

    drawBresenham(x1, y1, x2, y2);

    return 0;
}
