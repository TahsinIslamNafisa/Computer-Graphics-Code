#include <GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;

int xStart, yStart, xEnd, yEnd;

void plotPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawBresenham() {
    int dx = abs(xEnd - xStart);
    int dy = abs(yEnd - yStart);
    int sx = (xStart < xEnd) ? 1 : -1;
    int sy = (yStart < yEnd) ? 1 : -1;
    int err = dx - dy;

    int x = xStart;
    int y = yStart;

    while (true) {
        plotPixel(x, y);
        if (x == xEnd && y == yEnd) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x += sx; }
        if (e2 < dx) { err += dx; y += sy; }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // Red line
    drawBresenham();
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Black background
    glColor3f(1.0, 0.0, 0.0);
    gluOrtho2D(0, 500, 0, 500); // 2D coordinate system
}

int main(int argc, char** argv) {
    cout << "Enter start point (x y): ";
    cin >> xStart >> yStart;
    cout << "Enter end point (x y): ";
    cin >> xEnd >> yEnd;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
