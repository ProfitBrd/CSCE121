#include <iostream>
#include <fstream>
#include <string>
#include "logic.h"

using std::cout, std::endl, std::ifstream, std::string;

/**
 * TODO: Student implement this function
 * Load representation of the dungeon level from file into the 2D map.
 * Calls createMap to allocate the 2D array.
 * @param   fileName    File name of dungeon level.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference to set starting position.
 * @return  pointer to 2D dynamic array representation of dungeon map with player's location., or nullptr if loading fails for any reason
 * @updates  maxRow, maxCol, player
 */
char** loadLevel(const string& fileName, int& maxRow, int& maxCol, Player& player) { //CAN'T PASS HIDDEN, but now checks if missing one of the four original values
    ifstream infs (fileName);
    
    if ( infs.is_open() ){ //if the file is open
        double one; //if = 0, bad
        double two;
        double three; //check if >= maxcol, less than 0
        double four;
        
        //get the dimensions from the top of the file ??Will it ever give us a blank space, how to get it???
        //infs >> maxRow >> maxCol >> player.row >> player.col; //reassigns maxRow and maxCol, and player row and col
        infs >> one >> two >> three >> four;
        

        //if (one >= INT32_MAX || two >= INT32_MAX || three >= INT32_MAX || four >= INT32_MAX){
        
        if(one*two >= INT32_MAX || one+two >= INT32_MAX){ //if maxRow * maxCol is greater than INT32_MAX
            return nullptr;
        } 

        maxRow = (int)one;
        maxCol = (int)two;
        player.row = (int)three;
        player.col = (int)four;

        if ( (maxRow == 0) || (maxCol == 0) || (player.row >= maxRow) || (player.col >= maxCol) || (player.row < 0) || (player.col < 0) ){ //all the edge cases
            return nullptr;
        }


        char** mults;
        mults = createMap(maxRow, maxCol); //creates empty map
        
        int count = 0;
        
        //filling the array using two for loops
        char temp;
        bool hasExit = false;
        for(unsigned int row = 0; row < maxRow; row++){ 
            for(unsigned int col = 0; col < maxCol; col++){
                count++;
                if (count > maxRow * maxCol){
                    //cout << "MORE NUMBERS THAN ALLOWED" << endl;
                    deleteMap(mults, maxRow);
                    return nullptr;
                }
                else{
                    //cout << "HERE" << endl;
                    infs >> temp; //edge case where not separated by spaces? ---------------------------------------------------------------
                    //cout << "TEMP: " << temp << endl;
                    if (temp == TILE_OPEN || temp == TILE_PLAYER || temp == TILE_TREASURE || temp == TILE_AMULET || temp == TILE_MONSTER || temp == TILE_PILLAR || temp == TILE_DOOR || temp == TILE_EXIT){
                        if (temp == TILE_DOOR || temp == TILE_EXIT){
                            hasExit = true;
                        }
                        mults[row][col] = temp;
                    }
                    else{
                        //cout << "deleted" << endl;
                        deleteMap(mults, maxRow);
                        return nullptr;
                    }
                }
            }
        }
        
        if (infs >> temp){
            //cout << "WORKS?" << endl;
            deleteMap(mults, maxRow);
            return nullptr;
        }
        if (!hasExit){
            deleteMap(mults, maxRow);
            return nullptr;
        }
        
        //cout << "COUNT: " << count << " MULTIPLICATION: " << maxRow*maxCol << endl;
        mults[player.row][player.col] = TILE_PLAYER; //assigning player tile to the player location last
        
        return mults; //return mults if everything works
    }
    else{
        //returns nullptr if file is invalid
        return nullptr;
    }
}

/**
 * TODO: Student implement this function
 * Translate the character direction input by the user into row or column change.
 * That is, updates the nextRow or nextCol according to the player's movement direction.
 * @param   input       Character input by the user which translates to a direction.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @updates  nextRow, nextCol
 */
void getDirection(char input, int& nextRow, int& nextCol) {
    /*
    bool moveLeftTest = !((nextRow == 0 || nextCol == 0) && input == MOVE_LEFT)
    bool moveLeftTest = !((nextRow == 0 || nextCol == 0) && input == MOVE_LEFT)
    if (  ){

    }
    */
    //else{
        if (input == MOVE_DOWN){
            //cout << "down" << endl;
            nextRow += 1;
        }
        else if (input == MOVE_UP){
            //cout << "up" << endl;
            nextRow -= 1;
        }
        else if (input == MOVE_RIGHT){
            //cout << "RIGHT" << endl;
            nextCol += 1;
        }
        else if(input == MOVE_LEFT){
            //cout << "LEFT" << endl;
            nextCol -= 1;
        }
        else{
        }

    //}

}


/**
 * TODO: [suggested] Student implement this function
 * Allocate the 2D map array.
 * Initialize each cell to TILE_OPEN.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @return  2D map array for the dungeon level, holds char type.
 */
char** createMap(int maxRow, int maxCol) {
    //creating array of arrays
    char** mults = new char*[maxRow];  //creating array of pointers
    for (unsigned int row = 0; row < maxRow; row++){ //going through and allocating an array to each of the pointers
        mults[row] = new char[maxCol];
    }

    //initializing the array to all tile_open
    for(unsigned int row = 0; row < maxRow; row++){ 
        for(unsigned int col = 0; col < maxRow; col++){ //MEMORY LEAK, SHOULD BE maxCol--------------------------------------------------------------------------------------------------
            mults[row][col] = TILE_OPEN;
        }
    }
    return mults;
}



/**
 * TODO: Student implement this function
 * Deallocates the 2D map array.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @return None
 * @update map, maxRow
 */
void deleteMap(char**& map, int& maxRow) { //--------------WORKS!!------------------
    if (map) {
        for (int row = 0; row < maxRow; row++) {
            delete[] map[row];
        }
        delete[] map;
       
    }
    maxRow = 0;
    map = nullptr;

}

/**
 * TODO: Student implement this function
 * Resize the 2D map by doubling both dimensions.
 * Copy the current map contents to the right, diagonal down, and below.
 * Do not duplicate the player, and remember to avoid memory leaks!
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height), to be doubled.
 * @param   maxCol      Number of columns in the dungeon table (aka width), to be doubled.
 * @return  pointer to a dynamically-allocated 2D array (map) that has twice as many columns and rows in size.
 * @update maxRow, maxCol
 */
char** resizeMap(char** map, int& maxRow, int& maxCol) {

    if (map == nullptr){
        
        return nullptr;
    }
    if (maxRow > 537000000 || maxCol > 537000000){
        return nullptr;
    }
    if ( maxCol < 1 || maxRow < 1){
        return nullptr;
    }

    char** newMap = createMap(maxRow*2, maxCol*2); //create new map
    for (int row = 0; row < maxRow; row++){
        for (int col = 0; col < maxCol; col++){
            if (map[row][col] == TILE_PLAYER){
                newMap[row][col] = map[row][col];
                newMap[row + (maxRow)][col] = '-';
                newMap[row + (maxRow)][col + (maxCol)] = '-';
                newMap[row][col + (maxCol)] = '-';
            }
            else{
                newMap[row][col] = map[row][col];
                newMap[row + (maxRow)][col] = map[row][col];
                newMap[row + (maxRow)][col + (maxCol)] = map[row][col];
                newMap[row][col + (maxCol)] = map[row][col];
            }
        }
    }

    int fake  = maxRow;
    deleteMap(map, fake);
    maxRow *= 2;
    maxCol *= 2;

    return newMap;



}

/**
 * TODO: Student implement this function
 * Checks if the player can move in the specified direction and performs the move if so.
 * Cannot move out of bounds or onto TILE_PILLAR or TILE_MONSTER.
 * Cannot move onto TILE_EXIT without at least one treasure. 
 * If TILE_TREASURE, increment treasure by 1.
 * Remember to update the map tile that the player moves onto and return the appropriate status.
 * You can use the STATUS constants defined in logic.h to help!
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object to by reference to see current location.
 * @param   nextRow     Player's next row on the dungeon map (up/down).
 * @param   nextCol     Player's next column on dungeon map (left/right).
 * @return  Player's movement status after updating player's position.
 * @update map contents, player
 */
int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol) {
    
    int tempRow = player.row;
    int tempCol = player.col;

    if ( nextRow >= maxRow || nextCol >= maxCol || nextRow < 0 || nextCol < 0){ //if out of bounds, it stays
        return STATUS_STAY;
    }
    else if ( (map[nextRow][nextCol] == '|') || (map[nextRow][nextCol] == TILE_PILLAR) || (map[nextRow][nextCol] == TILE_MONSTER) ){ //if trying to travel into +, |, or M, status stay
        return STATUS_STAY;
    }

    else if( (map[nextRow][nextCol] == TILE_EXIT) && (player.treasure <= 0) ){
        return STATUS_STAY;
    }

    else{ //else we can move to the space
        map[player.row][player.col] = TILE_OPEN; //setting previous location to an empty space
        player.row = nextRow; //updating row and column
        player.col = nextCol;

        if (map[nextRow][nextCol] == TILE_AMULET){ //if it is an amulet
            map[nextRow][nextCol] = TILE_PLAYER;
            return STATUS_AMULET;
            //resizeMap(map, maxRow, maxCol);
        }
        else if(map[nextRow][nextCol] == TILE_TREASURE){ //If it is a treasure
            map[nextRow][nextCol] = TILE_PLAYER;
            player.treasure++;
            return STATUS_TREASURE;
        }
        else if (map[nextRow][nextCol] == TILE_DOOR){ //If it is the door
            map[nextRow][nextCol] = TILE_PLAYER; //update to new location of the player
            return STATUS_LEAVE;
        }
        else if (map[nextRow][nextCol] == TILE_EXIT){ //If it is the exit
            if (player.treasure > 0){
                map[nextRow][nextCol] = TILE_PLAYER;
                return STATUS_ESCAPE;
            }
            else{
                //map[nextRow][nextCol] = TILE_PLAYER; //update to new location of the player
                map[tempRow][tempCol] = TILE_PLAYER; //setting previous location to an player
                return STATUS_STAY;
            }
        }
        else{ //must be empty space
            map[nextRow][nextCol] = TILE_PLAYER;
            return STATUS_MOVE;
        }

    }


    //return STATUS_STAY;
}

/**
 * TODO: Student implement this function
 * Update monster locations:
 * We check up, down, left, right from the current player position.
 * If we see an obstacle, there is no line of sight in that direction, and the monster does not move.
 * If we see a monster before an obstacle, the monster moves one tile toward the player.
 * We should update the map as the monster moves.
 * At the end, we check if a monster has moved onto the player's tile.
 * @param   map         Dungeon map.
 * @param   maxRow      Number of rows in the dungeon table (aka height).
 * @param   maxCol      Number of columns in the dungeon table (aka width).
 * @param   player      Player object by reference for current location.
 * @return  Boolean value indicating player status: true if monster reaches the player, false if not.
 * @update map contents
 */
bool doMonsterAttack(char** map, int maxRow, int maxCol, const Player& player) {
    //cout << "PLAYER ROW: " << player.row << " PLAYER COLUMN: " << player.col << endl;
    bool unpassObj = false; //-----------------------------------------------------------------------------------------------DO I NEED??
    //cout << "hello" << endl;
    for (int i = player.row - 1; i >= 0; i--){ //starting from the player, check every row above it
        //cout << "CHECK: " << i << endl;
        if (map[i][player.col] == TILE_PILLAR || map[i][player.col] == '|'){
            unpassObj = true;
            break; //break out of for loop for above becuase there is an unpassable object
        }
        
        else if (map[i][player.col] == TILE_MONSTER){ //if the tile is a monster
            
            map[i][player.col] = TILE_OPEN;
            map[i + 1][player.col] = TILE_MONSTER; //move monster one tile down
            //cout << "Monster ROW: " << i+1 << " Monster COLUMN: " << player.col << endl;

            /*
            if (player.row == i + 1){
                return true;
            }
            */

        }

    }

    for (int i = player.row + 1; i < maxRow; i++){ //starting from the player, below it
        if (map[i][player.col] == TILE_PILLAR || map[i][player.col] == '|'){
            unpassObj = true;
            break; //break out of for loop for above becuase there is an unpassable object
        }

        else if (map[i][player.col] == TILE_MONSTER){ //if the tile is a monster
            
            map[i][player.col] = TILE_OPEN;
            map[i - 1][player.col] = TILE_MONSTER; //move monster one tile up
            //cout << "Monster ROW: " << i - 1<< " Monster COLUMN: " << player.col << endl;

            /*
            if (player.row == i - 1){
                return true;
            }
            */

        }
    }

    //-----------------------------------------------------------------------------------------------------------------set both o the >0 to >=0, 0 is in bounds
    for (int i = player.col - 1; i >= 0; i--){ //starting from the player, check every row left of it
        if (map[player.row][i] == TILE_PILLAR || map[player.row][i] == '|'){
            unpassObj = true;
            break; //break out of for loop for above becuase there is an unpassable object
        }


        else if (map[player.row][i] == TILE_MONSTER){ //if the tile is a monster
            
            map[player.row][i] = TILE_OPEN;
            map[player.row][i + 1] = TILE_MONSTER; //move monster one tile right
            //cout << "Monster ROW: " << player.row << " Monster COLUMN: " << i+1 << endl;

            /*
            if (player.col == i + 1){
                return true;
            }
            */
        }
    }

    for (int i = player.col + 1; i < maxCol; i++){ //starting from the player, check every row right of it
        if (map[player.row][i] == TILE_PILLAR || map[player.row][i] == '|'){
            unpassObj = true;
            break; //break out of for loop for above becuase there is an unpassable object
        }

        else if (map[player.row][i] == TILE_MONSTER){ //if the tile is a monster
            
            map[player.row][i] = TILE_OPEN;
            map[player.row][i - 1] = TILE_MONSTER; //move monster one tile left
            //cout << "Monster ROW: " << player.row << " Monster COLUMN: " << i-1 << endl;

            /*
            if (player.col == i - 1){
                return true;
            }
            */

        }
    }

    if (map[player.row][player.col] == TILE_MONSTER){
        return true;
    }
    else{
        return false;
    }
    
}
