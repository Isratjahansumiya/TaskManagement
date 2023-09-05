#pragma once
#include <string>

class Task {
public:
    Task(const std::string& name, const std::string& description, const std::string& dueDate);

    void display() const;
    void modifyName(const std::string& newName);
    void modifyDescription(const std::string& newDescription);
    void modifyDueDate(const std::string& newDueDate);
    bool operator<(const Task& other) const;
    bool matches(const std::string& keyword) const;

private:
    std::string name;
    std::string description;
    std::string dueDate;
};
