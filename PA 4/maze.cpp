/* 
maze.cpp

Author: Justin Kuo

Short description of this file:
This file contatins the maze search
function, which is a BFS algorithm.
Each point, and its north, south, east, west
direction are searched, and marked as visited
if it is open. Once the finish is found, 
the shortest path is backtracked, replacing
'*' on its way back.

*/

#include <iostream>
#include "mazeio.h"
#include "queue.h"

using namespace std;

// Prototype for maze_search, which you will fill in below.
int maze_search(char**, int, int);

// main function to read, solve maze, and print result
int main(int argc, char* argv[]) {
   int rows, cols, result;
   char** mymaze=NULL;
   
   if(argc < 2)
   {
       cout << "Please provide a maze input file" << endl;
       return 1;
   }
   mymaze = read_maze(argv[1], &rows, &cols);// FILL THIS IN
   
   if (mymaze == NULL) {
      cout << "Error, input format incorrect" << endl;
      return 1;
   }

   // when working on Checkpoint 3, you will call maze_search here.
   // here. but for Checkpoint 1, just assume we found the path.
   result = maze_search(mymaze, rows, cols); // TO BE CHANGED

   // examine value returned by maze_search and print appropriate output
   if (result == 1) { // path found!
      print_maze(mymaze, rows, cols);
   }
   else if (result == 0) { // no path :(
      cout << "No path could be found!" << endl;
   }
   else { // result == -1
      cout << "Invalid maze." << endl;
   }

   // ADD CODE HERE to delete all memory 
   // that read_maze allocated
    
    //deallocates memory for 1D array in mymaze
    for(int i=0;i<rows;i++){
        delete[] mymaze[i];
    }
    
    //deallocates memory for mymaze array
    delete[] mymaze;
    


   return 0;
}

/**************************************************
 * Attempt to find shortest path and return:
 *  1 if successful
 *  0 if no path exists
 * -1 if invalid maze (not exactly one S and one F)
 *
 * If path is found fill it in with '*' characters
 *  but don't overwrite the 'S' and 'F' cells
 *************************************************/
int maze_search(char** maze, int rows, int cols) 
{
  Location start; 
    int numStarts = 0; //number of starting points starts at 0
    int numFinish = 0; //number of finishes starts at 0
    bool pathFound = false;
    
    //finds the number of starts and finishes in the maze
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(maze[i][j] == 'S'){ 
                start.row = i; 
                start.col = j;
                numStarts++;
            } 
            else if(maze[i][j] == 'F'){
                numFinish++;
            }          
        }
    }
    //returns -1 if there is not exactly one S and F (invalid maze)
    if(numStarts !=1 || numFinish !=1){
        return -1;
    }
    //dynamic allocation of 2D array "visited"
    int** visited = new int*[rows];
    
    //allocate column in visited
    for(int i=0;i<rows;i++){
        visited[i] = new int[cols];
    }
    
    //initialize all visited values to be 0
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            visited[i][j] = 0;
        }
    }
    
    //initialize starting point in visited to 1
    visited[start.row][start.col] = 1;
    
    //intialize predecessor 2D array to (-1,-1)
    Location startingPredecessor;
    startingPredecessor.row = -1;
    startingPredecessor.col = -1;
    
    //dynamic allocation of predecessor array
    Location** predecessor = new Location*[rows];
       
    //allocates column in 2D array
    for(int i=0;i<rows;i++){
        predecessor[i] = new Location[cols];
    }
    //intialize predecessor 2D array to (-1,-1)
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            predecessor[i][j] = startingPredecessor;
        }
    }
    //creates queue with max size of the maze
    Queue q(rows*cols);
    
    //create queue and puts starting location at the end
    q.add_to_back(start);
    
    while(!q.is_empty()){
        //gets current location from front of queue
        Location curr = q.remove_from_front();
        
        //checks point directly above current point
        Location north;
        north.row = curr.row-1;
        north.col = curr.col; 
        //checks if point is within the bounds
        if(north.row >= 0 && north.row < rows && 
           north.col >= 0 && north.col < cols){
            //if finish is found,backtracks and prints * in the
            //path
            if(maze[north.row][north.col] == 'F'){
                while(maze[curr.row][curr.col] != 'S'){
                    maze[curr.row][curr.col] = '*';
                    curr = predecessor[curr.row][curr.col];
                }
                pathFound = true;
                break;
                //if the next spot is an open space, then mark as visited
                //and add back to queue
            } else if(maze[north.row][north.col] == '.' && 
                      visited[north.row][north.col] == 0){
                visited[north.row][north.col] = 1;
                predecessor[north.row][north.col] = curr;
                q.add_to_back(north);
            }    
        } 
        
        //checks for point directly below current
        Location south;
        south.row = curr.row+1;
        south.col = curr.col;
        if(south.row >= 0 && south.row < rows && 
           south.col >= 0 && south.col < cols){
            if(maze[south.row][south.col] == 'F'){
                while(maze[curr.row][curr.col] != 'S'){
                    maze[curr.row][curr.col] = '*';
                    curr = predecessor[curr.row][curr.col];
                }
                pathFound = true;
                break;
            } else if(maze[south.row][south.col] == '.' && 
                      visited[south.row][south.col] == 0){
                visited[south.row][south.col] = '1';
                predecessor[south.row][south.col] = curr;
                q.add_to_back(south);
            }
        } 
        
        Location east;
        east.row = curr.row;
        east.col = curr.col+1;
        if(east.row >= 0 && east.row < rows && 
           east.col >= 0 && east.col < cols){
            if(maze[east.row][east.col] == 'F'){
                while(maze[curr.row][curr.col] != 'S'){
                    maze[curr.row][curr.col] = '*';
                    curr = predecessor[curr.row][curr.col];
                }
                pathFound = true;
                break;
            } else if(maze[east.row][east.col] == '.' && 
                      visited[east.row][east.col] == 0){
                visited[east.row][east.col] = 1;
                predecessor[east.row][east.col] = curr;
                q.add_to_back(east);
            }
        } 
        
        Location west;
        west.row = curr.row;
        west.col = curr.col-1;
        if(west.row >= 0 && west.row < rows && 
           west.col >= 0 && west.col < cols){
            if(maze[west.row][west.col] == 'F'){
                while(maze[curr.row][curr.col] != 'S'){
                    maze[curr.row][curr.col] = '*';
                    curr = predecessor[curr.row][curr.col];
                }
                pathFound = true;
                break;
            } else if(maze[west.row][west.col] == '.' && 
                      visited[west.row][west.col] == 0){
                visited[west.row][west.col] = 1;
                predecessor[west.row][west.col] = curr;
                q.add_to_back(west);
            }
         }
      } 
    //deallocates memory of the second 1D array
    for(int i=0;i<rows;i++){
        delete[] predecessor[i];
        delete[] visited[i];
    }
    //deallocates memory for 2D array
    delete[] predecessor;
    delete[] visited;
    
    //returns 1 if a path is found
    if(pathFound == true){
        return 1;
    }
    //returns 0 (no path found)
    else{
        return 0;
    }   
}
