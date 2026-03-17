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
    // Constructor
    Queue() noexcept : elements(new T[1]), front(0), size(0), capacity(1)
    {}
    
    // Destructor
    ~Queue() noexcept
    {
        delete[] elements;
    }
    
    // Add an item to the back of the queue
    void enqueue(const T& value)
    {
        if (size >= capacity)
        {
            resize(capacity * 2);
        }
        
        size_t back = (front + size) % capacity;
        elements[back] = value;
        size++;
    }
    
    // Remove the item from the front of the queue
    void dequeue() noexcept
    {
        if (size > 0)
        {
            front = (front + 1) % capacity;
            size--;
            shrink();
        }
    }
    
    // Get the front value without removing it
    T& peek() noexcept
    {
        return elements[front];
    }
    
    // Check if queue is empty
    bool empty() const noexcept
    {
        return size == 0;
    }
    
    // Get the size of the queue
    size_t get_size() const noexcept
    {
        return size;
    }
    
    // Get the capacity of the queue
    size_t get_capacity() const noexcept
    {
        return capacity;
    }
    
    // Clear the queue
    void clear() noexcept
    {
        front = 0;
        size = 0;
        shrink();
    }
};