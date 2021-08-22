#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;

struct User {
    string username;
    string password;
};

User askData() {
    string username, password;
    cout << "Enter username: "; cin >> username;
    cout << "Enter password: "; cin >> password;
    User user = { username, password };
    return user;
};

void sign() {
    User user = askData();
    cout << "Signing up...\n";
    string filename = user.username + ".txt";
    if (filesystem::exists(filename)) {
        cout << "Your username is taken.";
    } else {
        ofstream UserFile(filename);
        UserFile << user.password;
        UserFile.close();
        cout << "Your account has been signed up successfully.";
    }
}

void login() {
    User user = askData();
    string filename = user.username + ".txt";
    if (filesystem::exists(filename)) {
        ifstream UserFile(filename);
        string password; getline(UserFile, password);
        if (user.password == password) {
            cout << "Logging in...\n";
            cout << "You are logged in.";
        } else {
            cout << "Invalid password.";
        }
    } else {
        cout << "You are not signed up.";
    }
}

int main() {
    cout << "1: Sign Up\n2: Login\n\nChoose option: ";
    int opt; cin >> opt;
    if (opt == 1) {sign();}
    else if (opt == 2) {login();}
    return 0;
}