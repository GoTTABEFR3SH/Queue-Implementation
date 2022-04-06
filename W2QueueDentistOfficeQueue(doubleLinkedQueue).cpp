/* ----------------------------------------------------------------------------
    This File contains the main program used for the Dentist Office Application
------------------------------------------------------------------------------ */

#include <iostream> // input output
#include <string> // so I can use getline()
#include "myQueueHeader.h" // file containing all the function definitions 
#include "myQueueSource.cpp" // file containing all of the implementation details for said function

struct patient  // struct that will be stored into the elements of the queue holding all of the patients info
{
    string name = "";
    string insuranceType;
    string socialSecurityNumber;
    string address;
    string dateOfVisit;
};

void addPatient(); // adds patient to queue
void nextPatient(); // advances current to the next patient
void previousPatient(); // goes to the previous paitient
void deletePatient(); // deletes the patient at the front of the queue
void viewCurrent(); // views the patient to which current is pointing to. Doesn't neccessarly have to be the first one
int displayMenu(); // displays the menu function
myQueue<patient> waitingQueue; // queue patients will be placed in


int main() // main function
{ 
    displayMenu(); // since this is a recursive function so we only need to call it once and it does the rest.
}


/*I only put the functions at the bottom so it would look a little neater*/

void addPatient() // function that adds patient to the queue 
{
    patient temp; // temp struct to hold patient information
    cout << "Patient Name? ";
    cin.ignore();
    getline(cin, temp.name); // get name getline is usde so we can use spaces in the input
    cout << "Insurance Type? ";
    getline(cin, temp.insuranceType);
    cout << "Social Security Number? ";
    cin >> temp.socialSecurityNumber;
    cout << "Patient Address? ";
    cin.ignore(); // ignore is to clear the input buffer without it the computer just skips the question
    getline(cin, temp.address);
    cout << "Date Of Vist? ";
    cin >> temp.dateOfVisit;
    waitingQueue.enQueue(temp); // add temp to the queue
}

void nextPatient() // moves the current pointer to the next patient so we can traverse the list
{
    if (!waitingQueue.isEmptyQueue())
    {
        waitingQueue.moveCurrentForward();   // calls the moveCurrentForward function we wrote 
    }
    else 
    {
        cout << "End Of Queue" << endl;
    }
}

void previousPatient() // same deal as next patient
{
    if (!waitingQueue.isEmptyQueue())
    {
        waitingQueue.moveCurrentBackwards();
    }
    else
    {
        cout << "Already At Front of Queue" << endl;
    }
}

void deletePatient() // deletes patient from the queue by calling dequeue
{
    waitingQueue.deQueue();
}

void viewCurrent() // displays the patients information of whatever current is pointing to 
{
    patient temp; // temp patient so we can properly display each element of the patient struct
    temp = waitingQueue.returnCurrent(); // setting temp to equal the node current is pointing to

    cout << "Patient Name: " << temp.name << endl; // cout all info in these next few line
    cout << "Insurance: " << temp.insuranceType << endl;
    cout << "Social Security Number: " << temp.socialSecurityNumber << endl;
    cout << "Address: " << temp.address << endl;
    cout << "Date Of Visit: " << temp.dateOfVisit << endl;
    cout << endl;
}

int displayMenu() // recursive function that uses a switch case and calls itself creating a loop that will run until 6 is inputed
{
    int input;
    if (waitingQueue.size() != 0) // dont display a current patient if there isn't any in the queue
    {
        cout << "Currently Viewing " << waitingQueue.returnCurrent().name << endl;
    }
    cout << endl;
    cout << "Select from one of the options below." << endl;
    cout << endl;
    cout << "1. Add Patient." << endl;
    cout << "2. Next Patient." << endl;
    cout << "3. Previous Patient." << endl;
    cout << "4. Delete Patient." << endl;
    cout << "5 View Current (Views patient who is currently being displayed at the top of menu)." << endl;
    cout << "6. Exit." << endl;
    cout << endl;
    cin >> input;
    cout << endl;

    switch (input)
    {
    case 1:
        addPatient();
        cout << endl;
        displayMenu();
        break;
    case 2:
        nextPatient();
        cout << endl;
        displayMenu();
        break;
    case 3:
        previousPatient();
        cout << endl;
        displayMenu();
        break;
    case 4:
        deletePatient();
        cout << endl;
        displayMenu();
        break;
    case 5:
        viewCurrent();
        cout << endl;
        displayMenu();
        break;
    case 6:
        cout << "Exiting......";
        return 0;
        break;
    }
    
}
