#ifndef SONG_HPP
#define SONG_HPP

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

        T *new_ptr = new T[new_capacity];


        for(int i = 0; i < size; i++)
        {
            new_ptr[i] = data_ptr[i];
        }


        delete[] data_ptr;


        data_ptr = new_ptr;


        capacity = new_capacity;
    }

public:


    dynamic_array()
    {
        size = 0;

        capacity = 2;


        data_ptr = new T[capacity];
    }


    ~dynamic_array()
    {
        delete[] data_ptr;
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
            write_line("Invalid index");

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


    T& get(int index)
    {
        return data_ptr[index];
    }


    const T& get(int index) const
    {
        return data_ptr[index];
    }


    int length() const
    {
        return size;
    }


    T& operator[](int index)
    {
        return data_ptr[index];
    }


    const T& operator[](int index) const
    {
        return data_ptr[index];
    }
};

#endif