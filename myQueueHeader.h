#pragma once

/* ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	THIS FILE HOLDS ALL OF THE FUNCTION DEFINITIONS FOR THE DOUBLE LINKED QUEUE. IMPLEMENTATION DETAILS CAN BE FOUND IN "myQueueSource.cpp"

	This is going to be a queue made from a double linked list.Since the program asks to view the nextand previous patient we need a way to go forwardand backward.Although adding is only done from the rear of course.
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- */

template <class Type>
struct nodeType
{
	Type info; // hold struct info
	nodeType<Type>* next; // points to the next element in the queue
	nodeType<Type>* back; // points to the previous element in the queue 
};

template <class Type>
class myQueue
{
public:
	const myQueue<Type>& operator=(const myQueue<Type>&); // overloads assigment operator 
	bool isEmptyQueue() const; // returns if queue is empty or not
	void initializeQueue(); // deletes queue
	Type front() const; // returns front element of queue
	Type back() const; // returns rear of queue
	void enQueue(const Type& queueElement); // adds element to the rear of queue
	void deQueue(); //deletes element from the front of the queue
	int size(); // returns count, so we can the number of elements in the queue
	void moveCurrentForward(); // moves current pointer forward. So we can move through the queue and view patients.
	void moveCurrentBackwards(); // moves current pointer backwards
	Type returnCurrent() const;
	myQueue(); // defualt constructor
	myQueue(const myQueue<Type>& otherQueue); // copy constructor
	~myQueue(); //Destructor

protected:
	nodeType<Type>* current; // pointer to tranverse the list




private:
	nodeType<Type>* queueFront; // points to the first element
	nodeType<Type>* queueRear; // points to the last element
	int count; //keeps track of how many elements are in the queue
	void copyQueue(const myQueue<Type>& otherQueue); // used to make a copy of a queue to overload the assignment operator







};