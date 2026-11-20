#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

struct User {
    string name;
    string email;
    string city;

    void input() {
        cout << "Enter name-> ";
        getline(cin, name);

        cout << "Enter email-> ";
        getline(cin, email);

        cout << "Enter city-> ";
        getline(cin, city);
    }

    void output() const {
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "City: " << city << endl;
    }
};

#endif

