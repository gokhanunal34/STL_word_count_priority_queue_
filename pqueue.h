#ifndef PQUEUE_H
#define PQUEUE_H

#include <queue> 	// priority queue contained in queue
#include <iostream>
#include <iterator> 
using namespace std;
// *****************************************************************
// * Very simple example of a priority queue embedded in a         *
// * template.   Note that the whole implementation was done       *
// * inline and a .hpp file was not used.                          *
// * Author: Dr. David A. Gaitros                                  *
// *****************************************************************
template <typename T>
class PQueue
{
    struct itemstruct
    {
        T   theitem;
        int priority;
    };
    // *****************************************************************
    // * A very important part of the priority Queue.   This is what  *
    // * the queue uses to determine how to move something up and     *
    // * down the queue.   It is usually in the form of a struct      *
    // * or a class.   Here we use a struct.                          *
    // ****************************************************************
    struct compare
    {
        bool operator ()(const itemstruct& lhs,
            const itemstruct& rhs)
        {
            if (lhs.priority < rhs.priority) return true;
            else return false;
        }
    };

public:
    void AddItem(const T X, const int p)
    {
        //cout << "Inserting " << X << " Of Priority " << p << endl;
        static itemstruct tempitem;
        tempitem.theitem = X;
        tempitem.priority = p;
        myqueue.push(tempitem);
    }
    int GetSize() { return myqueue.size(); }
    bool IsEmpty() { return myqueue.empty(); }
    // *****************************************************************
    // * The print is desctructive in that it has to pop the elements  *
    // * to get through the list.  I tried to use the [] operator to   *
    // * iterate through the list but it is not allowed.               *
    // *****************************************************************
    void Print()
    {
        //cout << endl << " The list of size " << myqueue.size() << endl;
        itemstruct tempitem{};

	//I added the counter to this file
	//and I changed the while and added if else statement
	//accordingly. 
	int counter = 0;
        while (counter < 10)
        {
		if (counter < myqueue.size())
		{
			cout << "Item: " << myqueue.top().theitem << " - " << "Occured " << myqueue.top().priority
			<< " times."<< "\n";
			myqueue.pop();
			++counter;
		}
		else
		{
			break;
		}
        }

    };
private:
    // *****************************************************************
    // * Instantiation of the priority queue.  It needs three things:  *
    // * (1) What thing you are storing...(2) What STL you are using   *
    // *     to store it and (4) the struct or class you are calling   *
    // *     as the comparator.                                        *
    // *****************************************************************

    priority_queue<itemstruct, vector<itemstruct>, compare> myqueue;
};

#endif 


