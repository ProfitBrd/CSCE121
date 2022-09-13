/*
 * CellData.h
 *
 *  Created on: Nov 9, 2021
 *      Author: student
 */

#include <iostream>
#include <string>
#include "CellData.h"

using std::cout;
using std::string;

CellData::CellData() : id("-1"), fov(-1), volume(-1), center_x(-1), center_y(-1), min_x(-1), max_x(-1), min_y(-1), max_y(-1) {} //initialize everything

CellData::CellData(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y) : id(id), fov(fov), volume(volume), center_x(center_x), center_y(center_y), min_x(min_x), max_x(max_x), min_y(min_y), max_y(max_y){} //initialize everything


CellData::~CellData() {} // You should not need to implement this

bool CellData::operator<(const CellData& b) {
	// Implement this
    if(fov == b.fov){
        if(id == b.id){ //if they are both equal
            return false;
        }
        else if(id < b.id){ //if the class is less than the right side
            return true;
        }
        else if(id > b.id){ //if class is greater than the right side
            return false;
        }
    }

    else{
        if(fov < b.fov){ //if the class fov is less than the right side
            return true;
        }
        else if(fov > b.fov){ //if the class fov is greater than the right side
            return false; 
        }

    }
    return false; //if they are equal
}

bool CellData::operator==(const CellData& b)
{
    // Implement this
    if ( (id == b.id) && (fov == b.fov) && (volume == b.volume) && (center_x == b.center_x) && (center_y == b.center_y) && (min_x == b.min_x) && (max_x == b.max_x) && (min_y == b.min_y) && (max_y == b.max_y)  ){
        return true;
    }
    return false;
}

