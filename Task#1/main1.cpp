#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <map>

struct str_task
{
    std::string name_task;
    std::time_t start_task;
    std::time_t end_task = 0;
};

void begin_task()
{
}
void end_task()
{
}
int main()
{
    std::map<std::string, int> name_task;
    std::vector<str_task> tasks;
    std::string running_task, command("");
    while (command != "exit")
    {
        std::cout << "Enter the command: ";
        std::cin >> command;
        if (command == "begin")
        {
            std::cout << "Enter the task: ";
            str_task tmp;
            std::cin >> tmp.name_task;
            if (running_task != "")
            {
                tasks[name_task[running_task]].end_task = std::time(nullptr);
                running_task = "";
            }
            running_task = tmp.name_task;
            tmp.start_task = std::time(nullptr);
            tasks.push_back(tmp);
            name_task[tmp.name_task] = tasks.size() - 1;
        }
        else if (command == "end" && running_task != "")
        {
            tasks[name_task[running_task]].end_task = std::time(nullptr);
            running_task = "";
        }
        else if (command == "status")
        {
            for (int i = 0; i < tasks.size(); ++i)
            {
                std::cout << '\t' << tasks[i].name_task
                          << "\nStart task: " << std::asctime(std::localtime(&tasks[i].start_task));
                if (tasks[i].end_task == 0)
                    std::cout << "Task in progress" << std::endl;
                else
                    std::cout << "End task: " << std::asctime(std::localtime(&tasks[i].end_task)) << std::endl;
            }
        }
    }
}