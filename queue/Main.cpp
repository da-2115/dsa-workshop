#include <iostream>

#include "Queue.h"

void test_queue()
{
    Queue<size_t> q;

    for (size_t i = 0; i < 64; ++i)
    {
        q.enqueue(i);
    }

    std::cout << "Front value: " << q.peek() << std::endl;
    std::cout << "Queue capacity: " << q.get_capacity() << std::endl;
    std::cout << "Queue size: " << q.get_size() << std::endl;

    // Dequeue (32) of the elements
    for (size_t i = 0; i < 32; ++i)
    {
        q.dequeue();
    }

    std::cout << "Front value: " << q.peek() << std::endl;
    std::cout << "Queue capacity: " << q.get_capacity() << std::endl;
    std::cout << "Queue size: " << q.get_size() << std::endl;

    // Dequeue (16) of the elements
    for (size_t i = 0; i < 16; ++i)
    {
        q.dequeue();
    }

    std::cout << "Front value: " << q.peek() << std::endl;
    std::cout << "Queue capacity: " << q.get_capacity() << std::endl;
    std::cout << "Queue size: " << q.get_size() << std::endl;

    q.clear();

    std::cout << "Queue capacity: " << q.get_capacity() << std::endl;
    std::cout << "Queue size: " << q.get_size() << std::endl;
    std::cout << "Is queue empty? " << q.empty() << std::endl;
}

int main()
{
    test_queue();

    return 0;
}