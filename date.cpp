#include <iostream>
#include <string>

#include "date.h"

Date::Date(const std::string& date)
{
    int size = date.size();
    auto dayPos = date.find('/');
    day = std::stoi(date.substr(0, dayPos));
    auto monthPos = date.find('/', dayPos + 1);
    month = std::stoi(date.substr(dayPos + 1, size - monthPos));
    year = std::stoi(date.substr(monthPos + 1));
}