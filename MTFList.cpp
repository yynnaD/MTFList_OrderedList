//
//  p1.cpp
//  Data Structures
//
//  Created by Danny Gletner on 1/20/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#include "MTFList.h"

/*
 * Constructor, creates an empty list.
 */
MTFList::MTFList(){
    count = 0;
    top = 0;
    back = 0;
}

/*
 * Prints the internal contents of the list.
 */
void MTFList::printInternal() {
    Node<int>* current = top;
    while(current != 0){
        cout << current->getObject() << " ";
        current = current->getNextPtr();
    }
    cout << endl;
}

/*
 * Creates a Node for an item and adds it to the front of the list.
 */
void MTFList::add(int item){
    Node<int> *newNode = new Node<int>(item);
    if(empty()) {
        back = newNode;
        top = newNode;
    }
    else {
        newNode->setNextPtr(top);
        top = newNode;
    }
    
}

/*
 * Takes in a target item, searches the list for it, and moves it to the front of the list.
 * Keeps a count of iterations made searching in this way.
 */
void MTFList::find(int item){
    Node<int>* prev = top;
    Node<int>* current = top->getNextPtr();
    
    //check if item is at top
    if(prev->getObject() == item){ count++; }
    else{
        count++; //iterate count anyway because top was checked
        while(current != 0){
            count++; //check is made in next line
            if(current->getObject() == item){
                moveToFront(current, prev);
                break;
            }
            else{
                prev = prev->getNextPtr();
                current = current->getNextPtr();
            }
        }//while
    }//else
}

bool MTFList::empty(){
    return (top == 0);
}

/*
 * Takes in a target Node (item) and the Node before it (prev)
 * and moves the item to the front of the list.
 */
void MTFList::moveToFront(Node<int>* item, Node<int>* prev){
    prev->setNextPtr(item->getNextPtr());
    item->setNextPtr(top);
    top = item;
    if(back == item){back = prev;}
}

/*
 * Returns the value of the count variable
 */
int MTFList::getCount(){
    return count;
}
