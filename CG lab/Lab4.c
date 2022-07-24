#include<stdio.h>
#include<GL/glut.h>
GLfloat theta[]={0,0,0};
GLint axis=1;
GLfloat vertices[][3]={{-1,-1,-1},
			{1,-1,-1},
			{1,1,-1},
			{-1,1,-1},
			{-1,-1,1},
			{1,-1,1},
			{1,1,1},
			{-1,1,1}
};

GLfloat Colors[][3]={{1,1,0},
		      {1,0,0},
		      {0,1,0},
		      {0,0,1},
		       {1,1,0},
		       {1,0,0},
		       {0,1,0},
		       {0,0,1}
};

void polygon(int a,int b,int c,int d)
{
glBegin(GL_POLYGON);
glColor3fv(Colors[a]);
glVertex3fv(vertices[a]);
glColor3fv(Colors[b]);
glVertex3fv(vertices[b]);
glColor3fv(Colors[c]);
glVertex3fv(vertices[c]);
glColor3fv(Colors[d]);
glVertex3fv(vertices[d]);
glEnd();
}

void colorcube(void)
{
polygon(0,1,2,3);
polygon(3,2,6,7);
polygon(0,4,7,3);
polygon(1,5,6,2);
polygon(4,5,6,7);
polygon(0,1,5,4);
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glRotatef(theta[0],1,0,0);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[2],0,0,1);
	colorcube();
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


void spincube()
{
	theta[axis]+=5;
	if(theta[axis]>360.0)
	   theta[axis]=0.0;
	glutPostRedisplay();
}


void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)  axis=0;
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_UP)  axis=1;
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_UP)  axis=2;
}

void myReshape(int w,int h)
{

	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-10,10);
	else
	glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-10.0,10.0);

	}


int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("ROTATING A COLOR CUBE_4MT19CS122");
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glutIdleFunc(spincube);
glutMouseFunc(mouse);
glEnable(GL_DEPTH_TEST);
//glMatrixMode(GL_PROJECTION);
glutMainLoop();
return 0;
}
