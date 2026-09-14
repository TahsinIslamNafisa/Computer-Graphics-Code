
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    int x, y;
};

int main() {
    int xc, yc, radius;
    cout << "Enter center coordinates (xc yc): ";
    cin >> xc >> yc;
    cout << "Enter radius: ";
    cin >> radius;

    int x = 0;
    int y = radius;
    int p = 1 - radius;

    vector<Point> circlePoints;

    auto plotPoints = [&](int x, int y) {
        // Store all 8 symmetric points
        circlePoints.push_back({xc + x, yc + y});
        circlePoints.push_back({xc - x, yc + y});
        circlePoints.push_back({xc + x, yc - y});
        circlePoints.push_back({xc - x, yc - y});
        circlePoints.push_back({xc + y, yc + x});
        circlePoints.push_back({xc - y, yc + x});
        circlePoints.push_back({xc + y, yc - x});
        circlePoints.push_back({xc - y, yc - x});
    };

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

    cout << "Circle points are:\n";
    for (auto pt : circlePoints) {
        cout << "(" << pt.x << ", " << pt.y << ")\n";
    }

    return 0;
}
