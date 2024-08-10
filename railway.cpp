#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class temp {
    string userName;
    string Email;
    string password, newPassword;

    ifstream file1;
    ofstream file;

public:
    temp(); // Constructor
    ~temp(); // Destructor
    void login();
    void signUP();
    void forgot();
}obj;
temp::temp() {
    file1.open("loginData.txt"); // Open file for reading
    file.open("loginData.txt", ios::app); // Open file for appending
}

temp::~temp() {
    file1.close();
    file.close();
}

class book_ticket {
protected:
    string boarding_station, end_station;
    string name[50],seat[50],age[50];
    int DD,MM,YY,n,result;
    ifstream file1, file2;
    ofstream file;
    int amount,no_of_tickets;
    int SL, third_ac, second_ac, first_ac;

public:
    void choose();
    void view();
    void cancel();

    void modifyLine(const string& filename, int lineNumber, const string& newContent);

}obj1;
int main1();
int main() {
    cout << "WELCOME TO TRAIN YATRI" << endl;
    cout << "\n EXISTING LOGIN-ID:-ishita" << endl;
    cout << "\n EXISTING PASSWORD:-12"<< endl;
    char choice;
    temp obj;

    do {
        cout << "\n Enter 1 for Login";
        cout << "\n Enter 2 for creating a new account ";
        cout << "\n Enter 3 for creating a new password if you have forgotten the earlier one";
        cout << "\n Enter 4 for Exit";
        cout << "\nEnter Your Choice :: ";
        cin >> choice;

        switch (choice) {
            case '1':
                obj.login();
                main1();
                break;
            case '2':
                obj.signUP();
                break;
            case '3':
                obj.forgot();
                break;
            case '4':
                return 0;
            default:
                cout << "Invalid Selection...!";
        }
    } while (true);

    return 0;
}

int main1(){
    char choice;
    cout << "\n Enter 1 for booking ticket";
    cout << "\n Enter 2 for viewing your booked tickets ";
    cout << "\n Enter 3 for canceling ticket";
    cout << "\n Enter 4 for going to home page";
    cout << "\n Enter Your Choice :: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case '1':
            obj1.choose();
            break;
        case '2':
            obj1.view();
            break;
        case '3':
            obj1.cancel();
            break;
        case '4':
            main();
            break;

        default:
            cout << "Invalid Selection...!";
    }
}
int main2(){
    char choice;
    cout << "\n Enter 2 for viewing your booked tickets ";
    cout << "\n Enter 3 for canceling ticket";
    cout << "\n Enter 5 for going to home page";
    cout << "\n Enter Your Choice :: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
         case '2':
            obj1.view();
            break;
        case '3':
            obj1.cancel();
            break;
        case '4':
            main();
            break;
        default:
            cout << "Invalid Selection...!";
    }
}
int main3(){
    char choice;

    cout << "\n Enter 3 for canceling ticket";
    cout << "\n Enter 4 for going to home page";
    cout << "\n Enter Your Choice :: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case '3':
            obj1.cancel();
            break;
        case '4':
            main();
            break;

        default:
            cout << "Invalid Selection...!";
    }
}
int main5(){
    char choice;
    cout << "\n Enter 4 for going to home page";
    cout << "\n Enter Your Choice :: ";
    cin >> choice;
    cin.ignore();

    switch(choice){
        case '4':
            main();
            break;

        default:
            cout << "Invalid Selection...!";
    }
}



void temp::signUP() {
    cout << "\nEnter your details ::" << endl;
    cout << "\nEnter Your User Name :: ";
    cin.ignore();
    getline(cin, userName);
    cout << "Enter Your Email Address :: ";
    getline(cin, Email);
    cout << "Enter Your Password :: ";
    getline(cin, password);

    file << userName << "*" << Email << "*" << password << endl;
}

void temp::login() {
    string searchName, searchPass;
    cout << "----------LOGIN---------" << endl;
    cout << "Enter Your User Name :: ";
    cin.ignore();
    getline(cin, searchName);
    cout << "Enter Your Password :: ";
    getline(cin, searchPass);

    if (!file1) {
        cout << "Unable to open file!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file1, line)) {
        size_t pos1 = line.find("*");
        size_t pos2 = line.rfind("*");
        string storedName = line.substr(0, pos1);
        string storedPass = line.substr(pos2 + 1);
        if (storedName == searchName && storedPass == searchPass) {
            found = true;
            cout << "\nPassword matched successfully" << endl;
            cout << "Account Login Successful...!" << endl;
            cout << "Username :: " << storedName << endl;
            cout << "Email :: " << line.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
            break;
        }
    }
    if (!found) {
        cout << "Username or Password is Incorrect...!" << endl;
    }
    file1.clear(); // Clear any error flags
    file1.seekg(0); // Reset file pointer to the beginning
}

void temp::forgot() {
    string searchName, searchEmail;
    cout << "Enter your details ::";
    cin.ignore();
    cout << "\nEnter Your UserName :: ";
    getline(cin, searchName);
    cout << "\nEnter Your Email Address :: ";
    getline(cin, searchEmail);

    if (!file1) {
        cout << "Unable to open file!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file1, line)) {
        size_t pos1 = line.find("*");
        size_t pos2 = line.rfind("*");
        string storedName = line.substr(0, pos1);
        string storedEmail = line.substr(pos1 + 1, pos2 - pos1 - 1);
        if (storedName == searchName && storedEmail == searchEmail) {
            found = true;
            cout << "\nAccount Found...!" << endl;
            cout << "Your Password :: " << line.substr(pos2 + 1) << endl;
            int d;
            cout << "Do you want to continue with the same password or change?" << endl;
            cout << "Enter 1 for same password / Enter 2 for change password: ";
            cin >> d;
            if (d == 2) {
                cout << "Enter your new password: ";
                cin.ignore();
                getline(cin, newPassword);
                password = newPassword;
                cout << "Password updated" << endl;
                // Update password in the file
                size_t pos = line.rfind("*");
                line.replace(pos + 1, string::npos, password);
                file << line << endl; // Write the updated line to the file
            }
            break;
        }
    }
    if (!found) {
        cout << "Account not found...!" << endl;
    }
    file1.clear(); // Clear any error flags
    file1.seekg(0); // Reset file pointer to the beginning
}




void book_ticket::modifyLine(const string& filename, int lineNumber, const string& newContent) {

    ifstream file1(filename);
    ofstream file;
    file.open("dnj.txt" ,ios::out | ios::app);
    if (!file1.is_open()) {
        cout << "Error: Unable to open file." << endl;
        return;
    }

    vector<string> lines;
    string line;
    while (getline(file1, line)) {
        lines.push_back(line);
    }

    file1.close();

    if (lineNumber >= 0 && lineNumber < lines.size()) {
        lines[lineNumber] = newContent;

    } else {
        cout << "Error: Line number out of range." << endl;
        return;
    }

    ofstream outputFile(filename);
    if (!outputFile.is_open()) {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }

    for (const string& modifiedLine : lines) {
        outputFile << modifiedLine << endl;
    }

    outputFile.close();
}

void book_ticket::choose() {
    int int1,int2,int3,int4;
    string compartment, t,paid;
    cout << "\nYou can book tickets for" << endl;
    cout << "\n1-delhi to jammu" << endl;
    cout << "\n2-lucknow to goa" << endl;
    cout << "\nBOOK TICKET" << endl;
    cout << "Choose your boarding station:" << endl;
    getline(cin, boarding_station);
    cout << "Choose your destination:" << endl;
    getline(cin, end_station);
    cout<<"enter date when you want to book your ticket :"<<endl;
    cout<<"Date(DD/MM/YY, enter each three of them in separate lines):"<<endl;
    cin>>DD>>MM>>YY;

    if ((boarding_station == "Delhi" || boarding_station == "delhi" || boarding_station == "DELHI") &&
        (end_station == "Jammu" || end_station == "jammu" || end_station == "JAMMU")) {

        file1.open("dnj.txt", ios::in);
        if (file1.is_open()) {
            string line;
            cout << "\n\n";

            modifyLine("dnj.txt", 4, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD+1) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("dnj.txt", 10, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD+1) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("dnj.txt", 16, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD+1) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("dnj.txt", 22, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("dnj.txt", 28, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY));

            while (getline(file1, line)) {
                cout << line << endl;
            }
            cout << "\n\nChoose from 1 to 5 to view the train status" << endl;
            cin >> n;
            file1.close();
            switch(n){
            case 1:
                    file1.open("dnj1.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 230 << " " << "3A:" << 330 << " " << "2A:" << 430 << " " << "1A:" << 630 << endl;
                        A:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*230 + int2*330 + int3*430 + int4*530;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto A;
                            }
                        file1.close();
                        file.open("dnj1.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
            case 2:
                    file1.open("dnj2.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 530 << " " << "3A:" << 640 << " " << "2A:" << 800 << " " << "1A:" << 1000 << endl;

                        B:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*530 + int2*640 + int3*800 + int4*1000;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto B;
                            }
                        file1.close();
                        file.open("dnj2.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                case 3:
                    file1.open("dnj3.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 450 << " " << "3A:" << 500 << " " << "2A:" << 550 << " " << "1A:" << 700 << endl;

                        C:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*450 + int2*500 + int3*550 + int4*700;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto A;
                            }
                        file1.close();
                        file.open("dnj3.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                    case 4:
                    file1.open("dnj4.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 130 << " " << "3A:" << 530 << " " << "2A:" << 590 << " " << "1A:" << 800 << endl;

                        D:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*130 + int2*530 + int3*590 + int4*800;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto D;
                            }
                        file1.close();
                        file.open("dnj4.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                    case 5:
                    file1.open("dnj5.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 900 << " " << "3A:" << 1440 << " " << "2A:" << 1600 << " " << "1A:" << 2000 << endl;

                        E:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*900 + int2*1440 + int3*1600 + int4*2000;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto E;
                            }
                        file1.close();
                        file.open("dnj5.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                }
        }else {
                    cout << "Unable to open file!" << endl;
                }

                cout << "Now available seats:" << endl;
                cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
        }
         if ((boarding_station == "Lucknow" || boarding_station == "lucknow" || boarding_station == "LUCKNOW") &&
        (end_station == "Goa" || end_station == "goa" || end_station == "GOA")) {

        file1.open("lng.txt", ios::in);
        if (file1.is_open()) {
            string line;
            cout << "\n\n";

            modifyLine("lng.txt", 4, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD+1) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("lng.txt", 10, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD+1) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("lng.txt", 16, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD+1) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("lng.txt", 22, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY));
            modifyLine("lng.txt", 28, to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY) +"\t\t\t" + to_string(DD) + "/" + to_string(MM) + "/" + to_string(YY));

            while (getline(file1, line)) {
                cout << line << endl;
            }
            cout << "\n\nChoose from 1 to 5 to view the train status" << endl;
            cin >> n;
            file1.close();
            switch(n){
            case 1:
                    file1.open("lng1.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 230 << " " << "3A:" << 330 << " " << "2A:" << 430 << " " << "1A:" << 630 << endl;
                        F:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*230 + int2*330 + int3*430 + int4*530;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto F;
                            }
                        file1.close();
                        file.open("lng1.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
            case 2:
                    file1.open("lng2.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 530 << " " << "3A:" << 640 << " " << "2A:" << 800 << " " << "1A:" << 1000 << endl;

                        G:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*530 + int2*640 + int3*800 + int4*1000;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto G;
                            }
                        file1.close();
                        file.open("lng2.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                case 3:
                    file1.open("lng3.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 450 << " " << "3A:" << 500 << " " << "2A:" << 550 << " " << "1A:" << 700 << endl;

                        H:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*450 + int2*500 + int3*550 + int4*700;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto H;
                            }
                        file1.close();
                        file.open("lng3.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                    case 4:
                    file1.open("lng4.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 130 << " " << "3A:" << 530 << " " << "2A:" << 590 << " " << "1A:" << 800 << endl;

                        I:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*130 + int2*530 + int3*590 + int4*800;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto I;
                            }
                        file1.close();
                        file.open("lng4.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                    case 5:
                    file1.open("lng5.txt", ios::in);

                    if (file1.is_open()) {

                        file1 >> SL ;
                        file1>> third_ac;
                        file1 >> second_ac;
                        file1 >> first_ac;
                        cout << "Available seats:" << endl;
                        cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
                        cout<<"\nprice of each compartment per seat in rupees:"<<endl;
                        cout << "SL:" << 900 << " " << "3A:" << 1440 << " " << "2A:" << 1600 << " " << "1A:" << 2000 << endl;

                        J:
                            cout << "\nhow many tickets do you want to buy?" << endl;
                            cin >> no_of_tickets;
                            cout<<"choose in which class do you want to book your tickets:"<<endl;
                            cout<<"\nenter the no of seats in each class:(where you wish to book your seat):"<<endl;
                            cout<<"Sleeper:";
                            cin>>int1;
                            cout<<"\nthird ac:";
                            cin>>int2;
                            cout<<"\nsecond ac:";
                            cin>>int3;
                            cout<<"\nfirst ac:";
                            cin>>int4;
                            if(int1 + int2+ int3+ int4==no_of_tickets)
                            {
                                SL-=int1;
                                third_ac-=int2;
                                second_ac-=int3;
                                first_ac-=int4;
                                amount=int1*900 + int2*1440 + int3*1600 + int4*2000;
                            }
                            else
                            {
                                cout<<"out of range!! try again."<<endl;
                                goto J;
                            }
                        file1.close();
                        file.open("lng5.txt", ios::out);
                    if (file.is_open()) {

                        file << SL << " " << third_ac << " " << second_ac << " " << first_ac << endl;
                        file.close();
                    } else {
                        cout << "Unable to open file for writing!" << endl;
                    }
                    } else {
                        cout << "Unable to open file!" << endl;
                    }
                    break;
                }
        }else {
                    cout << "Unable to open file!" << endl;
                }

                cout << "Now available seats:" << endl;
                cout << "SL:" << SL << " " << "3A:" << third_ac << " " << "2A:" << second_ac << " " << "1A:" << first_ac << endl;
        }


        cout << "do you confirm to book " << no_of_tickets << " tickets?(type Y for yes and N for no)" << endl;
        cin >> t;
        if(t == "Y") {
            cout << "Pls add your details" << endl;
            cin.ignore();
            for(int i = 0; i < no_of_tickets; i++) {
                cout << "name of passenger"<<" "<<i+1<<endl;
                getline(cin,name[i]);
            }
            for(int i = 0; i < no_of_tickets; i++) {
                cout << "age of passenger"<<" "<<i+1<<endl;
                getline(cin,age[i]);
            }
            for(int i = 0; i < no_of_tickets; i++) {
                cout << "seat preferrence of passenger"<<" "<<i+1<<" "<<"(upper/middle/lower)"<<endl;
                getline(cin,seat[i]);
            }
            file.open("details.txt", ios::out | ios::app);
            for(int i = 0; i < no_of_tickets; i++){
            file << name[i] << "*" << age[i] << "*" << seat[i] << endl;}
            file.close();

            K:
                    cout << "pls proceed with the payment:" << endl;
                cout << "Pay " << amount << " rupees" << endl;
                cout<<"type 'paid' to confirm the payment"<<endl;
                cin>>paid;
                if(paid=="paid")
                {
                    cout<<"Thank you! your booking is completed!"<<endl;
                    main2();
                }


            } else {
                cout << "amount not paid!, try again..." << endl;
                goto K;
                main1();
            }
    }
void book_ticket::view()
{
    cout<<"\ntrain name and number:"<<endl;
    if(n==1)
    {
        cout<<"1)JAMMU EXPRESS(1234)"<<endl;
    }
    else if(n==2)
    {
        cout<<"2)JAMMU RAJDHANI(7890)"<<endl;

    }
    else if(n==3)
    {
        cout<<"3)SHRI SHAKTI EXP(22461)"<<endl;

    }
    else if(n==4)
    {
        cout<<"4)DEE MCTM AC SF(22401)"<<endl;

    }
    else if(n==5){
        cout<<"5)UTTAR S KRANTI(22305)"<<endl;}
    else
    {
        main3();
    }
    ifstream file("details.txt");
    file1.open("details.txt", ios::in);
    if (!file.is_open()) {
        cout << "Unable to open file!" << endl;
        return;

    for(int i=0;i<no_of_tickets;i++){
        getline(file1, name[i], '*');
        getline(file1, age[i], '*');
        getline(file1, seat[i], '\n');}}
    else{

    for (int i = 0; i < no_of_tickets; i++) {
        cout << "Name: " << name[i] << "\t";
    }
    cout << "\n";
    for (int i = 0; i < no_of_tickets; i++) {
        cout << "Age: " << age[i] << "\t\t";
    }
    cout << "\n";
    for (int i = 0; i < no_of_tickets; i++) {
        cout << "Seat: " << seat[i] << "\t";
    }
    cout<<"\nDate:"<<DD<<"/"<<MM<<"/"<<YY;

    main3();
    file.close();
}}

void book_ticket::cancel()
{
    string w,key;
    const char *filename = "details.txt";
    q:
            cout<<"do you wish to cancel the ticket?"<<endl;
            cin>>w;
            if(w=="yes"||"Yes"||"YES"||"Y")
            {
               if (std::remove(filename) != 0) {

                } else {
                    cout<<"File successfully deleted\n"<<endl;
                }
                cout<<"Ticket cancelled successfully!"<<endl;
                cout<<"your money will be refunded within 24 hrs"<<endl;
                cout<<"press any letter to continue..."<<endl;
                cin>>key;
                cout<<amount<<" "<<"rupees has been refunded successfully"<<endl;
                main5();

            }
            else if (w=="no"||"No"||"NO"||"N")
            {
                cout<<"ticket not cancelled"<<endl;
                view();
                cout<<"press enter to comtinue"<<endl;
                cin>>key;
                main();
            }
            else
            {
                cout<<"wrong choice try again!!"<<endl;
                goto q;
            }
}
