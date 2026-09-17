#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "splashkit.h"

template<typename T>
class node
{
public:
    T data;
    node<T> *next;
};

template<typename T>
class linked_list
{
    public:
    node<T> *first;
    node<T> *last;

    linked_list()
    {
        first = nullptr;
        last = nullptr;
    }

    node<T>* add_node(T data)
    {
        node<T> *new_node = new node<T>();

        new_node->data = data;
        new_node->next = nullptr;

        if(first == nullptr)
        {
            first = new_node;
            last = new_node;
        }
        else
        {
            last->next = new_node;
            last = new_node;
        }
        return new_node;
    }

    void print()
    {
        node<T> *current = first;

        while(current != nullptr)
        {
            write_line(to_string(current->data));

            current = current->next;
        }
    }
    node<T>* find_previous_node(node<T> *target)
    {
        if(target == first)
        {
            return nullptr;
        }

        node<T> *current = first;

        while(current != nullptr)
        {
            if(current->next == target)
            {
                return current;
            }

            current = current->next;
        }

        throw string("Node not found");
    }

    void prepend(T data)
    {
        node<T> *new_node = new node<T>();

        new_node->data = data;

        new_node->next = first;

        first = new_node;

        if(last == nullptr)
        {
            last = new_node;
        }
    }

    void insert_after(node<T> *current_node, T data)  
    {
        node<T> *new_node = new node<T>();

        new_node->data = data;

        new_node->next = current_node->next;

        current_node->next = new_node;

        if(last == current_node)
        {
            last = new_node;
        }
    }

    void insert_before(node<T> *current_node, T data)
    {
        if(current_node == first)
        {
            prepend(data);

            return;
        }
        node<T> *previous_node = find_previous_node(current_node);

        node<T> *new_node = new node<T>();

        new_node->data = data;

        previous_node->next = new_node;

        new_node->next = current_node;
    }
};

#endif