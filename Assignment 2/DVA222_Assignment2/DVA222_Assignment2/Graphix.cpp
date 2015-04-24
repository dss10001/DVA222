#include "stdafx.h"
#include <math.h>
#include "Graphix.h"

//----------------------------------------------------------------------
//DO NOT DO ANYTHING HERE. JUST CLOSE THIS FILE. NOW!
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//I SAID NOW!
//----------------------------------------------------------------------

void DrawLine(int x1, int y1, int x2, int y2 )
{
    glBegin(GL_LINES);
        glVertex3f(x1, y1, 0.0);
        glVertex3f(x2, y2, 0.0);
    glEnd();    
}

void DrawRectanle(int x, int y, int width, int height )
{
	glBegin(GL_LINE_LOOP);
        glVertex3f(x, y, 0.0);
        glVertex3f(x+width, y, 0.0);
		glVertex3f(x+width, y+height, 0.0);
		glVertex3f(x, y+height, 0.0);
    glEnd();    
}

void DrawCircle(int cx, int cy, int radius )
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0;i <= 360; i+= 5)
	{
		int x = cos(i / 180.0 * 3.1416) * radius;
		int y = sin(i / 180.0 * 3.1416) * radius;
        glVertex3f(cx+x, cy+y, 0.0);
	}
    glEnd();    
}

void FillRectanle(int x, int y, int width, int height )
{
	glBegin(GL_QUADS);
        glVertex3f(x, y, 0.0);
        glVertex3f(x+width, y, 0.0);
		glVertex3f(x+width, y+height, 0.0);
		glVertex3f(x, y+height, 0.0);
    glEnd();    
}

void SetColor(int r, int  g, int  b)
{
	glColor3f(r/255.0,g/255.0,b/255.0);
}

void Redraw()
{
	invalidate = true;
}

void display(void)
{
	if (!invalidate)
		return;
	invalidate = false;
    //Clear all pixels
    glClear(GL_COLOR_BUFFER_BIT);

    Draw();
    // Don't wait start processing buffered OpenGL routines
    glFlush();

}

void init(void)
{
    //select clearing (background) color
    glClearColor(0.0, 0.0, 0.0, 0.0);
    //initialize viewing values 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 800.0, 600.0, 0.0, -1.0, 1.0);
}

void timerCB(int millisec)
{
    glutTimerFunc(millisec, timerCB, millisec); // for next timer event
    glutPostRedisplay();
}

void InitGraphix(int argc, char** argv)
{			 	
	//Initialise GLUT with command-line parameters. 
    glutInit(&argc, argv);
    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    //Set the window size
    glutInitWindowSize(800,600);
    //Set the window position
    glutInitWindowPosition(100,100);
    //Create the window
    glutCreateWindow("DVA 222 - Assignment 2");
    //Call init (initialise GLUT
    init();
    //Call "display" function
    glutDisplayFunc(display);
	glutTimerFunc(33, timerCB, 33); // redraw every 33 millisec (30fps)
    //Enter the GLUT event loop
    glutMainLoop();
}