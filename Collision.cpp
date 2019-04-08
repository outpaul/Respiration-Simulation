#include <GL/glut.h> 
#include<bits/stdc++.h>
using namespace std;
int n;
int mouse = 1;
//gravity = 9.8 units/sec^2
float g = 9.8;
//velocity in units/sec
float v1 = 10;
float v2 = 3;
//Masses are proportional to radius
float r1 = 0.5;
float r2 = 1.0;
//Coefficient of restitution
float e = 0.9; //for boundary
float e1 = 1; //for objects
//Shading for the object
int framen;
int h = 0;
void velocity1(unsigned char , int, int);
void velocity2(unsigned char , int, int);
void radius1(unsigned char , int, int);
void radius2(unsigned char , int, int);
void cRes1(unsigned char , int, int);
void cRes2(unsigned char , int, int);
void direction(unsigned char , int, int);
void noOfParticles(unsigned char , int, int);
void mouseFun(int, int , int, int);

void initLighting(){

	GLfloat qaAmbientLight[]    = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaLightPosition[]    = {0.5, 0, -3.5, 0.5};

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
}
float i = 3.75-r1;
int flag = 0;

float t = 0;
float dt = 0.05/3;
float j = 2.5;

void reshape(GLsizei width, GLsizei height){ 

	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();            
	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int animating = 0;  
void updateFrame(){
	if(h==1){
		if(i>=3.75-r1){
			flag = 1;
			v1 = e*v1;
		}
		if(i<-6.75+r1){
			flag = 0;
			v1 = e*v1;
		}
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(1.5f, 0.0f, -7.0f);
		 
			glBegin(GL_QUADS);
		      		glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f( 2.0f, 2.0f, -1.0f);
				glVertex3f(-5.0f, 2.0f, -1.0f);
				glVertex3f(-5.0f, 2.0f,  1.0f);
				glVertex3f( 2.0f, 2.0f,  1.0f);
			 
				glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f( 2.0f, -2.0f,  1.0f);
				glVertex3f(-5.0f, -2.0f,  1.0f);
				glVertex3f(-5.0f, -2.0f, -1.0f);
				glVertex3f( 5.0f, -2.0f, -1.0f);

				glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f(-5.0f,  2.0f,  1.0f);
				glVertex3f(-5.0f,  2.0f, -1.0f);
				glVertex3f(-5.0f, -2.0f, -1.0f);
				glVertex3f(-5.0f, -2.0f,  1.0f);
			 
			      
				glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f(2.0f,  2.0f, -1.0f);
				glVertex3f(2.0f,  2.0f,  1.0f);
				glVertex3f(2.0f, -2.0f,  1.0f);
				glVertex3f(2.0f, -2.0f, -1.0f);
			glEnd(); 
			GLfloat qaGreen[] = {0.0, 1.0, 0.0, 1.0}; 
			initLighting();
		if(flag==0){
			glTranslatef(i,0.0,-5.0);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);
			glutSolidSphere(0.5,25,25);
			glutSwapBuffers();
			i = i+(v1*0.05)/3;
			glFlush();
		}
		else{
			glTranslatef(i,0.0,-5.0);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);
			glutSolidSphere(0.5,25,25);
			glutSwapBuffers();
			i = i-(v1*0.05)/3;
			glFlush();
		}
	}
	else{
		if(j>2.5){
			flag = 0;
			j = 2.5;
			g = e*g;
		}
		if(j<=-2.5){
			flag = 1;
			j = -2.5;
			g = e*g;
		}
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(1.5f, 0.0f, -7.0f);
		 
			glBegin(GL_QUADS);
		      		glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f( 2.0f, 2.0f, -1.0f);
				glVertex3f(-5.0f, 2.0f, -1.0f);
				glVertex3f(-5.0f, 2.0f,  1.0f);
				glVertex3f( 2.0f, 2.0f,  1.0f);
			 
				glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f( 2.0f, -2.0f,  1.0f);
				glVertex3f(-5.0f, -2.0f,  1.0f);
				glVertex3f(-5.0f, -2.0f, -1.0f);
				glVertex3f( 5.0f, -2.0f, -1.0f);

				glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f(-5.0f,  2.0f,  1.0f);
				glVertex3f(-5.0f,  2.0f, -1.0f);
				glVertex3f(-5.0f, -2.0f, -1.0f);
				glVertex3f(-5.0f, -2.0f,  1.0f);
			 
			      
				glColor3f(1.0f, 0.5f, 0.0f); 
				glVertex3f(2.0f,  2.0f, -1.0f);
				glVertex3f(2.0f,  2.0f,  1.0f);
				glVertex3f(2.0f, -2.0f,  1.0f);
				glVertex3f(2.0f, -2.0f, -1.0f);
			glEnd(); 
			GLfloat qaGreen[] = {0.0, 1.0, 0.0, 1.0}; 
			initLighting();	
		if(flag==0){
			glTranslatef(0.0,j,-5.0);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);
			glutSolidSphere(0.5,25,25);
			glutSwapBuffers();
			j = j-((g*(t))*dt);
			t = t+dt;
			glFlush();
		}
		else{
			glTranslatef(0.0,j,-5.0);
			glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, qaGreen);
			glutSolidSphere(0.5,25,25);
			glutSwapBuffers();
			j = j+(g*(t))*dt;
			t = t-dt;
			if(t<=0){
				flag = 0;
			}
			glFlush();
		}
	}
	framen++;
}

void timerFunction(int timerID) {
    if (animating) {
        updateFrame();
        glutTimerFunc(10, timerFunction, 0);
        glutPostRedisplay();
    }
}

void startAnimation() {
   if ( ! animating ) {
       animating = 1;
       glutTimerFunc(10, timerFunction, 0);
   }
}

void pauseAnimation(){
    animating = 0;
}

void pKey(unsigned char ch, int x, int y) {
    if ( ch == ' ' ) {
		if ( animating )
		   pauseAnimation();
		else
		   startAnimation();
	}
}

void direction(unsigned char key, int x, int y){
//If H is pressed
	if(key == 104){
		h = 1;
		glutKeyboardFunc(pKey);
		startAnimation();
	}
//If V is pressed
	if(key == 118){
		h = 0;
		glutKeyboardFunc(pKey);
		startAnimation();
	}

}

void cRes1(unsigned char key, int x, int y){

	int s = 48;
	if(key>=48 && key <=57){
		
		e = (key - s)/10+0.1;
		if(n==1)
			glutKeyboardFunc(direction);
		else
			//displayP();
			cout<<"djk";
	}

}

void cRes2(unsigned char key, int x, int y){

	int s = 48;
	if(key>=48 && key <=57){
		
		e1 = (key - s)/10+0.1;
		glutKeyboardFunc(velocity1);
	}

}


void radius1(unsigned char key, int x, int y){

	int s = 48;
	if(key>=49 && key <=52){
		
		r1 = (key - s)/2;
		glutKeyboardFunc(cRes1);
	}

}

void radius2(unsigned char key, int x, int y){

	int s = 48;
	if(key>=49 && key <=52){
		
		r2 = (key - s)/2;
		glutKeyboardFunc(cRes2);
	}

}

void velocity1(unsigned char key, int x, int y){

	int s = 48;
	if(key>=49 && key <=57){
		
		v1 = (key - s)*2;
		glutKeyboardFunc(radius1);
	}

}

void velocity2(unsigned char key, int x, int y){

	int s = 48;
	if(key>=49 && key <=57){
		
		v2 = (key - s)*2;
		glutKeyboardFunc(radius2);
	}

}

void noOfParticles(unsigned char key, int x, int y){

	if(key==49){
		n = 1;
		glutKeyboardFunc(velocity1);
	}
	if(key==50){
		n = 2;
		glutKeyboardFunc(velocity2);
	}

}




int main(int argc, char** argv){

	glutInit(&argc, argv);            
	glutInitDisplayMode(GLUT_DOUBLE); 
	glutInitWindowSize(640, 480);   
	glutCreateWindow("Vertical and Horizontal motion");
	glutKeyboardFunc(noOfParticles); 
	framen = 0;
	glutReshapeFunc(reshape); 
	glutMainLoop();           
	glutHideWindow();
	return 0;
}
