#include <iostream>
using namespace std;

int main() {

    int sum = 0, val;

    cout << "Enter numbers: ";
    while (cin >> val) {
        sum += val;
    } 
    cout << "sum is " << sum << endl;
    return 0;
}