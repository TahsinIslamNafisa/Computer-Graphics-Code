#include <GL/glut.h> //midpoint circle algo
#include <iostream>
using namespace std;

int xc, yc, radius;

void plotPoints(int x, int y) {
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc - y);
    glVertex2i(xc + y, yc + x);
    glVertex2i(xc - y, yc + x);
    glVertex2i(xc + y, yc - x);
    glVertex2i(xc - y, yc - x);
}

void midpointCircle() {
    int x = 0;
    int y = radius;
    int p = 1 - radius;

    glBegin(GL_POINTS);
    while (x <= y) {
        plotPoints(x, y);
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    midpointCircle();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 0.0, 0.0);  // Background yellow
    glColor3f(1.0, 0.0, 0.0);          // Circle red
    glPointSize(2.0);
    gluOrtho2D(0, 500, 0, 500);        // 2D coordinate system
}

int main(int argc, char** argv) {
    cout << "Enter center coordinates (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> radius;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
