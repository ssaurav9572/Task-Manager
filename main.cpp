#include <iostream>
#include <vector>
#include <string>

class Task {
private:
    std::string name;
    bool completed;

public:
    Task(const std::string& name) : name(name), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    std::string getName() const {
        return name;
    }
};

class TaskManager {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& name) {
        tasks.push_back(Task(name));
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markCompleted();
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        }
    }

    void displayTasks() const {
        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << (i + 1) << ". " << tasks[i].getName();
            if (tasks[i].isCompleted()) {
                std::cout << " - Completed";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    TaskManager taskManager;
    int choice;

    do {
        std::cout << "\nTask Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Mark Task as Completed\n";
        std::cout << "3. Remove Task\n";
        std::cout << "4. View Tasks\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskName;
                std::cout << "Enter task name: ";
                std::cin.ignore();
                std::getline(std::cin, taskName);
                taskManager.addTask(taskName);
                break;
            }
            case 2: {
                int index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                taskManager.markTaskCompleted(index - 1);
                break;
            }
            case 3: {
                int index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                taskManager.removeTask(index - 1);
                break;
            }
            case 4:
                taskManager.displayTasks();
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
