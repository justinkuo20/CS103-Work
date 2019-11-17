#include "turtle.h"
#include <cmath>

Turtle::Turtle(double x0, double y0, double dir0){
    //intialize all data members
    x = x0;
    y = y0;
    dir = dir0;
    draw = true;
    color = draw::BLACK;
    draw::setcolor(color);
    
}
void Turtle::move(double dist){
    double x1 = x + (dist*cos(dir*(M_PI/180))); // changes x position based on dist
    double y1 = y + (dist*sin(dir*(M_PI/180))); // changes y position based on dist 
    //draws only if draw is true
    if(draw){
        draw::setcolor(color);
        draw::line(x, y, x1, y1);
    }
    x = x1;
    y = y1;
                  
    } 
//turn function implementation
void Turtle::turn(double deg){
    dir += deg; //turn is the num degress added to the turtle's current direction
}
void Turtle::setColor(Color c){
    color = c; 
}
void Turtle::off(){
    draw = false; //makes turtle stop drawing
}
void Turtle::on(){
    draw = true; //makes turtle resume drawing
}
