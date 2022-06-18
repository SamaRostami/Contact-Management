#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Helper.h"
#include "DisplayController.h"
using namespace std;

int CONTACT_COUNTER = 0;

int main()
{
    Contact contacts[100];
    while (true)
    {
        system("cls");
        cout << "............................................\n";
        cout << "               Contact Manager \n";
        cout << "............................................\n\n";
        cout << "::::::::::::::: PROGRAM MENU :::::::::::::::\n";
        cout << "1. Save New Contact\n";
        cout << "2. Display All Saved Contacts\n";
        cout << "3. Search Specific Contact\n";
        cout << "4. Modify Existing Contact\n";
        cout << "5. Delete Specific Contact\n";
        cout << "6. Delete All Existing Contacts\n";
        cout << "0. Exit\n\n";
        cout << "Enter Your Choice : ";
        int menuInpute = Helper::getRangeInput(0, 6);
        switch (menuInpute)
        {
        case 1:
            DisplayController::addContact(&contacts[CONTACT_COUNTER], contacts, &CONTACT_COUNTER);
            cout << CONTACT_COUNTER << endl;
            break;

        case 2:
            DisplayController::listContact(contacts, CONTACT_COUNTER);
            break;

        case 3:
            DisplayController::searchByName(contacts, CONTACT_COUNTER);
            break;

        case 4:
            DisplayController::updateContact(contacts, CONTACT_COUNTER);
            break;

        case 5:
            DisplayController::deleteContact(contacts, &CONTACT_COUNTER);
            break;

        case 6:
            DisplayController::deleteData(contacts, &CONTACT_COUNTER);
            break;

        case 0:
            cout << "Have a nice day!" << endl;
            exit(0);

        default:
            cout << "Invalid Option!!" << endl;
            break;
        }
    }

    return 0;
}