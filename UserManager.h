#pragma once
#include <vector>
#include "User.h"
#include "BaseManager.h"

class UserManager : public BaseManager {
private:
    std::vector<User> users;

public:
    void addUser(const User& user);

    const std::vector<User>& getUsers() const;

    User* findUserById(int id);

    void loadFromFile(const std::string& filename) override;
    void saveToFile(const std::string& filename) override;
    int size() const override;
};
