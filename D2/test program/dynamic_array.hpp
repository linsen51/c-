#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <cstdlib>
#include "splashkit.h"

template<typename T>
class dynamic_array
{
    private:

    T *data_ptr;

    int size;
    int capacity;

    void resize(int new_capacity)
    {
        T *new_ptr;
        
        new_ptr = (T *)realloc(data_ptr, sizeof(T) * new_capacity);

        if(new_ptr != NULL)
        {
            data_ptr = new_ptr;
            capacity = new_capacity;
        }
        else
        {
            write_line("Memory reallocation failed ");
        }
    }

    public:

    dynamic_array()
    {
        size = 0;
        capacity = 2;

        data_ptr = (T *)malloc(sizeof(T) * capacity);

        if(data_ptr == NULL)
        {
            write_line("Memory allocation failed");
        }
    }

    ~dynamic_array()
    {
        free(data_ptr);
        data_ptr = NULL;
    }

    void add(T value)
    {
        if(size >= capacity)
        {
            resize(capacity * 2);
        }
        data_ptr[size] = value;

        size++;
    }

    void remove(int index)
    {
        if(index < 0 || index >= size)
        {
            write_line("Invalid index ");

            return;
        }

        for(int i = index; i < size - 1; i++)
        {
            data_ptr[i] = data_ptr[i + 1];
        }
        size--;

        if(size < capacity / 4 && capacity > 2)
        {
            resize(capacity / 2);
        }
    }

    T get(int index)
    {
        return data_ptr[index];
    }

    void print()
    {
        for(int i = 0; i < size; i++)
        {
            write_line(to_string(data_ptr[i]));
        }
    }

    void print_capacity()
    {
        write_line("Capacity: " + to_string(capacity));
    }

    int length()
    {
        return size;
    }
    
};

#endif