#include <set>
#include <iostream>
#include <unordered_set>
#include <functional>
#include <map>
#include <unordered_map>

#include "keys.h"

int main()
{
    // Set
    std::set<ComparableDog> dogSet;
    ComparableDog ted ("Ted", "Labrador");
    ComparableDog rex ("Rex", "Berger Allemand");
    dogSet.emplace(ted);
    dogSet.emplace(rex);
    std::cout << dogSet.size() <<std::endl;
    
    ComparableDog ted_clone = ted;
    dogSet.emplace(ted_clone);
    std::cout << dogSet.size() <<std::endl;
    
    // Unordered Set
    HashableDog leo ("Leo", "Bull Terrier");
    HashableDog rouky ("Rouky", "Dalamtien");
    std::unordered_set<HashableDog> dogUnorderedset{leo, rouky};

    // map

    using Owner = std::pair<std::string, std::string>;
    std::map<ComparableDog, Owner> owners;
    owners.insert({ted,{"John","Doe"}});
    owners.insert_or_assign(ted, std::make_pair("John","Rachid"));

    return 0;
}