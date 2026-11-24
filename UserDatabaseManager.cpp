#include "UserDatabaseManager.h"
#include <fstream>
#include <sstream>

UserDatabaseManager::UserDatabaseManager(string file) {
    filename = file;
}

vector<User> UserDatabaseManager::loadUsers() {
    vector<User> users;
    ifstream fin(filename);
    string name, email, city;

    while (getline(fin, name, ',')) {
        getline(fin, email, ',');
        getline(fin, city);

        User user;
        user.name = name;
        user.email = email;
        user.city = city;

        users.push_back(user);
    }

    fin.close();

    return users;
}

bool UserDatabaseManager::getUserByEmail(const string& email, User& user) {
    vector<User> users = loadUsers();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].email == email) {
            user = users[i];
            return true;
        }
    }

    return false;
}

vector<User> UserDatabaseManager::getAllUsersByCity(const string& city) {
    vector<User> users = loadUsers();
    vector<User> result;

    for (int i = 0; i < users.size(); i++) {
        if (users[i].city == city) {
            result.push_back(users[i]);
        }
    }

    return result;
}
