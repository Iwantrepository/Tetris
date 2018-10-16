#ifndef TETRIS_H_INCLUDED
#define TETRIS_H_INCLUDED

#include "settings.h"
#include "figure.h"

void glDrawSq(int i, int j, int type)
{
    switch(type)
    {
    case 0:
        glColor3f(0.2,0.2,0.2);
        break;
    case 1:
        glColor3f(1.0,0.2,0.2);
        break;
    default:
        glColor3f(1.0,1.0,1.0);
        break;
    }

    glBegin(GL_QUADS);// GL_QUADS
		glVertex2i(i*QS, j*QS);
		glVertex2i(i*QS+QS, j*QS);
		glVertex2i(i*QS+QS, j*QS+QS);
		glVertex2i(i*QS, j*QS+QS);
	glEnd();

	glLineWidth(1);
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINE_LOOP);// GL_QUADS
		glVertex2i(i*QS, j*QS);
		glVertex2i(i*QS+QS, j*QS);
		glVertex2i(i*QS+QS, j*QS+QS);
		glVertex2i(i*QS, j*QS+QS);
	glEnd();

}

class Tetris
{
public:
    int field[FIELD_MAX_X][FIELD_MAX_Y];
    Figure player;

    int difficulty = 10;
    int timer = 100;

    void f_down();
    void f_right();
    void f_left();
    void next_figure();

    Tetris();
    ~Tetris(){};
    void glDisplay();
};

void Tetris::next_figure()
{
    for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                    if(player.buffer[i][j])
                        field[i+player.x][j+player.y] = player.buffer[i][j];
            }
        }
    Figure a;
    a.genRandFigure();
    player = a;
}

void Tetris::f_down()
{
    bool is_ok = 1;
    bool next = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(player.buffer[i][j]){
                if(player.y-1+j<0){
                    is_ok=0;
                    next = 1;
                }

                if(field[player.x+i][player.y-1+j] && is_ok){
                    is_ok=0;
                    next = 1;
                }
            }
        }
    }

    if(is_ok)
        player.y--;

    if(next)
        next_figure();
}

void Tetris::f_left()
{
    bool is_ok = 1;
    bool next = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(player.buffer[i][j]){
                if(player.x-1+i<0)
                    is_ok=0;

                if(field[player.x-1+i][player.y+j] && is_ok){
                    is_ok=0;
                    next = 1;
                }
            }
        }
    }

    if(is_ok)
        player.x--;

    if(next)
        next_figure();
}

void Tetris::f_right()
{
    bool is_ok = 1;
    bool next = 0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(player.buffer[i][j]){
                if(player.x+2+i>FIELD_MAX_X)
                    is_ok=0;

                if(field[player.x+1+i][player.y+j] && is_ok){
                    is_ok=0;
                    next = 1;
                }
            }
        }
    }

    if(is_ok)
        player.x++;

    if(next)
        next_figure();
}

Tetris::Tetris()
{
    for(int i=0; i<FIELD_MAX_X; i++)
    {
        for(int j=0; j<FIELD_MAX_Y; j++)
        {
            field[i][j] = 0;
        }
    }
}

void Tetris::glDisplay()
{
    for(int i=0; i<FIELD_MAX_X; i++)
    {
        for(int j=0; j<FIELD_MAX_Y; j++)
        {
            glDrawSq(i,j,field[i][j]);
        }
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(player.buffer[i][j])
            glDrawSq(player.x+i,player.y+j,(player.buffer[i][j])?1:0);
        }
    }
}
#endif // TETRIS_H_INCLUDED
