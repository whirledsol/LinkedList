//  LinkedList.cpp
//  Implementation for the LinkedList class
//  To demonstrate dynamic memory management
//  Programmed by: Dr. Monisha Pulimood
//  Modified by:

//  ** Add your maintenance documentation as appropriate **


#include "LinkedList.h"

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList(){
    
    clearList();

}

LinkedList::LinkedList(LinkedList& other){
    
    *this = other;
    
}


LinkedList& LinkedList::operator=(LinkedList& other){
    //check if both objects are equal
    if (this == &other){
        return *this;
    }
    //empty this list
    if(!isEmpty()){
        clearList();
    }
    
    cout << "Assignment operator " << endl;

    //create pointers
    Node* tempPtr;
    Node* t1;
    Node* t2;
    
    //t2 works with this list
    t2 = head;
    //t1 works with the other list
    t1 = other.head;
    
    //traverse the other list
    while(t1 != NULL){
        //create a new node
        tempPtr = new Node;
        //node gets the data from other other list
        tempPtr-> data = t1-> data;
        //temporarily set the link to null
        tempPtr-> nptr = NULL;
        //increment the t1 pointer
        t1 = t1-> nptr;
        
        
        //link the previous node in this list to the current tempPtr
        if (head == NULL)
        {
            head = tempPtr;
        }
        else
        {
            t2-> nptr = tempPtr;
        }
        
        t2 = tempPtr;

    //end while loop
    }
    
    cout << "Exiting assignment " << endl;
    //return the new list
    return *this;
}

void LinkedList::clearList(){
    while(!isEmpty()){
        removeFmFront();
    }
    head = NULL;
}


void LinkedList::addToFront (int item)
{
    Node* location;
    location = new Node;
    location->data = item;
    location->nptr = head;
    head = location;
    
}


void LinkedList::insertItem(int item)
{
    
    Node* currPtr;
    Node* prevPtr;
    Node* tempPtr;
    
    tempPtr->data = item;
    tempPtr->nptr= NULL;
    
    
    if (!isEmpty())
    {
        //use prevPtr and currPtr to traverse the list
        prevPtr = NULL;
        currPtr = head;
    
        while(currPtr != NULL && item > currPtr->data)
        {
            prevPtr = currPtr;
            currPtr = currPtr->nptr;
        }
        
        if(prevPtr == NULL)
        {
            tempPtr->nptr = head;
            head = tempPtr;
            
        }
        else
        {
            //at the end of the list or at the correct insert position
            tempPtr->nptr = currPtr;
            prevPtr->nptr = tempPtr;
        }
        
    }
    else
    {
            //if list is empty
            head = tempPtr;
    }
}

void LinkedList::removeFmFront ()
{
    if(!isEmpty()){
        Node*  tempPtr;
        tempPtr = head;
        head = head->nptr;
        delete  tempPtr;
    }
}


void LinkedList::removeItem (int item)
{
    
    // DO: add code here to find and remove specified item
    
}


bool LinkedList::isEmpty (void) const
{
    return (head == NULL);
}


istream& operator>> (istream &lhs, LinkedList  &rhs)
{
    int item;
    lhs >> item;
    cout<<item;
    /***** For Part 1 use addToFront() *******
     ***** For Part 2 use insertItem() *******/
    rhs.addToFront(item);
    
    return lhs;
}


ostream& operator<< (ostream& lhs, const LinkedList &rhs)
{
    Node* tempPtr;// = new Node;
    tempPtr = rhs.head;
    
    while(tempPtr != NULL){
        lhs<<tempPtr->data;
        lhs<<", ";
        tempPtr = tempPtr->nptr;
    }
    
    return lhs;
}






