#pragma once
#include <array>
#include <string>
#include <vector>
#include <map>
#include <string_view>

class PhoneNumber
{
private:
    std::array<int,5> _numbers;    
public:
    PhoneNumber(int n1, int n2, int n3, int n4, int n5);
    PhoneNumber(const PhoneNumber& other);
    bool is_valid() const;
    PhoneNumber& operator=(const PhoneNumber& other);
};

class Person
{
private:
    std::string _first_name;
    std::string _last_name;
    PhoneNumber _phone_number;
public:
    Person(const std::string& first_name, const std::string& last_name);
    Person(const std::string& first_name, const std::string& last_name, const PhoneNumber& phone_number);
    const std::string get_full_name() const;
    const std::string get_first_name() const;
    const std::string get_last_name() const;
    const PhoneNumber& get_phone_number() const;
    void              set_phone_number(const PhoneNumber& phone_number);
    bool              operator<(const Person& other);
};


using Identity = std::pair<std::string, std::string>;
using Lineage = std::vector<Person>;

class PhoneBook
{
private:
    std::map<Identity, Lineage> _personMap;
public:
    void insert(const Person& p);
    bool empty();
    const Lineage& operator[](int index);
    const Person& first_of_family(std::string_view family_name);
};