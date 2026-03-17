#include <iostream>
#include <string>

// Replace with HashMap.h or HashMapSolution.h depending on whether you are testing your HashMap or the solution one
#include "HashMap.h"

void test_hash_map()
{
    // Test hash map semantics

    HashMap<int, std::string> hash_map;

    // Insert 4 entries into hash_map
    hash_map.insert(0, "Dylan");
    hash_map.insert(1, "Oscar");
    hash_map.insert(2, "Renad");
    hash_map.insert(3, "Adrian");

    std::cout << hash_map.get(2).value() << std::endl; // Should print Renad

    // Remove Oscar from the hash map
    hash_map.remove(1);

    std::cout << hash_map.get(1).value_or("Not found") << std::endl; // Should print Not found
    
    // Insert Fraser into the hash map
    hash_map.insert(1, "Fraser");

    std::cout << hash_map.get(1).value_or("Not found") << std::endl; // Should print Fraser

    // Test copy semantics
    std::cout << "Testing copy semantics" << std::endl;
    
    HashMap<int, std::string> original;
    original.insert(1, "Oscar");
    original.insert(2, "Dylan");
    original.insert(3, "Markus");
    
    // Copy constructor
    HashMap<int, std::string> copy1(original);
    std::cout << "Copy constructor - get(2): " << copy1.get(2).value_or("Not found") << std::endl; // Should print Dylan
    
    // Copy assignment
    HashMap<int, std::string> copy2;
    copy2 = original;
    std::cout << "Copy assignment - get(3): " << copy2.get(3).value_or("Not found") << std::endl; // Should print Markus
    
    // Modify original and verify copies are independent
    original.remove(2);
    std::cout << "After removing from original - copy1.get(2): " << copy1.get(2).value_or("Not found") << std::endl; // Should print Dylan
    std::cout << "After removing from original - original.get(2): " << original.get(2).value_or("Not found") << std::endl; // Should print Not found
    
    // Test move semantics
    std::cout << "Testing move semantics" << std::endl;
    
    HashMap<int, std::string> donor;
    donor.insert(10, "X");
    donor.insert(20, "Y");
    donor.insert(30, "Z");
    
    // Move constructor
    HashMap<int, std::string> moved1(std::move(donor));
    std::cout << "Move constructor - get(20): " << moved1.get(20).value_or("Not found") << std::endl; // Should print Y
    
    // Move assignment
    HashMap<int, std::string> moved2;
    moved2.insert(99, "Placeholder");
    HashMap<int, std::string> donor2;
    donor2.insert(100, "A");
    donor2.insert(200, "B");
    moved2 = std::move(donor2);
    std::cout << "Move assignment - get(100): " << moved2.get(100).value_or("Not found") << std::endl; // Should print A
    std::cout << "After move assignment - moved2.get(99): " << moved2.get(99).value_or("Not found") << std::endl; // Should print Not found

    std::cout << "Done." << std::endl;
}

int main()
{
    test_hash_map();

    return 0;
}