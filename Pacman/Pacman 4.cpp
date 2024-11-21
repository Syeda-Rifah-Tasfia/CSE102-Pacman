#include "igraphics.h"
#include<stdlib.h>
#include<conio.h>

#define pi 3.1416
#define screenHeight 700
#define screenWidth 700

void walk();
void run();
void change();
void ball();
void bigBall();
void Blinky();
void Pinky();
void Clyde();
void Inky();
void ghostAppear();
void ghostChange();
void setEnemyVar();
double cart(int x1, int y1, int x2, int y2);
void Collision();
void Score();
int highScore();
void Pause();
void Resume();
void newGame();
void saveGame();
void loadGame();

int maze[31][30]={{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1},
                  {1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

int gameState=0;

int numberOfBalls=638;
int balltracer=1;
int bigB=0;
char pac[5][15]={"1.bmp", "2.bmp", "3.bmp", "4.bmp", "5.bmp"};
char gst[4][15]={"6.bmp", "7.bmp", "8.bmp", "20.bmp"};


//pacman position and speed:
int px1=14;
int py1=9;
int speed_x=0;
int speed_y=0;
int pacmanIndex=0;

int tracer=1, l=0, r=0, u=0, d=0, score=0;
int minute=0, second=0;
char str1[10]="0:00";
int pauseTracer=0, resumeTracer=0;
int specialKeyboardTracer=1;
int KeyboardTracer=1;

int i, j;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
double d1, d2, d3, d4;
int ghostTimer=200;

int col=0;
int lifeTracer[2]={1, 1};
int LIFE=3;

int newG=0;

FILE *fScore;
char SCORE[10]={0};
int scoreCount1=0, scoreList[10], scoreCount2=0;
char strScore[10];

int highScore()
{
FILE *f = NULL;
    int scoreCount1 = 0;
    f = fopen("Score.txt", "r");
    if(f == NULL) return 0;
    while(1){
        if(feof(f))break;
        fscanf(f, " %d", &scoreList[scoreCount1++]);

    }
    fclose(f);

    for(int i = 0; i < scoreCount1; i++)
    {
        for(int j = 0; j < scoreCount1; j++)
        {
            if(scoreList[i] > scoreList[j])
            {
                int temp = scoreList[i];
                scoreList[i] = scoreList[j];
                scoreList[j] = temp;
            }
        }
    }

    f = fopen("Score.txt", "w");
    for(int i = 0; i < scoreCount1; i++)
    {
       fprintf(f, " %d", scoreList[i]);
        if(i > 9){
            scoreCount1 = i;
            break;
        }
    }
    fclose(f);
    return scoreCount1;
}

struct enemy
{
    int gx;
    int gy;
    int gIndex;
    int gDirIndex;
    bool gShow=true;
};

enemy ghost[4];

int check(int x, int y)
{
    if(maze[x][y]==1)
        return 0;
    return 1;
}

void Blinky()
{
    Collision();
    double minimum = 10000000;
    int new_x, new_y;
    for(int i = 0; i < 4; i++)
    {
        if(check(ghost[0].gy+dy[i], ghost[0].gx+dx[i]))
        { //can go that direction
            d1 = cart(px1+4, py1, ghost[0].gx+dx[i], ghost[0].gy+dy[i]); //if it can go there, measure the distance
            if(d1 < minimum)
            { // if less than the lowest value, update the lowest
                minimum = d1;
                new_x = ghost[0].gx+dx[i]; //new destination
                new_y = ghost[0].gy+dy[i];
                ghost[0].gDirIndex=i;
            }
        }
    }
    ghost[0].gx = new_x;
    ghost[0].gy = new_y;
    saveGame();
}

void Pinky()
{
    Collision();
    double minimum = 10000000;
    int new_x, new_y;
    for(int i = 0; i < 4; i++)
    {
        if(check(ghost[1].gy+dy[i], ghost[1].gx+dx[i]))
        { //can go that direction
            d2 = cart(px1, py1, ghost[1].gx+dx[i], ghost[1].gy+dy[i]); //if it can go there, measure the distance
            if(d2 < minimum)
            { // if less than the lowest value, update the lowest
                minimum = d2;
                new_x = ghost[1].gx+dx[i]; //new destination
                new_y = ghost[1].gy+dy[i];
            }
        }
    }
    ghost[1].gx = new_x;
    ghost[1].gy = new_y;
    saveGame();
}

void Clyde()
{
    Collision();
    double minimum = 10000000;
    int new_x, new_y;
    for(int i = 0; i < 4; i++)
    {
        if(check(ghost[2].gy+dy[i], ghost[2].gx+dx[i]))
        { //can go that direction
            d3 = cart(px1, py1-3, ghost[2].gx+dx[i], ghost[2].gy+dy[i]); //if it can go there, measure the distance
            if(d3 < minimum)
            { // if less than the lowest value, update the lowest
                minimum = d3;
                new_x = ghost[2].gx+dx[i]; //new destination
                new_y = ghost[2].gy+dy[i];
            }
        }
    }
    ghost[2].gx = new_x;
    ghost[2].gy = new_y;
    saveGame();
}

void Inky()
{
    Collision();
    double minimum = 10000000;
    int new_x, new_y;
    for(int i = 0; i < 4; i++)
    {
        if(check(ghost[3].gy+dy[i], ghost[3].gx+dx[i]))
        { //can go that direction
            d4 = cart(py1, px1, ghost[3].gx+dx[i], ghost[3].gy+dy[i]); //if it can go there, measure the distance
            if(d4 < minimum)
            { // if less than the lowest value, update the lowest
                minimum = d4;
                new_x = ghost[3].gx+dx[i]; //new destination
                new_y = ghost[3].gy+dy[i];
            }
        }
    }
    ghost[3].gx = new_x;
    ghost[3].gy = new_y;
    saveGame();
}

void ghostAppear()
{
    for(i=0; i<4; i++)
    {
        iShowBMP2(ghost[i].gx*20, ghost[i].gy*20, gst[ghost[i].gIndex], 0);
    }
}

void ghostChange()
{
    for(i=0; i<4; i++)
    {
        ghost[i].gIndex=i;
    }
}

void setEnemyVar()
{
    for(i=0; i<4; i++)
    {
        ghost[i].gx=13;
        ghost[i].gy=15;
        if(i==1)
        {
            ghost[i].gy+=2;
        }
        if(i==2)
        {
            ghost[i].gx+=2;
        }
        if(i==3)
        {
            ghost[i].gx+=2;
            ghost[i].gy+=2;
        }
    }
  //  saveGame();
}

double cart(int x1, int y1, int x2, int y2)
{
    double distance;
    int temp;
    temp=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
    distance=sqrt(temp*1.0);
    return distance;
}

int k;
void Collision()
{
    if((px1==ghost[0].gx && py1==ghost[0].gy) || (px1==ghost[1].gx && py1==ghost[1].gy) || (px1==ghost[2].gx && py1==ghost[2].gy) || (px1==ghost[3].gx && py1==ghost[3].gy))
    {

        col=1;
        lifeTracer[k]=0;
        px1=14;
        py1=9;
        k++;
        LIFE--;
    }
    saveGame();
}

void Pause()
{
    iPauseTimer(0);
    iPauseTimer(1);
    iPauseTimer(2);
    iPauseTimer(3);
    iPauseTimer(4);
    iPauseTimer(5);
    iPauseTimer(6);
    iPauseTimer(7);
    iPauseTimer(8);
}

void Resume()
{
    iResumeTimer(0);
    iResumeTimer(1);
    iResumeTimer(2);
    iResumeTimer(3);
    iResumeTimer(4);
    iResumeTimer(5);
    iResumeTimer(6);
    iResumeTimer(7);
    iResumeTimer(8);
}

void iDraw()
{
    iClear();
    if(gameState==-1)
    {
        if(LIFE<=0)
        {
            //Score();
            Pause();
            specialKeyboardTracer=0;
            iShowBMP(0, 0, "End.bmp");
            newG=1;
            return;
        }
        int i, j;
        int x=0, y=0;
        for(i=0;i<31;i++)
        {
            for(j=0;j<30;j++)
            {
                if(maze[i][j]==1)
                {
                    iSetColor(11, 5, 222);
                    iRectangle(j*20, i*20, 20, 20);
                    iFilledRectangle(j*20, i*20, 20, 20);
                }
                else if(maze[i][j]==0)
                {
                    iSetColor(192, 192, 192);
                    iCircle(j*20+10, i*20+10, 3);
                    iFilledCircle(j*20+10, i*20+10, 3);
                }
                else if(maze[i][j]==2)
                {
                    iSetColor(0,255,0);
                    iRectangle(j*20, i*20, 20, 20);
                    iFilledRectangle(j*20, i*20, 20, 20);
                }
                else if(maze[i][j]==3)
                {
                    iSetColor(0,0,0);
                    iRectangle(j*20, i*20, 20, 20);
                    iFilledRectangle(j*20, i*20, 20, 20);
                }
                else if(maze[i][j]==4)
                {
                    iSetColor(0, 255, 0);
                    iCircle(j*20+10, i*20+10, 7);
                    iFilledCircle(j*20+10, i*20+10, 7);
                }
                x+=20;
            }
            x=0;
            y+=20;
        }
        iSetColor(255, 255, 255);
        iShowBMP2(px1*20, py1*20, pac[pacmanIndex], 0);
        if(lifeTracer[0]==1)
            iShowBMP2(550, 630, "3.bmp", 0);
        if(lifeTracer[1]==1)
            iShowBMP2(520, 630, "3.bmp", 0);
        iSetColor(255, 255, 0);
        iText(470, 633, "Life:", GLUT_BITMAP_TIMES_ROMAN_24);
        sprintf(SCORE, "Score: %d", score);
        iText(10, 680, SCORE, GLUT_BITMAP_TIMES_ROMAN_24);
        iText(10, 650, str1, GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255, 255, 0);
        if(second<10)
            sprintf(str1, "%d:0%d", minute, second);
        else
            sprintf(str1, "%d:%d", minute, second);
        iRectangle(630, 660, 60, 30);
        iText(640, 665, "Exit", GLUT_BITMAP_TIMES_ROMAN_24);
        iRectangle(630, 620, 65, 30);
        iText(630, 625, "Home", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(140, 680, "Press R/r to Start/Resume, press P/p to Pause", GLUT_BITMAP_TIMES_ROMAN_24);
        ghostAppear();
    }
    else if(gameState==0)
    {
        Pause();
        specialKeyboardTracer=0;
        iShowBMP(0, 0, "Home.bmp");
        iShowBMP2(50, 440, "Cont.bmp", 0XFFFFFF);
        iShowBMP2(47, 350, "New Game.bmp", 0XFFFFFF);
        iShowBMP2(50, 260, "Score.bmp", 0XFFFFFF);
        iShowBMP2(50, 185, "Help 1.bmp", 0XFFFFFF);
        iShowBMP2(50, 90, "Exit.bmp", 0XFFFFFF);
    }
    else if(gameState==1)
    {
        iSetColor(255, 255, 0);
        iShowBMP(0, 0, "Hscore.bmp");
        scoreCount2=highScore();
        printf("%d ", scoreCount2);
        iText(290, 600, "Scoreboard", GLUT_BITMAP_TIMES_ROMAN_24);
        iLine(285, 590, 405, 590);
        for(i=0; i<scoreCount2; i++)
        {
            sprintf(strScore, "%d.", i+1);
            iText(300, 550-i*50, strScore, GLUT_BITMAP_TIMES_ROMAN_24);
            sprintf(strScore, "%d", scoreList[i]);
            iText(340, 550-i*50, strScore, GLUT_BITMAP_TIMES_ROMAN_24);
        }
        iShowBMP2(0, 0, "Back.bmp", 0);
        iShowBMP2(583, 0, "Start.bmp", 0);
    }
    else if(gameState==2)
    {
        iShowBMP(0, 0, "Help Page.bmp");
        iShowBMP2(0, 0, "Back.bmp", 0);
        iShowBMP2(583, 0, "Start.bmp", 0);

    }
    else if(gameState==3)
    {
        iShowBMP(0, 0, "Mid.bmp");
    }
    else if(gameState==4)
    {
        //Game complete
        iShowBMP(0, 0, "Yay.bmp");
        Pause();
        specialKeyboardTracer=0;
        newG=1;
        //Score();
    }
    printf("%d\n", numberOfBalls);
}

//eating balls
void ball()
{
    if(LIFE==0)
    {
        Pause();
        return;
    }
    else
    {
        if(maze[py1][px1]==0)
        {
            maze[py1][px1]=3;
            score++;
            numberOfBalls--;
            if(numberOfBalls<=0)
                gameState=4;
        }
        if(maze[py1][px1]==4)
        {
            maze[py1][px1]=3;
            score+=10;
            numberOfBalls--;
            //bigB=1;
            if(numberOfBalls<=0)
                gameState=4;
        }
    }
    saveGame();
}

void iMouse(int button, int state, int mx, int my)
{
    if(gameState==-1 && mx>=630 && mx<=680 && my>=660 && my<=690)
    {
        exit(0);
    }
    if(gameState==-1 && mx>=630 && mx<=695 && my>=620 && my<=650)
    {
        Pause();
        specialKeyboardTracer=0;
        gameState=0;
    }
    else if(gameState==0 && mx>=50 && mx<=377 && my>=440 && my<=520)
    {
        loadGame();
        gameState=-1;
    }
    else if(gameState==0 && mx>=47 && mx<=432 && my>=350 && my<=431)
    {
        gameState=-1;
        newGame();
    }
    else if(gameState==0 && mx>=50 && mx<=270 && my>=260 && my<=341)
    {
        gameState=1;
    }

    else if(gameState==0 && mx>=50 && mx<=270 && my>=185 && my<=266)
    {
        gameState=2;
    }
    else if(gameState==0 && mx>=50 && mx<=270 && my>=90 && my<=171)
    {
        exit(0);
    }
    else if(gameState==1 && mx>=0 && mx<=117 && my>=0 && my<=67)
    {
        gameState=0;
    }
    else if(gameState==1 && mx>=583 && mx<=700 && my>=0 && my<=67)
    {
        gameState=-1;
        newGame();
    }
    else if(gameState==2 && mx>=0 && mx<=117 && my>=0 && my<=67)
    {
        gameState=0;
    }
    else if(gameState==2 && mx>=583 && mx<=700 && my>=0 && my<=67)
    {
        gameState=-1;
        newGame();
    }
    else if(gameState==3 && mx>=186 && mx<=472 && my>=557 && my<=659)
    {
        Pause();
        specialKeyboardTracer=0;
        gameState=0;
    }
    else if(gameState==3 && mx>=134 && mx<=534 && my>=388 && my<=512)
    {
        gameState=-1;
        Resume();
        specialKeyboardTracer=1;
    }
    else if(gameState==3 && mx>=203 && mx<=458 && my>=230 && my<=340)
    {
        exit(0);
    }
    else if(newG==1 && mx>=0 && mx<=190 && my>=0 && my<=60)
    {
        gameState=0;
        Score();
        newGame();
    }
    else if(newG==1 && gameState!=4 && mx>=530 && mx<=700 && my>=0 && my<=60)
    {
        Score();
        exit(0);
    }
}

void iMouseMove(int mx, int my)
{

}


void iKeyboard(unsigned char button)
{
    if(button=='p'||button=='P')
    {
        if(LIFE<=0)
        {
            Pause();
            specialKeyboardTracer=0;
            return;
        }
        else
        {
            Pause();
            specialKeyboardTracer=0;
            gameState=3;
        }
    }
    if(button=='r'||button=='R')
    {
        if(LIFE<=0)
        {
            Pause();
            return;
        }
        else
        {
            Resume();
            specialKeyboardTracer=1;
            gameState=-1;
            //pauseTracer=0;
        }
    }
    if(button=='N' && newG==1)
    {
        gameState=0;
        Score();
        newGame();
    }
//    if(button=='a')
//        gameState=4;

}

//running and walls
void run()
{
    if(l==1)
    {
        if(maze[py1][px1-1]==1)
        {
            speed_x=0;
            speed_y=0;
        }
        else
            speed_x=1;
        px1-=speed_x;
    }
    if(r==1)
    {
        if(maze[py1][px1+1]==1)
        {
            speed_x=0;
            speed_y=0;
        }
        else
            speed_x=1;
        px1+=speed_x;
    }
    if(u==1)
    {
        if(maze[py1+1][px1]==1)
        {
            speed_x=0;
            speed_y=0;
        }
        else
            speed_y=1;
        py1+=speed_y;
    }
    if(d==1)
    {
        if(maze[py1-1][px1]==1)
        {
            speed_x=0;
            speed_y=0;
        }
        else
            speed_y=1;
        py1-=speed_y;
    }
}


void iSpecialKeyboard(unsigned char key)
{
    if(key==GLUT_KEY_END)
    {
        Score();
        saveGame();
        Sleep(500);
        exit(0);
    }
    if(specialKeyboardTracer==0 || LIFE<=0)
    {
        Pause();
        return;
    }

    if(key==GLUT_KEY_LEFT)
    {
        l=1;
        r=0;
        u=0;
        d=0;
        pacmanIndex=1;
        run();
        ball();
        saveGame();
    }
    if(key==GLUT_KEY_RIGHT)
    {
        l=0;
        r=1;
        u=0;
        d=0;
        pacmanIndex=2;
        run();
        ball();
        saveGame();
    }
    if(key==GLUT_KEY_UP)
    {
        l=0;
        r=0;
        u=1;
        d=0;
        pacmanIndex=3;
        run();
        ball();
        saveGame();
    }
    if(key==GLUT_KEY_DOWN)
    {
        l=0;
        r=0;
        u=0;
        d=1;
        pacmanIndex=4;
        run();
        ball();
        saveGame();
    }

}

void Score()
{
    fScore=fopen("Score.txt", "a");
    fprintf(fScore, " %d", score);
    fclose(fScore);
    saveGame();
}

void walk(int x)
{
    if(pacmanIndex==x)
    {
        pacmanIndex+=x;
        if(pacmanIndex>x)
            pacmanIndex=0;
    }
}

void change()
{
    walk(1);
    walk(2);
    walk(3);
    walk(4);
   // saveGame();
}

void door()
{
    //maze[20][11]=0;

    //maze[20][12]=0;
}


void gameTime()
{
    if(second<10)
        sprintf(str1, "%d:0%d", minute, second);
    else
        sprintf(str1, "%d:%d", minute, second);
    second++;
    if(second==60)
    {
        second=0;
        minute++;
    }
  //  saveGame();
}

int bigBall_x, bigBall_y;
void bigBall()
{
    bigBall_x=rand()%20;
    bigBall_y=rand()%10;
    if(maze[bigBall_y][bigBall_x]==0)
    {
        maze[bigBall_y][bigBall_x]=4;
    }
    else if(maze[bigBall_y][bigBall_x]==3)
    {
        maze[bigBall_y][bigBall_x]=4;
        numberOfBalls++;
    }
 //   saveGame();
}

void newGame()
{
    for(i=0; i<31; i++)
    {
        for(j=0; j<30; j++)
        {
            if(maze[i][j]!=1 && maze[i][j]!=2)
            {
                maze[i][j]=0;
            }

        }
    }
    px1=14;
    py1=9;
    score=0;
    k=0;
    LIFE=3;
    second=0;
    minute=0;
    //gameTime();
    numberOfBalls=638;
    setEnemyVar();
    lifeTracer[0]=1;
    lifeTracer[1]=1;
    //gameState=-1;
    saveGame();
}

void saveGame()
{
    FILE *f=NULL;
    f = fopen("save.txt", "w");
    for(i=0; i<31; i++)
    {
        for(j=0; j<30; j++)
        {
            fprintf(f, "%d ", maze[i][j]);
        }
    }
    fprintf(f, "%d %d %d %d %d %d %d %d\n", score, k, LIFE, second, minute, numberOfBalls, lifeTracer[0], lifeTracer[1]);
    for(i=0; i<4; i++)
    {
        fprintf(f, "%d %d\n", ghost[i].gx, ghost[i].gy);
    }
    fprintf(f, "%d %d", px1, py1);
    fclose(f);
}

void loadGame()
{
    FILE *f=NULL;
    f = fopen("save.txt", "r");
    for(i=0; i<31; i++)
    {
        for(j=0; j<30; j++)
        {
            fscanf(f, "%d ", &maze[i][j]);
        }
    }
    fscanf(f, "%d %d %d %d %d %d %d %d\n", &score, &k, &LIFE, &second, &minute, &numberOfBalls, &lifeTracer[0], &lifeTracer[1]);
    for(i=0; i<4; i++)
    {
        fscanf(f, "%d %d\n", &ghost[i].gx, &ghost[i].gy);
    }
    fscanf(f, "%d %d", &px1, &py1);
    fclose(f);
}

int main()
{
    int i, j, x;
    //if(pauseTracer=1)
    //PlaySound("Song 1.wav", NULL, SND_LOOP | SND_ASYNC);
    iSetTimer(500, door);
    iSetTimer(200, change);
    iSetTimer(1000, gameTime);
    iSetTimer(10000, bigBall);
    iSetTimer(ghostTimer, Blinky);
    iSetTimer(ghostTimer, Pinky);
    iSetTimer(ghostTimer, Clyde);
    iSetTimer(ghostTimer, Inky);
    setEnemyVar();
    ghostChange();
    loadGame();
    int ballCount=0;
    for(i=0;i<31;i++)
    {
        for(j=0;j<30;j++)
        {
            if(maze[i][j]==0)
                ballCount++;
        }
    }
    printf("%d\n", ballCount);

    iInitialize(screenHeight, screenWidth, "Pacman");
}

