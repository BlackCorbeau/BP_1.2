#include <iostream>
#include "archive.h"
#include "utilities.h"

enum Actions { EXIT, INSERT, FIND, REMOVE, CLEAN };

int main() {
    int nums[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    TArchive<int> archive1(nums, 8);
    TArchive<int> archive(5, 2);
    archive.replace(2, 10);
    size_t n, pos;
    int* values = nullptr;
    DeleteSystem::DeleteMode delM;
    int user;

    std::exception err;
    bool exit = false;
    bool success;
    InputSystem::InsertMode mode;

    while (!exit) {
        system("cls");
        OutputSystem::show(archive);
        std::cout << "Menu:\n 1. insert,\n 2. find,\n 3. delete,\n 4. clean,\n 0. exit.\nYour choose: ";
        std::cin >> user;
        switch (user) {
        case Actions::EXIT:
            exit = true;
            break;
        case Actions::INSERT:
            if (values != nullptr) { delete[] values; values = nullptr; }
            values = InputSystem::insert<int>(n, pos, mode);
            success = false;
            if (mode == InputSystem::InsertMode::Front)
            {
                try {
                    archive.push_front(values[0]);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else if (mode == InputSystem::InsertMode::Back)
            {
                try {
                    archive.push_back(values[0]);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else if (mode == InputSystem::InsertMode::OneValue) {
                try {
                    archive.insert(values[0], pos);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else if (mode == InputSystem::InsertMode::SeveralValues) {
                try {
                    archive.insert(values, n, pos);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else {
                std::cout << "TBD" << std::endl;
            }
            if (success) {
                OutputSystem::insert();
            }
            system("pause");
            break;
        case Actions::FIND:
            std::cout << "TBD" << std::endl;
            system("pause");
            break;
        case Actions::REMOVE:
            if (values != nullptr) { delete[] values; values = nullptr; }
            DeleteSystem::delite(n, pos, delM);
            success = false;
            if (delM == DeleteSystem::DeleteMode::Front)
            {
                try {
                    archive.pop_front();
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else if (delM == DeleteSystem::DeleteMode::Back)
            {
                try {
                    archive.pop_back();
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            else if (delM == DeleteSystem::DeleteMode::ByIndex) {
                try {
                    archive.remove_by_index(pos);
                    success = true;
                }
                catch (std::exception err) {
                    std::cerr << err.what() << std::endl;
                }
            }
            break;
        case Actions::CLEAN:
            std::cout << "TBD" << std::endl;
            break;
        }
    }

    return 0;
}
