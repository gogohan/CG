

#include <iostream>
#include <GL/glut.h>
#include <windows.h>
using namespace std;

float x[4]={50,200,200,50};
float y[4]={50,50,150,150};
void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glColor3f(1,0,1);

	glBegin(GL_POLYGON);
		for(int i=0;i<4;i++)
			glVertex2f(x[i],y[i]);
	glEnd();
	glFlush();
}

void b_fill (int a,int b)
{
	glColor3f(1,0,0);
	float p[3],f[3];
	glReadPixels(a,b,1,1,GL_RGB,GL_FLOAT,p);
	if(p[0]==0 && p[1]==0 && p[2]==0)
			return ;
	glReadPixels(a,b,1,1,GL_RGB,GL_FLOAT,f);
		if(f[0]==1 && f[1]==0 && f[2]==0)
				return ;
	glBegin(GL_POINTS);
			glVertex2f(a,b);
		glEnd();
	b_fill(a+1,b);
	b_fill(a-1,b);
	b_fill(a,b+1);
	b_fill(a,b-1);



}

void f_fill(int a,int b)
{
	glColor3f(1,0,0);
		float p[3],f[3];
		glReadPixels(a,b,1,1,GL_RGB,GL_FLOAT,p);
		if(p[0]==0 && p[1]==0 && p[2]==0)
				return ;
		glReadPixels(a,b,1,1,GL_RGB,GL_FLOAT,f);
			if(f[0]==1 && f[1]==0 && f[2]==0)
					return ;
		glBegin(GL_POINTS);
				glVertex2f(a,b);
			glEnd();
		f_fill(a+1,b);
		f_fill(a-1,b);
		f_fill(a,b+1);
		f_fill(a,b-1);
}

void mouse(int btn,int state, int m, int n)
{
	if(btn==GLUT_LEFT_BUTTON && state ==GLUT_DOWN)
	{
		b_fill(x[3]+1,y[3]-1);
		//f_fill(m,500-n);
	}
}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("B FILL");
	gluOrtho2D(0,500,0,500);
	glutDisplayFunc(draw);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;

}


