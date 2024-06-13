#include <iostream>
#ifndef WORKSHOP_H
#define WORKSHOP_H
using namespace std;

class myclass {
private:
    string usertype, ID, Name, Tel, Password, Date, Venue, capacity, age, gender;
    int check = 0; char conti = 'y';
public:
    int userID = 0;
    int qstate = 0;
    MYSQL* conn = nullptr;
    MYSQL_ROW row = nullptr;
    MYSQL_RES* res = nullptr;
    int Register(string user);
    int login(string user);
    char add(string user);
    char deleteData(string user);
    char UpdateData(string user, string object);
    string total_capacity(string ID);
    double Mtotal_capacity(string month);
    double total_eventPM(string month);
    double total_attend(string month);
    string EventName(int ID);
};
#endif

