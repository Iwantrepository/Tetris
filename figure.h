#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include "settings.h"

class Figure
{
public:
    bool buffer[4][4];
    int type;
    int x;
    int y;

    Figure ();
    ~Figure(){};
    void turn();
    void genRandFigure();
    void xd(bool d);
    void yd(bool d);


};

void Figure::xd(bool d)
{
    x+=(d)?1:-1;
    if(x<0)
        x=0;

    int maxx=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(buffer[i][j]==1)
            {
                maxx=(i>maxx)?i:maxx;
            }
        }
    }

    if(x>FIELD_MAX_X-1-maxx)
        x=FIELD_MAX_X-1-maxx;
}

void Figure::yd(bool d)
{
    y+=(d)?1:-1;

    if(y>FIELD_MAX_Y-4)
        y=FIELD_MAX_Y-4;

    int maxy=0;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            if(buffer[i][j]==1)
            {
                maxy=(3-j>maxy)?3-j:maxy;
            }
        }
    }

    if(y<-3+maxy)
        y=-3+maxy;
}


void Figure::genRandFigure()
{
    type = rand()%6;
    printf("type-%d\n", type);

    switch(type)
    {
    case 0:
        {
            bool buf[4][4] = {{0,0,0,0},
                              {0,0,0,0},
                              {0,0,1,0},
                              {1,1,1,0}};
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    buffer[i][j] = buf[j][i];
                }
            }
            break;
        }
    case 1:
        {
            bool buf[4][4] = {{0,0,0,0},
                              {0,0,0,0},
                              {1,0,0,0},
                              {1,1,1,0}};
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    buffer[i][j] = buf[j][i];
                }
            }
            break;
        }
    case 2:
        {
            bool buf[4][4] = {{0,0,0,0},
                              {0,0,0,0},
                              {0,1,1,0},
                              {1,1,0,0}};
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    buffer[i][j] = buf[j][i];
                }
            }
            break;
        }
    case 3:
        {
            bool buf[4][4] = {{0,0,0,0},
                              {0,0,0,0},
                              {1,1,0,0},
                              {0,1,1,0}};
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    buffer[i][j] = buf[j][i];
                }
            }
            break;
        }
    case 4:
        {
            bool buf[4][4] = {{0,0,0,0},
                              {0,0,0,0},
                              {0,1,0,0},
                              {1,1,1,0}};
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    buffer[i][j] = buf[j][i];
                }
            }
            break;
        }
    case 5:
        {
            bool buf[4][4] = {{0,0,0,0},
                              {0,0,0,0},
                              {0,0,0,0},
                              {1,1,1,1}};
            for(int i=0; i<4; i++){
                for(int j=0; j<4; j++){
                    buffer[i][j] = buf[j][i];
                }
            }
            break;
        }
    default:
        break;
    }
}

Figure::Figure()
{
    x=FIELD_MAX_X/2-2;
    y=FIELD_MAX_Y-4;
    genRandFigure();
}
#endif // FIGURE_H_INCLUDED
