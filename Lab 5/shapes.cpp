#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
//draw rectangle function
void draw_rectangle(int top, int left, int height, int width) {
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            //checks if inputs are within grid
           if (i == 0||i == height-1||j == 0||j == width-1){
               if((i+top <= 256) && (j+left <= 256) && (i+top >= 0) && (j+left >= 0)){
                  image[i+top][j+left] = 0;
               }
            }
        }
    }
}
                  
// Fill in this function:

void draw_ellipse(int cy, int cx, int height, int width) {
   for(double theta=0.0;theta<2*M_PI; theta += 0.01) {
       //formula to find x and y coordinates of ellipse
       double x = (width/2)*cos(theta);
       double y = (height/2)*sin(theta);
       if((x + cx <= 256) && (y + cy <= 256) && (x + cx >= 0) && (y + cy >= 0)){
           image[(int)y + cy][(int)x + cx]= 0;
           }
      }
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
    //draw_rectangle(50, 100, 300, 100);
    //draw_ellipse(100, 50, 200, 200);
    
    while(true){
    cout << "To draw a rectangle, enter: 0" << endl;
    cout << "To draw an ellipse, enter: 1" << endl;
    cout << "To save your drawing as'output.bmp' and quit, enter: 2" << endl;
    int n;
    cin >> n;
    
    if(n==0) {
        int top;
        int left;
        int height;
        int width;
        cout << "Enter top left height width:";
        cin >> top >> left >>  height >> width;
        draw_rectangle(top, left, height, width);
            }
     if(n==1) {
        int cy;
        int cx;
        int height;
        int width;
        cout << "Enter cy cx height width:";
        cin >> cy >> cx >> height >> width;
        draw_ellipse(cy, cx, height, width);
        }
    
      if(n==2) {
        writeGSBMP("output.bmp", image);
         break;
        }
    }
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
}
