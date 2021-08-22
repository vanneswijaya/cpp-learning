#include <iostream>
using namespace std;

class Shape {
    protected: float w, h;
    public:
        void set_data(float a, float b) {
            w = a; h = b;
        }
};

class Rectangle: public Shape {
    public:
        float area() { return w*h; }
};

class Triangle: public Shape {
    public:
        float area() { return w*h/2; }
};

int main() {
    Rectangle rectangle;
    Triangle triangle;
    rectangle.set_data(2, 3);
    triangle.set_data(3, 4);
    cout << rectangle.area() << "\n";
    cout << triangle.area();
    return 0;
}