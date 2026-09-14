// DDA Line Drawing using OpenGL (Original Version)
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
using namespace std;

float xStart, yStart, xEnd, yEnd;

void drawDDA() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 1.0f, 0.0f); // Yellow line
    glPointSize(3.0f);

    glBegin(GL_POINTS);
    float dx = xEnd - xStart;
    float dy = yEnd - yStart;

    int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xInc = dx / steps;
    float yInc = dy / steps;

    float x = xStart;
    float y = yStart;

    for (int i = 0; i <= steps; i++) {
        glVertex2f(x / 700.0f, y / 500.0f); // Scale according to window size
        x += xInc;
        y += yInc;
    }
    glEnd();

    glFlush();
}

void setup() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0); // 2D projection
}

int main(int argc, char** argv) {
    cout << "Enter start point (x y): ";
    cin >> xStart >> yStart;
    cout << "Enter end point (x y): ";
    cin >> xEnd >> yEnd;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700, 500);
    glutInitWindowPosition(150, 100);
    glutCreateWindow("DDA Line Algorithm (Original)");
    setup();
    glutDisplayFunc(drawDDA);
    glutMainLoop();

    return 0;
}
