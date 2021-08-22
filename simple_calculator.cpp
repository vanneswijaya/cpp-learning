#include <iostream>

using namespace std;

int main() 
{
    int v1, v2;
    double r;
    char o;
    cout << "CALCULATOR\n";
    cout << "==========\n";

    cout << "Enter first number: ";
    cin >> v1;
    cout << "Enter second number: ";
    cin >> v2;

    cout << "Enter operator: ";
    cin >> o;

    if (o == '+') {
        r = v1 + v2;
    } else if (o == '-') {
        r = v1 - v2;
    } else if (o == '*') {
        r = v1 * v2;
    } else if (o == '/') {
        r = static_cast<double>(v1) / static_cast<double>(v2);
    } else {
        cout << "Invalid operator";
        return -1;
    }

    cout << "The result is " << r << endl;

    return 0;
}