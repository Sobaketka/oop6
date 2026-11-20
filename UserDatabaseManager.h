#ifndef USERDATABASEMANAGER_H
#define USERDATABASEMANAGER_H

#include "UserDatabaseInterface.h"

class UserDatabaseManager : public UserDatabaseInterface {
private:
    string filename;

    vector<User> loadUsers();

public:
    UserDatabaseManager(string file);

    bool getUserByEmail(const string& email, User& user) override;

    vector<User> getAllUsersByCity(const string& city) override;
};

#endif

