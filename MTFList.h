//
//  p1.h
//  Data Structures
//
//  Created by Danny Gletner on 1/20/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#ifndef MTFList_h
#define MTFList_h

#include <iostream>
#include <string>
#include <fstream>
#include "node.h"
#include <chrono>
#include <iomanip>

using namespace std;

class MTFList{
    
public:
    
    MTFList();
    void add(int item);
    void find(int item);
    void moveToFront(Node<int>* item, Node<int>* current);
    void printInternal();
    bool empty();
    int getCount();
private:
    Node<int>* top;
    Node<int>* back;
    int count;
    
};



#endif /* p1_h */
