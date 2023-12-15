#include "ArrayFileManager.h"
#include "Helper.h"
#include <fstream>
#include <iostream>
#include <sstream>

void ArrayFileManager::saveArrayToFile(const Contact *contacts, int size, const std::string &filename)
{
    std::remove(filename.c_str());

    std::ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        for (int i = 0; i < size; ++i)
        {
            const Contact &contact = contacts[i];
            outputFile << contact.firstName << ","
                       << contact.lastName << ","
                       << contact.age << ","
                       << contact.address << ","
                       << contact.email << ","
                       << contact.phoneNumber << "\n";
        }
        outputFile.close();
        std::cout << "Contact data saved to " << filename << " successfully." << std::endl;
    }
    else
    {
        std::cerr << "Unable to open the file." << std::endl;
    }
}

void ArrayFileManager::loadArrayFromFile(Contact contacts[], int &size, const std::string &filename)
{
    std::ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        size = 0;
        std::string line;
        while (std::getline(inputFile, line))
        {
            ++size;
        }
        inputFile.clear();
        inputFile.seekg(0, std::ios::beg);

        if (size > 0)
        {
            int index = 0;
            while (std::getline(inputFile, line) && index < size)
            {
                std::istringstream iss(line);
                std::string firstName, lastName, age, address, email, phoneNumber;
                if (std::getline(iss, firstName, ',') &&
                    std::getline(iss, lastName, ',') &&
                    std::getline(iss, age, ',') &&
                    std::getline(iss, address, ',') &&
                    std::getline(iss, email, ',') &&
                    std::getline(iss, phoneNumber))
                {
                    contacts[index++] = {firstName, lastName, age, address, email, phoneNumber};
                }
                else
                {
                    std::cerr << "Invalid line format: " << line << std::endl;
                }
            }
            std::cout << "Contact data loaded from " << filename << " successfully." << std::endl;
        }
        else
        {
            std::cerr << "File contains no data." << std::endl;
        }

        inputFile.close();
    }
    else
    {
        std::cerr << "Unable to open the file." << std::endl;
    }
}