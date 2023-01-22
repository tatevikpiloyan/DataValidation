#ifndef DATE_H
#define DATE_H


#include <iostream>

struct Date
{
    Date(const std::string&);

    std::size_t day;
    std::size_t month;
    std::size_t year;

};

#endif // DATE_H