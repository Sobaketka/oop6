#include <iostream>
#include "UserDatabaseManager.h"
#include "UserDatabaseProxy.h"

using namespace std;
#define DEBUG_MODE 1

void workWithDatabase(UserDatabaseInterface& db) {
    string email, city;
    User user;

    cout << "Enter email to search: ";
    getline(cin, email);

    if (db.getUserByEmail(email, user)) {
        cout << "\nUser found:\n";
        user.output();
    }
    else {
        cout << "\nUser not found!\n";
    }

    cout << "\nEnter city: ";
    getline(cin, city);

    vector<User> users = db.getAllUsersByCity(city);

    cout << "\nUsers from " << city << ":\n";

    if (users.empty()) {
        cout << "No users found!\n";
    }
    else {
        for (int i = 0; i < users.size(); i++) {
            users[i].output();
            cout << "\n";
        }
    }
}

int main() {
#if DEBUG_MODE
    UserDatabaseProxy database;
    cout << "DEBUG MODE\n\n";
#else
    UserDatabaseManager database("database.csv");
    cout << "RELEASE MODE\n\n";
#endif

    workWithDatabase(database);

    return 0;
}
