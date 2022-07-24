#include<stdio.h>
#include<GL/glut.h>

float h=0,k=0,theta;
int choice;



void draw_triangle()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(100.0,100.0);
	glVertex2f(400.0,100.0);
	glVertex2f(250.0,350.0);
	glEnd();
}


void display_about_origin()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glRotatef(theta,0,0,1);
	draw_triangle();
	glFlush();
}

void display_about_fixed_point()
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glTranslatef(h,k,0);
	glRotatef(theta,0,0,1);
	glTranslatef(-h,-k,0);
	draw_triangle();
	glFlush();
}



int main(int argc,char **argv)
{
	printf("Enter 1 for Rotation about the Origin :- \n");
	printf("Enter 2 for Rotation about the fixed(pivot) point :- \n");
	scanf("%d",&choice);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	
	if(choice == 1)
	{
		glutCreateWindow("Rotation about the Origin_4MT19CS117");
		
		printf("Enter the angle of Rotation :- \t");
		scanf("%f",&theta);
		glutDisplayFunc(display_about_origin);
		
	}
	
	else if(choice == 2)
	{
		glutCreateWindow("Rotation_about_fixed(pivot)_4MT19CS117");
		printf("Enter the angle of Rotation :- \t");
		scanf("%f",&theta);
		printf("Enter the Pivot(x,y) point:- \t");
		scanf("%f%f",&h,&k);
		
		glutDisplayFunc(display_about_fixed_point);
	}
	else
	{
		printf("*Wrong Choice*");
	}
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION); //symbollic constant
	glLoadIdentity();
	glOrtho(-500.0,500.0,-500.0,500.0,-500.0,500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutMainLoop();
	return 0;
}