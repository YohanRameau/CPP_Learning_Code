# TP4 - Héritage

## Exercice 1 - Appels téléphoniques

### Question 1 

`` const Person désigne une variable de type personne ne pouvant être modifié.``

`` const Person& désigne une référence vers un objet de type personne, cette référence est fixé et ne peut être modifié pour être attribué à un objet de type Person différent.``

En pratique stocker un attribut par référence permet de ne pas copier la mémoire de l'objet référencier, on ne peut plus construire de constructeur par défaut.

### Question 4

Pour redéfinir le comportement de la classe j'ai placé l'attribut ``_owner`` de la classe mère ``Phone``  en visibilité protected au lieu de private, j'ai également créer un getter pour avoir accès au champ _name. Je retourne Phone::ring() en cas d'égalité de position.

### Question 5
l'appel de ``HomePhone::ring`` sur une référence de type ``Phone`` s'apparente à du polymorphisme.
Les classes sur lesquelles on peut effectuer ce type d'appel sont les classes polymorphe. Pour réaliser ce genre de classe il faut :
- rendre le destructeur de la classe de base virtuel
- écrire override sur les fonctions redéfinies
- comprendre la notion de virtual table
- passer ses objets par références (ou par pointeurs quand cela est nécessaire) pour que les appels virtuals soient correctement exécutés. 
### Question 8

Le code compile, on remarque que malgrès que far_phone soit du type dynamique HomePhone c'est l'appel de Phone::ring() qui est effectué. Cela est du au fait que normal phone ne soit pas en référence et qu'une copie est effectué. normal_phone est donc typé statiquement et dynamiquement Phone.

### Question 9

Une classe qui ne peut plus être instanciable s'apparente à une interface

## Exercice 2 - Formes

### Question 0 

Je propose d'utilise le conteneur de la librairie <list> correspondant à une liste doublement chaîné, car il possède toutes les fonctions citées (front(), emplace_back(), merge(), et erase()

