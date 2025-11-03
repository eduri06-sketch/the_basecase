#ifndef ALUMNI_H
#define ALUMNI_H
#include "user.h"
#include <fstream>

class alumni : public user {
    string domain, company, gradYear;
public:
    void Register() override {
        cout << "\n     Alumni Registration      \n";
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Email: "; getline(cin, email);
        cout << "Enter Password: "; getline(cin, password);
        cout << "Enter Domain: "; getline(cin, domain);
        cout << "Enter Company: "; getline(cin, company);
        cout << "Enter Graduation Year: "; getline(cin, gradYear);

        ofstream file("data/alumni.txt", ios::app);
        file << name << "," << email << "," << password << "," << domain << "," << company << "," << gradYear << "\n";
        file.close();
        cout << "Registered successfully!\n";
    }

    bool Login(string mail, string pass) override {
        ifstream file("data/alumni.txt");
        string n, e, p, d, c, y;
        while (getline(file, n, ',') && getline(file, e, ',') && getline(file, p, ',') &&
               getline(file, d, ',') && getline(file, c, ',') && getline(file, y)) {
            if (e == mail && p == pass) return true;
        }
        return false;
    }
};
#endif
