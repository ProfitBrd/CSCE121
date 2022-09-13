#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
#include <cmath>

using std::cout;
using std::string;
using std::ostream;

LinkedList::LinkedList() : head(nullptr), tail(nullptr) {
	  // Implement this function
}

LinkedList::~LinkedList() {
	// Implement this function
    clear();
    head = nullptr;
    tail = nullptr;
}

LinkedList::LinkedList(const LinkedList& source) : head(nullptr), tail(nullptr){
    // Implement this function
    //Node* newNode = new Node()
    Node* currentNode = head; //is for the new list we are making
    Node* nextNode = nullptr; //node from other list


    if (source.head == nullptr){ //if the head is empty
        head = nullptr;
        tail = nullptr;
    }
    else if(source.head == source.tail){ //if there is only one item in the list
        head = new Node(); //head points to a new node
        head->data = source.head->data; //copy the head data over to the node head is pointing to
        head->next = nullptr; //there is not a second item
        tail->data = head->data; //copy the data over to tail becuase it is the same thing
        tail->next = nullptr;
    }
    else{
        head = new Node(); //where head is pointing is now a new node
        head->data = source.head->data; //bring the data in from the first node of the other list
        
        currentNode = head; //set our node = the new node we created above
        nextNode = source.head->next;
        while (nextNode != nullptr){
            Node* newNode = new Node();
            newNode->data = nextNode->data;  //copying over the data from other list's node to the new node we just created
            currentNode->next = newNode;
            currentNode = currentNode->next; //moving currentNode to the next node in the list

            


        
            nextNode = nextNode->next; //moving to next node on the other list
        } 
        tail = currentNode;


    }
    
}

LinkedList& LinkedList::operator=(const LinkedList& source)
{
    if (this != &source){
        clear();
        //head = nullptr;
        //tail = nullptr;
        //Node* newNode = new Node()
        Node* currentNode = head; //is for the new list we are making
        Node* nextNode = nullptr; //node from other list


        if (source.head == nullptr){ //if the head is empty
            head = nullptr;
            tail = nullptr;
        }
        else if(source.head == source.tail){ //if there is only one item in the list
            head = new Node(); //head points to a new node
            head->data = source.head->data; //copy the head data over to the node head is pointing to
            head->next = nullptr; //there is not a second item
            tail->data = head->data; //copy the data over to tail becuase it is the same thing
            tail->next = nullptr;
        }
        else{
            head = new Node(); //where head is pointing is now a new node
            head->data = source.head->data; //bring the data in from the first node of the other list
            
            currentNode = head; //set our node = the new node we created above
            nextNode = source.head->next;
            while (nextNode != nullptr){
                Node* newNode = new Node();
                newNode->data = nextNode->data;  //copying over the data from other list's node to the new node we just created
                currentNode->next = newNode;
                currentNode = currentNode->next; //moving currentNode to the next node in the list

            
                nextNode = nextNode->next; //moving to next node on the other list
            }
            //reassign tail ----------------------------------------------------------------------------------------------------------------Making the delete function not work and 
            tail = currentNode;


        }
    }
    return *this;

}

void LinkedList::insert(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    // Implement this function
    Node *newNode;					// A new node
    Node *nodePtr;					// To traverse the list
    Node *previousNode = nullptr;	// The previous node

    // Allocate a new node and store newValue there.
    newNode = new Node(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y);
    /*
    newNode->data.id = id;
    newNode->data.fov = fov;
    newNode->data.volume = volume;
    newNode->data.center_x = center_x;
    newNode->data.center_y = center_y;
    newNode->data.min_x = min_x;
    newNode->data.max_x = max_x;
    newNode->data.min_y = min_y;
    newNode->data.max_y = max_y;
    */
    
    // If there are no nodes in the list
    // make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr;
        tail = newNode;
    }
    else  // Otherwise, insert newNode
    {
        // Position nodePtr at the head of list.
        nodePtr = head;

        // Initialize previousNode to nullptr.
        previousNode = nullptr;

        // Skip all nodes whose value is less than newValue.
        while (nodePtr != nullptr)
        {
            if (newNode->data.fov > nodePtr->data.fov){ //move on until the fov we have is less than the next value
                previousNode = nodePtr;
                nodePtr = nodePtr->next;
            }
            else if (newNode->data.fov == nodePtr->data.fov){
                if (newNode->data.id < nodePtr->data.id){ //if the ID is less, we are at the correct spot
                    break;
                }
                else{ //if the ID is greater, move on
                    previousNode = nodePtr;
                    nodePtr = nodePtr->next;
                }
            }
            else{
                break;
            }
            
        }
        // If the new node is to be the 1st in the list,
        // insert it before all other nodes.
        if (previousNode == nullptr)
        {
            //newNode->next = head;
            head = newNode;
            newNode->next = nodePtr;
        }
        else if(nodePtr == nullptr){
            previousNode->next = newNode;
            newNode->next = nodePtr;
            tail = newNode;
        }
        else  // Otherwise insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void LinkedList::remove(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    // Implement this function
    Node *nodePtr;       // To traverse the list
    Node *previousNode;  // To point to the previous node

    // If the list is empty, do nothing.
    if (!head){
        return;
    }
    // Determine if the first node is the one.
    if (head->data.id == id && head->data.fov == fov && head->data.volume == volume && head->data.center_x == center_x && head->data.center_y == center_y && head->data.min_x == min_x && head->data.max_x == max_x && head->data.min_y == min_y && head->data.max_y == max_y)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        // Initialize nodePtr to head of list
        nodePtr = head;

        // Skip all nodes whose value member is 
        // not equal to num.
        while (nodePtr != nullptr && (nodePtr->data.id != id || nodePtr->data.fov != fov || nodePtr->data.volume != volume || nodePtr->data.center_x != center_x || nodePtr->data.center_y != center_y || nodePtr->data.min_x != min_x || nodePtr->data.max_x != max_x || nodePtr->data.min_y != min_y || nodePtr->data.max_y != max_y))
        {  
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        // If nodePtr is not at the end of the list, 
        // link the previous node to the node after
        // nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
            nodePtr = nullptr;
        }
    }
}

void LinkedList::clear() 
{
    Node *nodePtr;   // To traverse the list
    Node *nextNode;  // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }

    head = nullptr;
    tail = nullptr;
}

Node* LinkedList::getHead() const 
{
    // Implement this function it will be used to help grade other functions
    return head;
}

static void removeTrailingCharacters(std::string &str, const char charToRemove) {
    str.erase (str.find_last_not_of(charToRemove) + 1, std::string::npos );
    if (str.at(str.length() - 1) == '.'){
        str = str.substr(0, str.length() - 1);
    }
}

string LinkedList::print() const //------------------------------------------------------------------------Cut off trailing zeros, mimir will work then 
{
   	// Implement this function
    Node *nodePtr;  // To move through the list

   // Position nodePtr at the head of the list.
    nodePtr = head;

    // While nodePtr points to a node, traverse
    // the list.
    string returnString = "fov,volume,center_x,center_y,min_x,max_x,min_y,max_y\n";
    string str = "";
    while (nodePtr != nullptr)
    {
        // Display the value in this node.
        returnString += nodePtr->data.id;
        returnString += ",";

        str = std::to_string(nodePtr->data.fov);
        //cout << "DATA: " << nodePtr->data.fov << std::endl;
        //removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += ",";
        
        str = std::to_string(nodePtr->data.volume);
        removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += ",";

        str = std::to_string(nodePtr->data.center_x);
        removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += ",";

        str = std::to_string(nodePtr->data.center_y);
        removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += ",";

        str = std::to_string(nodePtr->data.min_x);
        removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += ",";

        str = std::to_string(nodePtr->data.max_x);
        removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += ",";

        str = std::to_string(nodePtr->data.min_y);
        removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += ",";

        str = std::to_string(nodePtr->data.max_y);
        removeTrailingCharacters(str, '0');
        returnString += str;
        returnString += "\n";

        //returnString += nodePtr->data.id + "," + std::to_string(nodePtr->data.fov) + "," + std::to_string(nodePtr->data.volume) + "," + std::to_string(nodePtr->data.center_x) + "," + std::to_string(nodePtr->data.center_y) + "," + std::to_string(nodePtr->data.min_x) + "," + std::to_string(nodePtr->data.max_x) + "," + std::to_string(nodePtr->data.min_y) + "," + std::to_string(nodePtr->data.max_y) + "\n";

        // Move to the next node.
        nodePtr = nodePtr->next;
    }
    return returnString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

// given a fov number, count the cells observed in that fov
int LinkedList::countN(int fov)
{
	/* Do not modify this function */
    int count = 0;
    Node* cur = head;
    while (cur)
    {
        if (cur->data.fov == fov)
            count++;
        cur = cur->next;
    }
    return count;
}

/* given a fov number, compute the average volume of all the cells observed in
 * that fov
 */
double LinkedList::average(int fov)
{
    // Implement this function
    Node *nodePtr;   // To traverse the list
    Node *nextNode;  // To point to the next node

    // Position nodePtr at the head of the list.
    nodePtr = this->head;

    double volumeAvg = 0;
    //int count = 0;
    // While nodePtr is not at the end of the list...
    if(this->countN(fov) == 0){
        return 0;
    }
    else if(this->countN(fov) == 1 && nodePtr->data.fov == fov){
        return(nodePtr->data.volume);
    }
    while (nodePtr != nullptr)
    {
        if (nodePtr->data.fov == fov){
            volumeAvg += nodePtr->data.volume;
            //count++;
        }
        // Save a pointer to the next node.
        nextNode = nodePtr->next;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }

    double answer = volumeAvg/this->countN(fov);
    return answer;
    

}

/* given a fov number, compute the variance volume of all the cells observed in
 * that fov
 */
double LinkedList::variance(int fov)
{
    /* Do not modify this function */
    double sum = 0;
    double avg = average(fov);
    int count = countN(fov);

    if (count == 0)
        return -1;

    Node* cur = head;
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += (cur->data.volume - avg) * (cur->data.volume - avg);
        cur = cur->next;
    }

    return sum/count;
}

/* given a fov number, remove outliers
 */
string LinkedList::outliers(int k, int j, int N)
{
    
    // Implement this function
    Node *nodePtr;   // To traverse the list
    //Node *nextNode;  // To point to the next node
    //Node *tempPointer;

    if (countN(k) < N){
        int tempk = stoi(k);
        int tempN = stoi(N);
        string output = "Hey " + tempN + " cells in fov " + tempk;
        return (output);
    }
    // Position nodePtr at the head of the list.
    nodePtr = head;

    //cout << "K: " << variance(k) << endl;
    //cout << "AVG: " << average(k) << endl;
    // cout << "J: " << j << endl;
    double deltak = sqrt(variance(k));
    double lowerBound = average(k) - (j * deltak);
    double upperBound = average(k) + (j * deltak);
    int numberCellsRemoved = 0;
    //cout << "lowerBound: " << lowerBound << endl;
    //cout << "upperBound: " << upperBound << endl;
    // While nodePtr is not at the end of the list...
    while (nodePtr != nullptr)
    {
        if ( ((nodePtr->data.volume >= upperBound) || (nodePtr->data.volume <= lowerBound)) && (nodePtr->data.fov == k) ){ //if it's out of bounds
            //cout << "DATA: " << nodePtr->data.id << " -- " << nodePtr->data.fov<< " -- " << nodePtr->data.volume<< " -- " << nodePtr->data.center_x<< " -- " << nodePtr->data.center_y<< " -- " << nodePtr->data.min_x<< " -- " << nodePtr->data.max_x<< " -- " << nodePtr->data.min_y<< " -- " << nodePtr->data.max_y << endl;
            numberCellsRemoved++; //Count adds one
            // nextNode = nodePtr->next;
            this->remove(nodePtr->data.id, nodePtr->data.fov, nodePtr->data.volume, nodePtr->data.center_x, nodePtr->data.center_y, nodePtr->data.min_x, nodePtr->data.max_x, nodePtr->data.min_y, nodePtr->data.max_y); //remove the node
            // nodePtr = nextNode;
        }
        nodePtr = nodePtr->next; //move on to next node
    }
    
    return(std::to_string(numberCellsRemoved) + " cells are removed.");
    
}

