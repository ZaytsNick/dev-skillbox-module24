#include <iostream>
#include <ctime>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

int main()
{
    std::time_t t = std::time(nullptr);
    std::cout << "Enter minutes and seconds: ";
    std::tm temp = *std::localtime(&t);
    std::cin >> std::get_time(&temp, "%M:%S");
    t = std::time(nullptr);
    std::tm end_timer = *std::localtime(&t);
    end_timer.tm_min = (end_timer.tm_min + temp.tm_min) % 60 + (end_timer.tm_sec + temp.tm_sec) / 60;
    end_timer.tm_sec = (end_timer.tm_sec + temp.tm_sec) % 60;
    // temp = *std::localtime(&t);
    // std::tm start_timer = temp;

    int second(0), minute(0);
    while ((temp.tm_min != end_timer.tm_min) || (temp.tm_sec != end_timer.tm_sec))
    {
        t = std::time(nullptr);
        temp = *std::localtime(&t);
        if (second !=( end_timer.tm_sec - temp.tm_sec < 0 ? end_timer.tm_sec - temp.tm_sec + 60 : end_timer.tm_sec - temp.tm_sec)  || minute != (end_timer.tm_min - (end_timer.tm_sec - temp.tm_sec < 0 ? 1 : 0) - temp.tm_min))
        {
            second = end_timer.tm_sec - temp.tm_sec < 0 ? end_timer.tm_sec - temp.tm_sec + 60 : end_timer.tm_sec - temp.tm_sec;
            minute = end_timer.tm_min - (end_timer.tm_sec - temp.tm_sec < 0 ? 1 : 0) - temp.tm_min;
            std::cout << minute << ":" << second << std::endl;
        }
    }
    // std::cout << std::put_time(&end_timer, "%M:%S") << " " << std::put_time(&start_timer, "%M:%S");
    std::cout << "DING! DING! DING!";
}