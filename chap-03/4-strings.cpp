#include <iostream>

/*
concaténation -> operator+ : auto str_3 = str1 + str2;
extration de sous-chaîne -> substr : auto str_me = std::string { "find me" }.substr(5, 2);
recherche -> find : auto pos = str.find("abc");
comparaison -> operator== : auto are_equal = (str1 == str2);
remplacement -> replace : std::string { "this is old" }.replace(8, 3, "new");
*/

void print_in_console(std::string_view str)
{
    std::cout << str << std::endl;
}

int main()
{
    print_in_console("Je m'appelle Yohan");
    return 0;
}
