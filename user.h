#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
using namespace std;

class user {
protected:
    string name, email, password;
public:
    virtual void Register() = 0;
    virtual bool Login(string email, string pwd) = 0;
};

#endif
