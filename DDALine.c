#include <iostream>
#include <cmath>
using namespace std;

const int WIDTH = 50;
const int HEIGHT = 20;

void drawDDA(int x1, int y1, int x2, int y2) {
    char screen[HEIGHT][WIDTH];

    // Initialize screen with dots
    for (int i = 0; i < HEIGHT; i++)
        for (int j = 0; j < WIDTH; j++)
            screen[i][j] = '.';

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = max(abs(dx), abs(dy));

    float xInc = dx / (float)steps;
    float yInc = dy / (float)steps;

    float x = x1, y = y1;
    for (int i = 0; i <= steps; i++) {
        int xi = round(x);
        int yi = round(y);
        if (xi >= 0 && xi < WIDTH && yi >= 0 && yi < HEIGHT)
            screen[HEIGHT - 1 - yi][xi] = '*'; // invert y for printing
        x += xInc;
        y += yInc;
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

    drawDDA(x1, y1, x2, y2);

    return 0;
}
