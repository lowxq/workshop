#include<iostream>
#include<iomanip>
#include<string>
#include<mysql.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;
#include"workshop.h"
string key = "123";
int querystate;
double currentID;

int  myclass::Register(string user)
{
    int alphaCount = 0, numCount = 0;
    string checkkey;
    system("cls");
    cin.ignore();
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t                            Welcome " + user + "                                " << endl;
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\tPlease insert following information to register: " << endl;
    cout << "\t\t1.Name         : ";
    getline(cin, Name);

    cout << "\t\t2.Age          : ";
    getline(cin, age);

    cout << "\t\t3.Gender       : ";
    getline(cin, gender);

    cout << "\t\t4.Contact numbers : ";
    getline(cin, Tel);
    cout << "\t\t5.Password (Your password should contain letter and number) : ";
    getline(cin, Password);
    const char* passwordArray = Password.c_str();
    for (int i = 0; i < Password.length(); i++)
    {
        if (isalpha(passwordArray[i]))
        {
            ++alphaCount;
        }
        else if (isdigit(passwordArray[i])) {
            ++numCount;
        }
    }
    while (alphaCount >= 1 && numCount >= 1) {
        if (user == "Admin") {
            cout << "\t\tEnter the secret key:";
            cin >> checkkey;
            cin.ignore(1, '\n');
            if (checkkey == key) {
                string checkID_query = "SELECT MAX(" + user + "_ID) FROM " + user;
                const char* squery = checkID_query.c_str();
                qstate = mysql_query(conn, squery);
                if (!qstate)
                {
                    res = mysql_store_result(conn);
                    if (row = mysql_fetch_row(res))
                    {
                        currentID = stod(row[0]);
                        string resetID_query = "ALTER TABLE Admin AUTO_INCREMENT = " + to_string(currentID + 1);

                        const char* IDquery = resetID_query.c_str();
                        querystate = mysql_query(conn, IDquery);
                        userID = currentID + 1;
                        if (!querystate) {
                            string insertdata_query = "insert into " + user + " (" + user + "_name," + user + "_age," + user + "_gender, " + user + "_Tel, " + user + "_Password) values ('" + Name + "', '" + age + "','" + gender + "','" + Tel + "', '" + Password + "')";
                            const char* query = insertdata_query.c_str();
                            querystate = mysql_query(conn, query);
                            cout << "\t\t=================================================================================" << endl;
                            cout << "\t\t                              Your ID number is " << userID << endl;
                            cout << "\t\t=================================================================================" << endl;
                            cout << "Press Enter To Continue to " + user + " Menu..." << endl;
                            cin.get();
                        }
                    }
                }
                else { cout << "Error in fetching latest ID" << mysql_errno(conn) << endl; }

                return querystate;
            }
            else {
                return qstate = 5;
            }
        }
        else {

            string countQuery = "SELECT COUNT(*) FROM " + user;
            const char* countQueryStr = countQuery.c_str();
            if (mysql_query(conn, countQueryStr) == 0)
            {
                res = mysql_store_result(conn);

                if (res)
                {
                    row = mysql_fetch_row(res);

                    if (row)
                    {
                        int rowCount = stoi(row[0]);
                        if (rowCount == 0) {
                            string resetID_query = "ALTER TABLE " + user + " AUTO_INCREMENT = 200";
                            const char* IDquery = resetID_query.c_str();
                            querystate = mysql_query(conn, IDquery);
                            if (!querystate) {
                                string insertdata_query = "insert into " + user + " (" + user + "_name," + user + "_age," + user + "_gender, " + user + "_Tel, " + user + "_Password) values ('" + Name + "', '" + age + "','" + gender + "','" + Tel + "', '" + Password + "')";
                                const char* query = insertdata_query.c_str();
                                querystate = mysql_query(conn, query);
                                cout << "\t\t=================================================================================" << endl;
                                cout << "\t\t                             Your ID number is 200" << endl;
                                cout << "\t\t=================================================================================" << endl;
                                cout << "You have been registered. Press Enter To Continue to " + user + " Menu..." << endl;

                            }

                        }
                        else
                        {
                            string checkID_query = "SELECT MAX(" + user + "_ID) FROM " + user;
                            const char* squery = checkID_query.c_str();
                            qstate = mysql_query(conn, squery);
                            res = mysql_store_result(conn);
                            if (row = mysql_fetch_row(res))
                            {
                                currentID = stod(row[0]);
                                string resetID_query = "ALTER TABLE " + user + " AUTO_INCREMENT = " + to_string(currentID + 1);
                                const char* IDquery = resetID_query.c_str();
                                querystate = mysql_query(conn, IDquery);
                                userID = currentID + 1;
                                if (!querystate)
                                {
                                    string insertdata_query = "insert into " + user + " (" + user + "_name," + user + "_age," + user + "_gender, " + user + "_Tel, " + user + "_Password) values ('" + Name + "', '" + age + "','" + gender + "','" + Tel + "', '" + Password + "')";
                                    const char* query = insertdata_query.c_str();
                                    querystate = mysql_query(conn, query);
                                    cout << "\t\t================================================================================= " << endl;
                                    cout << "\t\t                        Your ID number is " << userID << endl;
                                    cout << "\t\t=================================================================================" << endl;
                                    cout << "\nPress Enter To Continue to " + user + " Menu..." << endl;
                                    cin.get();
                                }
                            }
                        }
                    }
                    else {
                        cout << "Error: Unable to fetch the result." << endl;
                    }
                }
                else {
                    cout << "Error: Unable to store the result." << endl;
                }
            }
            else {
                cout << "Error in executing the query: " << mysql_error(conn) << endl;
                cout << "Error number: " << mysql_errno(conn) << endl;
            }

            return querystate;
        }
    }
    cout << "Please enter at least 1 number and 1 letter as your password. Please Try Again. " << endl;
    system("pause");
    return 8;

}
int myclass::login(string user)
{

    system("cls");
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t                               Welcome " + user + "                                  " << endl;
    cout << "\t\t=================================================================================" << endl;
    cin.ignore(1, '\n');
    cout << "\t\tPlease insert following information to login:" << endl << endl;
    cout << "\t\tYour Name: ";
    getline(cin, Name);
    cout << "\n\t\tYour Password: ";
    getline(cin, Password);
    string ID_query = "SELECT " + user + "_ID FROM " + user + " where " + user + "_name = '" + Name + "' and " + user + "_password = '" + Password + "'";
    const char* squery = ID_query.c_str();
    querystate = mysql_query(conn, squery);
    if (!querystate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            userID = stod(row[0]);
            cout << "\t\t=================================================================================" << endl;
            cout << "\t\t                                 Your ID is " << userID << endl;
            cout << "\t\t=================================================================================" << endl;
            string checkadmin_query = "select " + user + "_ID from " + user + " where " + user + "_name = '" + Name + "' and " + user + "_password = '" + Password + "'";
            const char* cu = checkadmin_query.c_str();
            qstate = mysql_query(conn, cu);
            cout << "Press enter to continue....";
            cin.get();
            return qstate;
        }

    }
}
char myclass::add(string user)
{
    char add = 'y';
    int numCount = 0, alphaCount = 0;
    system("cls");
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t            Please fill in the information to add " + user + "..." << endl;
    cout << "\t\t=================================================================================" << endl;
    cin.ignore();
    cout << "\t\t1.Name         : ";
    getline(cin, Name);

    cout << "\t\t2.Age          : ";
    getline(cin, age);

    cout << "\t\t3.Gender       : ";
    getline(cin, gender);

    cout << "\t\t4.Contact numbers : ";
    getline(cin, Tel);
    cout << "\t\t5.Password (Your password should contain letter and number) : ";
    getline(cin, Password);
    const char* passwordArray = Password.c_str();
    for (int i = 0; i < Password.length(); i++)
    {
        if (isalpha(passwordArray[i]))
        {
            ++alphaCount;
        }
        else if (isdigit(passwordArray[i])) {
            ++numCount;
        }
    }
    while (alphaCount >= 1 && numCount >= 1) {
        int qstate = 0;
        string add_query;
        add_query = "insert into " + user + " (" + user + "_name," + user + "_age," + user + "_gender, " + user + "_Tel, " + user + "_Password) values ('" + Name + "', '" + age + "','" + gender + "','" + Tel + "', '" + Password + "')";

        const char* query = add_query.c_str();
        qstate = mysql_query(conn, query);
        if (qstate == 0)
        {
            cout << "\nRecord Inserted" << endl;
        }
        else
        {
            cout << "failed" << endl;
            cout << "Error executing the query: " << mysql_error(conn) << endl;
        }
        cout << "============================================================" << endl;
        cout << "Do you want to continue add " + user + "(Y/N):" << endl;
        cin >> add;
        return add;
    }
    cout << "Invalid password. Please enter at least 1 letter and 1 number. " << endl;
    system("pause");
    add = 'y';
    return add;
}


char myclass::deleteData(string user)
{
    char del = 'y', cont = 'y', back = 'y';
    if (user == "Tutor" || user == "Staff")
    {
        system("cls");
        cout << "\t\t=================================================================================" << endl;
        cout << "\t\t                            " + user + "s List                                       " << endl;
        cout << "\t\t=================================================================================" << endl;
        string delete_query = "select " + user + "_id," + user + "_name, " + user + "_age," + user + "_gender," + user + "_tel from " + user;
        const char* query = delete_query.c_str();
        qstate = mysql_query(conn, query);

        if (!qstate)
        {
            cout << "\t\t " << setw(5) << "ID" << setw(40) << "Name" << setw(5) << "Age" << setw(10) << "Gender" << setw(30) << "Contact numbers" << endl;

            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << "\t\t " << setw(5) << row[0] << setw(40) << row[1] << setw(5) << row[2] << setw(10) << row[3] << setw(30) << row[4] << endl;
            }
        }

        cout << "\nInsert the " + user + " ID to delete his/her information:";
        cin >> ID;
        if (ID.empty()) {
            cout << "\nInvalid " + user + " ID. Please enter a valid ID." << endl;
            cin >> ID;
        }
        cout << "\nAre you sure you want to delete? (Y/N):";
        cin >> del;
        if (del == 'y' || del == 'Y')
        {

            string deletequery = "Delete from " + user + " where " + user + "_ID='" + ID + "'";
            const char* query = deletequery.c_str();
            qstate = mysql_query(conn, query);
            if (!qstate) {
                cout << user + " data delete successfully.....\n";
                system("pause");
            }
            else {
                cout << "This " + user + " has register a event. He/she informations cannot be delete.";
            }
        }
        else {
            cout << "\nPlease enter T to try again or enter Q to back to " + user + " record menu:";
            cin >> back;

        }
    }
    else if (user == "event")
    {
        system("cls");
        string delete_query = "select * from events";
        const char* query = delete_query.c_str();
        qstate = mysql_query(conn, query);

        if (!qstate)
        {
            cout << "\t\t===============================================================================================================================" << endl;
            cout << "\t\t                                                        Events List" << endl;
            cout << "\t\t===============================================================================================================================" << endl;
            cout << setw(11) << "Event ID" << setw(30) << "Name" << setw(20) << "Date" << setw(23) << "Time" << setw(25) << "Venue" << setw(10) << "capacity" << setw(5) << "Tutor ID" << endl;
            res = mysql_store_result(conn);
            while (row = mysql_fetch_row(res))
            {
                cout << setw(11) << row[0] << setw(30) << row[1] << setw(20) << row[2] << setw(23) << row[3] << setw(25) << row[4] << setw(10) << row[5] << setw(5) << row[6] << endl;
            }
        }
        cout << "\nInsert the " + user + " ID to delete the event information:";
        cin >> ID;
        if (ID.empty()) {
            cout << "\nInvalid " + user + " ID. Please enter a valid ID." << endl;
            cin >> ID;
        }
        cout << "\nAre you sure you want to delete? (Y/N):";
        cin >> del;
        if (del == 'y' || del == 'Y')
        {

            string deletequery = "Delete from events where events_ID='" + ID + "'";
            const char* query = deletequery.c_str();
            qstate = mysql_query(conn, query);
            if (!qstate) {
                cout << "\n\nEvent delete successfully.....\n";
                system("pause");
            }
            else {
                cout << "This event has been registered by staff. It cannot be deleted.";
                back = 'T';
            }
        }
        else {
            cout << "\nPlease enter T to try again or enter Q to back to " + user + " record menu:";
            cin >> back;

        }
    }
    return back;
}

char myclass::UpdateData(string user, string object)
{
    system("cls");
    cout << "\t\t=================================================================================" << endl;
    cout << "\t\t|                        Update " + object + " information                       |" << endl;
    cout << "\t\t=================================================================================" << endl;
    do {
        if (user == "Admin") {
            if (object == "event") {
                string  EID;
                system("cls");
                string displayquery = "select * from events";
                const char* query = displayquery.c_str();
                qstate = mysql_query(conn, query);

                if (!qstate)
                {
                    cout << "\t\t===============================================================================================================================" << endl;
                    cout << "\t\t                                                        Events List" << endl;
                    cout << "\t\t===============================================================================================================================" << endl;
                    cout << "\t\t " << setw(12) << "ID" << setw(30) << "Name" << setw(20) << "Date" << setw(23) << "Time" << setw(25) << "Venue" << setw(10) << "capacity" << setw(5) << "Tutor ID" << endl;
                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        cout << "\t\t " << setw(12) << row[0] << setw(30) << row[1] << setw(20) << row[2] << setw(23) << row[3] << setw(25) << row[4] << setw(10) << row[5] << setw(5) << row[6] << endl;
                    }
                    cout << "Select the event Id that you wish to update:";
                    cin >> EID;
                    cout << "\t\t=================================================================================" << endl;
                    cout << "\t\t1.Name                              \n";
                    cout << "\t\t2.Date                               \n ";
                    cout << "\t\t3.Venue                              \n ";
                    cout << "\t\t4.capacity                           \n ";
                    cout << "\t\t5.Tutor ID                           \n ";
                    cout << "\t\t=================================================================================" << endl;
                    cout << "\nChoose the information that you want to update:";
                    cin >> check;
                    if (check == 1)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\nName:";
                        cin.ignore();
                        getline(cin, Name);
                        string updatequery = "update events set events_Name = '" + Name + "' where events_ID = '" + EID + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 2)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\nDate:";
                        cin.ignore();
                        getline(cin, Date);
                        string updatequery = "update events set Events_Date = '" + Date + "' where events_ID = '" + EID + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 3)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\nVenue:";
                        cin.ignore();
                        getline(cin, Venue);
                        string updatequery = "update events set Events_Venue = '" + Venue + "' where events_ID = '" + EID + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 4)
                    {
                        cout << "\nInsert the new information.";
                        cout << "\ncapacity:";
                        cin.ignore();
                        getline(cin, capacity);
                        string updatequery = "update events set Events_capacity = '" + capacity + "' where events_ID = '" + EID + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 5)
                    {
                        string TID;
                        cout << "\nInsert the new information.";
                        cout << "\n Tutor ID:";
                        cin.ignore();
                        getline(cin, TID);
                        string updatequery = "update events set Tutor_ID = '" + TID + "' where events_ID = '" + EID + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }

                }
                else { cout << "Error in executing query. Error: " << mysql_error(conn) << endl; }
            }
            else {
                string updatequery = "select " + object + "_id," + object + "_name, " + object + "_Age," + object + "_gender," + object + "_tel from " + object;
                const char* query = updatequery.c_str();
                qstate = mysql_query(conn, query);

                if (!qstate)
                {
                    system("cls");
                    cout << "\t\t===============================================================================================================================" << endl;
                    cout << "\t\t                                                        " + object + " List" << endl;
                    cout << "\t\t===============================================================================================================================" << endl;
                    cout << "\t\t " << setw(5) << "ID" << setw(40) << "Name" << setw(5) << "Age" << setw(10) << "Gender" << setw(30) << "Contact numbers" << endl;

                    res = mysql_store_result(conn);
                    while (row = mysql_fetch_row(res))
                    {
                        cout << "\t\t " << setw(5) << row[0] << setw(40) << row[1] << setw(5) << row[2] << setw(10) << row[3] << setw(30) << row[4] << endl;
                    }
                }
                cout << "\n\nPlease select the " + object + "ID that you want to update his/her information\n";
                cin >> ID;
                cout << "\n1.Name\n2.Age\n3.Gender\n4.Contact numbers ";
                cout << "\nChoose the information that you want to update:";
                cin >> check;
                if (check == 1)
                {
                    cout << "Name:";
                    cin.ignore();
                    getline(cin, Name);
                    string updatequery = "update " + object + " set " + object + "_Name = '" + Name + "' where " + object + "_ID = '" + ID + "'";
                    const char* query = updatequery.c_str();
                    qstate = mysql_query(conn, query);

                }
                else if (check == 4)
                {
                    cout << "Contact numbers:";
                    cin.ignore();
                    getline(cin, Tel);
                    string updatequery = "update " + object + " set " + object + "_Tel = '" + Tel + "' where " + object + "_ID = '" + ID + "'";
                    const char* query = updatequery.c_str();
                    qstate = mysql_query(conn, query);

                }
                else if (check == 2)
                {
                    cout << "Age:";
                    cin.ignore();
                    getline(cin, age);
                    string updatequery = "update " + object + " set " + object + "_age = '" + age + "' where " + object + "_ID = '" + ID + "'";
                    const char* query = updatequery.c_str();
                    qstate = mysql_query(conn, query);

                }
                else if (check == 3)
                {
                    cout << "Gender:";
                    cin.ignore();
                    getline(cin, gender);
                    string updatequery = "update " + object + " set " + object + "_gender = '" + gender + "' where " + object + "_ID = '" + ID + "'";
                    const char* query = updatequery.c_str();
                    qstate = mysql_query(conn, query);

                }
            }
            cout << "=============================================================" << endl;
            cout << "Do you want to update other information? (Y/N):";
            cin >> conti;


        }
        else if (user == "Tutor" || user == "Staff") {

            string displayquery = "select * from " + user + " where " + user + "_ID = '" + to_string(userID) + "'";
            const char* query = displayquery.c_str();
            qstate = mysql_query(conn, query);

            if (!qstate)
            {
                system("cls");
                cout << "\t\t=================================================================================" << endl;
                cout << "\t\t|                        Update " + user + " information                       |" << endl;
                cout << "\t\t=================================================================================" << endl;
                cout << "Your information :" << endl;
                cout << setw(5) << "ID" << setw(40) << "Name" << setw(5) << "Age" << setw(10) << "Gender" << setw(30) << "Contact numbers" << setw(20) << "Password" << endl;
                res = mysql_store_result(conn);
                while (row = mysql_fetch_row(res))
                {
                    cout << setw(5) << row[0] << setw(40) << row[1] << setw(5) << row[2] << setw(10) << row[3] << setw(30) << row[4] << setw(20) << row[5] << endl;
                    cout << "\n1.Name\n2.Age\n3.Gender\n4.Contact numbers\n5.Password\n6.Back ";
                    cout << "\nChoose the information that you want to update:";
                    cin >> check;
                    if (check == 1)
                    {
                        cout << "Name:";
                        cin.ignore();
                        getline(cin, Name);
                        string updatequery = "update " + object + " set " + object + "_Name = '" + Name + "' where " + object + "_ID = '" + to_string(userID) + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 2)
                    {
                        cout << "Age:";
                        cin.ignore();
                        getline(cin, age);
                        string updatequery = "update " + object + " set " + object + "_age = '" + age + "' where " + object + "_ID = '" + to_string(userID) + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 4)
                    {
                        cout << "Gender:";
                        cin.ignore();
                        getline(cin, gender);
                        string updatequery = "update " + object + " set " + object + "_gender = '" + gender + "' where " + object + "_ID = '" + to_string(userID) + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 4)
                    {
                        cout << "Contact numbers:";
                        cin.ignore();
                        getline(cin, Tel);
                        string updatequery = "update " + object + " set " + object + "_Tel = '" + Tel + "' where " + object + "_ID = '" + to_string(userID) + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 5)
                    {
                        cout << "New Password:";
                        cin.ignore();
                        getline(cin, Password);
                        string updatequery = "update " + object + " set " + object + "_Password = '" + Password + "' where " + object + "_ID = '" + to_string(userID) + "'";
                        const char* query = updatequery.c_str();
                        qstate = mysql_query(conn, query);

                    }
                    else if (check == 4)
                    {
                        conti = 'n';
                        return conti;
                    }

                }


            }
            cout << "=============================================================" << endl;
            cout << "Do you want to update other information? (Y/N):";
            cin >> conti;
        }
    } while (conti == 'y' || conti == 'Y');
    return conti;
}
string myclass::total_capacity(string ID) {
    string capacity_query = "SELECT e.Events_ID, e.Events_Name, e.Events_capacity + COALESCE(COUNT(a.Attendance), 0) AS TotalCapacity FROM events e LEFT JOIN eventsregistration a ON e.Events_ID = a.Events_ID WHERE e.Events_ID = " + ID + " GROUP BY e.Events_ID, e.Events_Name, e.Events_capacity";
    const char* query = capacity_query.c_str();
    qstate = mysql_query(conn, query);
    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res))
        {
            capacity = stod(row[0]);
        }
    }
    return capacity;
}
double myclass::Mtotal_capacity(string month) {
    double cap = 1;

    string capacity_query = "SELECT MONTH (e.Events_Date) AS Month, COALESCE ( SUM(e.Events_capacity), 0) + COALESCE ( SUM(a.Staff_ID), 0)  AS TotalCapacity FROM events e LEFT JOIN ( SELECT Events_ID, count(Staff_ID) AS Staff_ID FROM eventsregistration GROUP BY Events_ID ) a ON e.Events_ID = a.Events_ID WHERE MONTH(e.Events_Date) = " + month + " GROUP BY MONTH(e.Events_Date)";

    const char* query = capacity_query.c_str();
    qstate = mysql_query(conn, query);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if ((row = mysql_fetch_row(res)) == nullptr)
        {
            cap = 0;
            return cap;
        }
        else
        {
            cap = stod(row[1]);
            return cap;
        }
    }
    else
    {
        cout << "MySQL Error: " << mysql_error(conn) << endl;
    }


}
double myclass::total_eventPM(string month) {
    double cap = 1;

    string capacity_query = "select count(events_ID) from events where month(events_date) =" + month;
    const char* query = capacity_query.c_str();
    qstate = mysql_query(conn, query);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if ((row = mysql_fetch_row(res)) == nullptr)
        {
            cap = 0;
            return cap;
        }
        else
        {
            cap = stod(row[0]);
            return cap;
        }
    }
    else
    {
        cout << "MySQL Error: " << mysql_error(conn) << endl;
    }


}
double myclass::total_attend(string month) {
    double cap = 1;

    string capacity_query = "select count(a.Attendance) from eventsregistration a join events e on e.Events_ID=a.Events_ID where month(Events_Date) = " + month + " and a.attendance =1";
    const char* query = capacity_query.c_str();
    qstate = mysql_query(conn, query);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if ((row = mysql_fetch_row(res)) == nullptr)
        {
            cap = 0;
            return cap;
        }
        else
        {
            cap = stod(row[0]);
            return cap;
        }
    }
    else
    {
        cout << "MySQL Error: " << mysql_error(conn) << endl;
    }


}
string myclass::EventName(int ID) {

    string Name_query = "select Events_name from events where Events_ID = " + to_string(ID);
    const char* query = Name_query.c_str();
    qstate = mysql_query(conn, query);

    if (!qstate)
    {
        res = mysql_store_result(conn);
        if (row = mysql_fetch_row(res)) {
            string name = row[0];
            return name;
        }
    }
    else
    {
        string name = "The event ID does not exist.";
        return name;
    }
}
