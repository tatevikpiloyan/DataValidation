#include <iostream>
#include "dataValidation.h"

int main()
{
    dataValidation data;
    // std::cout << std::boolalpha << data.validEmail("abd.sc@gmail.com") << std::endl;
    // std::cout << std::boolalpha << data.validNumber("63720823") << std::endl;
    // std::cout << std::boolalpha << data.validURL("www.Hello.cm") << std::endl;
    std::cout << std::boolalpha << data.validDate("2/02/2933") << std::endl;

}