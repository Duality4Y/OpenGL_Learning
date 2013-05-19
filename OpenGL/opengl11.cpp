#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

static GLfloat spin = 0.0;
GLfloat spinSpeed = 0.0;
GLfloat spinRate = 0.1;

int mousePos[2];
double mouseMapDegrees[2];

class log
{
	public:
	
};

void init(void)
{
	glClearColor(0.0,0.0,0.0,0.0);
	//glShadeModel(GL_FLAT);
}

void drawPrimitive(double width, double height, double depth,double spin)
{
	glRotatef(spin, 0.0,0.0, 1.0);
	glBegin(GL_QUADS);
	
	glColor3f(0.0f,0.0f,1.0f);
	glVertex3f(-(width),-(height), depth);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-(width),(height), depth);
	
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f((width), (height), depth);
	
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f((width), -(height), depth);
	glEnd();
}


void spinDisplay(int *mousePosition)
{
	int x = mousePosition[0], y = mousePosition[1];
	printf("mouse x,y: %d,%d \n",x,y);
	printf("x/360 and y/360: %f,%f\n",mouseMapDegrees[0]=(double)((x*10.0f)/360.0f),mouseMapDegrees[1]=(double)((y*10.f)/360.0f));
	printf("spinSpeed: %f, spinRate %f, spin %f \n", spinSpeed, spinRate, spin);
	spin += spinSpeed;
	if(spin > 360.0 or spin < -360.0)
	{
		//spin = spin - 360.0;
	}
	if(spinSpeed > 360.0 || spinSpeed < -360)
	{
		spinSpeed*= -1;
	}
	glutPostRedisplay();
}

void display(void)
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	//glRotatef(spin, 0.0, 0.0, 1.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	//glRectf(-25.0, -25.0, 25.0, 25.0);
	drawPrimitive(mouseMapDegrees[0]*0.5f,mouseMapDegrees[1]*0.5f,1.0f,spin);
	glPopMatrix();
	glutSwapBuffers();
	spinDisplay(mousePos);
}

void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void getMousePos(int x, int y)
{
	mousePos[0] = x, mousePos[1] = y;
}

void mouse(int button, int state, int x, int y)
{
	printf("button: %d, state: %d \n", button, state);
	switch(button)
	{
		case 7:
		case 4:
		//go back button mouse, decrease spin rate.
			if(spinSpeed>-360)
			{
				spinSpeed-=spinRate;
			}
			break;
		case 8:
		case 3:
		//go forward button mouse, increase spin rate.
			if(spinSpeed<360){
				spinSpeed+=spinRate;
			}
			break;
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	
	init();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//only called when there is a button change.
	glutMouseFunc(mouse);
	//called when the mouse moves
	glutPassiveMotionFunc(getMousePos);
	glutMainLoop();
	return 0;
}
