#include <iostream>
#include <vector>

typedef struct Task
{
  int taskID;
  std::string description;
  std::string time;
  bool completed;
} Task;

std::vector<Task> todoList;
int numTasks = 0;

void addTask(std::string description, std::string time)
{
  Task task = {numTasks, description, time, false};
  todoList.push_back(task);
  ++numTasks;
}

void completeTask(int taskID)
{
  for (int i = 0; i < todoList.size(); ++i)
  {
    Task* task = &todoList[i];
    if (task->taskID == taskID)
    {
      task->completed = true;
    }
  }
}

void removeTask(int taskID)
{
  for (auto task : todoList)
  {
    if (task.taskID == taskID)
    {
      todoList.erase(todoList.begin() + taskID);
      --numTasks;
    }
  }
}

void listTasks()
{
  std::cout << '\n';
  for (auto task : todoList)
  {
    std::cout << task.taskID << (task.completed ? " DONE " : " ACTIVE ") << task.description << ' ' << task.time << "\n\n";
  }
  std::cout << '\n';
}

int main(int argc, char* argv[])
{
  std::cout << "Todo List" << "\n\n";
  bool prgRunning = true;
  std::string userInputBuffer;
  std::string taskDescBuffer;
  std::string taskDateBuffer;
  int chkTaskID;
  int remTaskID;

  // Main loop
  while (prgRunning)
  {
    std::cout << "You have " << numTasks << " tasks." << "\n\n";
    std::cout << "Type add, remove, complete, list or quit.\n";
    std::getline(std::cin, userInputBuffer);

    if (userInputBuffer == "add")
    {
      std::cout << "Enter task description: ";
      std::getline(std::cin, taskDescBuffer);
      std::cout << "Enter task completion date: ";
      std::getline(std::cin, taskDateBuffer);
      addTask(taskDescBuffer, taskDateBuffer);
    }
    else if (userInputBuffer == "remove")
    {
      std::cout << "Enter the task number to remove: ";
      std::cin >> remTaskID;
      removeTask(remTaskID);
    }
    else if (userInputBuffer == "complete")
    {
      std::cout << "Enter the task number to check off: ";
      std::cin >> chkTaskID;
      completeTask(chkTaskID);
    }
    else if (userInputBuffer == "list") listTasks();
    else if (userInputBuffer == "quit") prgRunning = false;
    else std::cout << "Not a valid command.\n";
  }

  return 0;
}