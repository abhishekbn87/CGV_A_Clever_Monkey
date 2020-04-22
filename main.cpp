#include <iostream>
#include <GL/glut.h>
#include "apple.hpp"
// # include "elipse.hpp"
#include "monkey.hpp"
#define SPACEBAR 32
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "crocodile.hpp"
unsigned int bg1;
int scene = 1;
bool appleDown = false;
float xpos = 2870, ypos = 2900, cXpos = 915;

void init(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 5000, 0, 5000, 0, -500);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1, 1, 1, 1);
}

void displayScene1()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Monkey monkey;
    monkey.drawMonkey(3400, 2600, 0.5);
    Crocodile crocodile;
    crocodile.draw(cXpos, 575, 280);
    Apple apple;
    glDisable(GL_TEXTURE_2D);
    apple.draw(3600, 2800, 1);
    apple.draw(3600, 3900, 1);
    apple.draw(3400, 2800, 1);
    apple.draw(3400, 3800, 1);
    apple.draw(3000, 3800, 1);
    apple.draw(2600, 3100, 1);
    apple.draw(xpos, ypos, 1, 0);
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
void displayScene2()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
void moveCroc()
{
    if (cXpos <= 5000)
    {
        cXpos += 30;
        glutPostRedisplay();
    }
    else
    {
        glutIdleFunc(NULL);
        scene == 2;
        glutDisplayFunc(displayScene2);
        glutPostRedisplay();
    }
}
void keyboard(unsigned char key, int x, int y)
{
    if (scene == 1)
        if (appleDown)
            if (key == SPACEBAR)
            {
                xpos = 6000;
                glutPostRedisplay();
                glutIdleFunc(moveCroc);
            }
}
void idle()
{
    if (ypos >= 300)
    {
        ypos -= 30;
        glutPostRedisplay();
    }
    else
    {
        appleDown = true;
        glutIdleFunc(NULL);
    }
}

void mouse(int button, int state, int x, int y)
{
    if (scene == 1)
        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
            glutIdleFunc(idle);
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
    glutInitWindowSize(1024, 768);
    glutCreateWindow("A Clever Monkey");
    glutDisplayFunc(displayScene1);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);
    loadBackground();
    glutTimerFunc(500, timer, 0);
    glEnable(GL_DEPTH_TEST);
    init();
    glutMainLoop();
}