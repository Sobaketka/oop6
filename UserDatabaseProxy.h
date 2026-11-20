#ifndef USERDATABASEPROXY_H
#define USERDATABASEPROXY_H

#include "UserDatabaseInterface.h"

class UserDatabaseProxy : public UserDatabaseInterface {
private:
    vector<vector<string>> data;

public:
    UserDatabaseProxy();

    bool getUserByEmail(const string& email, User& user) override;

    vector<User> getAllUsersByCity(const string& city) override;
};

#endif

