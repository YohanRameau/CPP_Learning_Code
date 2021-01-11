#include <iostream>
#include <string>

int main()
{
    using namespace std;
    string word;
    for (int i = 0; i < 10; i++)
    {
        cout << "Dites-moi quelque chose !" << endl;
        cin >> word;
        cout << "Vous avez dit: " << word << endl;
    }

    

   /*
   int number = 0;
    while(number != -1)
    {
        std::cout << "Entrer un chiffre:" << std::endl;
        std::cin >> number;
        std::cout << "Vous avez entrer " << number << std::endl;
    }*/
    /*do
    {
        std::cout << "Entrer un chiffre:" << std::endl;
        std::cin >> number;
        std::cout << "Vous avez entrer " << number << std::endl;
    } while (number != -1);
    */
    
    /*for (int i = 0; i < 10; i++)
    {
        std::cout << "Entrer un chiffre:" << std::endl;
        std::cin >> number;
        std::cout << "Vous avez entrer " << number << std::endl;
    }*/
    

}