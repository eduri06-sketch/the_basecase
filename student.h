#ifndef STUDENT_H
#define STUDENT_H
#include "user.h"
#include <fstream>

class student : public user {
    string domain, year;
public:
    void Register() override {
        cout << "\n     Student Registration    \n";
        cout << "Enter Name: "; getline(cin, name);
        cout << "Enter Email: "; getline(cin, email);
        cout << "Enter Password: "; getline(cin, password);
        cout << "Enter Domain of Interest: "; getline(cin, domain);
        cout << "Enter Year: "; getline(cin, year);

        ofstream file("data/students.txt", ios::app);
        file << name << "," << email << "," << password << "," << domain << "," << year << "\n";
        file.close();
        cout << "Registered successfully!\n";
    }

    bool Login(string mail, string pass) override {
        ifstream file("data/students.txt");
        string n, e, p, d, y;
        while (getline(file, n, ',') && getline(file, e, ',') && getline(file, p, ',') && getline(file, d, ',') && getline(file, y)) {
            if (e == mail && p == pass) return true;
        }
        return false;
    }
};
#endif
