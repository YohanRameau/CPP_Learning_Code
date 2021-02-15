#include "PhoneBook.h"
#include <string>

                   /////// Personn ///////
PhoneNumber default_number = PhoneNumber(-1,-1,-1,-1,-1);

Person::Person(const std::string& first_name, const std::string& last_name)
    : Person(first_name, last_name, default_number)
{
}


Person::Person(const std::string& first_name, const std::string& last_name, const PhoneNumber& phone_number)
    : _first_name {first_name}, _last_name {last_name}, _phone_number {phone_number}
{
}

const std::string Person::get_full_name() const
{
    return _first_name + " " + _last_name;;
}

const PhoneNumber& Person::get_phone_number() const
{
    return _phone_number;
}

void Person::set_phone_number(const PhoneNumber& phone_number)
{
    _phone_number = phone_number;
}

bool Person::operator<(const Person& other)
{
    if(other._last_name == _last_name)
    {
        return _first_name < other._first_name;
    }
    return _last_name < other._last_name;
}

/*
const PhoneNumber Person::get_phone_number() const;
void              Person::set_phone_number();
*/

                /////// PhoneNumber ///////
PhoneNumber::PhoneNumber(int n1, int n2, int n3, int n4, int n5)
    : _numbers {n1, n2, n3, n4, n5}
{
}

PhoneNumber::PhoneNumber(const PhoneNumber& other)
    : _numbers{other._numbers}
{
}

PhoneNumber& PhoneNumber::operator=(const PhoneNumber& other)
{
    if (this != &other)
    {
        for (size_t i = 0; i < 5; i++)
        {
            _numbers[i] = other._numbers[i];
        }
    }
    return *this;
}

bool PhoneNumber::is_valid() const
{
    for(auto value : _numbers)
    {
        if (value < 0 || value > 99 ){
            return false;
        }
    }
    return true;
}
