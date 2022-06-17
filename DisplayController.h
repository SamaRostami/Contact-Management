#include <iostream>
#include <string>
#include <limits>

using namespace std;

class DisplayController
{
    public:
        static void addContact(Contact *contact, Contact contacts[], int count);
        static void listContact(Contact contacts[], int count);
        static void searchByName(Contact contacts[], int count);
        static void updateContact(Contact contacts[], int count);
        static void deleteContact(Contact contacts[], int *count);
        static void deleteData(Contact contacts[], int *count);
};