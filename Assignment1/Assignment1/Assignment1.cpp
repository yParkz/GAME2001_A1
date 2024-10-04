// Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"
#include "UnorderedArray.h"
#include "OrderedArray.h"

int main()
{
        UnorderedArray<int> uArr;
        uArr.Push(40);
        uArr.Push(80);
        uArr.Push(60);

        std::cout << "Unordered Array: ";
        for (int i = 0; i < uArr.GetSize(); ++i) 
        {
            std::cout << uArr[i] << " ";
        }
        std::cout << std::endl;

        OrderedArray<int> oArr(2, false);
        oArr.Push(40);
        oArr.Push(60);
        oArr.Push(80);

        std::cout << "Ordered Array: ";
        for (int i = 0; i < oArr.GetSize(); ++i) 
        {
            std::cout << oArr[i] << " ";
        }
        std::cout << std::endl;

        OrderedArray<int> oArrNoDuplicates(2, true);
        oArrNoDuplicates.Push(40);
        oArrNoDuplicates.Push(60);
        oArrNoDuplicates.Push(40);
        oArrNoDuplicates.Push(80);

        std::cout << "Ordered Array (No Duplicates): ";
        for (int i = 0; i < oArrNoDuplicates.GetSize(); ++i) 
        {
            std::cout << oArrNoDuplicates[i] << " ";
        }
        std::cout << std::endl;

        return 0;
}