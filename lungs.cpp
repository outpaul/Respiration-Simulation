#include <bits/stdc++.h>
#include <unistd.h>
#include <GL/glut.h>
#include <fstream>

using namespace std;

#define WIDTH 1024
#define HEIGHT 1440

int img[HEIGHT][WIDTH][3] = {0};
int cap = 0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    //glColor3f(1.0, 1.0, 1.0);
    glPointSize(1.0);
    glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
}

void drawCircle(GLint x, GLint y, GLfloat radius, int flag = 0, GLfloat pointSize = 1.0, GLfloat start = 0.0, GLfloat end = 6.28) {
    GLfloat step = 1/radius;
    GLfloat a, b;
    if(flag == 1)
        glColor3f(0.0f,0.0f,1.0f);
    else
        glColor3f(1.0f,0.0f,0.0f);
    glPointSize(pointSize);
    glBegin(GL_POINTS);
    for(GLfloat theta = start; theta <= end; theta += step) {
        a = x + (radius * cos(theta));
        b = y + (radius * sin(theta));
        glVertex2i(a, b);
    }
    glEnd();
    glPointSize(1.0);
    glFlush();
}

void drawOxyArrow(GLfloat alpha) {

	glColor4f(1.0, 0.0, 0.0, alpha);
	glPointSize(4.0);
	glBegin(GL_LINES);
	glVertex2i(492, 620);
	glVertex2i(242, 620);
	glVertex2i(300, 700);
	glVertex2i(242, 620);
	glVertex2i(300, 540);
	glVertex2i(242, 620);
	glEnd();
	glFlush();
}

void drawCarboxyArrow(GLfloat alpha) {
	glColor4f(0.0, 0.0, 1.0, alpha);
	glPointSize(4.0);
	glBegin(GL_LINES);
	glVertex2i(512, 600);
	glVertex2i(512, 350);
	glVertex2i(592, 542);
	glVertex2i(512, 600);
	glVertex2i(432, 542);
	glVertex2i(512, 600);
	glEnd();
	glFlush();
}

void renderLungs() {
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

void renderBronchi() {

}

void renderAlveoli (){
	/*
	glColor3f(1.0,0.0,0.0);
	glutSolidSphere(400, 100, 100);
	glFlush();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex3i(-500, 700, 5);
	glVertex3i(500, 700, 5);
	glEnd();
	glFlush();
	*/
	drawCircle(512, 620, 200, 1, 10.0);
	drawCircle(512, 620, 250, 1, 10.0, 2.1);
	drawCircle(512, 620, 300, 1, 10.0, 2.1);
	glutSwapBuffers();
}

void display() {

	glClear(GL_COLOR_BUFFER_BIT);
	if(cap == 0)
		renderLungs();
	else if(cap == 1)
		renderBronchi();
	else {
		//glTranslatef(512,720,-5.0);
		renderAlveoli();
	}

}

float x = 0, y = 0, xspeed = 0, yspeed = 0;;
int flag = 1, temp = 0;

void animateLungs() {
    if(x >= 0 ) {
        xspeed = 1 * flag;
        yspeed = 1 * flag;
    }
    if(x >= 38 ) {
        xspeed = 2* flag;
        yspeed = 0 * flag;
    }
    if(x >= 202 ) {
        xspeed = 1.8 * flag;
        yspeed = -2.4 * flag;
    }

     if(y <= -55) {
        xspeed = -0.9 * flag;
        yspeed = -3.6 * flag;

    }
     if(y<= -225) {
        xspeed = 0.3 * flag;
        yspeed = -3 * flag;

    }
     if(y<= -500) {
        xspeed = 2 * flag;
        yspeed = -2 * flag;

    }
     if(y<= -585) {
        xspeed = 0.2 * flag;
        yspeed = -2 * flag;

    }
     if(y<= -620) {
        xspeed = 2 * flag;
        yspeed = -2.4 * flag;

    }
     if(y<= -725) {
        flag = -1;

    }

    if(x <= 0 && y >= 0 && flag == -1) {
        xspeed = 0;
        yspeed = 0;
    }
    glClearColor(1.0, 1.0, 1.0, 0.0);
    display();
    drawCircle(282 + x, 1185 + y, 5, flag);
    drawCircle(277 + x, 1180 + y, 5, flag);
    drawCircle(272 + x, 1185 + y, 5, flag);
    glutSwapBuffers();
    x += xspeed;
    y += yspeed;
}

void animateAlveoli() {
	float radius = 275;
	GLfloat step = 1/radius;
    GLfloat a, b;
    int arrowFlag = 1;
    GLfloat alpha = 0;
    for(GLfloat theta = 2.1; theta <= 6.28; theta += step) {
    	glClear(GL_COLOR_BUFFER_BIT);
    	alpha += ((8 * step * arrowFlag)/(6.28 - 2.1));
    	if(alpha >= 1)
    		arrowFlag = -1;
    	else if(alpha <= 0)
    		arrowFlag = 1;
    	drawOxyArrow(alpha);
    	drawCarboxyArrow(1 - alpha);
    	for(int i = 0;i < 6;i++) {
    		int flag = 0;
    		a = 512 + (radius * cos(theta + i * 1.047));
        	b = 620 + (radius * sin(theta + i * 1.047));
        	if(((theta + i * 1.047) <= 6.28 || (theta + i * 1.047) - 6.28 >= 2.1) && (theta + i * 1.047) >= 2.1) {
        		if((theta + i * 1.047) - 6.28 > 4.2)
        			flag = 1;
        		else if(((theta + i * 1.047) > 4.2) && ((theta + i * 1.047) <= 6.28))
        			flag = 1;
        		drawCircle(a, b, 15, flag, 3);
        	}
    	}
        renderAlveoli();
    }
}

void animate() {
	if(cap == 0)
		animateLungs();
	else
		animateAlveoli();
}
void start(int button, int state, int x, int y) {

    if(button == GLUT_LEFT_BUTTON) {
        x = 0;
        y = 0;
        xspeed = 1;
        yspeed = 1;
        cap = 2;
    }
}

void handleKey(int key, int x, int y) {

    if(cap == 2) {
    	if(key == GLUT_KEY_LEFT) {
    	glRotatef(-1.0,0.0,1.0,0.0);
    	}
    	else if(key == GLUT_KEY_RIGHT) {
    		glRotatef(1.0,0.0,1.0,0.0);
    	}
    	renderAlveoli();
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
    glutInitWindowPosition(100,100);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutCreateWindow("Lungs");
    init();
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMouseFunc(start);
    //glutSpecialFunc(handleKey);
    glutMainLoop();


  return 1;
}
