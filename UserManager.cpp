#include "UserManager.h"
#include <fstream>

void UserManager::addUser(const User& user) {
    users.push_back(user);
}

const std::vector<User>& UserManager::getUsers() const {
    return users;
}

User* UserManager::findUserById(int id) {

    for (auto& user : users) {

        if (user.getId() == id)
            return &user;
    }

    return nullptr;
}

void UserManager::loadFromFile(const std::string& filename) {

    std::ifstream file(filename);

    int id;
    std::string name;

    while (file >> id >> name) {
        users.push_back(User(id, name));
    }
}

void UserManager::saveToFile(const std::string& filename) {

    std::ofstream file(filename);

    for (const auto& user : users) {

        file << user.getId() << " "
             << user.getName()
             << "\n";
    }
}

int UserManager::size() const {
    return users.size();
}
