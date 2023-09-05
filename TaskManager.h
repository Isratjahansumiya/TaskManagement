#pragma once
#include "Task.h"
#include <vector>

class TaskManager {
public:
    void addTask(const Task& task);
    void displayAllTasks() const;
    void deleteTask(int index);
    void modifyTask(int index, const std::string& newName, const std::string& newDescription, const std::string& newDueDate);
    std::vector<Task> searchTasks(const std::string& keyword) const;
    int getTaskCount() const;
    int getUserChoice();
    bool isValidDate(const std::string& date);
    std::string getValidDate();
    int getTaskIndex(int taskCount);

private:
    std::vector<Task> tasks;
};
