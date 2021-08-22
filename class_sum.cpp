#include <iostream>
using namespace std;

class Sum {
    public:
        int v1, v2;
        Sum(int x, int y) {
            v1 = x; v2 = y;
        }
        int calc() { return v1 + v2; }
};

int main() {
    int v1, v2;
    cout << "Enter first value: ";
    cin >> v1;
    cout << "Enter second value: ";
    cin >> v2;
    Sum sum(v1, v2);
    cout << "Sum is " << sum.calc();
    return 0;
}
