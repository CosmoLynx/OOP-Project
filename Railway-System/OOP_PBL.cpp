#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <fstream>
#include <limits>
using namespace std;

void manage();
void user();
void database();
void res();
void displaypassdetail();
void cancell();
void enquiry();
void displaycan();

char f[10] = "F";
char s[10] = "S";
int addr, ad, flag, f1, d, m, amt;
float tamt;

class login
{
public:
    char id[100];
    char pass[100];

    void getid()
    {
        cout << "Enter your id:";
        cin >> id;
        cout << "Enter the password: ";
        cin >> pass;
    }
    void displayid()
    {
        cout << id << "\t" << pass << endl;
    }
};
class detail
{
public:
    int tno;
    char tname[100];

    char bp[100];
    char dest[100];
    int c1, c1fare;
    int c2, c2fare;
    int d, m, y;
    void getdetail()
    {
        cout << "Enter the details as follows\n";
        cout << "Train no:";
        cin >> tno;
        cout << "Train name:";
        cin.sync();
        cin.getline(tname, 100);

        cout << "Boarding point:";
        cin >> bp;
        cout << "Destination pt:";
        cin >> dest;

        cout << "No of seats in First class & Fare per ticket:";
        cin >> c1 >> c1fare;
        cout << "No of seats in Second class & Fare per ticket:";
        cin >> c2 >> c2fare;
        cout << "Date of travel:";
        cin >> d >> m >> y;
    }
    void displaydetail()
    {

        cout << tno << "\t\t" << tname << "\t" << bp << "\t\t\t" << dest << "\t\t\t";
        cout << c1 << "\t\t\t" << c1fare << "\t\t\t" << c2 << "\t\t\t" << c2fare << "\t\t\t";
        cout << d << "-" << m << "-" << y << "\t" << endl
             << endl;
    }
};
class reser
{
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosr;
    int i;
    int d, m, y;
    int con;

    float amc;
    void getresdet()
    {
        cout << "\nEnter the details as follows\n";
        cout << "\nTrain no: ";
        cin >> tno;

        cout << "\nBoarding point: ";
        cin >> bp;
        cout << "\nDestination pt: ";
        cin >> dest;
        cout << "\nNo of seats required: ";
        cin >> nosr;
        cout << "\n\n";
        for (i = 0; i < nosr; i++)
        {
            cout << "Passenger " << i + 1 << " Name: ";
            cin.sync();
            cin.getline(pname[i], 100);

            cout << "Passenger " << i + 1 << " Age: ";
            cin >> age[i];
        }
        cout << "\n\nEnter Class\nF-first class\nS-second class\n: ";
        cin >> clas;
        cout << "\nDate of travel(DD MM YYYY): ";
        cin >> d >> m >> y;
        cout << "\n\nEnter the concession category\n";
        cout << "1.Military\n2.Senior citizen\n";
        cout << "3.Children below 5 yrs\n4.None\n: ";
        cin >> con;
        cout << "............END OF GETTING DETAILS............\n";
    }
    void displayresdet()
    {
        cout << "\n...............................................\n";
        cout << "...............................................\n";
        cout << "PNR No: " << pnr;
        cout << "\n\nTrain No: " << tno;
        cout << "\n\nTrain Name: ";
        cout << tname;
        cout << "\n\nBoarding Point: ";
        cout << bp;
        cout << "\n\nDestination Point: ";
        cout << dest;
        cout << "\n\nNo of seats reserved: " << nosr;
        for (i = 0; i < nosr; i++)
        {
            cout << "\n\nPassenger " << i + 1 << " Name:";
            cout << pname[i];
            cout << "\nPassenger " << i + 1 << " Age:" << age[i];
        }

        cout << "\n\nYour class: ";
        cout << clas;
        cout << "\n\nDate of reservation: " << d << "-" << m << "-" << y;
        cout << "\n\nYour concession category: " << con;
        cout << "\n\nYou must pay: " << amc << endl;
        cout << "***********************************************\n";
        cout << "***********************************************\n\n";
    }
};
class canc
{
public:
    int pnr;
    int tno;
    char tname[100];
    char bp[10];
    char dest[100];
    char pname[10][100];
    int age[20];
    char clas[10];
    int nosc;
    int d, m, y;
    float amr;
    void getcancdet()
    {
        cout << "Enter the details as follows\n";
        cout << "PNR no: ";
        cin >> pnr;
        cout << "Date of cancellation(DD MM YYYY): ";
        cin >> d >> m >> y;
        cout << "...........END OF GETTING DETAILS...........\n";
    }
    void displaycancdet()
    {
        cout << "...........................................\n";
        cout << "...........................................\n";
        cout << "PNR No:" << pnr;
        cout << "\n\nTrain No: " << tno;
        cout << "\nTrain Name: ";
        cout << tname;
        cout << "\n\nBoarding Point: ";
        cout << bp;

        cout << "\n\nDestination Point: ";
        puts(dest);
        cout << "\n\nYour class: ";
        puts(clas);
        cout << "\n\nNo of seats to be cancelled: " << nosc;

        for (int i = 0; i < nosc; i++)
        {
            cout << "\n\nPassenger " << i + 1 << " Name: ";
            cout << pname[i];
            cout << "\nPassenger " << i + 1 << " Age: " << age[i];
        }

        cout << "\n\nDate of cancellation: " << d << "-" << m << "-" << y;
        cout << "\n\nYou can collect: " << amr << "rs" << endl;
        cout << "*****************************************\n";
        cout << ".........END OF CANCELLATION.............\n";
        cout << "*****************************************\n";
    }
};

int main()
{
    int ch;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    cout << ".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    do
    {
        try
        {
            cout << "......................MAIN MENU......................\n";
            cout << "1.Admin mode\n2.User mode\n3.Exit\n";
            cout << "Enter your choice: ";
            cin >> ch;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                throw invalid_argument("Invalid input! Please enter a valid number.");
            }

            cout << endl;
            switch (ch)
            {
            case 1:
                database();
                break;
            case 2:
                user();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice! Please enter a number between 1 and 3.\n";
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    } while (ch < 3);

    return 0;
}

void database()
{
    char password[15];
    const char *pass = "1234";
    cout << "Enter the administrator password: ";
    cin >> password;
    detail a;
    fstream f;
    int ch;
    char c;
    if (strcmp(pass, password) != 0)
    {
        cout << "Enter the password correctly\n";
        cout << "You are not permitted to login in this mode\n";
    }
    if (strcmp(pass, password) == 0)
    {
        char c;
        do
        {
            try
            {
                cout << "...........ADMINISTRATOR MENU...........\n";
                cout << "1.Add Train Details in Database\n";
                cout << "2.Display All Trains Details\n";
                cout << "3.User Management\n";
                cout << "4.Display All Reservations\n";
                cout << "5.Display Cancellations\n";
                cout << "6.Return to Main Menu\n";
                cout << "Enter your choice: ";
                cin >> ch;

                if (cin.fail())
                {
                    cin.clear();                                         // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                    throw invalid_argument("Invalid input! Please enter a valid number.");
                }

                cout << endl;
                switch (ch)
                {
                case 1:
                    f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
                    do
                    {
                        a.getdetail();
                        f.write((char *)&a, sizeof(a));
                        cout << "Do you want to add one more record?\n";
                        cout << "y-for Yes\nn-for No\n: ";
                        cin >> c;

                        if (c != 'y' && c != 'n')
                        {
                            throw invalid_argument("Invalid choice! Enter 'y' or 'n'.");
                        }
                    } while (c == 'y');
                    f.close();
                    break;

                case 2:
                    cout << "Train No.\tTrain Name\tBoarding Station\tDestination Station\tFirst Class Seats\tFirst Class Fare\tSecond Class Seats\tSecond Class Fare\tDate\n";
                    f.open("t.txt", ios::in | ios::out | ios::binary | ios::app);
                    f.seekg(0);
                    while (f.read((char *)&a, sizeof(a)))
                    {
                        a.displaydetail();
                    }
                    f.close();
                    cout << "\n\n";
                    break;

                case 3:
                    manage();
                    break;

                case 4:
                    displaypassdetail();
                    break;

                case 5:
                    displaycan();
                    break;

                case 6:
                    cout << "Returning to Main Menu.\n";
                    break;

                default:
                    cout << "Invalid choice! Please enter a number between 1 and 6.\n";
                }
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
            }
        } while (ch < 6);

        f.close();
    }
}

void displaycan()
{
    fstream f3;
    canc c;
    f3.open("cn.txt", ios::in | ios::out | ios::binary);
    f3.seekg(0);
    while (f3.read((char *)&c, sizeof(c)))
    {
        c.displaycancdet();
    }
    f3.close();
}

void res()
{
    detail a;
    reser b;
    fstream f1, f2;
    time_t t;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary | ios::app);
    int ch;
    cout << "\nEnter Train No.: ";
    cin >> b.tno;

    while (f1.read((char *)&a, sizeof(a)))
    {
        if (a.tno == b.tno)
        {
            cout << "\nEnter Train No. again for confirmation\n";
            b.getresdet();
            if (strcmp(b.clas, f) == 0)
            {
                if (a.c1 >= b.nosr)
                {
                    strcpy(b.tname, a.tname);
                    amt = a.c1fare;
                    addr = f1.tellg();
                    ad = sizeof(a);
                    f1.seekp(addr - (ad));
                    a.c1 = a.c1 - b.nosr;
                    f1.write((char *)&a, sizeof(a));
                    if (b.con == 1)
                    {
                        cout << "Concession category: MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category: SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category: CHILDREN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "------------------------------------------------------\n";
                    cout << "--------------Your ticket is reserved-----------\n";
                    cout << "-----------------End of reservation menu-------\n";
                }
                else
                {
                    cout << "**********Sorry requested seats are not available********\n";
                }
            }
            else if (strcmp(b.clas, s) == 0)
            {
                if (a.c2 >= b.nosr)
                {
                    strcpy(b.tname, a.tname);
                    amt = a.c2fare;
                    addr = f1.tellg();
                    ad = sizeof(a);
                    f1.seekp(addr - (ad));
                    a.c2 = a.c2 - b.nosr;
                    f1.write((char *)&a, sizeof(a));
                    if (b.con == 1)
                    {
                        cout << "Concession category:MILITARY PERSONNEL\n";
                        b.amc = b.nosr * ((amt * 50) / 100);
                    }
                    else if (b.con == 2)
                    {
                        cout << "Concession category:SENIOR CITIZEN\n";
                        b.amc = b.nosr * ((amt * 60) / 100);
                    }
                    else if (b.con == 3)
                    {
                        cout << "Concession category:CHILDERN BELOW FIVE\n";
                        b.amc = 0.0;
                    }
                    else if (b.con == 4)
                    {
                        cout << "You cannot get any concession\n";
                        b.amc = b.nosr * amt;
                    }
                    srand((unsigned)time(&t));
                    b.pnr = rand();
                    f2.write((char *)&b, sizeof(b));
                    b.displayresdet();
                    cout << "---------------------------------------\n";
                    cout << "--------Your ticket is reserved--------\n";
                    cout << "------------End of reservation---------\n";
                }
                else
                {
                    cout << "********Sorry requested seats are not available*******\n";
                }
            }
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        cout << "............Wrong train no......................\n";
        cout << "......Enter the train no from the data base.....\n";
    }
    f1.close();
    f2.close();
}
void displaypassdetail()
{
    fstream f;
    reser b;
    f.open("p.txt", ios::in | ios::out | ios::binary);
    f.seekg(0);
    while (f.read((char *)&b, sizeof(b)))
    {
        b.displayresdet();
    }
    f.close();
}
void enquiry()
{
    cout << "Train No.\tTrain Name\tBoarding Station\tDestination Station\tFirst Class Seats\tFirst Class Fare\tSecond Class Seats\tSecond Class Fare\tDate\n";
    fstream f;
    f.open("t.txt", ios::in | ios::out | ios::binary);
    detail a;
    while (f.read((char *)&a, sizeof(a)))
    {
        a.displaydetail();
    }
    f.close();
}

void cancell()
{
    detail a;
    reser b;
    canc c;
    int flagc = 0;
    fstream f1, f2, f3, temp;
    f1.open("t.txt", ios::in | ios::out | ios::binary);
    f2.open("p.txt", ios::in | ios::out | ios::binary);
    f3.open("cn.txt", ios::in | ios::out | ios::binary | ios::app);
    temp.open("temp.txt", ios::in | ios::out | ios::binary | ios::app);
    cout << "**********CANCELLATION MENU*********\n";
    c.getcancdet();
    while (f2.read((char *)&b, sizeof(b)))
    {
        if (b.pnr == c.pnr)
        {
            c.tno = b.tno;
            strcpy(c.tname, b.tname);
            strcpy(c.bp, b.bp);
            strcpy(c.dest, b.dest);
            c.nosc = b.nosr;
            for (int j = 0; j < c.nosc; j++)
            {
                strcpy(c.pname[j], b.pname[j]);
                c.age[j] = b.age[j];
            }
            strcpy(c.clas, b.clas);
            if (strcmp(c.clas, f) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {

                    if (a.tno == c.tno)
                    {
                        a.c1 = a.c1 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a);
                        f1.seekp(addr - (ad));
                        f1.write((char *)&a, sizeof(a));
                        tamt = b.amc;

                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one atleast month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }
                        c.displaycancdet();
                    }
                }
            }
            else if (strcmp(c.clas, s) == 0)
            {
                while (f1.read((char *)&a, sizeof(a)))
                {

                    if (a.tno == c.tno)
                    {
                        a.c2 = a.c2 + c.nosc;
                        d = a.d;
                        m = a.m;
                        addr = f1.tellg();
                        ad = sizeof(a);
                        f1.seekp(addr - (ad));
                        f1.write((char *)&a, sizeof(a));
                        tamt = b.amc;

                        if ((c.d == d) && (c.m == m))
                        {
                            cout << "You are cancelling at the date of departure\n";
                            c.amr = tamt - ((tamt * 60) / 100);
                        }
                        else if (c.m == m)
                        {
                            cout << "You are cancelling at the month of departure\n";
                            c.amr = tamt - ((tamt * 50) / 100);
                        }
                        else if (m > c.m)
                        {
                            cout << "You are cancelling one month before the date of departure\n";
                            c.amr = tamt - ((tamt * 20) / 100);
                        }
                        else
                        {
                            cout << "Cancelling after the departure\n";
                            cout << "Your request cannot be completed\n";
                        }

                        c.displaycancdet();
                    }
                }
            }
            flagc = 1;
        }
        else
        {
            if (flagc != 1)
            {
                flagc = 0;
            }
            temp.write((char *)&b, sizeof(b));
        }
    }
    if (flagc == 0)
    {
        cout << "\n\nEnter the correct PNR no\n\n";
    }
    f3.write((char *)&c, sizeof(c));
    f1.close();
    f2.close();
    f3.close();
    remove("p.txt");
    rename("temp.txt", "p.txt");
}

void user()
{
    login a;
    int flagu;
    int ch;
    cout << "*****************************************************\n";
    cout << "***********WELCOME TO THE USER MENU****************\n";
    cout << "****************************************************\n";
    char password[15];

    fstream f;
    f.open("id.txt", ios::in | ios::out | ios::binary);
    char id[100];
    cout << "Enter your id: ";
    cin >> id;

    cout << "Enter the password: ";
    cin >> password;
    while (f.read((char *)&a, sizeof(a)))
    {
        if ((strcmp(a.id, id) == 0) && (strcmp(a.pass, password) == 0))
        {
            do
            {
                cout << "1. Reserve\n2. Cancel\n3. Enquiry\n4. Return to the main menu\n";
                cout << "Enter your choice: ";

                try
                {
                    cin >> ch;

                    if (cin.fail())
                    {
                        cin.clear();                                         // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        throw invalid_argument("Invalid input! Please enter a valid number.");
                    }

                    cout << endl;
                    switch (ch)
                    {
                    case 1:
                        res();
                        break;
                    case 2:
                        cancell();
                        break;
                    case 3:
                        enquiry();
                        break;
                    case 4:
                        cout << "Returning to the main menu.\n";
                        break;
                    default:
                        cout << "Invalid choice! Please enter a number between 1 and 4.\n";
                    }
                }
                catch (const invalid_argument &e)
                {
                    cout << e.what() << endl;
                }
            } while (ch != 4);

            return;
        }
        else
        {
            flagu = 1;
        }
    }
    if (flagu == 1)
    {
        cout << "Enter your user id and password correctly\n";
    }
}

void manage()
{
    int ch;
    fstream f;
    char c;
    login a;
    cout << ".........WELCOME TO THE USER MANAGEMENT MENU........\n";
    do
    {
        try
        {
            cout << "1.Add User in Database\n";
            cout << "2.Display details\n";
            cout << "3.Return to the main menu\n";
            cout << "Enter your choice: ";
            cin >> ch;

            if (cin.fail())
            {
                cin.clear();                                         // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                throw invalid_argument("Invalid input! Please enter a valid number.");
            }

            cout << endl;
            switch (ch)
            {
            case 1:
                f.open("id.txt", ios::in | ios::out | ios::binary | ios::app);
                do
                {
                    a.getid();
                    f.write((char *)&a, sizeof(a));
                    cout << "Do you want to add one more record\n";
                    cout << "y-Yes\nn-No\n";
                    cin >> c;

                    if (c != 'y' && c != 'n')
                    {
                        throw invalid_argument("Invalid choice! Enter 'y' or 'n'.");
                    }
                } while (c == 'y');
                f.close();
                break;

            case 2:
                f.open("id.txt", ios::in | ios::out | ios::binary);
                f.seekg(0);
                cout << "UserID\tPassword\n";
                while (f.read((char *)&a, sizeof(a)))
                {
                    a.displayid();
                }
                f.close();
                break;

            case 3:
                cout << "Returning to the main menu.\n";
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 3.\n";
            }
        }
        catch (const invalid_argument &e)
        {
            cout << e.what() << endl;
        }
    } while (ch < 3);
}