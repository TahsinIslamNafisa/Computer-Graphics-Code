#include <GL/glut.h> //bresenham circle algo
#include <iostream>
using namespace std;

int centerX, centerY, radius;

void plotPoints(int xc, int yc, int x, int y) {
    // Draw 8 symmetric points of the circle
    glVertex2f((xc + x) / 100.0f, (yc + y) / 100.0f);
    glVertex2f((xc - x) / 100.0f, (yc + y) / 100.0f);
    glVertex2f((xc + x) / 100.0f, (yc - y) / 100.0f);
    glVertex2f((xc - x) / 100.0f, (yc - y) / 100.0f);
    glVertex2f((xc + y) / 100.0f, (yc + x) / 100.0f);
    glVertex2f((xc - y) / 100.0f, (yc + x) / 100.0f);
    glVertex2f((xc + y) / 100.0f, (yc - x) / 100.0f);
    glVertex2f((xc - y) / 100.0f, (yc - x) / 100.0f);
}

void drawCircle() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0); // 🔴 Red circle
    glPointSize(3);

    glBegin(GL_POINTS);

    int x = 0;
    int y = radius;
    int d = 3 - 2 * radius; // Decision parameter

    plotPoints(centerX, centerY, x, y);

    while (y >= x) {
        x++;
        if (d > 0) {
            y--;
            d = d + 4 * (x - y) + 10;
        } else {
            d = d + 4 * x + 6;
        }
        plotPoints(centerX, centerY, x, y);
    }

    glEnd();
    glFlush();
}

void setupView() {
    glClearColor(1.0, 1.0, 0.0, 1.0); // 🟡 Yellow background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1, 0, 1, -1, 1);
}

int main(int argc, char** argv) {
    cout << "Enter center coordinates (x y): ";
    cin >> centerX >> centerY;
    cout << "Enter radius: ";
    cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Circle Drawing");
    setupView();
    glutDisplayFunc(drawCircle);
    glutMainLoop();

    return 0;
}
