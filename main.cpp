//
//  main.cpp
//  Data Structures
//
//  Created by Danny Gletner on 1/20/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//
#include "MTFList.h"
#include "OrderedList.h"
/*
 * Main function. Takes in a file of data, creates a MTFList with that data,
 * as well as an orderedList with the same data.
 * Times the nanoseconds it takes to mergeSort and query the orderedList
 * Times the nanoseconds it takes to query the MTFList
 * Outputs both lists, times, and traversal counts to the terminal.
 * Compares the times and outputs which was faster.
 */

/*
 In order for other main functions to run with file organziation like this
 the other main functions that are not intended to be running must be commented out.
 */


int main(int argc, const char * argv[]) {
    string filename = argv[1];
    ifstream inFile;
    unsigned size = 0;
    unsigned searchSize = 0;
    int item = 0;
    MTFList MTFlist;
    OrderedList orderedList;
    
    inFile.open(filename.c_str());
    if(!inFile){
        cout << "ERROR: File open unsuccessful" << endl;
        exit(EXIT_FAILURE);
    }
    
    //take in # of items to be added
    inFile >> size;
    orderedList = OrderedList(size);
    
    //add items to each list
    for(unsigned i = 0; i < size; i++){
        inFile >> item;
        orderedList.add(item);
        MTFlist.add(item);
    }
    //take in items to be searched
    inFile >> searchSize;
    int temp[searchSize];
    for(int i = 0; i <= searchSize; i++){
        inFile >> item;
        temp[i] = item;
    }
    
    //timing of mergeSort and binarySearch
    auto start = chrono::high_resolution_clock().now();
    orderedList.mergeSort(orderedList.getList());
    for(int i = 0; i < searchSize; i++){
        orderedList.binarySearch(temp[i]);
    }
    auto finish = chrono::high_resolution_clock().now();
    double orderedTime = chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    
    //time searching MTFList
    auto start2 =  chrono::high_resolution_clock().now();
    for(int i = 0; i < searchSize; i++){
        MTFlist.find(temp[i]);
    }
    auto finish2 =  chrono::high_resolution_clock().now();
    double MTFTime = chrono::duration_cast<std::chrono::nanoseconds>(finish2-start2).count();
    
    //need to output everything
    cout << "OrderedList: "; orderedList.printInternal();
    cout << "---------------------" << endl;
    cout << "MTFList after Queries: "; MTFlist.printInternal();
    cout << "---------------------" << endl;
    
    cout << "Time taken to sort and query OrderedList: ";
    cout << fixed << setprecision(2) << orderedTime << "ns" << endl;
    cout << "Query count: " << orderedList.getCount() << endl;
    
    cout << "Time taken to query MTFList: ";
    cout << fixed << setprecision(2) << MTFTime << "ns" << endl;
    cout << "Traversal Count: " << MTFlist.getCount() << endl;
    
    if(orderedTime < MTFTime){
        cout << "Ordered List is faster by " << MTFTime-orderedTime << " nanoseconds!" << endl;
    }
    else
        cout << "MTFList is faster by " << orderedTime-MTFTime << " nanoseconds!" << endl;
    
    inFile.close();
}

