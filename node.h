//
//  node.h
//  Data Structures
//
//  Created by Danny Gletner on 1/20/20.
//  Copyright © 2020 Danny Gletner. All rights reserved.
//

#ifndef node_h
#define node_h

template <typename T>
class Node {
    
public:
    Node( const T & = T() );
    void setObject( const T & );
    T &getObject();
    void setNextPtr( Node<T> * );
    Node<T> *getNextPtr() const;
    
private:
    T object;
    Node<T> *nextPtr;
    
}; // Node<T> class


template <typename T>
Node<T>::Node( const T &object )
{
    this->object = object;
    this->nextPtr = 0;
} // Node<T>::Node

template <typename T>
void Node<T>::setObject( const T &object )
{
    this->object = object;
} // Node<T>::setObject

template <typename T>
T &Node<T>::getObject()
{
    return object;
} // Node<T>::getObject

template <typename T>
void Node<T>::setNextPtr( Node<T> *nextPtr )
{
    this->nextPtr = nextPtr;
} // Node<T>::setNextPtr

template <typename T>
Node<T> *Node<T>::getNextPtr() const
{
    return nextPtr;
} // Node<T>::getNextPtr

#endif // node_h


