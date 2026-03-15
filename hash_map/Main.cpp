#include <iostream>
#include <string>

// Replace with HashMap.h or HashMapSolution.h depending on whether you are testing your HashMap or the solution one
#include "HashMapSolution.h"

void test_hash_map()
{
    HashMap<int, std::string> hash_map;

    hash_map.insert(0, "Dylan");
    hash_map.insert(1, "Oscar");
    hash_map.insert(2, "Renad");
    hash_map.insert(3, "Adrian");

    std::cout << hash_map.get(2).value() << std::endl; // Should print Renad

    hash_map.remove(1);

    std::cout << hash_map.get(1).value_or("Not found") << std::endl; // Should print Not found
    
    hash_map.insert(1, "Fraser");

    std::cout << hash_map.get(1).value_or("Not found") << std::endl; // Should print Fraser

    // Test copy and move semantics

    HashMap<int, int> h_map1;
    HashMap<int, int>& h_map2 = h_map1;
}

int main()
{
    test_hash_map();

    return 0;
}