#include <iostream>
#include <string>
#include <windows.h>
#include <limits>
#include "Helper.h"
#include "DisplayController.h"

using namespace std;

string phoneNumber;

void DisplayController::addContact(Contact *contact, Contact contacts[], int count)
{
    system("cls");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Add Contact :::::::::::::::\n\n";
    cout << "First Name : ";
    cin >> contact->firstName;
    cout << "Last Name: ";
    cin >> contact->lastName;
checkphoneNumber:
    cout << "Phone number: ";
    cin >> phoneNumber;
    int contactId = Helper::searchPhoneNumber(phoneNumber, contacts, count);
    if (!(contactId == -1))
    {
        cout << "Contact Already Exists Please Enter Another Phonenumber\n";
        goto checkphoneNumber;
    }
    contact->phoneNumber = phoneNumber;
    cout << "Age ( 0 For unknown ): ";
    cin >> contact->age;
    cout << "Address: ";
    cin >> contact->address;
    cout << "Email: ";
    cin >> contact->email;
    cout << "\n\nNew Contact Inserted Succesfully!";
    Helper::pressEnterToReturn();
}

void DisplayController::listContact(Contact contacts[], int count)
{
    system("cls");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Contact List :::::::::::::::\n\n";
    if (!count == 0)
    {
        for (int i = 0; i < count; i++)
        {

            cout << i + 1 << ")"
                 << "\tFirst Name: " << contacts[i].firstName
                 << "\tLast Name: " << contacts[i].lastName
                 << "\tAge: " << contacts[i].age
                 << "\tAddress: " << contacts[i].address
                 << "\tEmail: " << contacts[i].email
                 << "\tPhone Number: " << contacts[i].phoneNumber
                 << endl;
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
    string searchQuery;
    system("cls");
    cout << "............................................\n";
    cout << "               Contact Manager \n";
    cout << "............................................\n\n";
    cout << "::::::::::::::: Contact Search :::::::::::::::\n\n";
    cout << "Enter Contact Name For Search : ";
    cin >> searchQuery;
    int contactId = Helper::searchName(searchQuery, contacts, count);
    if (contactId == -1)
    {
        Helper::noResultFound();
    }
    else
    {
        cout << "\n"
             << contactId + 1 << ")"
             << "\tFirst Name: " << contacts[contactId].firstName
             << "\tLast Name: " << contacts[contactId].lastName
             << "\tAge: " << contacts[contactId].age
             << "\tAddress: " << contacts[contactId].address
             << "\tEmail: " << contacts[contactId].email
             << "\tPhone Number: " << contacts[contactId].phoneNumber
             << endl;
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
            *count += 1;
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
            delete(contacts);
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