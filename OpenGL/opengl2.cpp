#include <GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void handlKeypress(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 27: //Escape key.
			exit(0);
			break;
	}
	printf("x=%d, y=%d and key(int)=%d \n", x, y, (int)key);
}

void initRendering()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

viod handleResize(int w, int h)
{
	
}

int main(int argc, char** argv)
{
	return 0;
}
