#include "student.h"
#include "alumni.h"
#include "functions.h"
#include <iostream>
using namespace std;

int main() {
    int choice;
    while (true) {
        cout << "\n         STUDENT ALUMNI MENTORING PLATFORM         \n";
        cout << "1. Student Registration\n2. Alumni Registration\n3. Student Login\n4. Alumni Login\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();
          //student registration
        if (choice == 1) {
           student s;
            s.Register();
        } 
        //alumni registration
        else if (choice == 2) {
           alumni a;
            a.Register();
        } 
        //student login
        else if (choice == 3) {
            string email, password;
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Password: "; getline(cin, password);

            student s;
            if (s.Login(email, password)) {
                cout << "Login successful!\n";
                int opt;
                do {
                    cout << "\n     Student Menu      \n";
                    cout << "1. Search Alumni by Domain\n";
                    cout << "2. Send Mentorship Request\n";
                    cout << "3. View Messages from Alumni\n";
                    cout << "4. Give Feedback\n";
                    cout << "5. Logout\n";
                    cout << "Choice: "; 
                    cin >> opt; 
                    cin.ignore();

                    if (opt == 1) {
                        string domain;
                        cout << "Enter Domain: "; getline(cin, domain);
                        search_alumni(domain);
                    } 
                    else if (opt == 2) {
                        string alumEmail;
                        cout << "Enter Alumni Email: "; getline(cin, alumEmail);
                        send_mentorshiprequest(email, alumEmail);
                    } 
                    else if (opt == 3) {
                        view_messages(email);  }
                    else if (opt == 4) {
                        string to;
                        cout << "Enter Alumni Email for Feedback: "; getline(cin, to);
                        give_feedback(email, to);
                    }

                } while (opt != 5);
            } 
            else cout << "Invalid login.\n";
        } 
        //alumni login
        else if (choice == 4) {
            string email, password;
            cout << "Enter Email: "; getline(cin, email);
            cout << "Enter Password: "; getline(cin, password);

            alumni a;
            if (a.Login(email, password)) {
                cout << "Login successful!\n";
                int opt;
                do {
                    cout << "\n    Alumni Menu    \n";
                    cout << "1. View Mentorship Requests\n";
                    cout << "2. Send Message to Student\n";
                    cout << "3. Logout\n";
                    cout << "Choice: "; 
                    cin >> opt; 
                    cin.ignore();

                    if (opt == 1) {
                        view_requests();   
                    } 
                    else if (opt == 2) {
                        string studentName;
                        cout << "Enter Student Name to Message: ";
                        getline(cin, studentName);
                        send_message(email, studentName); 
                    }

                } while (opt != 3);
            } 
            else cout << "Invalid login.\n";
        } 
        else if (choice == 5) {
            cout << "\nExiting program..s\n";
            break;
        }
    }
    return 0;
}
