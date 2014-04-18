//  LinkedList.h
//  Class definition for the LinkedList class
//  To demonstrate dynamic memory management
//  Programmed by: Dr. Monisha Pulimood
//  Modified by:

//  ** Add your maintenance documentation as appropriate **

#include <iostream>

using namespace std;

#if !defined (LINKEDLIST_H)
#define LINKEDLIST_H


struct Node
{
    int data;
    Node * nptr;
};


class LinkedList
{
private:
    

    Node* head;
    
public:
    LinkedList ();
    //destructor
    ~LinkedList();
    //assignment operator
    LinkedList& operator=(LinkedList&);
    //copy constructor
    LinkedList(LinkedList&);
    //clears the list
    void clearList();
    
	// DO: Add any methods that may be needed
	
    bool isEmpty (void) const;
    
    void addToFront(int);    //add item to front of list
    void insertItem(int);    //add item in sorted order
    void removeFmFront();    //remove item from front of list
    void removeItem(int);    //find and remove specified item
    
    friend ostream& operator<< (ostream &, const LinkedList &);
    friend istream& operator>> (istream &, LinkedList &);
};



#endif



