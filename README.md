# Task Management App

This Task Management app is a console-based application developed using Visual Studio 2022. It allows you to create, view, modify, search, and delete tasks. You can manage your tasks efficiently using this application.

## Getting Started

To use this Task Management app, follow these steps:

1. Clone or download the source code from the repository.

2. Open the project in Visual Studio 2022.

3. Build and run the application.

4. Follow the on-screen menu options to manage your tasks.

## Features

### 1. Create Task

- You can create a new task by providing a name, description, and due date.
- The due date must be in the format `DD/MM/YYYY`, and it must be a future date.

### 2. View All Tasks

- Display a list of all tasks, including their names, descriptions, and due dates.
- Tasks are sorted by their due dates in ascending order.

### 3. Delete Task

- You can delete a task by specifying its index.
- If you enter an invalid index, the application will prompt you to enter a valid one.
- Type 'exit' to go back to the main menu.

### 4. Modify Task

- Modify an existing task's name, description, and due date.
- Specify the task's index to make changes.
- Ensure you provide a valid index, and follow the prompts to enter the new task details.
- Type 'exit' to go back to the main menu.

### 5. Search Tasks

- Search for tasks by entering a keyword.
- The app will display tasks whose names or due dates contain the keyword.
- Type 'exit' to go back to the main menu.

### 6. Exit

- Exit the application when you are done managing your tasks.

## Code Structure

The application consists of the following key files:

- `Task.h` and `Task.cpp`: Define the `Task` class, which represents individual tasks.
- `TaskManager.h` and `TaskManager.cpp`: Define the `TaskManager` class, which manages tasks and provides functionality for task management.
- `main.cpp`: Implements the user interface and menu options.

## Important Notes

- When entering dates, please use the format `DD/MM/YYYY`.

- The due date for a task must be in the future; the application will not accept past dates.

- Ensure you provide valid input when prompted, and follow the instructions displayed on the screen.


