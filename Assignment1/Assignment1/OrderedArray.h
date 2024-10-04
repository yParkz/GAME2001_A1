#pragma once
#include "Array.h"
template <typename T>
class OrderedArray : public Array<T>
{
private:
    bool m_preventDuplicates;

public:
    OrderedArray(int capacity = 2, bool preventDuplicates = false)
        : Array<T>(capacity), m_preventDuplicates(preventDuplicates) {}

    void Push(const T& element) override 
    {
        if (this->m_size >= this->m_capacity) 
        {
            this->Expand();
        }

        if (m_preventDuplicates && Contains(element)) 
        {
            return;
        }

        int i;
        for (i = this->m_size - 1; (i >= 0 && this->m_array[i] > element); i--) 
        {
            this->m_array[i + 1] = this->m_array[i];
        }

        this->m_array[i + 1] = element;
        this->m_size++;
    }

    bool Contains(const T& element) 
    {
        for (int i = 0; i < this->m_size; ++i) 
        {
            if (this->m_array[i] == element) 
            {
                return true;
            }
        }
        return false;
    }
};