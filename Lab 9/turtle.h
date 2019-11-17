#ifndef TURTLE_H_
#define TURTLE_H_
#include "draw.h"

class Turtle {
private: 
    double x;
    double y;
    double dir;
    Color color;
    bool draw;
public:
    Turtle(double x0, double y0, double dir0); //turtle constuctor
    void move(double dist); 
    void turn(double deg); 
    void setColor(Color c); //change line color that his turle draws from now on
    void off(); //make this turtle stop drawing lines when it moves
    void on(); //make this turtle resume drawing lines when it moves

};

#endif 