#include <iostream>
#include <string>
class Person
{
private:
    std::string    _name;
    unsigned short _age = 0;

public:
    void set_name(const std::string& name)
    {
        _name = name;
    }
    void set_age(unsigned short age)
    {
        _age = age;
    }

    std::string get_name(void) const
    {
        return _name;
    }
    int get_age(void) const
    {
        return _age;
    }
};

int main()
{
    Person p;

    p.set_name("Batman");
    p.set_age(23);

    std::cout << "Person named '" << p.get_name() << "' is " << p.get_age() << " years old." << std::endl;

    return 0;
}

