#include <iostream>
#include "logic.h"

using std::cout;
using std::endl;

// TODO(student): Write unit tests for the functions in logic.h
//                You should end up with at least 500 lines of test code
/*
void TestLoadLevel1(){
    std::string testFileName = "example.tx";
    Player testPerson;
    int row = 8; //make negative?
    int col = 8;
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    delete[] mapPointer;
    mapPointer = nullptr;
}
*/
void TestLoadLevel2(){
    std::string testFileName = "example.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 3;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    for (int i = 0; i < row; i++){
        delete[] mapPointer[i];
        mapPointer[i] = nullptr;
    }
    delete[] mapPointer;
    mapPointer = nullptr;
}

void TestLoadLevel3(){
    std::string testFileName = "example.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = 5;
    int col = 8;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    for (int i = 0; i < row; i++){
        delete[] mapPointer[i];
        mapPointer[i] = nullptr;
    }
    delete[] mapPointer;
    mapPointer = nullptr;
}

void TestLoadLevel4(){
    std::string testFileName = "example.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = -1;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    for (int i = 0; i < row; i++){
        delete[] mapPointer[i];
        mapPointer[i] = nullptr;
    }
    delete[] mapPointer;
    mapPointer = nullptr;
}

void TestLoadLevel5(){
    std::string testFileName = "BadFile.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = 3;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    /*
    for (int i = 0; i < row; i++){
        delete[] mapPointer[i];
        mapPointer[i] = nullptr;
    }
    delete[] mapPointer;
    */
    mapPointer = nullptr;
}

void TestLoadLevel6(){
    std::string testFileName = "BadFile1.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = 3;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel7(){
    std::string testFileName = "BadFile2.txt";
    Player player;
    player.col = 0;
    player.row = 0;
    int row = 3;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, player);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel8(){
    std::string testFileName = "BadFile3.txt";
    Player player;
    player.col = 0;
    player.row = 0;
    int row = 3;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, player);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel9(){
    std::string testFileName = "BadFile4.txt";
    Player player;
    player.col = 0;
    player.row = 0;
    int row = 3;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, player);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel10(){
    std::string testFileName = "BadFile5.txt";
    Player player;
    player.col = 0;
    player.row = 0;
    int row = 3;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, player);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel11(){
    std::string testFileName = "example.txt";
    Player player;
    player.col = -1;
    player.row = 0;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, player);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel12(){
    std::string testFileName = "example.txt";
    Player player;
    player.col = 0;
    player.row = -1;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, player);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel13(){
    std::string testFileName = "example.tx";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel14(){
    std::string testFileName = "BadFile6.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = 4;
    int col = 4;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel15(){
    std::string testFileName = "BadFile7.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = 3;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel16(){
    std::string testFileName = "BadFile9.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 0;
    int row = 4;
    int col = 4;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel17(){
    std::string testFileName = "BadFile10.txt";
    Player testPerson;
    testPerson.col = 5;
    testPerson.row = 0;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel18(){
    std::string testFileName = "BadFile11.txt.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel19(){
    std::string testFileName = "BadFile12.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel20(){
    std::string testFileName = "BadFile13.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel21(){
    std::string testFileName = "BadFile14.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel22(){
    std::string testFileName = "BadFile15.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel23(){
    std::string testFileName = "BadFile16.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel24(){
    std::string testFileName = "BadFile17.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}


void TestLoadLevel25(){
    std::string testFileName = "BadFile18.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel26(){
    std::string testFileName = "BadFile19.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel27(){
    std::string testFileName = "BadFile20.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel28(){
    std::string testFileName = "BadFile21.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel29(){
    std::string testFileName = "BadFile22.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}

void TestLoadLevel30(){
    std::string testFileName = "BadFile23.txt";
    Player testPerson;
    testPerson.col = 0;
    testPerson.row = 5;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}



//---------------------------------------------------------------------------------------------

//test moving up and back down / test moving right and left

//returns direction
void TestDirection1(){
    int hello = 1;
    int hello1 = 1;
    getDirection('W', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection2(){
    int hello = INT32_MAX;
    int hello1 = 1;
    getDirection('q', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection3(){
    int hello = INT32_MAX;
    int hello1 = 1;
    getDirection('e', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection4(){
    int hello = INT32_MAX;
    int hello1 = 1;
    getDirection('w', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection5(){
    int hello = INT32_MAX;
    int hello1 = 1;
    getDirection('a', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection6(){
    int hello = 17;
    int hello1 = 1;
    getDirection('s', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection7(){
    int hello = 14;
    int hello1 = 1;
    getDirection('d', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection8(){
    int hello = 13;
    int hello1 = 1;
    getDirection(' ', hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection9(){
    int hello = -1;
    int hello1 = 1;
    getDirection('s', hello, hello1);
    //cout << "WTF" << endl;
}


void TestDirection10(){
    int hello = 1;
    int hello1 = 1;
    getDirection(MOVE_DOWN, hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection11(){
    int hello = 1;
    int hello1 = -1;
    getDirection(MOVE_UP, hello, hello1);
    //cout << "WTF" << endl;
}


void TestDirection12(){
    int hello = 1;
    int hello1 = 2;
    getDirection(MOVE_UP, hello, hello1);
    getDirection(MOVE_DOWN, hello, hello1);
    //cout << "WTF" << endl;
}

void TestDirection13(){
    int hello = 1;
    int hello1 = 2;
    getDirection(MOVE_RIGHT, hello, hello1);
    getDirection(MOVE_LEFT, hello, hello1);
    //cout << "WTF" << endl;
}



//---------------------------------------------------------------------------------------------


void TestDeleteMap1(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}
/*
void TestDeleteMap2(){
    std::string testFileName = "example.tx";
    Player testPerson;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}


void TestDeleteMap3(){
    std::string testFileName = "example.tx";
    Player testPerson;
    int row = 5;
    int col = 3;
    
    char** mapPointer;
    
    deleteMap(mapPointer, row);
    mapPointer = nullptr;
}
*/

//---------------------------------------------------------------------------------------------


void TestResizeMap1(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    

    mapPointer = resizeMap(mapPointer, row, col);

    deleteMap(mapPointer, row);

    mapPointer = nullptr;
}

//Test on a file that has @, not a file that doesn't work
void TestResizeMap2(){
    std::string testFileName = "GoodFile1.txt";
    Player testPerson;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    

    mapPointer = resizeMap(mapPointer, row, col);

    deleteMap(mapPointer, row);

    mapPointer = nullptr;
}

void TestResizeMap3(){
    std::string testFileName = "GoodFile2.txt";
    Player testPerson;
    int row = 5;
    int col = 3;
    
    char** mapPointer = loadLevel(testFileName, row, col, testPerson);
    

    mapPointer = resizeMap(mapPointer, row, col);

    deleteMap(mapPointer, row);

    mapPointer = nullptr;
}


//---------------------------------------------------------------------------------------------

void TestDoPlayerMove1(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;

    //ACTAULLY CHANGES THE row and col to new positions
    getDirection(MOVE_RIGHT, nextRow, nextCol);

    //int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_DOWN, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_LEFT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
        
    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_LEFT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

//hitting monster
void TestDoPlayerMove2(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;

    //ACTAULLY CHANGES THE row and col to new positions
    getDirection(MOVE_RIGHT, nextRow, nextCol);

    //int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
        
    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoPlayerMove3(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;

    //ACTAULLY CHANGES THE row and col to new positions
    getDirection(MOVE_RIGHT, nextRow, nextCol);

    //int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
        
    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoPlayerMove4(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;

    //ACTAULLY CHANGES THE row and col to new positions
    getDirection(MOVE_RIGHT, nextRow, nextCol);

    //int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    
    getDirection(INPUT_STAY, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
        
    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoPlayerMove5(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;

    //ACTAULLY CHANGES THE row and col to new positions
    getDirection(MOVE_RIGHT, nextRow, nextCol);

    //int doPlayerMove(char** map, int maxRow, int maxCol, Player& player, int nextRow, int nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);

    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    
    getDirection(INPUT_STAY, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
        
    getDirection(INPUT_QUIT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

//---------------------------------------------------------------------------------------------


void TestDoMonsterAttack1(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;


    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoMonsterAttack2(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;


    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoMonsterAttack3(){
    std::string testFileName = "example.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;


    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_LEFT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_DOWN, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoMonsterAttack4(){
    std::string testFileName = "GoodFile3.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;


    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_LEFT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_DOWN, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}


void TestDoMonsterAttack5(){
    std::string testFileName = "GoodFile4.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;


    getDirection(MOVE_RIGHT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_UP, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_DOWN, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(MOVE_LEFT, nextRow, nextCol);
    doPlayerMove(mapPointer, maxRow, maxCol, testPerson, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoMonsterAttack6(){
    std::string testFileName = "GoodFile5.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;


    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    getDirection(INPUT_STAY, nextRow, nextCol);
    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

void TestDoMonsterAttack7(){
    std::string testFileName = "GoodFile6.txt";
    Player testPerson;
    int maxRow = 5;
    int maxCol = 3;
    
    //create map
    char** mapPointer = loadLevel(testFileName, maxRow, maxCol, testPerson);
    int nextRow = 0;
    int nextCol = 0;


    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);

    doMonsterAttack(mapPointer, maxRow, maxCol, testPerson);


    //delete map
    deleteMap(mapPointer, maxRow);

    mapPointer = nullptr;
}

//---------------------------------------------------------------------------------------------

int main() {
    TestDirection1();
    TestDirection2();
    TestDirection3();
    TestDirection4();
    TestDirection5();
    TestDirection6();
    TestDirection7();
    TestDirection8();
    TestDirection9();
    TestDirection10();
    TestDirection11();
    TestDirection12();
    TestDirection13();
    

    //TestLoadLevel1();
    TestLoadLevel2();
    TestLoadLevel3();
    TestLoadLevel4();
    TestLoadLevel5();
    TestLoadLevel6();
    TestLoadLevel7();
    TestLoadLevel8();
    TestLoadLevel9();
    TestLoadLevel10();
    TestLoadLevel11();
    TestLoadLevel12();
    TestLoadLevel13();
    TestLoadLevel14();
    TestLoadLevel15();
    TestLoadLevel16();
    TestLoadLevel17();
    TestLoadLevel18();
    TestLoadLevel19();
    TestLoadLevel20();
    TestLoadLevel21();
    TestLoadLevel22();
    TestLoadLevel23();
    TestLoadLevel24();
    TestLoadLevel25();
    TestLoadLevel26();
    TestLoadLevel27();
    TestLoadLevel28();
    TestLoadLevel29();
    TestLoadLevel30();



    TestDeleteMap1();




    TestResizeMap1();
    TestResizeMap2();


    TestDoPlayerMove1();
    TestDoPlayerMove2();
    TestDoPlayerMove3();
    TestDoPlayerMove4();
    TestDoPlayerMove5();



    TestDoMonsterAttack1();
    TestDoMonsterAttack2();
    TestDoMonsterAttack3();
    TestDoMonsterAttack4();
    TestDoMonsterAttack5();
    TestDoMonsterAttack6();
    TestDoMonsterAttack7();




    return 0;
}
