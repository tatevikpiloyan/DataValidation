#ifndef DATA_VALIDATION
#define DATA_VALIDATION

#include <string>
#include <vector>

#include "date.h"

class dataValidation
{
public:
    dataValidation() = default;
    ~dataValidation() = default;

public:
    bool validEmail(const std::string&);
    bool validURL(const std::string&);
    bool validHost(const std::string&);
    bool validDate(const std::string&);
    bool validNumber(const std::string&);
    bool validName(const std::string&);
    
private:
    using VecS = std::vector<std::string>;
    static const VecS domainNames;
    static const std::string prefixChars;
    static const char asperand;
    static const char capitalFirstLetter;
    static const char smallFirstLetter;
    static const char capitalLastLetter;
    static const char smallLastLetter;
    static const char firstNumber;
    static const char lastNumber;
    static const char subChar;
    static const std::string protocol;
    static const std::string scheme;
    static const char dot;
    static const std::string hostPref;
    Date* date;
};

#endif // DATA_VALIDATION