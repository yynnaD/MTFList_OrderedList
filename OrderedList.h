//
//  OrderedList.hpp
//  Data Structures
//
//  Created by Danny Gletner on 1/26/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#ifndef OrderedList_h
#define OrderedList_h

#include <stdio.h>
#include "node.h"
#include <iostream>
#include <string>
#include <cmath>
#include <chrono>
#include <iomanip>

using namespace std;

class OrderedList{
public:
    OrderedList();
    OrderedList(int cap);
    void add(int item);
    void binarySearch(int item);
    void mergeSort(int* list);
    void mergeSort(int* list, int temp[], int start, int end);
    void merge(int* list, int temp[], int start, int middle, int end);
    void printInternal();
    bool empty();
    int getCount();
    int getSize();
    int* getList();
private:
    int count;
    int* list;
    int size;

};
#endif /* OrderedList_h */
