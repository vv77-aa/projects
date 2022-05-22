#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>

			 //620,470 end points


int counter=0,ballx=0,bally=50,startx,boardx=0,boardstx;
int ball(int &ballx,int &bally,int &startx);
int board(int &boardx,int &boardstx);

void show(int &boardstx,int &ballx,int &bally,int &startx)
 {char lol1;
  cleardevice();

  setcolor(BLUE);
  setfillstyle(SOLID_FILL,BLUE);
  rectangle(boardstx+boardx,430,boardstx+100+boardx,450);
  floodfill(boardstx+2+boardx,440,BLUE);

  setcolor(RED);
  setfillstyle(SOLID_FILL,RED);
  circle(startx*50,bally,20);
  floodfill(startx*50,bally,RED);


  if((bally+50)>=430)
    {if(((ballx+20)>(boardstx+boardx))&&((ballx-20)<boardstx+boardx+100))
       {delay(1000);
	counter++;
	ballx=0;
	bally=50;
	boardx=0;
	boardstx=20;
	goto lol1;
       }
     else
      {delay(3000);
       exit(0);
      }

    }

  lol1:
  board(boardx,boardstx);
 }


int ball(int &ballx,int &bally,int &startx)
 {int balldir,c=0;

  randomize();
  lol1:

  startx=rand()%3+2; //coord for start pos


  ballx=rand()%2+1;

  balldir=rand()%2+1;

  if(balldir==2)
   {if(((startx*50)+(ballx*50))>600)
     {for(;((startx*50)+(ballx*50))>600;ballx--)
       {;}
     }
    startx+=ballx;
   }

  if(balldir==1)
   {if(((startx*50)-(ballx*50))<40)
     {for(;((startx*50)-(ballx*50))<40;ballx--)
      {;}

     }
    startx-=ballx;
   }
  bally+=50;
  show(boardstx,ballx,bally,startx);
  return 0;
 }

int board(int &boardx,int &boardstx)
 {char bdir;

  setcolor(BLUE);
  setfillstyle(SOLID_FILL,BLUE);
  rectangle(boardstx+boardx,430,boardstx+100+boardx,450);
  floodfill(boardstx+2+boardx,440,BLUE);
  gotoxy(1,1);
  cout<<"ENTER THE DIRECTION OF THE BOARD a=left,d=right ";
  bdir=getche();if(bdir==' ')exit(0);
  boardx=1;
  cleardevice();
  setcolor(RED);
  setfillstyle(SOLID_FILL,RED);
  circle(startx*50,bally,20);
  floodfill(startx*50,bally,RED);
  if(bdir=='a'||bdir=='A')
   {if((boardstx-(100*boardx))<20)
     {for(;boardstx-(100*boardx)<20;boardx--)
       {;}
     }

    boardstx-=(100*boardx);
    boardx=0;

   }
  if(bdir=='d'||bdir=='D')
   {if(boardstx+(100*boardx)>520)
     {for(;boardstx+(100*boardx)>520;boardx--)
      {;}
     }

    boardstx+=(100*boardx);
    boardx=0;

   }

  ball(ballx,bally,startx);

  return 0;
 }

int main()
  {int gm,gd=DETECT;boardstx=20;
   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   setcolor(RED);
   setfillstyle(SOLID_FILL,RED);
   circle(startx*50,bally,20);
   floodfill(startx*50,bally,RED);

   board(boardx,boardstx);

   getch();
   return 0;
  }