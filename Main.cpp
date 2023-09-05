#include "Task.h"
#include "TaskManager.h"
#include <iostream>
#include <string>

int main() {
    TaskManager taskManager;

    while (true) {
        int choice = taskManager.getUserChoice();
        switch (choice) {
        case 1: {
            std::string name, description, dueDate;
            while (true) {
                std::cout << "Enter task name: ";
                std::getline(std::cin, name);

                // Validate the task name
                if (name.empty()) {
                    std::cout << "Task name cannot be empty.\n";
                }
                else {
                    break;
                }
            }

            std::cout << "Enter task description: ";
            std::getline(std::cin, description);

            // Get a valid due date
            dueDate = taskManager.getValidDate();  // Use the getValidDate method

            Task newTask(name, description, dueDate);
            taskManager.addTask(newTask);

            std::cout << "Task created successfully!\n";
            break;
        }
        case 2: {
            if (taskManager.getTaskCount() == 0) {
                std::cout << "No tasks to display.\n";
            }
            else {
                std::cout << "List of all tasks:\n";
                taskManager.displayAllTasks();
            }
            break;
        }

        case 3: {
            if (taskManager.getTaskCount() == 0) {
                std::cout << "No tasks to delete.\n";
            }
            else {
                int index;
                while (true) {
                    std::cout << "Enter the index of the task to delete or type 'exit' to go back: ";
                    std::string userInput;
                    std::getline(std::cin, userInput);

                    if (userInput == "exit") {
                        break; // User wants to go back
                    }

                    try {
                        index = std::stoi(userInput);
                    }
                    catch (std::exception&) {
                        std::cout << "Invalid input. Please enter a valid index or type 'exit' to go back.\n";
                        continue;
                    }

                    if (index < 1 || index > taskManager.getTaskCount()) {
                        std::cout << "Invalid index. Please enter a valid index or type 'exit' to go back.\n";
                        continue;
                    }

                    taskManager.deleteTask(index - 1);
                    std::cout << "Task deleted successfully!\n";
                    break;
                }
            }
            break;
        }
        case 4: {
            std::string newName, newDescription, newDueDate;
            int index;

            while (true) {
                std::cout << "Enter the index of the task or type 'exit' to go back: ";
                std::string userInput;
                std::getline(std::cin, userInput);

                if (userInput == "exit") {
                    break; // User wants to go back
                }

                try {
                    index = std::stoi(userInput);
                }
                catch (std::exception&) {
                    std::cout << "Invalid input. Please enter a valid index or type 'exit' to go back.\n";
                    continue;
                }

                if (index < 1 || index > taskManager.getTaskCount()) {
                    std::cout << "Invalid index. Please enter a valid index or type 'exit' to go back.\n";
                    continue;
                }

                std::cout << "Enter new task name: ";
                std::getline(std::cin, newName);

                // Validate the new task name
                if (newName.empty()) {
                    std::cout << "Task name cannot be empty. Please enter a valid task name.\n";
                    continue;
                }

                std::cout << "Enter new task description: ";
                std::getline(std::cin, newDescription);

                // Get a valid new due date
                newDueDate = taskManager.getValidDate();

                taskManager.modifyTask(index - 1, newName, newDescription, newDueDate);
                std::cout << "Task modified successfully!\n";
                break;
            }
            break;
        }

        case 5: {
            std::string keyword;
            while (true) {
                std::cout << "Enter keyword (TaskName/DueDate) to search (or type 'exit' to go back): ";
                std::getline(std::cin, keyword);

                if (keyword == "exit") {
                    break;
                }
                else if (keyword.empty()) {
                    std::cout << "Keyword cannot be empty. Please enter a valid keyword or type 'exit' to go back.\n";
                }
                else {
                    std::vector<Task> matchingTasks = taskManager.searchTasks(keyword);

                    if (matchingTasks.empty()) {
                        std::cout << "No tasks match the search criteria.\n";
                    }
                    else {
                        std::cout << "Matching tasks:\n";
                        for (const Task& task : matchingTasks) {
                            task.display();
                        }
                    }
                }
            }
            break;
        }
        case 6: {
            std::cout << "Exiting the application. Goodbye!\n";
            return 0;
        }
        default: {
            std::cin.clear();
            std::cout << "Invalid choice. Please select a valid option.\n";
            break;
        }
        }
    }
    return 0;
}
