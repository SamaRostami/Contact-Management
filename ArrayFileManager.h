#ifndef ARRAYFILEMANAGER_H
#define ARRAYFILEMANAGER_H

#include <string>
#include "Helper.h"

class ArrayFileManager
{
public:
    static void saveArrayToFile(const Contact *contacts, int size, const std::string &filename);
    static void loadArrayFromFile(Contact contacts[], int &size, const std::string &filename);
};

#endif