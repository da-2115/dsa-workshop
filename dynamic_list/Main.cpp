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

    std::cout << "Size of list: " << list.get_size() << std::endl;
    std::cout << "Capacity of list: " << list.get_capacity() << std::endl;

    std::cout << "Should print Oscar: " << list[1] << std::endl;

    list.remove("Oscar");

    std::cout << "Should print Renad: " << list[1] << std::endl;
}

int main()
{
    test_list();

    return 0;
}