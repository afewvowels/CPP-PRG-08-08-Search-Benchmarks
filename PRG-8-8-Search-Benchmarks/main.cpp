//
//  main.cpp
//  PRG-8-8-Search-Benchmarks
//
//  Created by Keith Smith on 10/9/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that has an array of at least 20 integers. It should call a function that
//  uses the linear search algorithm to locate one of the values. The function should keep
//  a count of the number of comparisons it makes until it finds the value. The program
//  then should call a function that uses the binary search algorithm to locate the same
//  value. It should also keep count of the number of comparisons it makes. Display these
//  values on the screen.

#include <iostream>
#include <random>

using namespace std;

const int INT_ARRAY_SIZE = 20;
const int INT_VALUE_MIN = -99999;
const int INT_VALUE_MAX = 99999;

int intArrayToSearch[INT_ARRAY_SIZE];

// Functions used to populate array and select search term
void populateArray();
int selectForSearch();
int generateRandom(const int, const int);

// Functions for searching and sorting
int searchLinear(const int);
int searchBinary(const int);
int sortBubble();
int sortSelection();

int main() {
    
    int intIntegerToFind;
    int intComparisons;
    
    populateArray();
    
    intIntegerToFind = selectForSearch();
    
    intComparisons = searchLinear(intIntegerToFind);
    
    cout << "Linear search took: " << intComparisons << " comparisons." << endl;
    
    intComparisons = sortBubble();
    
    cout << "The bubble sort took: " << intComparisons << " swaps." << endl;
    
    intComparisons = searchBinary(intIntegerToFind);
    
    cout << "Binary search took: " << intComparisons << " comparisons." << endl;
    
    populateArray();
    
    intComparisons = sortSelection();
    
    cout << "The selection sort took: " << intComparisons << " swaps." << endl;
    
    return 0;
}

void populateArray()
{
    for(int i = 0 ; i < INT_ARRAY_SIZE ; i++)
    {
        intArrayToSearch[i] = generateRandom(INT_VALUE_MIN, INT_VALUE_MAX);
    }
}

int selectForSearch()
{
    int intSearch;
    int intIndexRandom;
    
    intIndexRandom = generateRandom(0, INT_ARRAY_SIZE);
    
    intSearch = intArrayToSearch[intIndexRandom];
    
    return intSearch;
}

int generateRandom(const int intLow, const int intHigh)
{
    int intIntegerRandom;
    
    random_device rd;
    
    mt19937 engine(rd());
    
    uniform_int_distribution<int> distribution(intLow, intHigh);
    
    intIntegerRandom = distribution(engine);
    
    return intIntegerRandom;
}

int searchLinear(const int intSearch)
{
    int intComparisons = 0;
    
    for(int i = 0 ; i < INT_ARRAY_SIZE ; i++)
    {
        if(intArrayToSearch[i] != intSearch)
        {
            intComparisons++;
        }
        else if(intArrayToSearch[i] == intSearch)
        {
            intComparisons++;
            break;
        }
    }
    
    return intComparisons;
}

int searchBinary(const int intSearch)
{
    int intComparisons = 0;
    
    int intFirst = 0;
    int intMiddle;
    int intLast = INT_ARRAY_SIZE - 1;
    
    while(intFirst <= intLast)
    {
        intMiddle = (intFirst + intLast) / 2;
        if(intArrayToSearch[intMiddle] == intSearch)
        {
            intComparisons++;
            break;
        }
        else if(intArrayToSearch[intMiddle] > intSearch)
        {
            intComparisons++;
            intLast = intMiddle - 1;
        }
        else if(intArrayToSearch[intMiddle] < intSearch)
        {
            intComparisons++;
            intFirst = intMiddle + 1;
        }
    }
    
    return intComparisons;
}

int sortBubble()
{
    int intSwaps = 0;
    int intMaxElement;
    int intTemp;
    
    for(intMaxElement = INT_ARRAY_SIZE - 1 ; intMaxElement > 0 ; intMaxElement--)
    {
        for(int index = 0 ; index < intMaxElement ; index++)
        {
            if(intArrayToSearch[index] > intArrayToSearch[index + 1])
            {
                intSwaps++;
                intTemp = intArrayToSearch[index];
                intArrayToSearch[index] = intArrayToSearch[index + 1];
                intArrayToSearch[index + 1] = intTemp;
            }
        }
    }
    
    return intSwaps;
}

int sortSelection()
{
    int intSwaps = 0;
    int intMinIndex;
    int intMinValue;
    int intTemp;
    
    for(int start = 0 ; start < (INT_ARRAY_SIZE - 1) ; start++)
    {
        intMinIndex = start;
        intMinValue = intArrayToSearch[start];
        for(int index = start + 1 ; index < INT_ARRAY_SIZE ; index++)
        {
            if(intArrayToSearch[index] < intMinValue)
            {
                intSwaps++;
                intMinValue = intArrayToSearch[index];
                intMinIndex = index;
            }
        }
        intTemp = intArrayToSearch[intMinIndex];
        intArrayToSearch[intMinIndex] = intArrayToSearch[start];
        intArrayToSearch[start] = intTemp;
    }
    
    return intSwaps;
}
