#ifndef USER_H
#define USER_H

#include <string>

struct User {
    std::string firstName, middleName, lastName, gender, birthDate;
    std::string username, password;
};

#endif
