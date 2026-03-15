#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>

void bubble_sort(std::vector<int>& vec)
{
    // Your code goes here!
}

int main()
{
    std::vector<int> data = { 5, 3, 9, 8, 4, 4, 6 };

    std::cout << "Original vector: ";

    for (int& i : data)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    bubble_sort(data);

    std::cout << "Sorted vector using bubble sort: ";

    for (int& i : data)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}