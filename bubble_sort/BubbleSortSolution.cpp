#include <iostream>
#include <vector>
#include <cstddef>
#include <algorithm>

// Bubble sort
void bubble_sort(std::vector<int>& vec)
{
    bool swapped;

    for (size_t i = 0; i < vec.size() - 1; ++i)
    {
        // Set swapped to false, initially
        swapped = false;

        for (size_t j = 0; j < vec.size() - i - 1; ++j)
        {
            // If vec at index j is greater than vec at the next index j + 1
            if(vec[j] > vec[j + 1])
            {
                // Swap the two elements using the standard library swap function and set swapped to true
                std::swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
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