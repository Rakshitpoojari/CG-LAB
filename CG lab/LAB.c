#include<stdio.h>
#include<GL/glut.h>
int x1,x2,y1,y2;

void draw_pixel(int x,int y)
{
//int i;
glPointSize(16);
glBegin(GL_POINTS);
glColor3f(0,0,1);
glVertex2i(x,y);
glEnd();
//for(i=0;i<1000000000000;i++)
//glFlush();
}
void draw_line(int x1,int x2,int y1,int y2)
{
int dy,dx,i,e;
int incx,incy,inc1,inc2;
incx=1;
incy=1;
int x,y;
dx=x2-x1;
dy=y2-y1;
	if(dx<0)
	dx=-dx;

	if(dy<0)
	dy=-dy;

	if(x2<x1)
	incx=-1;

	if(y2<y1)
	incy=-1;
x=x1;
y=y1;
	if(dx>dy)
	
	{
	draw_pixel(x,y);
	e=2*dy-dx;
	inc1=2*(dy-dx);
	inc2=2*dy;
	for(i=0;i<dx;i++)
	{
	if(e>=0)
	{
	y+=incy;
	e+=inc1;
	}
	else 
	e+=inc2;
	x+=incx;
	draw_pixel(x,y);
	}
}
else
	{
	draw_pixel(x,y);
	e=2*dy-dx;
	inc1=2*(dy-dx);
	inc2=2*dy;
	for(i=0;i<dy;i++)
	{
	if(e>0)
	{
	x+=incx;
	e+=inc1;
	}
	else 
	e+=inc2;
	y+=incy;
	draw_pixel(x,y);
	}
	}
}
void DISPLAY()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_line(x1,x2,y1,y2);
glFlush();
}
int main(int argc,char **argv)
{
printf("Enter two End Points of the line");
scanf("%d%d%d%d",&x1,&x2,&y1,&y2);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(200,100);
glutCreateWindow("BRESHENHAMS LINE DRAWING ALGORITHM");
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0,100,0,100);
glClearColor(1,1,1,0);
glutDisplayFunc(DISPLAY);
glutMainLoop();
return 0;
}




