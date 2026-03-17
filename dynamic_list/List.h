#pragma once

#include <cassert>
#include <memory>
#include <algorithm>

template<class T>
class List
{
private:
    T* elements;
    size_t size;
    size_t capacity;
    
    void resize(size_t new_capacity)
    {
        T* new_elements = new T[new_capacity];
        
        for (size_t i = 0; i < size; ++i)
        {
            new_elements[i] = elements[i];
        }
        
        delete[] elements;
        elements = new_elements;
        capacity = new_capacity;
    }
    
    void shrink_capacity()
    {
        // Only shrink if we're using less than 1/4 of capacity and capacity > 1
        if (capacity > 1 && size <= capacity / 4)
        {
            size_t new_capacity = capacity / 2;
            if (new_capacity < 1) new_capacity = 1;
            resize(new_capacity);
        }
    }

public:
    // Implement the following
    // below:

    List() noexcept;
    ~List() noexcept;

    const T& operator[](size_t index) const noexcept;
    void append(const T& value);
    void remove(const T& value);

    bool empty() const noexcept;
    void clear() noexcept;

    size_t get_size() const noexcept;
    size_t get_capacity() const noexcept;
};