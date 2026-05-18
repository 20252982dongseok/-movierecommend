#pragma once
#include <string>

class User {
private:
    int id;
    std::string name;

public:
    User(int id, const std::string& name);

    int getId() const;
    std::string getName() const;
};
