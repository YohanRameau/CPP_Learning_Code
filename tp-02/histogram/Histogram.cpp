#include "Histogram.h"
#include <iostream>

Histogram::Histogram() : 
    _count {new unsigned char[26] {}}
    {
        std::cout << "Appel du constructeur par défaut." << std::endl;
    }

Histogram::Histogram(const Histogram& histogram) :
    Histogram()
    {
        for (size_t i = 0; i < 26; i++)
        {
            _count[i] = histogram._count[i];
        }
        
        std::cout << "Appel du constructeur de copie" << std::endl;
    }
Histogram::~Histogram(){
    std::cout << "Appel du destructeur." << std::endl;
    delete[] _count;
}

Histogram& Histogram::operator=(const Histogram& other)
{
    if(this != &other){
        _count = other._count;
    }
    return *this;
}

void Histogram::print() const{
    char c = 'a';
    for (size_t i = 0; i < 26; i++)
    {
        std::cout << c << ":" << _count[i] << std::endl;
        c++;
    }
    
}

void Histogram::analyze(const std::string& s)
{
    for (size_t i = 0; i < s.length(); i++)
    {
        char letter = ::tolower(s[i]) ;
        _count[letter - 'a'] ++;
    }
    
}