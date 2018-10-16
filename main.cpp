#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <dos.h>
#include <ctime>
#include <windows.h>
#include "figure.h"
#include "tetris.h"

using namespace std;

Tetris tetris;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(2);
	glColor3f(0.0, 0.0, 0.0);

	tetris.glDisplay();

	glFlush();
}

void myfoo()
{
    tetris.timer--;
    if(tetris.timer==0)
    {
        tetris.timer = tetris.difficulty*10;
        tetris.f_down();
    }
    Sleep(10);

    display();
}

void Reshape(int Width, int Height)
{
	if (Height == 0)
	{
		Height = 1;
	}

	glViewport(0, 0, (GLsizei)Width, (GLsizei)Height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)Width, 0.0, (GLdouble)Height);

	display();
}

void init()
{
   glClearColor(1.0, 1.0, 1.0, 1.0);
}

void processNormalKeys(unsigned char key, int x, int y) {

	switch(key)
	{
    case 27:
        exit(0);
        break;
    case 246: case 'w':
        printf("W\n");
        tetris.player.yd(1);
        break;
    case 244: case 'a':
        printf("A\n");
        tetris.f_left();
        //tetris.player.xd(0);
        break;
    case 251: case 's':
        printf("S\n");
        tetris.f_down();
        tetris.timer = tetris.difficulty*10;
        //tetris.player.yd(0);
        break;
    case 226: case 'd':
        printf("D\n");
        tetris.f_right();
        //tetris.player.xd(1);
        break;
    case 32:
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                    if(tetris.player.buffer[i][j])
                        tetris.field[i+tetris.player.x][j+tetris.player.y] = tetris.player.buffer[i][j];
            }
        }
        break;
    default:
        tetris.player.genRandFigure();
        printf("%d\n", key);
        break;
	}
	display();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(500, 200);
	glutInitWindowSize(QS*FIELD_MAX_X, QS*FIELD_MAX_Y);
	glutCreateWindow( "Main window" );

	init();
    glutDisplayFunc(display);
 	glutReshapeFunc(Reshape);
 	glutIdleFunc(myfoo);

 	glutKeyboardFunc(processNormalKeys);
	//glutSpecialFunc(processSpecialKeys);

    printf("It's a test app.");
	glutMainLoop();
	return 0;
}

