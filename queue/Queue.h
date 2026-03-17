#pragma once

template<class T>
class Queue
{
private:
    T* elements;
    size_t front;
    size_t size;
    size_t capacity;
    
    void resize(size_t new_capacity)
    {
        T* new_elements = new T[new_capacity];
        
        // Copy elements in order from front
        for (size_t i = 0; i < size; ++i)
        {
            new_elements[i] = elements[(front + i) % capacity];
        }
        
        delete[] elements;
        elements = new_elements;
        front = 0;
        capacity = new_capacity;
    }
    
    void shrink()
    {
        // Keep shrinking while we're using 50% or less of capacity and capacity > 1
        while (capacity > 1 && size <= capacity / 2)
        {
            size_t new_capacity = capacity / 2;
            if (new_capacity < 1) new_capacity = 1;
            resize(new_capacity);
        }
    }
    
public:
    // Implement the below
    // methods:

    Queue() noexcept;
    ~Queue() noexcept;
    
    void enqueue(const T& value);
    void dequeue() noexcept;
    
    T& peek() noexcept;
    
    bool empty() const noexcept;
    
    size_t get_size() const noexcept;
    size_t get_capacity() const noexcept;
    
    void clear() noexcept;
};