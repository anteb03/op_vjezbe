#include <iostream>
#include <cmath>

using namespace std; 

template <typename T>

class Point {
private:
    T x, y;

public:
    Point(T xV, T yV) : x(xV), y(yV) {}

    friend ostream& operator<<(ostream& os, const Point& point) {
        os << "(" << point.x << "," << point.y << ")";
        return os;
    }

    double operator-(const Point& drugi) const {
        T rx = x - drugi.x;
        T ry = y - drugi.y;
        return sqrt(rx * rx + ry * ry);
    }
};

int main() {
    Point<int> p1(2, 3), p2(3, 4);
    cout << "Udaljenost tocaka " << p1 << " i " << p2 << " je " << p1 - p2 << endl;

    return 0;
}