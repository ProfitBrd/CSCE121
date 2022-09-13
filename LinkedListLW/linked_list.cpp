#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    // TODO(student)
    
    MyNode* adding = new MyNode(name, score);
    if (_size == 0){
        _head = adding;
        _tail = adding;
        
    }
    else{
        adding->prev = _tail; //pointing back
        _tail->next = adding; //pointing to new node
        _tail = adding;
    }
    _size++;
}

void MyList::clear() {
    // TODO(student)
    
    MyNode *nodePtr;   // To traverse the list
    MyNode *nextNode;  // To point to the next node

   // Position nodePtr at the head of the list.
    nodePtr = _head;

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
    _size = 0;
    _head = nullptr;
    _tail = nullptr;
    
}

bool MyList::remove(const std::string& name) {
    // TODO(student)
    return false;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO(student)
    return false;
}

MyList::MyList()
  : _size(0), _head(nullptr), _tail(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
