#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <mysql.h> 
#include<stdlib.h>
#include"workshop.h"
#include <ctime>
#include <sstream>//libmysql
#include<fstream>
#pragma warning (disable:4996)

void AdminMainMenu();
void TutorMainMenu();
void StaffMainMenu();
void MainMenu();
void AdminMenu();
void StaffMenu();
void record(string);
void userMenu(string);
void TutorMenu();
void tutorrecord();
void Staffrecord();
void eventrecord(string);
void display(string);
void eventdisplay();
void report();
myclass C;
using namespace std;
char conti = 'y';
char error = 'x';
class db_response
{

public:
    static void DatabaseConnection()
    {

        C.conn = mysql_init(0);
        if (C.conn)
        {
            cout << "Database Connected" << endl;
        }
        else
        {
            cout << "Failed To Connect!" << endl;
        }

        C.conn = mysql_real_connect(C.conn, "localhost", "root", "", "companyeventregistration", 3306, NULL, 0);
        if (C.conn)
        {
            cout << "Database Connected To MySql" << endl;
        }
        else
        {
            cout << "Failed To Connect!" << endl;
        }

    }
};

int main() {
    system("cls");
    system("title My Project");
    db_response::DatabaseConnection();
    MainMenu();
    return 0;
}
void MainMenu()
{
    system("cls");
    char user;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|  Welcome to Company Events and Training Registration Management System        |" << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|1. Admin                                                                       |" << endl;
    cout << "\t\t|2. Tutor                                                                       |" << endl;
    cout << "\t\t|3. Staff                                                                       |" << endl;
    cout << "\t\t|4. Exit                                                                        |" << endl;
    cout << "\t\t=================================================================================" << endl << endl;
    cout << "\t\tChoice: ";
    cin >> user;

    switch (user)
    {
    case '1':
        AdminMainMenu();
        break;
    case '2':
        TutorMainMenu();
        break;
    case '3':
        StaffMainMenu();
        break;
    case '4':
        cout << "Exiting..." << endl;
        exit(0);
    default:
        cout << endl << "Please enter a number between 1 - 4 to continue." << endl;
        system("pause");
        system("cls");
        MainMenu();
        break;
    }

}
//admin main menu
//==================================================================================================================================

void AdminMainMenu()
{
    char c = 'y';

    char menu;

    system("cls");
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|                               ADMIN MAIN MENU                                  |" << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|1. Admin Login                                                                  |" << endl;
    cout << "\t\t|2. Admin Register                                                               |" << endl;
    cout << "\t\t|3. Back                                                                         |" << endl;
    cout << "\t\t=================================================================================" << endl << endl;

    cout << "Enter 1 to login or 2 to register: ";
    cin >> menu;
    switch (menu)
    {
    case '1':
        do {
            C.qstate = C.login("Admin");
            if (!C.qstate)
            {
                C.res = mysql_store_result(C.conn);
                if (C.res->row_count == 1)
                {
                    while (C.row = mysql_fetch_row(C.res))
                        string ID = C.row[0];
                    AdminMenu();
                }
                else
                {
                    cout << "Invalid username or password. Want to try again? (y/n): ";
                    cin >> c;
                }
            }
            else
            {
                cout << "Invalid username or password. Want to try again? (y/n): ";
                cin >> c;

            }
        } while (c == 'y' || c == 'Y');
        MainMenu();
        break;
    case '2':
        do {
            C.qstate = C.Register("Admin");
            if (!C.qstate)
            {
                system("cls");
                cout << "\nYou have been registered. Press Enter to Continue...\n";
                conti = 'Q';
                AdminMenu();
            }
            else if (C.qstate == 5) {
                cout << "Wrong secret key. You are not able to register to be admin.";
                cout << "Enter Y to try again or Q to exit:";
                cin >> conti;
                if (conti == 'Q' || conti == 'q') {
                    AdminMainMenu();
                }
            }
            else if (C.qstate == 8) {
                conti = 'y';
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(C.conn) << " - " << mysql_error(C.conn) << endl;
            }
        } while (conti == 'y' || conti == 'Y');
        break;
    case '3':
        MainMenu();
        break;
    default:
        cout << endl << "Please enter a number between 1 - 3 to continue." << endl;
        system("pause");
        AdminMainMenu();
        break;
    }
}

void TutorMainMenu()
{
    char c = 'y';
    system("cls");
    char menu;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|                               TUTOR MAIN MENU                                  |" << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|1. Tutor Login                                                                  |" << endl;
    cout << "\t\t|2. Tutor Register                                                               |" << endl;
    cout << "\t\t|3. Back                                                                         |" << endl;
    cout << "\t\t=================================================================================" << endl << endl;
    cout << "Enter 1 to login or 2 to register: ";
    cin >> menu;

    switch (menu)
    {
    case '1':
        do {
            C.qstate = C.login("Tutor");
            if (!C.qstate)
            {
                C.res = mysql_store_result(C.conn);
                if (C.res->row_count == 1)
                {
                    while (C.row = mysql_fetch_row(C.res))
                    {
                        string ID = C.row[0];
                        TutorMenu();
                    }
                }
                else
                {
                    cout << "Invalid username or password. Want to try again? (y/n): ";
                    cin >> c;
                }
            }
            else
            {
                cout << "Invalid username or password. Want to try again? (y/n): ";
                cin >> c;
            }
        } while (c == 'y' || c == 'Y');
        MainMenu();
        break;
    case '2':
        do {
            C.qstate = C.Register("Tutor");
            if (!C.qstate)
            {
                system("cls");
                cout << "\nYou have been registered. Press Enter to Continue...\n";
                conti = 'Q';
                TutorMenu();
            }
            else if (C.qstate == 8) {
                conti = 'y';
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(C.conn) << " - " << mysql_error(C.conn) << endl;
            }
        } while (conti == 'y' || conti == 'Y');
        break;
    case '3':
        MainMenu();
        break;
    default:
        cout << endl << "Please enter a number between 1 - 3 to continue." << endl;
        system("pause");
        system("cls");
        TutorMainMenu();
        break;
    }

}

void StaffMainMenu() {
    system("cls");
    char menu;
    char c = 'y';
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|                                Staff MAIN MENU                                 |" << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|1. Staff Login                                                                  |" << endl;
    cout << "\t\t|2. Staff Register                                                               |" << endl;
    cout << "\t\t|3. Back                                                                         |" << endl;
    cout << "\t\t=================================================================================" << endl << endl;
    cout << "Enter 1 to login or 2 to register:  ";
    cin >> menu;

    switch (menu)
    {
    case '1':
        do {
            C.qstate = C.login("Staff");
            if (!C.qstate)
            {
                C.res = mysql_store_result(C.conn);
                if (C.res->row_count == 1)
                {
                    while (C.row = mysql_fetch_row(C.res))
                    {
                        string ID = C.row[0];
                        StaffMenu();
                    }
                }
                else
                {
                    cout << "Invalid username or password. Want to try again? (y/n): ";
                    cin >> c;
                }
            }
            else
            {
                cout << "Invalid username or password. Want to try again? (y/n): ";
                cin >> c;
            }
        } while (c == 'y' || c == 'Y');
        MainMenu();
        break;
    case '2':
        do {
            C.qstate = C.Register("Staff");
            if (!C.qstate)
            {
                system("cls");
                cout << "\nYou have been registered. Press Enter to Continue...\n";
                conti = 'Q';
                StaffMenu();
            }
            else if (C.qstate == 8) {
                conti = 'y';
            }
            else
            {
                cout << "Query Execution Problem!" << mysql_errno(C.conn) << " - " << mysql_error(C.conn) << endl;
            }
        } while (conti == 'y' || conti == 'Y');
        break;
    case '3':
        MainMenu();
        break;
    default:
        cout << endl << "Please enter a number between 1 - 3 to continue.";
        system("pause");
        system("cls");
        StaffMainMenu();
        break;
    }

}
//admin menu========================================================================================================
void AdminMenu()
{

    do {
        system("cls");
        int A_Menu;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|                               Admin Menu                                       | \n";
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|1.Tutor record                                                                  |" << endl;
        cout << "\t\t|2.Staff record                                                                  |" << endl;
        cout << "\t\t|3.Event record                                                                  |" << endl;
        cout << "\t\t|4.Report record                                                                 |" << endl;
        cout << "\t\t|5.Display                                                                       |" << endl;
        cout << "\t\t|6.Back                                                                          |" << endl;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\tYour choice : ";

        cin >> A_Menu;
        if (A_Menu == 1) {
            record("Tutor");
        }
        else if (A_Menu == 2) {
            record("Staff");
        }
        else if (A_Menu == 3) {
            eventrecord("Admin");
        }
        else if (A_Menu == 4) {
            report();
            cin.ignore();
        }
        else if (A_Menu == 5) {
            display("Admin");
        }
        else if (A_Menu == 6) {
            main();
        }
        else {
            cout << "Please enter a number 1-6 only." << endl;
            error = 'c';
            system("pause");
        }
    } while (error == 'c');
}

void record(string user)
{
    system("cls");
    int T_record;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t                              " + user + " record                               \n";
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|1.Add                                                                          |" << endl;
    cout << "\t\t|2.Delete                                                                       |" << endl;
    cout << "\t\t|3.Update                                                                       |" << endl;
    cout << "\t\t|4.Back to Admin Menu                                                           |" << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\tYour choice : ";
    cin >> T_record;
    cout << "===================================================" << endl;
    if (T_record == 1)
    {
        cin.ignore(256, '\n');
        char add = C.add(user);
        while (add == 'y' || add == 'Y')
        {
            add = C.add(user);

        }
        if (add == 'n' || add == 'N')
        {
            system("cls");
            cout << "\n\tPress enter to back to " + user + " record menu....." << endl;
            cout << "=====================================================";
            cin.get();
            record(user);
        }
    }
    else if (T_record == 2)
    {
        char cont;
        do {
            char back = C.deleteData(user);
            if (back == 'Q' || back == 'q')
            {
                record(user);
            }
            else if (back == 'T' || back == 't')
            {
                back = C.deleteData(user);
            }
            cout << "====================================================";
            cout << "\n\nDo you want to delete other " + user + "? (Y/N):";
            cin >> cont;
        } while (cont == 'y' || cont == 'Y');
        system("cls");
        cout << "\n\tPress enter to back to " + user + " record menu....." << endl;
        cout << "=====================================================";
        cin.get();
        record(user);
    }
    else if (T_record == 3)
    {
        char terus = 'y';
        do {
            terus = C.UpdateData("Admin", user);

        } while (terus == 'y' || terus == 'Y');
        if (terus == 'N' || terus == 'n')
            record(user);
        else {
            cout << "Please insert yes(y) or no(n) only..... ";
            cin >> terus;
            if (terus == 'Y' || terus == 'y') {
                C.UpdateData("Admin", user);
            }
            else if (terus == 'N' || terus == 'n') {
                record(user);
            }
        }
    }
    else if (T_record == 4)
    {
        AdminMenu();
    }
    else
    {
        cout << "Please select number 1-4 only." << endl;
        system("pause");
        record(user);
    }
}
void userMenu(string user) {
    if (user == "Tutor")
        TutorMenu();
    else if (user == "Staff")
        StaffMenu();
}
void TutorMenu()
{
    int T_Menu;
    char addAttandees, attendance, conti = 't';
    string  ID, Staff_ID, attendancecheck;
    do {
        system("cls");

        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|                                   Tutor Menu                                   | \n";
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|1.Tutor information record                                                      |" << endl;
        cout << "\t\t|2.Event information record                                                      |" << endl;
        cout << "\t\t|3.Display                                                                       |" << endl;
        cout << "\t\t|4.record attendance                                                             |" << endl;
        cout << "\t\t|5.Back                                                                          |" << endl;
        cout << "\t\t=================================================================================" << endl;

        cout << "\t\tYour choice : ";
        cin >> T_Menu;
        if (T_Menu == 1) {
            tutorrecord();
        }
        else if (T_Menu == 2) {
            eventrecord("Tutor");
        }
        else if (T_Menu == 3) {
            display("Tutor");
        }
        else if (T_Menu == 5) {
            main();
        }
        else if (T_Menu == 4) {
            do {
                system("cls");
                string delete_query = "select * from events where Tutor_ID =" + to_string(C.userID);
                const char* query = delete_query.c_str();
                C.qstate = mysql_query(C.conn, query);
                if (!C.qstate)
                {
                    cout << "======================================================================================================================" << endl;
                    cout << "                                                   Event list                                                               " << endl;
                    cout << "======================================================================================================================" << endl;
                    cout << setw(11) << "Event ID" << setw(30) << "Name" << setw(20) << "Date" << setw(25) << "Time" << setw(25) << "Venue" << setw(10) << "capacity" << setw(10) << "Tutor ID" << endl;
                    C.res = mysql_store_result(C.conn);
                    while (C.row = mysql_fetch_row(C.res))
                    {
                        cout << setw(11) << C.row[0] << setw(30) << C.row[1] << setw(20) << C.row[2] << setw(27) << C.row[3] << setw(25) << C.row[4] << setw(10) << C.row[5] << setw(10) << C.row[6] << endl;
                    }
                    mysql_free_result(C.res);
                }
                else
                {
                    cout << "Query execution failed. Error: " << mysql_error(C.conn) << endl;
                }
                cout << "\nEnter the event ID to insert the attendances record : ";
                cin >> ID;

                cout << "\nEnter the staff ID :";
                cin >> Staff_ID;
                cout << "\nDo he/she attend the event? (y/n)" << endl;
                cin >> attendance;
                if (attendance == 'y')

                {
                    attendancecheck = "1";
                    int querystate = 0;
                    string addAttandees_query;
                    addAttandees_query = "Update eventsregistration set attendance = '" + attendancecheck + "' where events_ID = '" + ID + "' and Staff_ID = '" + Staff_ID + "'";;
                    const char* query = addAttandees_query.c_str();
                    querystate = mysql_query(C.conn, query);
                    if (!querystate) {
                        string displayquery = "select * from eventsregistration where events_ID = '" + ID + "' order by staff_ID";
                        const char* query = displayquery.c_str();
                        C.qstate = mysql_query(C.conn, query);

                        if (!C.qstate)
                        {
                            system("cls");
                            cout << setw(11) << "Events ID" << setw(15) << "Staff ID" << setw(20) << "Attendance" << endl;
                            C.res = mysql_store_result(C.conn);
                            while (C.row = mysql_fetch_row(C.res))
                            {
                                cout << setw(11) << C.row[0] << setw(17) << C.row[1] << setw(20) << C.row[2] << endl;

                            }
                            cout << "Press T to continue or Q to quit:";
                            cin >> conti;


                        }


                    }
                    else {
                        cout << "\n\nThis record has been registered before..." << endl;
                        cout << "\nPress T to try again or Q to back to tutor menu:";
                        cin >> conti;
                    }

                }
                else if (attendance == 'n')
                {
                    attendancecheck = "0";
                    int querystate = 0;
                    string addAttandees_query;
                    addAttandees_query = "Update eventsregistration set attendance = '" + attendancecheck + "' where events_ID = '" + ID + "' and staff_ID = '" + Staff_ID + "'";;
                    const char* query = addAttandees_query.c_str();
                    querystate = mysql_query(C.conn, query);
                    if (!querystate) {
                        string displayquery = "select * from eventsregistration where events_ID = '" + ID + "' order by Staff_ID";
                        const char* query = displayquery.c_str();
                        C.qstate = mysql_query(C.conn, query);

                        if (!C.qstate)
                        {
                            system("cls");
                            cout << setw(11) << "Events ID" << setw(15) << "Staff ID" << setw(20) << "Attendance" << endl;
                            C.res = mysql_store_result(C.conn);
                            while (C.row = mysql_fetch_row(C.res))
                            {
                                cout << setw(11) << C.row[0] << setw(17) << C.row[1] << setw(20) << C.row[2] << endl;

                            }
                            cout << "Press T to continue or Q to quit:";
                            cin >> conti;
                        }

                    }
                    else {
                        cout << "\n\nThis record has been registered before..." << endl;
                        cout << "\nPress T to try again or Q to back to tutor menu:";
                        cin >> conti;
                    }

                }
                else { conti = 'Q'; }

            } while (conti == 'T' || conti == 't');
            if (conti == 'Q' || conti == 'q')
            {
                TutorMenu();
            }
        }
        else {
            cout << "please select number 1-5 only" << endl;
            system("pause");
            error = 'c';
        }
    } while (error == 'c');
}
void StaffMenu()
{
    do {
        system("cls");
        int E_Menu;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|                                  Staff Menu                                    |" << endl;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|1.Staff information record                                                      |" << endl;
        cout << "\t\t|2.Search event and registration                                                 |" << endl;
        cout << "\t\t|3.Schedule                                                                      |" << endl;
        cout << "\t\t|4.Back                                                                          |" << endl;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\tYour choice: ";
        cin >> E_Menu;
        if (E_Menu == 1) {
            Staffrecord();
        }
        else if (E_Menu == 2)
        {
            eventdisplay();
        }
        else if (E_Menu == 4) {
            MainMenu();
        }
        else if (E_Menu == 3) {
            system("cls");
            cout << "============================================================================================================================================================" << endl;
            cout << "                                                                       Schedule                                                                              " << endl;
            cout << "============================================================================================================================================================" << endl;
            string displayquery = "select e.events_ID, e.Events_Name, e.Events_date , e.events_time, e.Events_Venue, e.Events_capacity, e.Tutor_ID from events e join eventsregistration a on e.events_ID = a.events_id where a.Staff_ID = " + to_string(C.userID) + " order by e.events_date";
            const char* query = displayquery.c_str();
            C.qstate = mysql_query(C.conn, query);
            if (!C.qstate)
            {
                cout << setw(12) << "ID" << setw(40) << "Name" << setw(15) << "Date" << setw(25) << "Time" << setw(30) << "Venue" << setw(16) << "capacity" << setw(11) << "Tutor ID" << endl;
                C.res = mysql_store_result(C.conn);
                while (C.row = mysql_fetch_row(C.res))
                {
                    cout << setw(12) << C.row[0] << setw(40) << C.row[1] << setw(15) << C.row[2] << setw(25) << C.row[3] << setw(30) << C.row[4] << setw(16) << C.row[5] << setw(11) << C.row[6] << endl;

                }
            }
            system("pause");
            StaffMenu();
        }
        else {
            cout << "Please enter number 1-4 only." << endl;
            system("pause");
            error = 'c';
        }
    } while (error == 'c');
}

void display(string user)
{
    system("cls");
    int list; char back;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|                                 Display Menu                                   | " << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|Select a list that you want to display:                                         |" << endl;
    cout << "\t\t|1.Event List                                                                    |" << endl;
    cout << "\t\t|2.Tutor List                                                                    |" << endl;
    cout << "\t\t|3.Staff List                                                                    |" << endl;
    cout << "\t\t|4.Attendees List                                                                |" << endl;
    cout << "\t\t|5.Back                                                                          |" << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\tchoose: ";
    cin >> list;
    if (list == 1)
    {
        if (user == "Tutor") {
            string displayquery = "select * from events where tutor_ID = " + to_string(C.userID);
            const char* query = displayquery.c_str();
            C.qstate = mysql_query(C.conn, query);

            if (!C.qstate)
            {
                system("cls");
                cout << "\t\t===============================================================================================================================" << endl;
                cout << "\t\t                                                        Events List" << endl;
                cout << "\t\t===============================================================================================================================" << endl;
                cout << "\t\t" << setw(11) << "ID" << setw(30) << "Name" << setw(20) << "Date" << setw(23) << "Time" << setw(25) << "Venue" << setw(15) << "capacity" << setw(10) << "Tutor ID" << endl;
                C.res = mysql_store_result(C.conn);
                while (C.row = mysql_fetch_row(C.res))
                {
                    cout << "\t\t " << setw(11) << C.row[0] << setw(30) << C.row[1] << setw(20) << C.row[2] << setw(23) << C.row[3] << setw(25) << C.row[4] << setw(15) << C.row[5] << setw(10) << C.row[6] << endl;

                }
            }
        }
        else {
            string displayquery = "select * from events";
            const char* query = displayquery.c_str();
            C.qstate = mysql_query(C.conn, query);

            if (!C.qstate)
            {
                system("cls");
                cout << "\t\t===============================================================================================================================" << endl;
                cout << "\t\t                                                        Events List" << endl;
                cout << "\t\t===============================================================================================================================" << endl;
                cout << "\t\t" << setw(11) << "ID" << setw(30) << "Name" << setw(20) << "Date" << setw(23) << "Time" << setw(25) << "Venue" << setw(15) << "capacity" << setw(10) << "Tutor ID" << endl;
                C.res = mysql_store_result(C.conn);
                while (C.row = mysql_fetch_row(C.res))
                {
                    cout << "\t\t " << setw(11) << C.row[0] << setw(30) << C.row[1] << setw(20) << C.row[2] << setw(23) << C.row[3] << setw(25) << C.row[4] << setw(15) << C.row[5] << setw(10) << C.row[6] << endl;

                }
            }
        }
    }
    else if (list == 4) {
        if (user == "Admin") {
            int EID;
            system("cls");
            cout << "=========================================================================================================================" << endl;
            cout << "                                                   Event list                                                               " << endl;
            cout << "=========================================================================================================================" << endl;
            string displayquery = "select events_ID, Events_Name, Events_date,events_time, Events_Venue, Events_capacity, Tutor_ID from events";
            const char* query = displayquery.c_str();
            C.qstate = mysql_query(C.conn, query);
            if (!C.qstate)
            {
                cout << setw(12) << "ID" << setw(40) << "Name" << setw(15) << "Date" << setw(20) << "Time" << setw(25) << "Venue" << setw(15) << "capacity" << setw(10) << "Tutor ID" << endl;
                C.res = mysql_store_result(C.conn);
                while (C.row = mysql_fetch_row(C.res))
                {
                    cout << setw(12) << C.row[0] << setw(40) << C.row[1] << setw(15) << C.row[2] << setw(20) << C.row[3] << setw(25) << C.row[4] << setw(15) << C.row[5] << setw(10) << C.row[6] << endl;

                }
                cout << "Select a event ID to show the attendance list or 0 to quit: ";
                cin >> EID;
                if (EID != 0) {
                    system("cls");
                    cout << "====================================================================================================================================" << endl;
                    cout << "                                                   Attendees list                                                               " << endl;
                    cout << "====================================================================================================================================" << endl;

                    string displayquery = "select events_ID, staff.staff_ID, staff.staff_name,staff.staff_tel from eventsregistration join staff on eventsregistration.staff_id = staff.staff_ID  where events_ID = " + to_string(EID) + " order by events_ID";
                    const char* query = displayquery.c_str();
                    C.qstate = mysql_query(C.conn, query);

                    if (!C.qstate)
                    {
                        cout << "\t\t" << setw(11) << "Events ID" << setw(20) << "Staff ID" << setw(25) << "Attendees" << setw(25) << "Contact numbers" << endl;
                        C.res = mysql_store_result(C.conn);
                        while (C.row = mysql_fetch_row(C.res))
                        {
                            cout << "\t\t" << setw(11) << C.row[0] << setw(22) << C.row[1] << setw(25) << C.row[2] << setw(25) << C.row[3] << endl;

                        }
                    }
                }

            }
        }
        else {
            int EID;
            system("cls");
            cout << "=========================================================================================================================" << endl;
            cout << "                                                   Event list                                                               " << endl;
            cout << "=========================================================================================================================" << endl;
            string displayquery = "select events_ID, Events_Name, Events_date, events_time,Events_Venue, Events_capacity, Tutor_ID from events where tutor_ID = " + to_string(C.userID) + " order by events_ID";
            const char* query = displayquery.c_str();
            C.qstate = mysql_query(C.conn, query);
            if (!C.qstate)
            {
                cout << setw(12) << "ID" << setw(40) << "Name" << setw(15) << "Date" << setw(23) << "Time" << setw(30) << "Venue" << setw(16) << "capacity" << setw(11) << "Tutor ID" << endl;
                C.res = mysql_store_result(C.conn);
                while (C.row = mysql_fetch_row(C.res))
                {
                    cout << setw(12) << C.row[0] << setw(40) << C.row[1] << setw(15) << C.row[2] << setw(23) << C.row[3] << setw(30) << C.row[4] << setw(16) << C.row[5] << setw(11) << C.row[6] << endl;

                }
                cout << "Select a event ID to show the attendance list: ";
                cin >> EID;
                system("cls");
                string displayquery = "select events_ID, staff.staff_ID, staff.staff_name,staff.staff_tel from eventsregistration join staff on eventsregistration.staff_id = staff.staff_ID where events_ID = " + to_string(EID) + " order by events_ID ";
                const char* query = displayquery.c_str();
                C.qstate = mysql_query(C.conn, query);

                if (!C.qstate)
                {
                    system("cls");
                    cout << "\t\t============================================================================================" << endl;
                    cout << "\t\t                                  Attendees List" << endl;
                    cout << "\t\t============================================================================================" << endl;
                    cout << "\t\t" << setw(11) << "Events ID" << setw(20) << "Staff ID" << setw(25) << "Attendees" << setw(25) << "Contact numbers" << endl;
                    C.res = mysql_store_result(C.conn);
                    while (C.row = mysql_fetch_row(C.res))
                    {
                        cout << "\t\t" << setw(11) << C.row[0] << setw(22) << C.row[1] << setw(25) << C.row[2] << setw(25) << C.row[3] << endl;

                    }
                }
            }
        }
    }
    else if (list == 2) {

        string displayquery = "select Tutor_ID, Tutor_Name,Tutor_Age, Tutor_gender, Tutor_Tel from Tutor";
        const char* query = displayquery.c_str();
        C.qstate = mysql_query(C.conn, query);

        if (!C.qstate)
        {
            system("cls");
            cout << "\t\t=============================================================================================" << endl;
            cout << "\t\t                                  Tutors List" << endl;
            cout << "\t\t=============================================================================================" << endl;
            cout << "\t\t" << setw(11) << "Tutor ID" << setw(25) << "Tutor Name" << setw(5) << "Age" << setw(10) << "Gender" << setw(25) << "Contact numbers" << endl;
            C.res = mysql_store_result(C.conn);
            while (C.row = mysql_fetch_row(C.res))
            {
                cout << "\t\t" << setw(11) << C.row[0] << setw(25) << C.row[1] << setw(5) << C.row[2] << setw(10) << C.row[3] << setw(25) << C.row[4] << endl;

            }
        }
    }
    else if (list == 3) {

        string displayquery = "select Staff_ID, Staff_Name,Staff_age,Staff_gender, Staff_Tel from Staff";
        const char* query = displayquery.c_str();
        C.qstate = mysql_query(C.conn, query);

        if (!C.qstate)
        {
            system("cls");
            cout << "\t\t===========================================================================================" << endl;
            cout << "\t\t                              Staff List" << endl;
            cout << "\t\t===========================================================================================" << endl;
            cout << "\t\t" << setw(11) << "Staff ID" << setw(25) << "Staff Name" << setw(5) << "Age" << setw(10) << "Gender" << setw(25) << "Contact numbers" << endl;
            C.res = mysql_store_result(C.conn);
            while (C.row = mysql_fetch_row(C.res))
            {
                cout << "\t\t" << setw(11) << C.row[0] << setw(25) << C.row[1] << setw(5) << C.row[2] << setw(10) << C.row[3] << setw(25) << C.row[4] << endl;

            }
        }
    }
    else if (list == 5) {
        if (user == "Admin")
            AdminMenu();
        else if (user == "Tutor")
            TutorMenu();
    }
    cout << "Enter Q to back:";
    cin >> back;
    if (back == 'Q' || back == 'q') {
        display(user);
    }

}
void eventdisplay()
{
    int search;
    system("cls");
    int reg;
    cout << "You can search the events by month (for example: 1 for january): ";
    cin >> search;
    string displayquery = "select Events_ID,events_Name,events_Date,events_time,events_venue,Events_capacity, tutor_name from events join tutor on events.tutor_ID = tutor.tutor_ID where month(events.events_Date) = " + to_string(search);
    const char* query = displayquery.c_str();
    C.qstate = mysql_query(C.conn, query);

    if (!C.qstate)
    {
        cout << "========================================================================================================================================================" << endl;
        cout << "                                                   Event list                                                               " << endl;
        cout << "========================================================================================================================================================" << endl;
        cout << setw(11) << "Event ID" << setw(30) << "Name" << setw(15) << "Date" << setw(23) << "Time" << setw(30) << "Venue" << setw(15) << "Capacity" << setw(25) << "Tutor Name" << endl;
        C.res = mysql_store_result(C.conn);
        while (C.row = mysql_fetch_row(C.res))
        {
            cout << setw(11) << C.row[0] << setw(30) << C.row[1] << setw(15) << C.row[2] << setw(23) << C.row[3] << setw(30) << C.row[4] << setw(15) << C.row[5] << setw(25) << C.row[6] << endl;
        }
    }
    cout << "\nEnter event ID to register or '0' to back to Staff Menu:";
    cin >> reg;

    if (reg == 0)
    {
        StaffMenu();
    }
    else {
        string check_query = "SELECT * FROM eventsregistration WHERE events_ID = " + to_string(reg) + " AND Staff_ID = " + to_string(C.userID);
        const char* check_query_cstr = check_query.c_str();
        C.qstate = mysql_query(C.conn, check_query_cstr);
        if (C.qstate == 0)
        {
            C.res = mysql_store_result(C.conn);
            if (C.res != nullptr && mysql_num_rows(C.res) > 0)
            {
                cin.ignore();
                cout << "\n\nYou are already registered for this event. Please choose another event.\n";
                cout << "\nPress enter to select another event." << endl;
                cin.get();
                eventdisplay();
                return;
            }
        }
        else
        {

            cout << "The event ID is not exist. Please select again" << endl;
            system("pause");
            eventdisplay();

        }
        int querystate = 0;
        int capacity;
        string add_query = "INSERT INTO eventsregistration (events_ID, Staff_ID) VALUES (" + to_string(reg) + "," + to_string(C.userID) + ")";
        const char* insert_query = add_query.c_str();

        querystate = mysql_query(C.conn, insert_query);
        if (querystate == 0)
        {
            cout << "Record Inserted.\n";
            system("pause");
            C.qstate = mysql_query(C.conn, ("select Events_capacity from events where events_ID= " + to_string(reg)).c_str());
            if (!C.qstate) {
                C.res = mysql_store_result(C.conn);
                if (C.row = mysql_fetch_row(C.res)) {

                    capacity = stod(C.row[0]) - 1;
                    C.qstate = mysql_query(C.conn, ("UPDATE events SET events_capacity = " + to_string(capacity) + " WHERE events_ID = " + to_string(reg)).c_str());
                }
            }
            system("cls");
            string displayquery = "select * from events";
            const char* query = displayquery.c_str();
            C.qstate = mysql_query(C.conn, query);

            if (!C.qstate)
            {
                cout << "=====================================================================================================================================" << endl;
                cout << "                                                   Event list                                                               " << endl;
                cout << "=====================================================================================================================================" << endl;
                cout << setw(11) << "Event ID" << setw(30) << "Name" << setw(15) << "Date" << setw(23) << "Time" << setw(30) << "Venue" << setw(15) << "capacity" << setw(25) << "Tutor ID" << endl;
                C.res = mysql_store_result(C.conn);
                while (C.row = mysql_fetch_row(C.res))
                {
                    cout << setw(11) << C.row[0] << setw(30) << C.row[1] << setw(15) << C.row[2] << setw(23) << C.row[3] << setw(30) << C.row[4] << setw(15) << C.row[5] << setw(25) << C.row[6] << endl;
                }
            }
            cout << "\nDo you want to register for another event? (Y/N): ";
            char choice;
            cin >> choice;

            if (choice == 'Y' || choice == 'y')
            {

                eventdisplay();
            }
            else
            {
                // Return to the EmployeeMenu 
                StaffMenu();
            }
        }
        else
        {
            cout << "Query Execution Problem: " << mysql_error(C.conn) << endl;

        }
    }

}
void tutorrecord() {
    int select;
    system("cls");
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|                              Tutor record                                      | \n";
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|1.Update                                                                        |" << endl;
    cout << "\t\t|2.Back to Tutor Menu                                                            |" << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\tYour choice: ";
    cin >> select;
    cout << "-----------------------------------------" << endl;
    if (select == 1) {
        char conti = C.UpdateData("Tutor", "Tutor");
        if (conti == 'Y' || conti == 'y') {
            conti = C.UpdateData("Tutor", "Tutor");
        }
        else if (conti == 'N' || conti == 'n') {
            tutorrecord();
        }
        else {
            cout << "Please insert yes(y) or no(n) only..... ";
            cin >> conti;
        }
    }
    else if (select == 2) {
        TutorMenu();
    }
    else
    {
        cout << "Please select 1 or 2";
        system("pause");
        tutorrecord();
    }
}
void eventrecord(string user) {

    do {
        double eventID;
        string Name, Date, Venue, capacity, ID, time;
        char conti;
        int choice;
        system("cls");

        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|                                Event record                                    | \n";
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|1.Add                                                                           |" << endl;
        cout << "\t\t|2.Delete                                                                        |" << endl;
        cout << "\t\t|3.Update                                                                        |" << endl;
        cout << "\t\t|4.Back                                                                          |" << endl;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\tYour choice: ";
        cin >> choice;
        if (choice == 1) {
            do {
                system("cls");
                cout << "\t\t=================================================================================" << endl;
                cout << "\t\t|                                Add Event                                       | \n";
                cout << "\t\t=================================================================================" << endl;
                cout << "\nPlease write down the information of event that you want to add:" << endl;
                cin.ignore();
                cout << "1.Event Name:";
                getline(cin, Name);
                cout << "\n2.Event Date(ex:01/01/2024):";
                getline(cin, Date);
                cout << "\n3.Event Time:";
                getline(cin, time);
                cout << "\n4.Event Venue:";
                getline(cin, Venue);
                cout << "\n5.Event capacity:";
                getline(cin, capacity);
                if (user == "Admin") {
                    cout << "\n4.Event tutor ID:";
                    getline(cin, ID);
                }
                cout << "\nThe information are correct? (y/n):";
                cin >> conti;
                cin.ignore(256, '\n');
                if (conti == 'y' || conti == 'Y')
                {
                    string checkID_query = "SELECT MAX(events_ID) FROM events";
                    const char* squery = checkID_query.c_str();
                    C.qstate = mysql_query(C.conn, squery);
                    if (!C.qstate)
                    {
                        C.res = mysql_store_result(C.conn);
                        if (C.row = mysql_fetch_row(C.res))
                        {
                            eventID = stod(C.row[0]);
                            string resetID_query = "ALTER TABLE events AUTO_INCREMENT = " + to_string(eventID + 1);
                            const char* IDquery = resetID_query.c_str();
                            C.qstate = mysql_query(C.conn, IDquery);

                            if (!C.qstate) {
                                int querystate = 0;
                                string add_query;
                                if (user == "Admin")
                                {
                                    add_query = "INSERT INTO events (events_Name, events_date,events_time, events_Venue, events_capacity, tutor_Id) VALUES ('" + Name + "', STR_TO_DATE('" + Date + "', '%d/%m/%Y'), '" + time + "','" + Venue + "',' " + capacity + "', " + ID + ")";
                                    const char* query = add_query.c_str();
                                    querystate = mysql_query(C.conn, query);
                                }
                                else if (user == "Tutor") {
                                    add_query = "INSERT INTO events (events_Name, events_date,events_time, events_Venue, events_capacity, tutor_Id) VALUES ('" + Name + "', STR_TO_DATE('" + Date + "', '%d/%m/%Y'), '" + time + "','" + Venue + "', '" + capacity + "', " + to_string(C.userID) + ")";
                                    const char* query = add_query.c_str();
                                    querystate = mysql_query(C.conn, query);
                                }
                                if (querystate == 0)
                                {
                                    cout << "Record Inserted" << endl;
                                    cin.get();
                                    eventrecord(user);
                                }
                                else
                                {
                                    cout << "Error" << endl;
                                }
                            }
                        }
                    }
                }
                else
                {
                    cout << "Enter T to try again or Q to back to " + user + " Menu" << endl;
                    cin >> conti;
                }
            } while (conti == 't' || conti == 'T');
            if (user == "Tutor") {
                TutorMenu();
            }
            else if (user == "Admin") {
                AdminMenu();
            }
        }
        else if (choice == 2)
        {
            string object = "event";
            char cont;
            if (user == "Admin") {
                do {

                    char back = C.deleteData(object);
                    if (back == 'Q' || back == 'q')
                    {
                        record(object);
                    }
                    else if (back == 'T' || back == 't')
                    {
                        back = C.deleteData(object);
                    }

                    cout << "\n\nDo you want to delete other " + object + "? (Y/N):";
                    cin >> cont;
                } while (cont == 'y' || cont == 'Y');
                system("cls");
                cout << "Returning back to " + object + " record menu....";
                record(object);
            }
            else if (user == "Tutor")
            {
                cout << "You are not able to delete event, please refer to admin to delete the events." << endl;
                system("pause");
                /*char del = 'y', cont = 'y', back = 'y';
                do {

                    system("cls");
                    string display_query = "select * from events where Tutor_ID =" + to_string(C.userID);
                    const char* query = display_query.c_str();

                    C.qstate = mysql_query(C.conn, query);

                    if (!C.qstate)
                    {
                        cout << "======================================================================================================================" << endl;
                        cout << "                                                   Event list                                                               " << endl;
                        cout << "======================================================================================================================" << endl;
                        cout << setw(11) << "Event ID" << setw(30) << "Name" << setw(20) << "Date" << setw(23) << "Time" << setw(25) << "Venue" << setw(10) << "capacity" << setw(15) << "Tutor ID" << endl;
                        C.res = mysql_store_result(C.conn);
                        while (C.row = mysql_fetch_row(C.res))
                        {
                            cout << setw(11) << C.row[0] << setw(30) << C.row[1] << setw(20) << C.row[2] << setw(23) << C.row[3] << setw(25) << C.row[4] << setw(10) << C.row[5] << setw(15) << C.row[6] << endl;
                        }
                    }
                    else
                    {
                        cout << "Query execution failed. Error: " << mysql_error(C.conn) << endl;
                    }
                    cout << "\nInsert the event ID to delete the event information or enter Q to back to Tutor Menu: ";
                    cin >> ID;
                    if (ID.empty()) {
                        cout << "\nInvalid event ID. Please enter a valid ID." << endl;
                        cin >> ID;
                    }
                    else if (ID == "q" || ID == "Q") {
                        back = 'n';
                        break;

                    }
                    cout << "\nAre you sure you want to delete? (Y/N):";
                    cin >> del;
                    if (del == 'y' || del == 'Y')
                    {

                        string deletequery = "Delete from events where events_ID=" + ID;
                        const char* query = deletequery.c_str();
                        C.qstate = mysql_query(C.conn, query);
                        if (!C.qstate) {
                            cout << "\n\nData delete successfully.....\n";
                            cout << "\n\nDo you want to delete other event ? (Y/N):";
                            cin >> back;
                        }
                        else {
                            cout << "This event has been registered by staff. It cannot be deleted." << endl;
                            cout << "\nDo you want to try again? (Y/N): ";
                            cin >> back;
                        }
                    }
                    else {
                        cout << "\nDo you want to try again? (Y/N): ";
                        cin >> back;

                    }
                } while (back == 'Y' || back == 'y');
                if (back == 'N' || back == 'n')
                    TutorMenu();
    */
            }

            TutorMenu();


        }

        else if (choice == 3)
        {
            char terus = 'y';
            if (user == "Admin") {
                user = "event";
                do {

                    terus = C.UpdateData("Admin", user);

                } while (terus == 'y' || terus == 'Y');
                if (terus == 'N' || terus == 'n')
                    record(user);
                else {
                    cout << "Please insert yes(y) or no(n) only..... ";
                    cin >> terus;
                    if (terus == 'Y' || terus == 'y') {
                        C.UpdateData("Admin", user);
                    }
                    else if (terus == 'N' || terus == 'n') {
                        record(user);
                    }
                }
            }
            else if (user == "Tutor")
            {
                char del = 'y', cont = 'y', back = 'y';
                int check;
                do {

                    system("cls");
                    string display_query = "select * from events where Tutor_ID =" + to_string(C.userID);
                    const char* query = display_query.c_str();

                    C.qstate = mysql_query(C.conn, query);

                    if (!C.qstate)
                    {
                        cout << "=========================================================================================================================" << endl;
                        cout << "                                                   Event list                                                               " << endl;
                        cout << "=========================================================================================================================" << endl;
                        cout << setw(11) << "Event ID" << setw(30) << "Name" << setw(20) << "Date" << setw(23) << "Time" << setw(25) << "Venue" << setw(10) << "capacity" << setw(10) << "Tutor Id " << endl;
                        C.res = mysql_store_result(C.conn);
                        while (C.row = mysql_fetch_row(C.res))
                        {
                            cout << setw(11) << C.row[0] << setw(30) << C.row[1] << setw(20) << C.row[2] << setw(23) << C.row[3] << setw(25) << C.row[4] << setw(10) << C.row[5] << setw(10) << C.row[6] << endl;
                        }
                    }
                    else
                    {
                        cout << "Query execution failed. Error: " << mysql_error(C.conn) << endl;
                    }
                    cout << "\nInsert the event ID to update the event information or Q to back to Tutor Menu:";
                    cin >> ID;
                    if (ID.empty()) {
                        cout << "\nInvalid event ID. Please enter a valid ID." << endl;
                        cin >> ID;
                    }
                    else if (ID == "Q" || ID == "q") {
                        back = 'q';
                        break;
                    }
                    cout << "\n--------------------------------------";
                    cout << "\n1.Name                              \n";
                    cout << "\n2.Date                               \n ";
                    cout << "\n3.Time                               \n ";
                    cout << "\n4.Venue                              \n ";
                    cout << "\n5.capacity                           \n ";
                    cout << "\n--------------------------------------";
                    cout << "\nChoose the information that you want to update:";
                    cin >> check;
                    if (check == 1)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\nName:";
                        cin.ignore();
                        getline(cin, Name);
                        string updatequery = "update events set events_Name = '" + Name + "' where events_ID = '" + ID + "'";
                        const char* query = updatequery.c_str();
                        C.qstate = mysql_query(C.conn, query);

                    }
                    else if (check == 2)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\nDate:";
                        cin.ignore();
                        getline(cin, Date);
                        string updatequery = "update events set Events_Date = '" + Date + "' where events_ID = '" + ID + "'";
                        const char* query = updatequery.c_str();
                        C.qstate = mysql_query(C.conn, query);

                    }
                    else if (check == 3)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\nTime:";
                        cin.ignore();
                        getline(cin, time);
                        string updatequery = "update events set Events_time = '" + time + "' where events_ID = '" + ID + "'";
                        const char* query = updatequery.c_str();
                        C.qstate = mysql_query(C.conn, query);

                    }

                    else if (check == 4)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\nVenue:";
                        cin.ignore();
                        getline(cin, Venue);
                        string updatequery = "update events set Events_Venue = '" + Venue + "' where events_ID = '" + ID + "'";
                        const char* query = updatequery.c_str();
                        C.qstate = mysql_query(C.conn, query);

                    }
                    else if (check == 5)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\ncapacity:";
                        cin.ignore();
                        getline(cin, capacity);
                        string updatequery = "update events set Events_capacity = '" + capacity + "' where events_ID = '" + ID + "'";
                        const char* query = updatequery.c_str();
                        C.qstate = mysql_query(C.conn, query);

                    }

                    cout << "\nPlease enter C to continue update or enter Q to back to tutor menu:";
                    cin >> back;
                } while (back == 'C' || back == 'c');
                if (back == 'Q' || back == 'q')
                    TutorMenu();
            }
            TutorMenu();
        }

        else if (choice == 4)
        {
            if (user == "Tutor") {
                TutorMenu();
            }
            else if (user == "Admin")
            {
                AdminMenu();

            }
        }
        else
        {
            cout << "Please select 1-3" << endl;
            system("pause");
            error = 'c';
        }
    } while (error == 'c');
}

void Staffrecord() {
    int select;
    do {
        system("cls");
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|                          Staff Information Record                              |" << endl;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|1.Update                                                                        |" << endl;
        cout << "\t\t|2.Back to Staff Menu                                                            |" << endl;
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\tYour choice : ";
        cin >> select;
        cout << "-----------------------------------------" << endl;
        if (select == 1) {
            char conti;
            do {
                conti = C.UpdateData("Staff", "Staff");

                if (conti == 'N' || conti == 'n')
                {
                    Staffrecord();
                }
                else {
                    cout << "Please insert yes(y) or no(n) only..... ";
                    cin >> conti;
                }
            } while (conti == 'Y' || conti == 'y');
        }
        else if (select == 2) {
            StaffMenu();
        }
        else
        {
            cout << "Please select 1 or 2" << endl;
            system("pause");
            error = 'c';
        }
    } while (error == 'c');
}
void report()
{
    int pilihan;
    do {
        system("cls");

        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t|                                   Report                                       |" << endl;
        cout << "\t\t=================================================================================" << endl;
        cout << "\n\t\t1.Attendance List\n\t\t2.Monthly percentage of attendance\n\t\t3.Back";
        cout << "\nSelect a list to save the report:";
        cin >> pilihan;
        if (pilihan == 1)
        {
            int EID;
            system("cls");
            cout << "=========================================================================================================================" << endl;
            cout << "                                                   Event list                                                               " << endl;
            cout << "=========================================================================================================================" << endl;
            string displayquery = "select events_ID, Events_Name, Events_date,events_time, Events_Venue, Events_capacity, Tutor_ID from events";
            const char* query = displayquery.c_str();
            C.qstate = mysql_query(C.conn, query);
            if (!C.qstate)
            {
                cout << setw(12) << "ID" << setw(40) << "Name" << setw(15) << "Date" << setw(23) << "Time" << setw(20) << "Venue" << setw(16) << "capacity" << setw(11) << "Tutor ID" << endl;
                C.res = mysql_store_result(C.conn);
                while (C.row = mysql_fetch_row(C.res))
                {
                    cout << setw(12) << C.row[0] << setw(40) << C.row[1] << setw(15) << C.row[2] << setw(23) << C.row[3] << setw(20) << C.row[4] << setw(16) << C.row[5] << setw(11) << C.row[6] << endl;

                }
                cout << "To generate your attendance list file, enter the event ID: ";
                cin >> EID;
                ofstream file("Attendance_List.txt");
                file << "=========================================================================================================================" << endl;
                file << "                                                   Attendance list                                                               " << endl;
                file << "=========================================================================================================================" << endl;
                string displayquery = "select events_ID, Events_Name, Events_date, Events_Venue, Tutor_Name from events join tutor on events.Tutor_ID = tutor.tutor_ID where events_ID = " + to_string(EID);
                const char* query = displayquery.c_str();
                C.qstate = mysql_query(C.conn, query);
                if (!C.qstate)
                {
                    C.res = mysql_store_result(C.conn);
                    while (C.row = mysql_fetch_row(C.res))
                    {
                        file << "Event Name: " << C.row[1] << endl;
                        file << "Event Date: " << C.row[2] << endl;
                        file << "Event Venue: " << C.row[3] << endl;
                        file << "Tutor Name: " << C.row[4] << endl;

                    }
                }
                else {
                    cout << "The event ID does not exist.Try again";
                    system("pause");
                    report();
                }
                string Aquery = "select staff.staff_ID, staff.staff_name,staff.staff_tel, e.attendance from eventsregistration e join staff on e.staff_id = staff.staff_ID where e.events_ID =" + to_string(EID) + " order by staff_ID";
                const char* aquery = Aquery.c_str();
                C.qstate = mysql_query(C.conn, aquery);
                file << "=========================================================================================================================" << endl;
                if (!C.qstate)
                {
                    file << setw(11) << "Staff ID" << setw(50) << "Staff Name" << setw(30) << "Contact numbers" << setw(30) << "Attendance" << endl;
                    C.res = mysql_store_result(C.conn);
                    while (C.row = mysql_fetch_row(C.res))
                    {
                        file << setw(11) << C.row[0] << setw(50) << C.row[1] << setw(30) << C.row[2] << setw(30) << C.row[3] << endl;

                    }
                }

                cout << "\nReport generated successfully." << endl;
                system("pause");
                file.close();
                report();
            }
            else
            {
                cout << "Error executing the query: " << mysql_error(C.conn) << endl;
            }
        }
        else if (pilihan == 2)
        {
            ofstream file("Monthly_percentage_of_attendance.txt");
            int month = 1;

            file << "=========================================================================================================================" << endl;
            file << "                                           Monthly percentage of attendance                                                     " << endl;
            file << "=========================================================================================================================" << endl;

            file << setw(10) << "Month" << setw(25) << "Total organized events" << setw(25) << "Overall capacity" << setw(25) << "Numbers of attendees" << setw(25) << "Percentage of attendance" << endl;
            do
            {
                double TotalCapacity = C.Mtotal_capacity(to_string(month));
                double Totalevent = C.total_eventPM(to_string(month));
                double TotalAttend = C.total_attend(to_string(month));
                double ave = (TotalAttend / TotalCapacity) * 100;
                if (isnan(ave)) {
                    ave = 0;
                }
                ostringstream tempStream;
                tempStream << fixed << setprecision(2) << ave;
                file << setw(5) << month << setw(25) << Totalevent << setw(25) << TotalCapacity << setw(25) << TotalAttend << setw(20) << tempStream.str() << endl;
                month++;
            } while (month != 13);
            cout << "Report generated successfully." << endl;
            system("pause");
            file.close();
            report();

        }
        else if (pilihan == 3)
        {
            AdminMenu();
        }
        else {
            cout << "Please enter only 1 or 2.";
            system("pause");
            error = 'c';
        }
    } while (error == 'c');
}