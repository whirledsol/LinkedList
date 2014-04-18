//  LinkedListDriver.cpp
//  Driver program to test the implementation of the LinkedList class
//  To demonstrate dynamic memory management
//  Programmed by: Dr. Monisha Pulimood
//  Modified by:

//  ** Add your maintenance documentation as appropriate **

#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

bool inputFmFile (LinkedList &);

int main(void)
{
	
    LinkedList list1, list2, list3;

    /********                PART 1.                   ********
     ********  Comment out the code below for Part 2.  ********/
    
    cout << "The linked lists add data to and remove data from the front of the list." << endl;
    
    cout << "Enter data for the first list (from intData4.csv). " << endl;
    
    if (inputFmFile(list1))
        cout << "The data in the first list is: " << endl << list1 << endl;
    else
        cout << "Error reading data from file." << endl;
    
    cout << "Enter data for the second list (from intData3.csv). " << endl;
    
    if (inputFmFile(list2))
        cout << "The data in the second list is: " << endl << list2 << endl;
    else
        cout << "Error reading data from file." << endl;
    
    cout << "Before list3 = list1; list3 is: " << endl << list3 << endl;
    list3 = list1;
    cout << "After list3 = list1; list3 is: " << endl << list3 << endl;
    list1.removeFmFront();
    list1.removeFmFront();
    
    cout << "After removing some items, list1 is: " << endl << list1 << endl;
    cout << "After removing some items from list1, list3 is: " << endl << list3 << endl;
    
    LinkedList list4 (list2);
    cout << "list4 created as a copy of list2 is: " << endl << list4 << endl;
    
    list2.removeFmFront();
    list2.removeFmFront();
    list2.removeFmFront();
    list2.removeFmFront();
    list2.removeFmFront();
    
     cout << "After removing items list2 is: " << endl << list2 << endl;
     
     cout << "List 1 is: "<< list1 << endl;
     cout << "List 2 is: "<< list2 << endl;
     cout << "List 3 is: "<< list3 << endl;
     cout << "List 4 is: "<< list4 << endl;
     
    /********    Comment out up to here for Part 2 ********/
    
    
    
    
    /********                PART 2.                 ********
     ********  Uncomment the code below for Part 2.  ********
     
     
     
	cout << "The linked lists maintain data sorted in ascending order." << endl;
	
    cout << "Enter data for the first list (from intData4.csv). " << endl;
	
	if (inputFmFile(list1)) 
		cout << "The data in the first list is: " << endl << list1 << endl;
	else 
		cout << "Error reading data from file." << endl;
	
	cout << "Enter data for the second list (from intData3.csv). " << endl;
    
	if (inputFmFile(list2)) 
		cout << "The data in the second list is: " << endl << list2 << endl;
	else 
		cout << "Error reading data from file." << endl;
    
    list3 = list1;
    cout << "After list3 = list1; list3 is: " << endl << list3 << endl;
    list1.removeItem(3785);
    list1.removeItem(37536);
   
    cout << "After removing some items, list1 is: " << endl << list1 << endl;
    cout << "After removing some items from list1, list3 is: " << endl << list3 << endl;
     
    LinkedList list4 (list2);
	cout << "list4 created as a copy of list2 is: " << endl << list4 << endl;
    
    list2.removeItem(12566);
    list2.removeItem(123969);
    list2.removeItem(1250442);
    list2.removeItem(1277515);
    list2.removeItem(1245050);
    
    cout << "After removing items list2 is: " << endl << list2 << endl;
    
    cout << "List 1 is: "<< list1 << endl;
    cout << "List 2 is: "<< list2 << endl;
    cout << "List 3 is: "<< list3 << endl;
    cout << "List 4 is: "<< list4 << endl;
    ********    Uncomment up to here for Part 2 ********/
    
    cout << endl;
	cout << "Exiting program." << endl;
	return 0;
}


bool inputFmFile (LinkedList &inputList)
{
	bool worked = true;
	string inFileName;
	ifstream inStr;
	int element = 0;
	
	do 
	{
		cout << "Enter name of file to read from: ";
		cin >> inFileName;
		
		inStr.open (inFileName.c_str());
		if (inStr.fail())
		{
			cerr << "Error opening file. Try again." << endl;
			inStr.clear();
			inStr.ignore(80, '\n');
			worked = false;
		}
		else 
			worked = true;
		
	} while (!worked);
	
	while (!inStr.eof())
	{
		inStr >> element;
        /***** For Part 1 use addToFront(element) *******
         ***** For Part 2 use insertItem(element) *******/
        
        inputList.addToFront(element);
		//inputList.insertItem(element);
	}
	
	inStr.close();
	return worked;
}
