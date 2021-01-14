#include <iostream>
#include <string>

class Person
{
public:
    Person(const std::string& name, const std::string& surname)
        : _name {name}
        , _surname {surname}
        {}

    void set_age(unsigned int age)         { _age = age; }
    std::string get_full_name() const { return _surname + " " + _name; }
    unsigned int       get_age() const  { return _age; }

    

private:
    std::string  _name;
    std::string  _surname;
    unsigned int _age = 0u;
};

int main()
{
    Person p {"Batman"};
    
    p.set_age(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}
