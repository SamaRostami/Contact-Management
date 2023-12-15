#ifndef HELPER_H
#define HELPER_H

#include <string>

using std::string;

struct Contact
{
    string firstName;
    string lastName;
    string age;
    string address;
    string email;
    string phoneNumber;
};

class Helper
{
    public:
        void message(string type, string content);
        static void noResultFound();
        static void pressEnterToReturn();
        static int getRangeInput(int min, int max);
        static int searchName(string searchQuery, Contact contacts[], int count);
        static int searchPhoneNumber(string searchQuery, Contact contacts[], int count);
};

#endif