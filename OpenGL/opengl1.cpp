#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void handleKeypress(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27: //Escape Key.
			exit(0);
			break;
	}
	printf("x: %d, y: %d and key(int): %d | \n", x, y, (int)key);
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);//enable lighting
	glEnable(GL_LIGHT0); //enable light
	glEnable(GL_LIGHT1); //enable light
	glEnable(GL_NORMALIZE); //automaticly normalize normals.
	glShadeModel(GL_SMOOTH); //enable smooth shading.
}

void handleResize(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w/(double)h,1.0, 200.0);
}

float _angle = -70.0f;

void drawScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glTranslatef(0.0f, 0.0f, -8.0f);
	
	//add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f,0.2f,1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//add psitioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f};//color {0.5f, 0.5f, 0.5f}
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; // position (4.0f, 0.0f, 8.0f)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//add directed light
	GLfloat lightColor1[] = {0.5f, 0.2f, 0.2f, 1.0f};
	//comming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
	
	glRotatef(_angle, 0.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	
	//Front
	//glNormal3f(0.0f, 0.0f, 1.0f);
	glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	
	//Right
	//glNormal3f(1.0f, 0.0f, 0.0f);
	glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, 1.0f, 1.5f);
	glNormal3f(1.0f, 0.0f, 1.0f);
	glVertex3f(1.5f, -1.0f, 1.5f);
	
	//Back
	//glNormal3f(0.0f, 0.0f, -1.0f);
	glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, 1.0f, -1.5f);
	glNormal3f(1.0f, 0.0f, -1.0f);
	glVertex3f(1.5f, -1.0f, -1.5f);
	
	//Left
	//glNormal3f(-1.0f, 0.0f, 0.0f);
	glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, -1.0f, -1.5f);
	glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, -1.0f, 1.5f);
	glNormal3f(-1.0f, 0.0f, 1.0f);
	glVertex3f(-1.5f, 1.0f, 1.5f);
	glNormal3f(-1.0f, 0.0f, -1.0f);
	glVertex3f(-1.5f, 1.0f, -1.5f);
	
	glEnd();
	glutSwapBuffers();
}

void update(int value)
{
	_angle += 1.5f;
	if(_angle>360)
	{
		_angle -= 360;
	}
	
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv)
{
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	
	//create the window
	glutCreateWindow("Lighting - videotutorialsrock.com");
	initRendering();
	
	//Set handler functions
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	
	glutTimerFunc(25, update, 0); //add a timer
	
	glutMainLoop();
	return 0;
}
