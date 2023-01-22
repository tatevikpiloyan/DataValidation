#include <iostream>
#include <algorithm>

#include "dataValidation.h"

const dataValidation::VecS dataValidation::domainNames = {"gmail.com", "mail.ru", "yahoo.com", "icloud.com"};
const std::string dataValidation::prefixChars = {"-_./"};
const char dataValidation::asperand = '@';
const char dataValidation::capitalFirstLetter = 'A';
const char dataValidation::smallFirstLetter = 'a';
const char dataValidation::capitalLastLetter = 'Z';
const char dataValidation::smallLastLetter = 'z';
const char dataValidation::firstNumber = '0';
const char dataValidation::lastNumber = '9';
const char dataValidation::subChar = '-';
const std::string dataValidation::protocol = {"http"};
const std::string dataValidation::scheme = {"://"};
const char dataValidation::dot = '.';
const std::string dataValidation::hostPref = {"www"};


bool dataValidation::validEmail(const std::string& email)
{
    auto asperandPos = email.find(asperand);
    if ((asperandPos == std::string::npos) || (asperandPos == 0))
    {
        return false;
    }
    auto domain = email.substr(asperandPos + 1);
    if (std::find_if(domainNames.begin(), domainNames.end(),
        [&](const std::string& str) { return str == domain; }) == domainNames.end())
    {
        return false;
    }
    auto prefix = email.substr(0, asperandPos);
    return validName(prefix);
}

bool dataValidation::validURL(const std::string& url)
{
    auto schemePos = url.find(scheme);
    auto protocolPos = url.find(protocol);
    if (protocolPos != std::string::npos)
    {
        if ((protocolPos + protocol.size()) != schemePos)
        {
            return false;
        }
    }
    else if (schemePos != std::string::npos)
    {
        if ((schemePos - protocol.size()) != schemePos)
        {
            return false;
        }
    }
    else
    {
        schemePos = -scheme.size();
    }
    return validHost(url.substr(schemePos + scheme.size()));
}

bool dataValidation::validHost(const std::string& host)
{
    int size = host.size();
    auto prefixPos = host.find(hostPref);
    auto dotPos = host.find(dot);
    if ((prefixPos == std::string::npos) || (dotPos == std::string::npos)) { return false; }    
    if (dotPos != (prefixPos + hostPref.size())) { return false; }
    if (host.find(dot, dotPos + 1) == std::string::npos) { return false; }
    return validName(host.substr(dotPos + 1));
}


bool dataValidation::validName(const std::string& name)
{
    int size = name.size();
    bool charFlag = false;
    for (int i = 0; i < size; ++i)
    {
        if (!((name[i] >= capitalFirstLetter && name[i] <= capitalLastLetter)
            || (name[i] >= smallFirstLetter && name[i] <= smallLastLetter)
            || (name[i] >= firstNumber && name[i] <= lastNumber)))
        {
            auto charPos = prefixChars.find(name[i]);
            if (charPos != std::string::npos)
            {
                if (charFlag) { return false; }
                charFlag = true;
                continue;
            }
            return false;
        }
        charFlag = false;
    }
    return true;
}


bool dataValidation::validDate(const std::string& string)
{
    date = new Date(string);
    if (!((date->day >= 1 && date->day <= 31)
        && (date->month >= 1 && date->month <= 12)
        && (date->year >= 1 && date->year <= 9999)))
    {
        return false;
    }
    if (!((date->year % 4 == 0)
        && (date->year % 100 != 0) || (date->year % 400 != 0)))
    {
        if (date->month == 2)
        {
            return date->day <= 28;
        }
    }
    return true;
}

bool dataValidation::validNumber(const std::string& number)
{
    int size = number.size();
    int opPos = number.find(subChar);
    if (opPos != std::string::npos)
    {
        if (number[opPos + 1] == firstNumber)
        {
            return false;
        }
    }
    if ((opPos > 0) || ((opPos + 1) >= size))
    {
        return false;
    }
    for (int i = opPos + 1; i < size; ++i)
    {
        if (!(number[i] >= firstNumber && number[i] <= lastNumber))
        {
            return false;
        }
    }
    return true;
}