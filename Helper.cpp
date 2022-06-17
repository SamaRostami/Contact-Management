#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Helper.h"

using namespace std;

void log(string type, string content)
{
    cout << "[" << type << "]: " << content << endl;
}

int Helper::getRangeInput(int min, int max)
{
    int userInput = 0;
    while (true)
    {
        cin >> userInput;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            log("error", "Invalid input, please try again");
        }
        else
        {
            if (userInput < min || userInput > max)
            {
                log("error", "Invalid input, please try again");
            }
            else
            {
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return userInput;
            }
        }
    }
}

int Helper::searchName(string searchQuery, Contact contacts[], int count)
{
    int contactId;
    for (contactId = 0; contactId < count; contactId++)
    {
        if (searchQuery == contacts[contactId].firstName || searchQuery == contacts[contactId].lastName)
        {
            return contactId;
            break;
        }
    }
    return contactId = -1;
}

int Helper::searchPhoneNumber(string searchQuery, Contact contacts[], int count)
{
    int contactId;
    for (contactId = 0; contactId < count; contactId++)
    {
        if (searchQuery == contacts[contactId].phoneNumber)
        {
            return contactId;
            break;
        }
    }
    return contactId = -1;
}

void Helper::noResultFound()
{
    cout << "\n\n::::::::::::: No Result Found! :::::::::::::\n\n";
}

void Helper::pressEnterToReturn()
{
    cin.ignore();
    cout << "\n\n<- Press Enter to return to the Menu";
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
}

