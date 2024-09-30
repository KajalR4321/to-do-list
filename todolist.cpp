#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool isCompleted;

    Task(string desc) : description(desc), isCompleted(false) {}
};

class ToDoList {
    vector<Task> tasks;

public:
    // Add a new task to the list
    void addTask(string description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    // View all tasks with their status
    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "\n--- To-Do List ---\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description 
                 << " [" << (tasks[i].isCompleted ? "Completed" : "Pending") << "]" << endl;
        }
    }

    // Mark a task as completed
    void markTaskCompleted(int taskNumber) {
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        tasks[taskNumber - 1].isCompleted = true;
        cout << "Task " << taskNumber << " marked as completed." << endl;
    }

    // Remove a task from the list
    void removeTask(int taskNumber) {
        if (taskNumber < 1 || taskNumber > tasks.size()) {
            cout << "Invalid task number." << endl;
            return;
        }

        cout << "Removing task: " << tasks[taskNumber - 1].description << endl;
        tasks.erase(tasks.begin() + taskNumber - 1);
    }
};

int main() {
    ToDoList myList;
    int choice, taskNumber;
    string taskDescription;

    do {
        cout << "\n--- To-Do List Menu ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To handle newline characters

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                myList.addTask(taskDescription);
                break;
            case 2:
                myList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                myList.markTaskCompleted(taskNumber);
                break;
            case 4:
                cout << "Enter task number to remove: ";
                cin >> taskNumber;
                myList.removeTask(taskNumber);
                break;
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
