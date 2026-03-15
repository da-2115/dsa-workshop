#pragma once

#include <cassert>
#include <memory>
#include <algorithm>

template<class T>
class List
{
private:
    std::unique_ptr<T[]> elements;
    size_t size;
    size_t capacity;
    
    void resize()
    {
        size_t new_capacity = capacity == 0 ? 1 : capacity * 2;
        std::unique_ptr<T[]> new_elements(new T[new_capacity]);
        
        for (size_t i = 0; i < size; ++i)
        {
            new_elements[i] = elements[i];
        }
        
        elements = std::move(new_elements);
        capacity = new_capacity;
    }
    
public:
    List() noexcept : elements(nullptr), size(0), capacity(0)
    {}

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
            resize();
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
                return;
            }
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