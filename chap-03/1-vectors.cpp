#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
    // Constructeur numéro 10 : Initialise le vector à partir d'un initializer-list.
    
    std::vector<int> vec_1 = std::vector<int>{4, 0};

     // Constructeur numéro 3 : initialise un vector avec count object ici quatre zéro.
    
    std::vector<int> vec_2 = std::vector<int>(4, 0);
    
    
    
    // Initialisation du vector avec le constructueur
    // utilisant les itérateurs de début et de fin d'un tableau.
    
    int array[] = {0, 1, 2, 3, 4, 5};
    int* begin = array;
    int* end = array + 6;
    std::vector<int> vec_3 = std::vector<int>(begin, end);
    
    
    // Accès aux éléments 
    
    int length = vec_3.size();
    for (int i = 0; i < length/2; i++)
    {
        std::cout << "echange entre:"<<vec_3[i] << "et" << vec_3[length - 1 - i] << std::endl;
        std::swap(vec_3[i], vec_3[length - i - 1]);
    }
    for(auto v:vec_3)
    {
        std::cout << v << std::endl; 
    }
    
    // Insertions
    // Deux fonctions permettent d'inserer à nimporte quel indice un élément dans le tableau. 
    // insert qui ajoute simplement un élément dans le tableau et emplace qui copy l'élément pour un construire un nouveau dans le tableau  

    // Display the content of values.
    /*for (auto it = vec_3.begin(); it != vec_3.end(); ++it)
    {
        std::cout << *it << std::endl;
    }*/

    // Duplicate each element of vector
    for (auto it = vec_3.begin(); it != vec_3.end(); it += 2)
    {
        it = vec_3.insert(it,*it);
    }
    
    for (auto it = vec_3.begin(); it != vec_3.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    // suppression
    
    // Avec pop_back()
    while(!vec_3.empty())
    {
        vec_3.pop_back();
    }

    // Avec erase() il faut utiliser un opérateur
    for (size_t i = 0; i < 3; i++)
    {
        vec_3[i] = i;
    }
    
    vec_3.erase(vec_3.begin() + 2);

    std::vector vec_4 {0,1,2,3,4,5,6,7,8,9,10};
    // vec_4.erase(vec_4.begin() + 2, vec_4.begin() + 7 );
    for(auto v : vec_4)
    {
        std::cout << v << std::endl;
    }

    const auto it = std::find(vec_4.begin(), vec_4.end(), 9);
    if(it != vec_4.end())
    {
        vec_4.erase(it);
    }


    return 0;

}