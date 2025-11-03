#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

void search_alumni(string domain);
void send_mentorshiprequest(string studentEmail, string alumniEmail);
void view_requests();
void give_feedback(string from, string to);
void send_message(string from, string to);
void view_messages(string user);
#endif
