#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <map>
struct birthday_date
{
    std::string name;
    std::tm birthday;
};

int main()
{
    std::vector<birthday_date> bd_date;
    std::time_t t = std::time(nullptr);
    std::tm local = *std::localtime(&t);
    std::map<int, std::vector<int>> bd_tm_local;
    birthday_date tmp;
    while (tmp.name != "end")
    {
        std::cout << "Enter birthday date: ";
        // tmp.birthday
        std::tm(tmp.birthday) = *std::localtime(&t);
        std::cin >> tmp.name;
        if (tmp.name == "end")
            break;
        std::cin >> std::get_time(&tmp.birthday, "%Y-%m-%d");
        bd_date.push_back(tmp);
        bd_tm_local[tmp.birthday.tm_yday].push_back(bd_date.size() - 1);
    }
    bd_tm_local[local.tm_yday].push_back(bd_date.size() + 1);
    std::map<int, std::vector<int>>::iterator it = bd_tm_local.find(local.tm_yday);
    while (true)
    {
        bool check(false);
        for (int i = 0; i < it->second.size(); i++)
        {
            if (it->second[i] == bd_date.size() + 1)
                continue;
            else
            {
                std::cout << "Next birthday is " << std::put_time(&bd_date[it->second[i]].birthday, "%m-%d") << ":" << std::endl;
                for (int i = 0; i < it->second.size(); i++)
                {
                    std::cout << bd_date[it->second[i]].name << std::endl;
                }
                check = true;
                break;
            }
        }
        if (check)
            break;
        else
            it++;
    }
}

/*
Nina 2004-01-21
Gosha 2002-03-21
Nick 2001-06-05
Ed 2001-04-18
Vlada 2003-05-28
Anton 2001-11-22
Pasha 2001-04-18
Anny 2003-05-28
end
*/