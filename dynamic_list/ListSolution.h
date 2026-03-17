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
    List() noexcept : elements(new T[1]), size(0), capacity(1)
    {}
    
    // Destructor - free heap allocated memory
    ~List() noexcept
    {
        delete[] elements;
    }

    // Index operator getter
    const T& operator[](size_t index) const noexcept
    {
        assert(index < size);

        return elements[index];
    }

    // Append an item to the end of the list
    void append(const T& value)
    {
        if (size >= capacity)
        {
            resize(capacity * 2);
        }

        elements[size++] = value;
    }

    // Remove a value from the list
    void remove(const T& value)
    {
        for (size_t i = 0; i < size; ++i)
        {
            if (elements[i] == value)
            {
                // Shift elements left
                for (size_t j = i; j < size - 1; ++j)
                {
                    elements[j] = elements[j + 1];
                }
                
                size--;
                shrink_capacity();
                return;
            }
        }
    }

    bool empty() const noexcept
    {
        return size == 0;
    }
    
    // Clear the list and shrink capacity
    void clear() noexcept
    {
        size = 0;
        
        if (capacity > 1)
        {
            resize(1);
        }
    }
    
    size_t get_size() const noexcept
    {
        return size;
    }
    
    size_t get_capacity() const noexcept
    {
        return capacity;
    }
};