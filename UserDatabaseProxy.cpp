
#include "UserDatabaseProxy.h"

UserDatabaseProxy::UserDatabaseProxy() {
    data = {
        {"Hvostik", "hvostik@gmail.com", "Rivne"},
        {"Liana", "liana@gmail.com", "Lytsk"},
        {"Ninka", "nink@gmail.com", "Chernivtsi"},
        {"Lenka", "lenka@gmail.com", "Lviv"},
        {"Dasha", "dasha@gmail.com", "Varash"},
        {"Zoyka", "zoy@gmail.com", "Chernivtsi"},
        {"Misha", "mishka@gmail.com", "Kyiv"},
        {"Syshka", "syshk@gmail.com", "Odesa"},
        {"Svetka", "sve@gmail.com", "Rivne"},
        {"Nata", "nata@gmail.com", "Chernivtsi"}
    };
}

bool UserDatabaseProxy::getUserByEmail(const string& email, User& user) {
    for (int i = 0; i < data.size(); i++) {
        if (data[i][1] == email) {
            user.name = data[i][0];
            user.email = data[i][1];
            user.city = data[i][2];

            return true;
        }
    }

    return false;
}

vector<User> UserDatabaseProxy::getAllUsersByCity(const string& city) {
    vector<User> result;

    for (int i = 0; i < data.size(); i++) {
        if (data[i][2] == city) {
            User user;

            user.name = data[i][0];
            user.email = data[i][1];
            user.city = data[i][2];

            result.push_back(user);
        }
    }

    return result;
}
