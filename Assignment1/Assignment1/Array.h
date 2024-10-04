#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Array 
{
protected:
    T* m_array;
    int m_size;
    int m_capacity;

public:
    Array(int capacity = 2)
        : m_size(0), m_capacity(capacity) 
    {
        m_array = new T[m_capacity];
    }

    virtual ~Array() 
    {
        delete[] m_array;
    }

    virtual void Expand() 
    {
        m_capacity *= 2;
        T* newArray = new T[m_capacity];

        for (int i = 0; i < m_size; ++i) 
        {
            newArray[i] = m_array[i];
        }

        delete[] m_array;
        m_array = newArray;
    }

    virtual void Push(const T& element) = 0;

    int GetSize() const 
    { 
        return m_size; 
    }

    T& operator[](int index) 
    {
        if (index < 0 || index >= m_size)
        {
            throw std::out_of_range("Index out of range");
        }

        return m_array[index];
    }
};