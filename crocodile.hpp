#ifndef CROCODILE_H
#define CROCODILE_H
#include <GL/glut.h>
#include <math.h>
#include "elipse.hpp"
#include "circle.hpp"
Ellipse ellipse;
class Crocodile
{
private:
    Circle circle;

public:
    void draw(int xpos, int ypos)
    {
        glPushMatrix();
        // glTranslatef(xpos,ypos,0);
        // glRotatef(305,0,0,1);
        ellipse.setColor(0, 0.5, 0);
        ellipse.draw(200, 600, 200, 600, 7, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 600, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 820, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(200, 380, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(350, 500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 700, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(70, 500, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 1040, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 0.2, 0);
        ellipse.draw(150, 230, 50, 80, 6, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(200, 1100, 150, 450, 8, false, 0, 360);
        //ellipse.setColor(0,0,0);
        // ellipse.draw(200,1300,100,450,7,true,330,370);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(70, 1300, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(150, 1520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 1, 0);
        ellipse.draw(250, 1520, 50, 50, 9, false, 0, 360);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(150, 1520, 30, 30, 8, false, 0, 360);
        circle.setColor(0, 0, 0);
        ellipse.setColor(0, 0, 0);
        ellipse.draw(250, 1520, 30, 30, 8, false, 0, 360);
        circle.draw(20, 60, 1300, 6, false, 0, 360);
        circle.setColor(0, 0, 0);
        circle.draw(20, 200, 1300, 6, false, 0, 360);
        // circle.setColor(0,0.2,0);
        //circle.draw(20,200,1300,6,false,0,360);
        glFlush();
        glPopMatrix();
    }
};
#endif /*CROCODILE_H*/