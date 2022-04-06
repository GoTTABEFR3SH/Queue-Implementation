/* --------------------------------------------------------------------------------------------------
	This file holds the implementation details for the functions found in myQueueHeader.h
-----------------------------------------------------------------------------------------------------*/

#include "myQueueHeader.h" //include header
#include <iostream> //for input output
#include <assert.h> // so we can use the assert function

using namespace std; // so we dont have to type std:: before eveything
template<class Type>
bool myQueue<Type>::isEmptyQueue() const // checks if queue is empty
{
	return (queueFront == nullptr); // is queueFront equals nullptr than the queue is empty
}

template <class Type>
void myQueue<Type>::initializeQueue() // takes queue and makes it empty
{
	nodeType<Type>* temp; // create temporary node thats going to be deleted 
	while (queueFront != nullptr) // while the queue is not empty
	{
		temp = queueFront; //set temp to the front of queue
		queueFront = queueFront->next; // advance queuefront to the next element in the queue
		delete temp; // deletes temp which is now the old queueFront
	}
	queueRear = nullptr; // Then once queue is empty set the rest as they would be in an empty queue
	current = nullptr;
	count = 0;
}

template <class Type>
void myQueue<Type>::enQueue(const Type& newElement) // adds a new element to the rear of the queue
{
	nodeType<Type>* newNode; // create pointer to newnode
	newNode = new nodeType<Type>; // create the new node
	newNode->info = newElement; // set the new nodes info the the inputed element
	newNode->back = nullptr; //set to nullptr for now
	newNode->next = nullptr; // set to nullptr for now

	if (queueFront == nullptr) // if this node is the first in the queue
	{
		queueFront = newNode;
		queueRear = newNode;
		current = newNode;
	}

	else // if this node is not the first in the queue 
	{
		newNode->back = queueRear; // set the back link of newnode to queueRear which therfore attaches it to the rest of the queue
		queueRear->next = newNode; // take the node that is currently queueRear and set the forward link to the newnode completing the connection
		queueRear = queueRear->next; // advance queueRear so it now equals the newly added node
		current = queueFront; // just here to make sure current gets reset to the front element this is more specific to this assignment but it wont hurt other use cases
	}
	
	count++; //update count so we can keep track of queue size
}

template <class Type>
Type myQueue<Type>::front() const // returns front element of the queue the const is there because we dont want to actually mody anything just to return the front info
{
	assert(queueFront != nullptr); // make sure we are not calling on an empty queue this is more for debugging I have found than for anything else 
	return queueFront->info; // return the front elements info 
}

template <class Type>
Type myQueue<Type>::back() const // returns the rear elements info 
{
	assert(queueRear != nullptr); // same thing as front
	return queueRear->info; // same thing as front
}

template <class Type>
Type myQueue<Type>::returnCurrent() const // returns the nodes info that current is pointing at 
{
	assert(current != nullptr); // same as front
	return current->info; // same as front
}




template <class Type>
void myQueue<Type>::deQueue() // deletes element from the front of the queue
{
	nodeType<Type>* temp; // create a temp pointer to keep track of the front element we are going to delete
	if (!isEmptyQueue()) // if queue is not empty
	{
		temp = queueFront; // set temp to point to the front
		queueFront = queueFront->next; // advance queueFront to the next element 
		queueFront->back = nullptr; // update the back link 
		current = queueFront; // update current so it resets
		delete temp; // delete temp which is pointing to the old queueFront
		count--; // decrease count
	}

	else  // or the queue is empty
	{
		cout << "Can not delete from empty queue" << endl;
	}
}

template <class Type>
int myQueue<Type>::size() // returns count indicating the size of the queue
{
	return count;
}

template <class Type>
void myQueue<Type>::moveCurrentForward() // moves the pointer current to point to the next node
{
	if (current->next != nullptr && current != nullptr) // if current is not already pointing at the end of the list
	{
		current = current->next; // advance current
	}

	else // if current is at the end of the queue
	{
		cout << "End Of Queue" << endl;
	}
}

template <class Type>
void myQueue<Type>::moveCurrentBackwards() // moves current to point to the previous node
{
	if (current->back != nullptr && current != nullptr) // if current isn't already pointing at the front of the queue
	{
		current = current->back; // move current back 
	}
	else // current is already at the front of the queue
	{
		cout << "No element to move backwards too" << endl;
	}
}



template<class Type>
myQueue<Type>::myQueue() // default constructor
{
	queueFront = nullptr;
	queueRear = nullptr;
	current = nullptr;
	count = 0;
}

template<class Type>
void myQueue <Type>::copyQueue(const myQueue<Type>& otherQueue) //copy constructor
{
	nodeType<Type>* newNode, * tempCurrent, * last; // pointer to newnode to hold the newnode to be added, tempCurrent to hold the currnet place in the queue we are copying from and last to update the next links 

	if (queueFront != nullptr) // if queue is not empty make it empty
	{
		initializeQueue();
	}

	if (otherQueue.queueFront == nullptr) // is other queue is just an empty queue then the this queue is going to be empty nothing to copy
	{
		queueFront = nullptr;
		queueRear = nullptr;
		current = nullptr;
		count = 0;
	}

	else // if not
	{
		nodeType<Type>* last; // guess I declared it twice whoops dont wanna delelte it because im scared it'll break something

		tempCurrent = otherQueue.queueFront; // tempCurrent eqauls front of the other queue
		count = 1; // the size now only equals one of the queue being copied too
		queueFront = new nodeType<Type>; // creating queueRear and queueFront
		queueRear = new nodeType<Type>;

		queueFront->info = tempCurrent->info; // set queuefront equal to the other queues queue front 
		queueFront->back = nullptr; // since this is the first node in the queue we set everything else to null pointer 
		queueFront->next = nullptr; 

		queueRear = queueFront; // queueFront is QueueRear theres only one element at this point
		last = queueFront; // this is so we can link up the next pointers in the loop took like an hour of debugging to find this fix haha
		tempCurrent = tempCurrent->next; // advance to the next node to be copied

		

		while (tempCurrent != nullptr) // repeat with the remainder of the queue until the last element
		{
			newNode = new nodeType<Type>; // create the new node

			newNode->info = tempCurrent->info; // copy the info into it
			newNode->back = queueRear; // now its linked the last element that was copied therfore attaching it to the list
			newNode->next = nullptr; // at this point its the last node so there is nothing to attach it to
			last->next = newNode; // update the next link of the previously copied node thus both links are now pointing at each other creating the linked list forehead
			queueRear = newNode; // update queue rear
			last = newNode; // update last so we can do the next link thing again
			tempCurrent = tempCurrent->next; // advance to the next node to be copied
			count++; // increment count so we know the size at the end
		}

	}
}

template<class Type>
myQueue<Type>::~myQueue() // destructor deallocates memory when this ish goes out of scope
{
	initializeQueue();
}

template<class Type>
myQueue<Type>::myQueue(const myQueue& otherQueue) // copy construtor
{
	queueFront = nullptr;
	queueRear = nullptr;
	current = nullptr;
	count = 0;
	copyQueue(otherQueue);
}


template<class Type>
const myQueue<Type>& myQueue<Type>::operator=(const myQueue<Type>& otherQueue) // overloads assignment operator 
{
	if (this != &otherQueue) // avoid a self copy thats just a waste of computer power 
	{
		copyQueue(otherQueue);
	}
	return *this;
}