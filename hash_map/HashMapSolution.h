#pragma once

#include <vector>
#include <cstddef>
#include <algorithm>
#include <optional>

#include "Item.h"

template<class K, class V>
class HashMap
{
private:
    enum class State { EMPTY, OCCUPIED, DELETED };

    std::vector<Item<K, V>> data;
    std::vector<State> states;
    size_t capacity;
    size_t size;

    void swap(HashMap& other)
    {
        std::swap(data, other.data);
        std::swap(states, other.states);
        std::swap(capacity, other.capacity);
        std::swap(size, other.size);
    }

    int hash(const K& key) const noexcept
    {
        if (capacity == 0)
        {
            return 0;
        }
        
        return std::hash<K>{}(key) % capacity;
    }

    void resize(size_t new_capacity)
    {
        if (new_capacity == 0)
        {
            return;
        }

        std::vector<Item<K, V>> old_data = data;
        std::vector<State> old_states = states;

        data.resize(new_capacity);
        states.assign(new_capacity, State::EMPTY);
        capacity = new_capacity;
        size = 0;

        for (size_t i = 0; i < old_data.size(); ++i)
        {
            if (old_states[i] == State::OCCUPIED)
            {
                insert(old_data[i].key, old_data[i].value);
            }
        }
    }

public:
    HashMap() noexcept : data{}, states{}, capacity(0), size(0)
    {}

    HashMap(const HashMap& other) noexcept : data(other.data), states(other.states), capacity(other.capacity), size(other.size)
    {}

    HashMap& operator=(const HashMap& other)
    {
        if (this != &other)
        {
            data = other.data;
            states = other.states;
            capacity = other.capacity;
            size = other.size;
        }
        
        return *this;
    }

    HashMap(HashMap&& other) noexcept
    {
        swap(other);
    }

    HashMap& operator=(HashMap&& other)
    {
        if (this != &other)
        {
            swap(other);
        }

        return *this;
    }

    void insert(const K& key, const V& value) noexcept
    {
        if (capacity == 0)
        {
            resize(16);
        }

        if (size >= capacity / 2)
        {
            resize(capacity * 2);
        }

        int index = hash(key);
        int first_deleted = -1;
        int start_index = index;

        while (true)
        {
            if (states[index] == State::EMPTY)
            {
                if (first_deleted != -1)
                {
                    index = first_deleted;
                }
                ++size;
                break;
            }

            else if (states[index] == State::DELETED && first_deleted == -1)
            {
                first_deleted = index;
            }
            
            else if (states[index] == State::OCCUPIED && data[index].key == key)
            {
                break;
            }

            index = (index + 1) % capacity;

            if (index == start_index && states[index] != State::OCCUPIED)
            {
                if (first_deleted != -1)
                {
                    index = first_deleted;
                }
                ++size;
                break;
            }
        }

        data[index] = {key, value};
        states[index] = State::OCCUPIED;
    }

    std::optional<V> get(const K& key) const noexcept
    {
        if (capacity == 0) return std::nullopt;

        int index = hash(key);
        int start_index = index;

        while (states[index] != State::EMPTY)
        {
            if (states[index] == State::OCCUPIED && data[index].key == key)
            {
                return data[index].value;
            }

            index = (index + 1) % capacity;

            if (index == start_index)
            {
                break;
            }
        }

        return std::nullopt;
    }

    void remove(const K& key) noexcept
    {
        if (capacity == 0) return;

        int index = hash(key);
        int start_index = index;

        while (states[index] != State::EMPTY)
        {
            if (states[index] == State::OCCUPIED && data[index].key == key)
            {
                states[index] = State::DELETED;
                --size;
                return;
            }

            index = (index + 1) % capacity;

            if (index == start_index)
            {
                break;
            }
        }
    }
};