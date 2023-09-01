#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <limits>
#include "Helper.h"
#include "DisplayController.h"

using namespace std;

string phoneNumber;
int i = 1;

void DisplayController::addContact(Contact *contact, Contact contacts[], int *count)
{
    system("cls");
    Contact newContact;
    ofstream phone("contacts.txt", ios::app);
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Add Contact :::::::::::::::\n\n";
    cout << "First Name : ";
    cin >> newContact.firstName;
    cout << "Last Name: ";
    cin >> newContact.lastName;
checkphoneNumber:
    cout << "Phone number: ";
    cin >> phoneNumber;
    int contactId = Helper::searchPhoneNumber(phoneNumber, contacts, *count);
    if (!(contactId == -1))
    {
        cout << "Contact Already Exists Please Enter Another Phonenumber\n";
        goto checkphoneNumber;
    }
    newContact.phoneNumber = phoneNumber;
    cout << "Age ( 0 For unknown ): ";
    cin >> newContact.age;
    cout << "Address: ";
    cin >> newContact.address;
    cout << "Email: ";
    cin >> newContact.email;
    if (phone.is_open())
    {
        phone << newContact.firstName << " "
              << newContact.lastName << " "
              << newContact.age << " "
              << newContact.address << " "
              << newContact.email << " "
              << newContact.age << " "
              << newContact.phoneNumber << endl;
        cout << "\n\nNew Contact Inserted Succesfully!";
        *count += 1;
    }
    else
    {
        cout << "\n\tError in opening record!";
    }

    Helper::pressEnterToReturn();
}

void DisplayController::listContact(Contact contacts[], int count)
{
    system("cls");
    Contact listContact;
    ifstream testcontacts("contacts.txt");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Contact List :::::::::::::::\n\n";
    if (!count == 0)
    {
        while (testcontacts >> listContact.firstName >> listContact.lastName >> listContact.age >> listContact.address >> listContact.email >> listContact.phoneNumber)
        {

            cout << i << ")"
                 << "\tFirst Name: " << listContact.firstName
                 << "\tLast Name: " << listContact.lastName
                 << "\tAge: " << listContact.age
                 << "\tAddress: " << listContact.address
                 << "\tEmail: " << listContact.email
                 << "\tPhone Number: " << listContact.phoneNumber
                 << endl;
            i++;
        }
    }
    else
    {
        Helper::noResultFound();
    }

    Helper::pressEnterToReturn();
}

void DisplayController::searchByName(Contact contacts[], int count)
{

    system("cls");
    bool found = false;
    string searchQuery;
    Contact listContact;
    ifstream testcontacts("contacts.txt");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Contact Search :::::::::::::::\n\n";
    cout << "Enter Contact Name For Search : ";
    cin >> searchQuery;
    while (testcontacts >> listContact.firstName >> listContact.lastName >> listContact.age >> listContact.address >> listContact.email >> listContact.phoneNumber)
    {
        if (searchQuery == listContact.firstName || searchQuery == listContact.firstName)
        {

            cout << "\tFirst Name: " << listContact.firstName
                 << "\tLast Name: " << listContact.lastName
                 << "\tAge: " << listContact.age
                 << "\tAddress: " << listContact.address
                 << "\tEmail: " << listContact.email
                 << "\tPhone Number: " << listContact.phoneNumber
                 << endl;
            found = true;
            break;
        }
    }
    if (found == false)
    {
        Helper::noResultFound();
    }

    Helper::pressEnterToReturn();
}

void DisplayController::updateContact(Contact contacts[], int count)
{
    string name, lastName, phonenumber, age, address, email;
    char yesNo;
start:
    system("cls");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Contact Update :::::::::::::\n\n";
    if (count == 0)
    {
        Helper::noResultFound();
        Helper::pressEnterToReturn();
    }
    else
    {
    getPhonenumber:
        cout << "Enter Contact Phonenumber For Update : ";
        cin >> phoneNumber;
        int contactId = Helper::searchPhoneNumber(phoneNumber, contacts, count);
        if (contactId == -1)
        {
            Helper::noResultFound();
            goto getPhonenumber;
        }

        cout << "\n"
             << contactId + 1 << ")"
             << "\tFirst Name: " << contacts[contactId].firstName
             << "\tLast Name: " << contacts[contactId].lastName
             << "\tAge: " << contacts[contactId].age
             << "\tAddress: " << contacts[contactId].address
             << "\tEmail: " << contacts[contactId].email
             << "\tPhone Number: " << contacts[contactId].phoneNumber
             << endl;

    getYesNo:
        cout << "\nDo you want to update this Contact(Y/N) : ";
        cin >> yesNo;

        if (yesNo == 'Y' || yesNo == 'y')
        {
            cout << "\n\nNew First Name : ";
            cin >> name;
            contacts[contactId].firstName = name;
            cout << "New Last Name: ";
            cin >> lastName;
            contacts[contactId].lastName = lastName;
        checkphoneNumber:
            cout << "New Phone number: ";
            cin >> phoneNumber;
            int searchtId = Helper::searchPhoneNumber(phoneNumber, contacts, count);
            if (!(searchtId == -1))
            {
                cout << "Contact Already Exists Please Enter Another Phonenumber\n";
                goto checkphoneNumber;
            }
            contacts[contactId].phoneNumber = phoneNumber;
            cout << "New Age ( 0 For unknown ): ";
            cin >> age;
            contacts[contactId].age = age;
            cout << "New Address: ";
            cin >> address;
            contacts[contactId].address = address;
            cout << "New Email: ";
            cin >> email;
            contacts[contactId].email = email;
            cout << "\n\nNew Contact Updated succesfully!";

            Helper::pressEnterToReturn();
        }
        else if (yesNo == 'N' || yesNo == 'n')
        {
            Helper::pressEnterToReturn();
        }
        else
        {
            cout << "please Enter Valid Character.";
            goto getYesNo;
        }
    }
}

void DisplayController::deleteContact(Contact contacts[], int *count)
{
    char yesNo;

    system("cls");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Contact Delete :::::::::::::\n\n";
    if (*count == 0)
    {
        Helper::noResultFound();
        Helper::pressEnterToReturn();
    }
    else
    {
    getPhonenumber:
        cout << "Enter Contact Phonenumber For Delete : ";
        cin >> phoneNumber;
        int contactId = Helper::searchPhoneNumber(phoneNumber, contacts, *count);
        if (contactId == -1)
        {
            Helper::noResultFound();
            goto getPhonenumber;
        }

        cout << "\n"
             << contactId + 1 << ")"
             << "\tFirst Name: " << contacts[contactId].firstName
             << "\tLast Name: " << contacts[contactId].lastName
             << "\tAge: " << contacts[contactId].age
             << "\tAddress: " << contacts[contactId].address
             << "\tEmail: " << contacts[contactId].email
             << "\tPhone Number: " << contacts[contactId].phoneNumber
             << endl;

    getYesNo:
        cout << "\nDo you want to delete this Contact(Y/N) : ";
        cin >> yesNo;

        if (yesNo == 'Y' || yesNo == 'y')
        {
            for (int i = contactId; i < *count; i++)
            {
                contacts[i] = contacts[i + 1];
            }

            cout << "\n\nContact Deleted succesfully!";
            *count -= 1;
            Helper::pressEnterToReturn();
        }
        else if (yesNo == 'N' || yesNo == 'n')
        {
            Helper::pressEnterToReturn();
        }
        else
        {
            cout << "please Enter Valid Character.";
            goto getYesNo;
        }
    }
}

void DisplayController::deleteData(Contact contacts[], int *count)
{
    char yesNo;

    system("cls");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << ":::::::::::: Delete All Contacts :::::::::::::\n\n";
    if (*count == 0)
    {
        Helper::noResultFound();
        Helper::pressEnterToReturn();
    }
    else
    {
    getYesNo:
        cout << "\nDo you want to delete all Contacts(Y/N) : ";
        cin >> yesNo;

        if (yesNo == 'Y' || yesNo == 'y')
        {
            delete (contacts);
            cout << "\n\nContacts Deleted succesfully!";
            *count = 0;
            Helper::pressEnterToReturn();
        }
        else if (yesNo == 'N' || yesNo == 'n')
        {
            Helper::pressEnterToReturn();
        }
        else
        {
            cout << "please Enter Valid Character.";
            goto getYesNo;
        }
    }
}