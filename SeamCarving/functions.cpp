#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"

using namespace std;



// TODO Write this function
int energy(const Pixel *const*image, int col, int row, int width, int height)
{
    int coordRighta = 0;
    int coordRightb = 0;
    int coordLefta = 0;
    int coordLeftb = 0;
    int coordTopa = 0;
    int coordTopb = 0;
    int coordBottoma = 0;
    int coordBottomb = 0;

    //decrementing dimensions by 1 because arrays start at 0
    int width2 = width - 1;
    int height2 = height - 1;


    //cout << "Number: " << arr[row][col] << endl;
    int x = col;
    int y = row;
    int maxXVal = width2;
    int maxYVal = height2;


    if (col == 0 || row == 0 || col == maxXVal || row == maxYVal){ //edge cases, literally
    
        //implement corner cases
        if (y - 1 < 0 && x + 1 > maxXVal){ //top right corner
            coordRighta = 0; //changing
            coordRightb = y;
            coordLefta = x - 1;
            coordLeftb = y;
            coordTopa = x;
            coordTopb = maxYVal; //changing
            coordBottoma = x;
            coordBottomb = y + 1;
            //cout << "Top Right" << endl;
        }
        else if(y + 1 > maxYVal && x + 1 > maxXVal){ //bottom right corner
            coordRighta = 0; //changing
            coordRightb = y;
            coordLefta = x - 1;
            coordLeftb = y;
            coordTopa = x;
            coordTopb = y - 1;
            coordBottoma = x;
            coordBottomb = 0; //changing
            //cout << "Bottom Right" << endl;
        }
        else if(y + 1 > maxYVal && x - 1 < 0){ //bottom left corner
            coordRighta = x + 1; 
            coordRightb = y;
            coordLefta = maxXVal; //changing
            coordLeftb = y;
            coordTopa = x;
            coordTopb = y - 1; 
            coordBottoma = x;
            coordBottomb = 0; //changing
            //cout << "Bottom left" << endl;
        }
        else if(y - 1 < 0 && x - 1 < 0){
            coordRighta = x + 1; 
            coordRightb = y;
            coordLefta = maxXVal; //changing
            coordLeftb = y;
            coordTopa = x;
            coordTopb = maxYVal;  //changing
            coordBottoma = x;
            coordBottomb = y + 1; 
            //cout << "Top left" << endl;
        }
        
        
        
        
        //other single edge cases
        else if (y + 1 <= maxYVal && y - 1 >= 0){  //if y is in bounds in both directions, x must be wrong (Also make sure not corner case)
            if (x - 1 < 0){ //if it's too far left, wrap around to max value
                coordRighta = x + 1;
                coordRightb = y;
                coordLefta = maxXVal; //changing
                coordLeftb = y;
                coordTopa = x;
                coordTopb = y - 1;
                coordBottoma = x;
                coordBottomb = y + 1;
                //cout << "Too far left" << endl;
            }
            else if (x + 1 > maxXVal){ //too far right, wrap around to the min value
                coordRighta = 0; //changing
                coordRightb = y;
                coordLefta = x - 1;
                coordLeftb = y;
                coordTopa = x;
                coordTopb = y - 1;
                coordBottoma = x;
                coordBottomb = y + 1;
                //cout << "Too far right" << endl;
            }
        
        }
        else if (x + 1 <= maxXVal && x - 1 >= 0){ //if x is in bounds on both directions y must be wrong (Also make sure not corner case)
            
            if (y - 1 < 0){ //too far up, wrap to bottom
                coordRighta = x + 1;
                coordRightb = y;
                coordLefta = x - 1;
                coordLeftb = y;
                coordTopa = x;
                coordTopb = maxYVal; //changing
                coordBottoma = x;
                coordBottomb = y + 1;
                //cout << "Too far up" << endl;
            }
            if (y + 1 > maxYVal){ //too far down, wrap to top
                coordRighta = x + 1;
                coordRightb = y;
                coordLefta = x - 1;
                coordLeftb = y;
                coordTopa = x;
                coordTopb = y - 1; 
                coordBottoma = x;
                coordBottomb = 0; //changing
                //cout << "Too far down" << endl;
                
            }

        }


    }
    else{ //if not an edge case
        coordRighta = x + 1;
        coordRightb = y;
        coordLefta = x - 1;
        coordLeftb = y;
        coordTopa = x;
        coordTopb = y - 1; 
        coordBottoma = x;
        coordBottomb = y + 1; //changing
        //cout << "Just right" << endl;        

    }

    //debugging
    /*
    cout << "Right: " << "(" << coordRighta << "," << coordRightb << ")" << endl;
    cout << "Left: " <<  "(" << coordLefta << "," << coordLeftb << ")" << endl;
    cout << "Top: " <<  "(" << coordTopa << "," << coordTopb << ")" <<endl;
    cout << "Bottom: " << "(" << coordBottoma << "," << coordBottomb << ")" << endl;
  
    cout << "Right " << square(absoluteValue(arr[coordRightb][coordRighta])) << endl;
    cout << "Left " << square(absoluteValue(arr[coordLeftb][coordLefta])) << endl;
    cout << "Bottom " << square(absoluteValue(arr[coordBottomb][coordBottoma])) << endl;
    cout << "Top " << square(absoluteValue(arr[coordTopb][coordTopa])) << endl;
    */
    //Get the pixel values from each of the coordinates
    Pixel pixelRight = image[coordRighta][coordRightb];
    Pixel pixelLeft = image[coordLefta][coordLeftb];
    Pixel pixelTop = image[coordTopa][coordTopb];
    Pixel pixelBottom = image[coordBottoma][coordBottomb];
    
    //make absolute vaue function
    int redHoriz = pow((pixelRight.r - pixelLeft.r), 2);
    int blueHoriz = pow((pixelRight.b - pixelLeft.b), 2);
    int greenHoriz = pow((pixelRight.g - pixelLeft.g), 2);
    int Horizontal = redHoriz + blueHoriz + greenHoriz;

    int redVert = pow((pixelTop.r - pixelBottom.r), 2);
    int blueVert = pow((pixelTop.b - pixelBottom.b), 2);
    int greenVert = pow((pixelTop.g - pixelBottom.g), 2);
    int Vertical = redVert + blueVert + greenVert;
    /*
    int redHoriz = square(absoluteValue(pixelRight.r - pixelLeft.r));
    int blueHoriz = square(absoluteValue(pixelRight.b - pixelLeft.b));
    int greenHoriz = square(absoluteValue(pixelRight.g - pixelLeft.g));
    int Horizontal = redHoriz + blueHoriz + greenHoriz;

    int redVert = square(absoluteValue(pixelTop.r - pixelBottom.r));
    int blueVert = square(absoluteValue(pixelTop.b - pixelBottom.b));
    int greenVert = square(absoluteValue(pixelTop.g - pixelBottom.g));
    int Vertical = redVert + blueVert + greenVert;
    */
    return (Vertical + Horizontal);
  //return 0;
}

// TODO Write this function
int getVerticalSeam(const Pixel *const*image, int start_col, int width, int height, int* seam)
{
    //int newHeight = height - 1;
    int newWidth = width - 1;
    int sumEnergy = 0;
    string tempSeamString = ""; //adding numbers to splice later
    string returnSeamString = "";

    int xval = start_col;
    seam[0] = xval;
    sumEnergy += energy(image, xval, 0, width, height);
    

    for (int yval = 1; yval < height; yval++){ //starting one place down
      if (xval == 0){
        int energyMiddle = energy(image, xval, yval, width, height);
        int energyRight = energy(image, xval + 1, yval, width, height);
        if (energyMiddle <= energyRight){ //if the middle column is the least (or equal to)
          xval = xval; //xval stays in middle column
        }
        else{
          xval = xval + 1; //move it one right
        }

      }
      
      else if (xval == newWidth){
        int energyLeft = energy(image, xval - 1, yval, width, height);
        int energyMiddle = energy(image, xval, yval, width, height);
        if (energyMiddle <= energyLeft){ //if middle is the least or the same
          xval = xval; //xval stays middle 
        }
        else{
          xval = xval - 1; //xval moves left
        }

      }

      else{
        int energyLeft = energy(image, xval - 1, yval, width, height);
        int energyMiddle = energy(image, xval, yval, width, height);
        int energyRight = energy(image, xval + 1, yval, width, height);

        //simpler and better method of doing commented out code below
        if (energyMiddle <= energyLeft && energyMiddle <= energyRight ){ //always points left in event of tie
          xval = xval; //no change, stay middle
        }
        else if (energyLeft < energyMiddle && energyLeft < energyRight){ //if left is the last option, as going "right" is actually my energyLeft
          xval = xval - 1; //go left
        }
        else if(energyRight <= energyLeft && energyRight < energyMiddle){
          xval = xval + 1; //go right
        }
        /*
        if (energyMiddle <= energyRight){ //always points mid in event of tie
          tempEnergy = energy(image, xval, yval, width, height); //no change, stay middle
        }else{
          tempEnergy = energy(image, xval + 1, yval, width, height);
        }
        
        if (tempEnergy <= energyLeft){ //testing energies
          if(tempEnergy == energyMiddle){
            xval = xval;
          }
          else if(tempEnergy == energyRight){
            xval = xval + 1;
          }
          else{ //else it has to be left (it's our last choice)
            xval = xval - 1;
          }
        }
        */
        
      }
      
      seam[yval] = xval;
      sumEnergy += energy(image, xval, yval, width, height);



    }

  return sumEnergy;
}

  /*
  //for loop
  //int energy(const Pixel *const*image, int col, int row, int width, int height)
  int sumEnergy = 0;
  int returnEnergy = 1234560;
  string tempSeamInt = ""; //going to add nubers to this so I can splice it later ----------------------------------------------- DO THIS, and add to function
  //int* tempArr = new int[height];
  
  for (int i = start_col; i < width; i++){ //going along top, column by column
    string tempSeamInt = "";
    int xval = i; //reset xval to start on the next column over
    //tempSeamInt += i;


    for (int vertical = 0; vertical < height; vertical++){ //going down
      
      int energyLeft = energy(image, xval - 1, vertical + 1, width, height);
      int energyMiddle = energy(image, xval, vertical + 1, width, height);
      int energyRight = energy(image, xval + 1, vertical + 1, width, height);
      
      sumEnergy += energy(image, xval, vertical, width, height); //adding the energy at the current address
      //seam[i] = xval; //adding the xvalue to seam list

      if (xval - 1 < 0){ //if it's a left border Pixel
        if (energyMiddle <= energyRight){ //if the middle column is the least (or equal to)
          xval = xval; //xval stays in middle column
        }
        else{
          xval = xval + 1; //move it one right
        }
      }

      else if (xval + 1 > width){ //if it's a right border Pixel
        //set xval
        if (energyLeft <= energyMiddle){ //if the side is the least or the same
          xval = xval - 1; //xval moves left
        }
        else{
          xval = xval; //xval stays in the middle
        }
      }

      else{ //if it's not a border pixel AKA we can test 3 of the next numbers
        //set xval
        if (energyLeft <= energyMiddle && energyLeft <= energyRight ){ //always points left in event of tie
          xval = xval - 1; //move left next turn
        }
        else if (energyMiddle < energyLeft && energyMiddle <= energyRight){ //if left is greater energy and right is same or greater energy
          xval = xval; //no change
        }
        else if(energyRight < energyLeft && energyRight < energyMiddle){
          xval = xval + 1; //move right next turn
        }
      }

    }
    if (sumEnergy < returnEnergy){ //if the energy is less, save it to return it
      returnEnergy = sumEnergy;

    }

  }
  //delete[] tempArr;
  return sumEnergy;
  */



// TODO Write this function
void removeVerticalSeam(Pixel **image, int& width, int height, int *verticalSeam)
{
  for (int yval = 0; yval < height; yval++){ //going down the list (y values)
    for (int xval = verticalSeam[yval]; xval < width - 1; xval++){ //setting xval = vertical seam at that point, as we are cutting that one out
      image[xval][yval] = image[xval + 1][yval]; //setting the pixel equal to the next one over, effectively replacing it and moving the picture down
    }
  }
  width -= 1; //total width decreases by one, so we change the actual value
}

// TODO Write this function for extra credit
int getHorizontalSeam(const Pixel *const*image, int start_row, int width, int height, int* seam)
{
    //int newHeight = height - 1;
    int sumEnergy = 0;
    string tempSeamString = ""; //adding numbers to splice later
    string returnSeamString = "";

    int yval = start_row;
    seam[0] = yval;
    sumEnergy += energy(image, 0, yval, width, height);
    
    
    for (int xval = 1; xval < width; xval++){ //starting one place down
      if (yval == 0){
        int energyMiddle = energy(image, xval, yval, width, height);
        int energyRight = energy(image, xval, yval + 1, width, height);
        if (energyMiddle <= energyRight){ //if the middle column is the least (or equal to)
          yval = yval; //xval stays in middle column
        }
        else{
          yval = yval + 1; //move it one right
        }

      }
      
      else if (yval == height - 1){
        int energyLeft = energy(image, xval, yval - 1, width, height);
        int energyMiddle = energy(image, xval, yval, width, height);
        if (energyMiddle <= energyLeft){ //if middle is the least or the same
          yval = yval; //xval stays middle 
        }
        else{
          yval = yval - 1; //xval moves left
        }

      }

      else{
        int energyLeft = energy(image, xval, yval - 1, width, height);
        int energyMiddle = energy(image, xval, yval, width, height);
        int energyRight = energy(image, xval, yval + 1, width, height);

        //simpler and better method of doing commented out code below
        if (energyMiddle <= energyLeft && energyMiddle <= energyRight ){ //always points left in event of tie
          yval = yval; //no change, stay middle
        }
        else if (energyLeft < energyMiddle && energyLeft < energyRight){ //if left is the last option, as going "right" is actually my energyLeft
          yval = yval - 1; //go left
        }
        else if(energyRight <= energyLeft && energyRight < energyMiddle){
          yval = yval + 1; //go right
        }
        /*
        if (energyMiddle <= energyRight){ //always points mid in event of tie
          tempEnergy = energy(image, xval, yval, width, height); //no change, stay middle
        }else{
          tempEnergy = energy(image, xval + 1, yval, width, height);
        }
        
        if (tempEnergy <= energyLeft){ //testing energies
          if(tempEnergy == energyMiddle){
            xval = xval;
          }
          else if(tempEnergy == energyRight){
            xval = xval + 1;
          }
          else{ //else it has to be left (it's our last choice)
            xval = xval - 1;
          }
        }
        */
        
      }
      
      seam[xval] = yval;
      sumEnergy += energy(image, xval, yval, width, height);



    }

  return sumEnergy;
  /*
  if (image == nullptr) { ; }
  if (start_row == 0)  { ; }
  if (width == 0)  { ; }
  if (height == 0) { ; }
  if (seam == nullptr) { ; }
  return 0;
  */
}

// TODO Write this function for extra credit
void removeHorizontalSeam(Pixel **image, int width, int& height, int *horizontalSeam)
{
  for (int xval = 0; xval < height; xval++){ //going down the list (y values)
    for (int yval = horizontalSeam[xval]; yval < height - 1; yval++){ //setting xval = vertical seam at that point, as we are cutting that one out
      image[xval][yval] = image[xval][yval + 1]; //setting the pixel equal to the next one over, effectively replacing it and moving the picture down
    }
  }
  height -= 1; //total width decreases by one, so we change the actual value
  /*
  if (image == nullptr) { ; }
  if (width == 0)  { ; }
  if (height == 0) { ; }
  if (horizontalSeam == nullptr) { ; }
  */

}

int *findMinVerticalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first col (index 0)
  int *minSeam = new int[height]{0};
  int minDist = getVerticalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[height]{0};
  int candidateDistance = -1; // invalid distance

  // start at second col (index 1) since we initialized with first col (index 0)
  for (int col = 1; col < width; ++col)
  {
    candidateDistance = getVerticalSeam(image, col, width, height, candidateSeam);

    if (candidateDistance < minDist)
    { // new min
      //  swap min & candidate
      minDist = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

  // clean up 
  delete [] candidateSeam;

  return minSeam;
}

int *findMinHorizontalSeam(const Pixel *const*image, int width, int height)
{
  // initialize minSeam and minDistance to seam starting at first row (index 0)
  int *minSeam = new int[width]{0};
  int minDistance = getHorizontalSeam(image, 0, width, height, minSeam);

  int *candidateSeam = new int[width]{0};
  int candidateDistance = -1; // invalid distance

  // start at second row (index 1) since we initialized with first row (index 0)
  for (int row = 1; row < height; ++row)
  {
    candidateDistance = getHorizontalSeam(image, row, width, height, candidateSeam);

    if (candidateDistance < minDistance)
    { // new minimum
      //  swap min and candidate seams
      minDistance = candidateDistance;
      int* temp = candidateSeam;
      candidateSeam = minSeam;
      minSeam = temp;
    }
  }

    // clean up 
  delete [] candidateSeam;

  return minSeam;
}

Pixel **createImage(int width, int height)
{
  cout << "Start createImage... " << endl;

  // Create a one dimensional array on the heap of pointers to Pixels
  //    that has width elements (i.e. the number of columns)
  Pixel **image = new Pixel *[width] {}; // initializes to nullptr

  for (int col = 0; col < width; ++col)
  { // loop through each column
    // assign that column to a one dimensional array on the heap of Pixels
    //  that has height elements (i.e. the number of rows)
    try
    {
      image[col] = new Pixel[height];
    }
    catch (std::bad_alloc &e)
    {
      // clean up already allocated arrays
      for (int i = 0; i < col; ++i)
      {
        delete[] image[i];
      }
      delete[] image;
      // rethrow
      throw e;
    }
  }

  // initialize cells
  // cout << "Initializing cells..." << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "(" << col << ", " << row << ")" << endl;
      image[col][row] = {0, 0, 0};
    }
  }
  cout << "End createImage... " << endl;
  return image;
}

void deleteImage(Pixel **image, int width)
{
  cout << "Start deleteImage..." << endl;
  // avoid memory leak by deleting the array
  for (int i = 0; i < width; ++i)
  {
    delete[] image[i];
  }
  delete[] image;
  image = nullptr;
  cout << "End deleteImage..." << endl;
}

bool isValidColor(int colorVal)
{
  if (colorVal < 0 || colorVal > 255)
  {
    return false;
  }
  return true;
}

Pixel ** loadImage(string filename, int &width, int &height)
{
  cout << "Start loadImage..." << endl;
  // remove
  ifstream ifs(filename);
  if (!ifs.is_open())
  {
    throw std::invalid_argument("Failed to open input file (" + filename + ")");
  }

  string type;
  ifs >> type; // should be P3
  if (toupper(type.at(0)) != 'P' || type.at(1) != '3')
  {
    throw std::domain_error("Not PPM type P3 (" + type + ")");
  }
  ifs >> width;
  // cout << "w and h: " << w << " " << h << endl;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for width");
  }
  if (width <= 0)
  {
    ostringstream oss;
    oss << "Width in file must be greater than 0 (" << width << ")";
    throw std::domain_error(oss.str());
  }

  ifs >> height;
  if (ifs.fail())
  {
    cout << "Read non-integer value for height" << endl;
  }
  if (height <= 0)
  {
    ostringstream oss;
    oss << "Height in file must be greater than 0 (" << height << ")";
    throw std::domain_error(oss.str());
  }

  int colorMax = 0;
  ifs >> colorMax;
  if (ifs.fail())
  {
    throw std::domain_error("Read non-integer value for max color value");
  }
  if (colorMax != 255)
  {
    ostringstream oss;
    oss << "Max color value must be 255 (" << colorMax << ")";
    throw std::domain_error(oss.str());
  }

  // load image throws exceptions but we will let them pass through
  Pixel **image = createImage(width, height);

  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      // cout << "Pixel(" << col << ", " << row << ")" << endl;
      ifs >> image[col][row].r;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for red");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for red (" << image[col][row].r << ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].g;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for green");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for green (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }

      ifs >> image[col][row].b;
      if (ifs.fail() && !ifs.eof())
      { // bad input that is not caused by being at the end of the file
        throw std::domain_error("Read non-integer value for blue");
      }
      if (!isValidColor(image[col][row].r))
      {
        ostringstream oss;
        oss << "Invalid color value for blue (" << image[col][row].r + ")";
        throw std::domain_error(oss.str());
      }
    }
  }
  cout << "End loadImage..." << endl;
  return image;
}

void outputImage(string filename, const Pixel *const *image, int width, int height)
{
  cout << "Start outputImage..." << endl;
  // remove code
  // declare/define and open output file stream with filename
  ofstream ofs(filename);
  // ensure file is open
  if (!ofs.is_open())
  {
    throw std::invalid_argument("Error: failed to open output file - " + filename);
  }
  ofs << "P3" << endl;
  ofs << width << " " << height << endl;
  ofs << 255 << endl;
  for (int row = 0; row < height; ++row)
  {
    for (int col = 0; col < width; ++col)
    {
      ofs << image[col][row].r << " ";
      ofs << image[col][row].g << " ";
      ofs << image[col][row].b << " ";
    }
    ofs << endl;
  }
  cout << "End outputImage..." << endl;
}