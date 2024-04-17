#include "Models.h"
#include <iostream>
#include <fstream>
#include <string>

Doktor::Doktor()
{
	std::cin >> id;
	std::cin >> password;
	std::cin >> spetialization;
	std::cin >> exp;
	std::cin >> university;
    this->writeToFile("Doktors.txt");
}

void Doktor::Registrate_Pet()
{
    Pet _pet;
}

void Doktor::Create_Reception()
{
    Reception res;
}

void Doktor::Close_Reception()
{
    // удаление
}

void Doktor::writeToFile(const std::string& filename)
{
    std::ofstream file(filename, std::ios::out);
    if (file.is_open())
    {
        file << id << std::endl;
        file << password << std::endl;
        file << spetialization << std::endl;
        file << exp << std::endl;
        file << university << std::endl;
        file << access_level << std::endl;
        file.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file for writing" << std::endl;
    }
}

void Doktor::readFromFile(const std::string& filename)
{
    std::ifstream file(filename, std::ios::in);
    if (file.is_open())
    {
        file >> id;
        file >> password;
        file >> spetialization;
        file >> exp;
        file >> university;
        file >> access_level;
        file.close();
    }
    else
    {
        std::cerr << "Error: Unable to open file for reading" << std::endl;
    }
}

bool remove_line(const char* filename, size_t index)
{
    std::vector<std::string> vec;
    std::ifstream file(filename);
    if (file.is_open())
    {
        std::string str;
        while (std::getline(file, str))
            vec.push_back(str);
        file.close();
        if (vec.size() < index)
            return false;
        vec.erase(vec.begin() + index);
        std::ofstream outfile(filename);
        if (outfile.is_open())
        {
            std::copy(vec.begin(), vec.end(),
                std::ostream_iterator<std::string>(outfile, "\n"));
            outfile.close();
            return true;
        }
        return false;
    }
    return false;
}