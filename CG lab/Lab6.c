#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
GLfloat v[4][3]={{0,0,1},{0,1,0},{-1,-0.5,0},{1,-0.5,0}};
GLfloat colors[4][3]={{1,0,0},{0,1,0},{0,0,1},{0,0,0}};
int n;



void tetra(float *a,float *b,float *c,float *d)
{
glColor3fv(colors[0]);
traingles(a,b,c);
glColor3fv(colors[1]);
traingles(a,c,d);
glColor3fv(colors[2]);
traingles(a,d,b);
glColor3fv(colors[3]);
traingles(b,d,c);
}

void traingles(float *va,float *vb,float *vc)
{
glVertex3fv(va);
glVertex3fv(vb);
glVertex3fv(vc);
}

void divide_tetra(float *a,float *b,float *c,float *d,int m)
{
float mid[6][3];
int j;
if(m>0)
{
for(j=0;j<3;j++)  mid[0][j]=( a[j]+ b[j])/2;
for(j=0;j<3;j++)  mid[1][j]=( a[j]+ c[j])/2;
for(j=0;j<3;j++)  mid[2][j]=( a[j]+ d[j])/2;
for(j=0;j<3;j++)  mid[3][j]=( b[j]+ c[j])/2;
for(j=0;j<3;j++)  mid[4][j]=( c[j]+ d[j])/2;
for(j=0;j<3;j++)  mid[5][j]=( b[j]+ d[j])/2;

divide_tetra(a,mid[0],mid[1],mid[2],m-1);
divide_tetra(mid[0],b,mid[3],mid[5],m-1);
divide_tetra(mid[1],mid[3],c,mid[4],m-1);
divide_tetra(mid[2],mid[5],mid[4],d,m-1);
}
else
{
tetra(a,b,c,d);
}
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glBegin(GL_TRIANGLES);
divide_tetra(v[0],v[1],v[2],v[3],n);
glEnd();
glFlush();
}

void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	glOrtho(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,-2,2);
	else
	glOrtho(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,-2.0,2.0);
}
	
int main(int argc,char **argv)
{
printf("Enter The No of Divisons");
scanf("%d",&n);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
glutCreateWindow("3d Tetra");
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glEnable(GL_DEPTH_TEST);
glClearColor(1,1,1,1);
glutMainLoop();
return 0;
}



