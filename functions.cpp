#include "functions.h"

//search alumni
void search_alumni(string domain) {
    ifstream file("data/alumni.txt");
    string name, email, pass, dom, comp, year;
    bool found = false;

    cout << "\n    Alumni Matching Domain: " << domain << "    \n";
    while (getline(file, name, ',') && getline(file, email, ',') && getline(file, pass, ',') &&
           getline(file, dom, ',') && getline(file, comp, ',') && getline(file, year)) {
        if (dom == domain) {
            found = true;
            cout << "Name: " << name << "\nEmail: " << email 
                 << "\nCompany: " << comp << "\nYear: " << year << "\n\n";
        }
    }
    if (!found) cout << "No alumni found for this domain.\n";
    file.close();
}

//send mentor request
void send_mentorshiprequest(string studentmail, string alumnimail) {
    ofstream file("data/requests.txt", ios::app);
    file << studentmail << "->" << alumnimail << "\n";
    file.close();
    cout << "Mentorship request sent!\n";
}

//view request(student to alumni)
void view_requests() {
    ifstream file("data/requests.txt");
    string line;
    queue<string> requests; // FIFO order

    while (getline(file, line)) {
        requests.push(line);
    }

    cout << "\n    Pending Mentorship Requests    \n";
    if (requests.empty()) {
        cout << "No pending requests.\n";
        return;
    }

    while (!requests.empty()) {
        cout << requests.front() << endl;
        requests.pop();
    }
    file.close();
}

//give feedback
void give_feedback(string from, string to) {
    string rating, comment;
    cout << "Enter Rating : ";
    getline(cin, rating);
    cout << "Enter Feedback Comment: ";
    getline(cin, comment);

    ofstream file("data/feedback.txt", ios::app);
    file << from << "->" << to << "," << rating << "," << comment << "\n";
    file.close();
    cout << "Feedback recorded successfully!\n";
}

//send message(alumni to student)
void send_message(string from, string to) {
    string message;
    cout << "\nEnter your message to " << to << ": ";
    getline(cin, message);

    ofstream file("data/messages.txt", ios::app);
    file << "From: " << from << " | To: " << to << " | Message: " << message << "\n";
    file.close();
    cout << "Message sent successfully!\n";
}

//messages
void view_messages(string user) {
    ifstream file("data/messages.txt");
    string line;
    bool found = false;

    cout << "\n    Your Messages     \n";
    while (getline(file, line)) {
        if (line.find("To: " + user) != string::npos) {
            cout << line << endl;
            found = true;
        }
    }

    if (!found) cout << "No messages found.\n";
    file.close();
}
