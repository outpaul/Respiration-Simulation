#include <bits/stdc++.h>
#include <unistd.h>
#include <GL/glut.h>
#include <fstream>

using namespace std;

#define WIDTH 1024
#define HEIGHT 1440

int img[HEIGHT][WIDTH][3] = {0};

void drawCircle(GLint x, GLint y, GLfloat radius, int flag) {
    GLfloat step = 1/radius;
    GLfloat a, b;
    if(flag == 1)
        glColor3f(0.0f,0.0f,1.0f);
    else
        glColor3f(1.0f,0.0f,0.0f);
    glBegin(GL_POINTS);
    for(GLfloat theta = 0; theta <= 360; theta += step) {
        a = x + (radius * cos(theta));
        b = y + (radius * sin(theta));
        glVertex2i(a, b);
    }
    glEnd();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void display() {

    glBegin(GL_POINTS);
    for(int i = 0;i < HEIGHT;i++) {
        for(int j = 0;j < WIDTH;j++) {
            //glColor3f(img[i][j]/255.0,0.0f,0.0f);
            glColor3f(img[i][j][2]/255.0,img[i][j][0]/255.0,img[i][j][1]/255.0);
            glVertex2i(j,HEIGHT - i);
        }
    }
	glEnd();
    glFlush();
}

float x = 0, y = 0, xspeed = 0, yspeed = 0;;
int flag = 1;

void animate1() {
    if(x >= 58) {
        xspeed = 0.005 * flag;
        yspeed = -0.2 * flag;
    }
    if(y <= -100) {
        xspeed = -0.4 * flag;
        yspeed = -0.2 * flag;
    }
    if(y <= -110) {
        flag = -1;
    }
    if(flag == -1 && y >= 0) {
        xspeed = -0.2;
        yspeed = 0;
    }
    if(x <= 0 && y >= 0 && flag == -1) {
        xspeed = 0;
        yspeed = 0;
    }
    glClearColor(1.0, 1.0, 1.0, 0.0);
    display();
    drawCircle(152 + x, 462 + y, 2, flag);
    drawCircle(149 + x, 461 + y, 2, flag);
    drawCircle(151 + x, 458 + y, 2, flag);
    glutSwapBuffers();
    x += xspeed;
    y += yspeed;
}
void alveoli (){


    drawCircle(152 + x, 462 + y, 2, flag);
    drawCircle(149 + x, 461 + y, 2, flag);
    drawCircle(151 + x, 458 + y, 2, flag);

}
void start(int button, int state, int x, int y) {

    if(button == GLUT_LEFT_BUTTON) {
        x = 0;
        y = 0;
        xspeed = 0.2;
        yspeed = 0;
    }
}

int main(int argc, char **argv) {
    string line;
    ifstream xfile("array.txt");
    if(xfile.is_open()) {
        for(int i = 0;i < HEIGHT;i++) {
            for(int j = 0;j < WIDTH;j++) {
                for(int k = 0;k < 3;k++) {
                    getline(xfile,line);
                    img[i][j][k] = stoi(line);
                }
            }
        }
    }
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(700,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Lungs");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(animate1);
    glutMouseFunc(start);
    glutMainLoop();


  return 1;
}
