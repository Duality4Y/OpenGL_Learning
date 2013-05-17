#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>

bool* keyStates = new bool[256];

double depth = 0.0f;

void keyOperations(void)
{
	if(keyStates['a'])
	{
		printf("a was pressed \n");
	}
}

void renderPrimitive(void)
{
	//glColor3f(0.0f, 0.0f, 1.0f);
	
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}

void display(void)
{
	keyOperations();
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -2.0f);
	renderPrimitive();
	glFlush();
}

void reshape(int width, int height)
{
	glViewport(0,0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)width/(GLfloat)height, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void keyPressed(unsigned char key, int x, int y)
{
	keyStates[key] = true;
}

void keyUp(unsigned char key, int x, int y)
{
	keyStates[key] = false;
}

int myMain(){return 0;}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("your first opengl window");
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);
	glutKeyboardUpFunc(keyUp);
	glutMainLoop();
	
	return 0;
}
