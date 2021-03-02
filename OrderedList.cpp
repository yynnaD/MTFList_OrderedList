//
//  OrderedList.cpp
//  Data Structures
//
//  Created by Danny Gletner on 1/26/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#include "OrderedList.h"

/*
 * Constructor
 */
OrderedList::OrderedList(){}

/*
 * Explicit constructor
 * cap is the capacity of the array, i.e. number of items to be added
 */
OrderedList::OrderedList(int cap){
    count = 0;
    list = new int[cap];
    size = 0;
}

/*
 * Adds an int item to the orderedList
 * item is an int to be added
 */
void OrderedList::add(int item){
    list[size] = item;
    size++;
}

/*
 * A binary search method.
 * item is the item to be searched for
 */
void OrderedList::binarySearch(int item){
    int low = 0;
    int high = size-1;
    
    while(low <= high) {
        int mid = (low + high)/2;
        count++;
        if(item ==  list[mid]){
            break;
        }
        else if(item > list[mid]){
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
}

/*
 * mergeSort driver method.
 * takes in a list of ints and creates an array of the same size
 * Both arrays are then passed in to mergeSort
 */
void OrderedList::mergeSort(int* list){
    int temp[size];
    
    mergeSort(list, temp, 0, size-1);
}

/*
 * A merge sort method.
 * list is a list of ints to be sorted
 * temp[] is an array to place sorted result
 * start is the index marking the beginning of the array
 * end is the index marking the end of the array
 */
void OrderedList::mergeSort(int* list, int temp[], int start, int end){
    if(start < end){
        int mid = (start + end)/2;
        mergeSort(list, temp, start, mid);
        mergeSort(list, temp, mid + 1, end);
        merge(list, temp, start, mid+1, end); //needs implementation
    }
}


/* Sorts and merges 2 arrays
 * list is a list of ints to be sorted
 * temp is an array to place the merged result
 * left is the left most index of the subarray
 * right is the start of the right subarray
 * end is the end index of the right array
 */
void OrderedList::merge(int *list, int temp[], int left, int right, int end){
    int endL = right -1;
    int index = left;
    
    while(left <= endL && right <= end){
        count++;
        if(list[left] < list[right]){
            temp[index] = list[left];
            left++;
            index++;
        }
        else{
            temp[index] = list[right];
            right++;
            index++;
        }
    }
    while(left <= endL){
        temp[index] = list[left];
        left++;
        index++;
    }
    while(right <= end){
        temp[index] = list[right];
        right++;
        index++;
    }
    for(int i = 0; i < index; i++){
        list[i] = temp[i];
    }
}

/*
 * returns true if the size of the orderedList is 0
 */
bool OrderedList::empty(){
    return size == 0;
}

int OrderedList::getSize(){
    return size;
}

int OrderedList::getCount(){
    return count;
}

int* OrderedList::getList(){
    return list;
}

//prints the contents of the orderedList
void OrderedList::printInternal(){
    for(unsigned i = 0; i < size; i++){
        cout << list[i] << " ";
    }
    cout << endl;
}
