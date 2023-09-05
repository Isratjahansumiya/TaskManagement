#include "Task.h"
#include <iostream>
#include <algorithm>

Task::Task(const std::string& name, const std::string& description, const std::string& dueDate)
    : name(name), description(description), dueDate(dueDate) {}

void Task::display() const {
    std::cout << "Name: " << name << "\nDescription: " << description << "\nDue Date: " << dueDate << "\n";
}

void Task::modifyName(const std::string& newName) {
    name = newName;
}

void Task::modifyDescription(const std::string& newDescription) {
    description = newDescription;
}

void Task::modifyDueDate(const std::string& newDueDate) {
    dueDate = newDueDate;
}

bool Task::operator<(const Task& other) const {
    return dueDate < other.dueDate;
}

bool Task::matches(const std::string& keyword) const {
    return name.find(keyword) != std::string::npos || dueDate.find(keyword) != std::string::npos;
}
