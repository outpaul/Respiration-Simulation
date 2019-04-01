#include <bits/stdc++.h>
#include <unistd.h>
#include <GL/glut.h>
#include <fstream>

using namespace std;

//vector<vector <vector<int>>> img(533, vector<int>(433, vector<int> (3)));


void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 438, 0, 533);
}

void display() {

    /*glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex2i(50,50);
    glVertex2i(250,50);
    glVertex2i(100,100);*/
    glBegin(GL_POINTS);
    for(int i = 0;i < 533;i++) {
        for(int j = 0;j < 438;j++) {
            //glColor3f(img[i][j]/255.0,0.0f,0.0f);
            glColor3f(img[i][j]/255.0,img[i][j]/255.0,img[i][j]/255.0);
            glVertex2i(j,533 - i);
        }
    }
	glEnd();
    glFlush();
}

float x = 0, y = 0, xspeed = 0, yspeed = 0;;

void animate1() {
    if(x >= 58) {
        xspeed = 0.005;
        yspeed = -0.2;
    }
    if(y <= -100) {
        xspeed = -0.4;
        yspeed = -0.2;
    }
    if(y <= -110) {
        x = 1000;
        y = 1000;
    }
    glClearColor(1.0, 1.0, 1.0, 0.0);
    display();
    glBegin(GL_TRIANGLES);
    glColor3f(1,0,0);
    glVertex2i(152+x,464+y);
    glVertex2i(147+x,460+y);
    glVertex2i(152+x,456+y);
    glEnd();
    glFlush();
    x += xspeed;
    y += yspeed;
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
    /*string line;
    ifstream xfile("array.txt");
    if(xfile.is_open()) {
        while(getline(xfile, line)) {

        }
    }*/
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(700,100);
    glutInitWindowSize(438,533);
    glutCreateWindow("Lungs");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(animate1);
    glutMouseFunc(start);
    glutMainLoop();


  return 1;
}