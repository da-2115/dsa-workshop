#include <iostream>
#include <string>

// Replace with List.h or ListSolution.h depending on whether you are testing your List or the solution one
#include "List.h"

void test_list()
{
    List<std::string> list;

    list.append("Dylan");
    list.append("Oscar");
    list.append("Renad");
    list.append("Adrian");
    list.append("Leslie");
    list.append("Fraser");
    list.append("Markus");

    std::cout << "Size of list: " << list.get_size() << std::endl; // Should be 7
    std::cout << "Capacity of list: " << list.get_capacity() << std::endl; // Should be 8

    std::cout << "Should print Oscar: " << list[1] << std::endl;

    list.remove("Oscar");

    std::cout << "Should print Renad: " << list[1] << std::endl;

    list.clear();

    std::cout << "Size of list: " << list.get_size() << std::endl; // Should be 0
    std::cout << "Capacity of list: " << list.get_capacity() << std::endl; // Should be 1

    // Add a name to the now intital/cleared list:
    list.append("Chuck Norris");
    list.append("John Cena");
    list.append("Some other dude");
    std::cout << list[0] << ", " << list[1] << ", " << list[2] << std::endl; // Should print Chuck Norris, John Cena, Some other dude
    std::cout << "Size of list: " << list.get_size() << std::endl; // Should be 3
    std::cout << "Capacity of list: " << list.get_capacity() << std::endl; // Should be 4

    list.clear();
}

int main()
{
    test_list();

    return 0;
}