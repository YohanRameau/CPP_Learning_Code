#pragma once

#include <string>

class ComparableDog
{
public:
    ComparableDog(const std::string& name, const std::string& species)
        : _name { name }, _species { species }
    {}

    bool operator<(const ComparableDog& other) const
    {
        if (_name == other._name)
        {
            return _species < other._species;
        }
        return _name < other._name;
    }

private:
    std::string _name;
    std::string _species;
};

class HashableDog
{
public:
    HashableDog(const std::string& name, const std::string& species)
        : _name { name }, _species { species }
    {}
    
    size_t get_hash() const
    {
        std::hash<std::string> hash_fcn;
        size_t                 hash_of_name = hash_fcn(d._name);
        size_t                 hash_of_species = hash_fcn(d._species);
        return hash_of_name ^ hash_of_species;
    }

    bool operator==(const HashableDog& other) const
    {
        return _name == other._name && _species == other._species;
    }
        
    
private:
    std::string _name;
    std::string _species;
};


namespace std {

template <>
struct hash<HashableDog>
{
    size_t operator()(const HashableDog& dog) const
    {
        return dog.get_hash();
    }
};

}

