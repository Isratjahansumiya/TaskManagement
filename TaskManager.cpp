#include "TaskManager.h"
#include <iostream>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <limits>

void TaskManager::addTask(const Task& task) {
    tasks.push_back(task);
    std::sort(tasks.begin(), tasks.end());
}

void TaskManager::displayAllTasks() const {
    for (int i = 0; i < tasks.size(); ++i) {
        std::cout << "Index: " << (i + 1) << "\n";
        tasks[i].display();
        std::cout << "--------------------------\n";
    }
}

void TaskManager::deleteTask(int index) {
    if (index >= 0 && index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

void TaskManager::modifyTask(int index, const std::string& newName, const std::string& newDescription, const std::string& newDueDate) {
    if (index >= 0 && index < tasks.size()) {
        tasks[index].modifyName(newName);
        tasks[index].modifyDescription(newDescription);
        tasks[index].modifyDueDate(newDueDate);
        std::sort(tasks.begin(), tasks.end());
    }
}

std::vector<Task> TaskManager::searchTasks(const std::string& keyword) const {
    std::vector<Task> matchingTasks;
    for (const Task& task : tasks) {
        if (task.matches(keyword)) {
            matchingTasks.push_back(task);
        }
    }
    return matchingTasks;
}

int TaskManager::getTaskCount() const {
    return tasks.size();
}

int TaskManager::getUserChoice() {
    int choice;
    std::cout << "1. Create Task\n2. View All Tasks\n3. Delete Task\n4. Modify Task\n5. Search Tasks\n6. Exit\n";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
    return choice;
}

bool TaskManager::isValidDate(const std::string& date) {
    if (date.size() != 10 || date[2] != '/' || date[5] != '/') {
        return false;
    }

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));
    int year = std::stoi(date.substr(6, 4));

    return (day >= 1 && day <= 31) && (month >= 1 && month <= 12) && (year >= 0);
}

std::string TaskManager::getValidDate() {
    std::string dueDate;
    auto now = std::chrono::system_clock::now();
    std::time_t today_time = std::chrono::system_clock::to_time_t(now);
    struct tm today_tm;

    while (true) {
        std::cout << "Enter due date (format: DD/MM/YYYY): ";
        std::cin >> dueDate;

        if (isValidDate(dueDate)) {
            int day = std::stoi(dueDate.substr(0, 2));
            int month = std::stoi(dueDate.substr(3, 2));
            int year = std::stoi(dueDate.substr(6, 4));

            localtime_s(&today_tm, &today_time);
            if (year < today_tm.tm_year + 1900 || (year == today_tm.tm_year + 1900 && month < today_tm.tm_mon + 1) ||
                (year == today_tm.tm_year + 1900 && month == today_tm.tm_mon + 1 && day < today_tm.tm_mday)) {
                std::cout << "Due date cannot be in the past. Please enter a future date.\n";
                continue;
            }
            else {
                break;
            }
        }
        else {
            std::cout << "Invalid due date format. Please enter a valid date.\n";
        }

        // Clear input buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return dueDate;
}

int TaskManager::getTaskIndex(int taskCount) {
    int index;
    while (true) {
        std::cout << "Enter the index of the task: ";
        std::cin >> index;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid index.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else if (index >= 1 && index <= taskCount) {
            // Clear only the invalid input, not the newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        else {
            std::cout << "Invalid index. Please enter a valid index.\n";
        }
    }
    return index - 1;
}

