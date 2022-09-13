#include<iostream>
#include<string>
#include "Node.h"
#include "CellData.h"

using std::cout;

// Default constructor
// remember to initialize next to nullptr
Node::Node(): data(CellData()), next(nullptr)
{
} 

// Parameterized constructor
// remember to initialize next to nullptr
Node::Node(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y) : data(CellData(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y)), next(nullptr)
{
}

bool Node::operator<(const Node& b){
    if (data < b.data){ //if given is less than right side return true
        return true;
    }
    else{ //if it isn't less than the right side (if it's equal or greater)
        return false;
    }
}

bool Node::operator==(const Node& b){
    if (data == b.data){ //if its equal return true
        return true;
    }
    else{ //else return false
        return false;
    }
}
