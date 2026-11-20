#ifndef USERDATABASEINTERFACE_H
#define USERDATABASEINTERFACE_H

#include "User.h"
#include <vector>
using namespace std;

class UserDatabaseInterface {
public:
    virtual bool getUserByEmail(const string& email, User& user) = 0;

    virtual vector<User> getAllUsersByCity(const string& city) = 0;

    virtual ~UserDatabaseInterface() {}
};

#endif
