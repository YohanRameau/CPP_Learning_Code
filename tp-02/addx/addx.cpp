#include <iostream>

/* Ici on construit une structure avec une variable static stockant un entier commun à chaque innstance de la classe 
   et une méthode apply permettant d'incrémenter d'un certain nombre (définit à l'instanciation de la classe).
   A la fin nous avons donc la même valeur de global_sum pour chaque variable de type AddX 
*/

struct AddX {
  static int global_sum;
  const int _x;
  
  AddX(const int x) : _x{x}
  {}
    
  void apply() const { global_sum += _x; }
};

int AddX::global_sum = 0; // initialisation  Si on enlève cette ligne l'utilisation de la variable static demeurre impossible car elle n'a pas de class-initializer.

int main() {
  AddX add10{10}, add5{5};
  add10.apply();
  add5.apply();

  AddX add1{1};
  add1.apply();
  add1.apply();
  
  std::cout << add5.global_sum << std::endl << add1.global_sum << std::endl;
  return 0;
}