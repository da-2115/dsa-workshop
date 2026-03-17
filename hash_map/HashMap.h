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

    void swap(HashMap& other);

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
    // Implement the below
    // methods:
    
    HashMap() noexcept;

    HashMap(const HashMap& other) noexcept;
    HashMap& operator=(const HashMap& other);

    HashMap(HashMap&& other) noexcept;
    HashMap& operator=(HashMap&& other);

    void insert(const K& key, const V& value) noexcept;

    std::optional<V> get(const K& key) const noexcept;

    void remove(const K& key) noexcept;
};