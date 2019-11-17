/* 
mazeio.cpp

Author: Justin Kuo

Short description of this file:
Reads and prints out the maze from 
an input file.

*/

#include <iostream>
#include <fstream>
#include "mazeio.h"

using namespace std;

/*************************************************
 * read_maze:
 * Read the maze from the given filename into a 
 *  2D dynamically  allocated array.
 * 
 * Return the pointer to that array.
 * Return NULL (a special address) if there is a problem, 
 * opening the file or reading in the integer sizes.
 *
 * The first argument is the filename of the maze input.
 *  You should use an ifstream to open and read from this
 *  file.
 *
 * We also pass in two pointers to integers. These are
 * output parameters (i.e. declared by the caller and 
 * passed-by-reference for this function to fill in).
 * Fill the integers pointed to by these arguments
 * with the number of rows and columns 
 * read (the first two input values).
 *
 *************************************************/
char** read_maze(char* filename, int* rows, int* cols) 
{
   // FILL THIS IN
    //creates file stream and opens file
    ifstream inputFile(filename); 
    //checks if file was able to be opened
    if(inputFile.fail()){
        return NULL;
    }
    
    //reads the first two numbers from the start of the file
    inputFile >> *rows >> *cols; 
    
    //returns NULL if the numbers were unable to be read
    if(inputFile.fail()){
        return NULL;
    }
      
    //dynamically allocates a 2D array
    char**maze = new char*[*rows];
    
    //allocates memory for the number of columns
    for(int i=0;i<*rows;i++){
        maze[i] = new char[*cols];
    }
    
    //fills in data for maze
    for(int i=0;i<*rows;i++){
        for(int j=0;j<*cols;j++){
            inputFile >> maze[i][j];
           //checks for invalid characters in the maze
            if(maze[i][j] != '#' && maze[i][j] != 'S' && 
               maze[i][j] != 'F' && maze[i][j] != '.'){
                    return NULL;
                }
        }
        
    }
    return maze;
}
    
    

/*************************************************
 * Print the maze contents to the screen in the
 * same format as the input (rows and columns, then
 * the maze character grid).
 *************************************************/
void print_maze(char** maze, int rows, int cols) 
{
   // FILL THIS IN
    cout << rows << " " << cols << endl;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
}

