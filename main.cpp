# include <iostream>
#include <GL/glut.h>
# include "apple.hpp"
// # include "elipse.hpp"
# include "monkey.hpp"
# define STB_IMAGE_IMPLEMENTATION
# include "stb_image.h"


unsigned int bg1;

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}

void displayScene1(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
           Circle circle;
    // circle.setColor(0, 0, 0);
    // circle.draw(500, 1024, 1024, 1);
    // Line line;
    // line.setColor(0, 0, 0);
    // line.draw(1000, 1000, 2000, 2000, 1);
    // Ellipse ellipse;
    // ellipse.setColor(0, 0, 0);
    // ellipse.draw(1000, 1000, 50, 100, 1);
    
    // Triangle triangle;
    // triangle.setColor(0, 0, 0);
    // triangle.draw(1000, 1000, 3000, 1000, 2000, 3000, 1);
    
    Monkey monkey;
    monkey.drawMonkey(3400,2600,0.5);
    
    
    
    Apple apple;
    apple.draw(3600,2800,1);
    apple.draw(3600,3900,1);
    apple.draw(3400,2800,1);    
    apple.draw(3400,3800,1);
    apple.draw(3000,3800,1);
    apple.draw(2600,3100,1);
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    glBegin(GL_QUADS);
    glVertex3f(0, 0, 10);
    glTexCoord2f(0, 0);
    glVertex3f(0, 5000, 10);
    glTexCoord2f(0, 1);
    glVertex3f(5000, 5000, 10);
    glTexCoord2f(1, 1);
    glVertex3f(5000, 0, 10);
    glTexCoord2f(1, 0);
    glEnd();
    glFlush();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}

void loadBackground(void)
{
    glGenTextures(1, &bg1);
    glBindTexture(GL_TEXTURE_2D, bg1);
    // set the bg1 wrapping/filtering options (on the currently bound bg1 object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    // load and generate the bg1
    int width, height, nrChannels;
    unsigned char *data = stbi_load("background1.psd", &width, &height, &nrChannels, STBI_rgb_alpha);
    if (data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        //glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load bg1" << std::endl;
    }
    stbi_image_free(data);
}

void timer(int value)
{
    glutPostRedisplay();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 1024);
    glutCreateWindow("A Smart Crow");
    glutDisplayFunc(displayScene1);
    loadBackground();
    glutTimerFunc(500,timer,0);
    glEnable(GL_DEPTH_TEST);
    init();
    glutMainLoop();
}