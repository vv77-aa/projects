#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>

//glob var
int ballx,bally,colo,col[]={1,2,4,5,6,8,9,10,12,13,14,15},sav[10],pos[10],ch;
int rc=0,rw=0;
char move,ans[10];

//1=blue
//2=green
//4=red
//5=magenta
//6=brown
//8=dark grey
//9=ltblue
//10=ltgreen
//12=skin
//13=pink
//14=yellow
//15=white


//func prots

int balls();
int show();

//func body

int show()
 {for(int a=0;a<=11;a++)
   {if(a==0)
     {setcolor(col[a]);
      outtextxy(a*50,25,"B");
     }
    if(a==1)
     {setcolor(col[a]);
      outtextxy(a*50,25,"G");
     }
    if(a==2)
     {setcolor(col[a]);
      outtextxy(a*50,25,"R");
     }
    if(a==3)
     {setcolor(col[a]);
      outtextxy(a*50,25,"M");
     }
    if(a==4)
     {setcolor(col[a]);
      outtextxy(a*50,25,"BR");
     }
    if(a==5)
     {setcolor(col[a]);
      outtextxy(a*50,25,"GY");
     }
    if(a==6)
     {setcolor(col[a]);
      outtextxy(a*50,25,"LB");
     }
    if(a==7)
     {setcolor(col[a]);
      outtextxy(a*50,25,"LG");
     }
    if(a==8)
     {setcolor(col[a]);
      outtextxy(a*50,25,"S");
     }
    if(a==9)
     {setcolor(col[a]);
      outtextxy(a*50,25,"P");
     }
    if(a==10)
     {setcolor(col[a]);
      outtextxy(a*50,25,"Y");
     }
    if(a==11)
     {setcolor(col[a]);
      outtextxy(a*50,25,"W");
     }
   }

  for(int i=1;i<=5;i++)
   {setcolor(15);
    ballx=pos[i];
    colo=sav[i];
    circle(100+pos[i]*100,80+80*(i-1),30);
    gotoxy(1,1);
    gets(ans);
    if(ans[0]=='b'||ans[0]=='B')    //m br gy lb lg s p y w
     {ch=1;
     }
    if(ans[0]=='g'||ans[0]=='G')
     {ch=2;
     }
    if(ans[0]=='r'||ans[0]=='R')
     {ch=4;
     }
    if(ans[0]=='m'||ans[0]=='M')
     {ch=5;
     }
    if((ans[0]=='b'||ans[0]=='B')&&(ans[1]=='r'||ans[1]=='R'))
     {ch=6;
     }
    if((ans[0]=='g'||ans[0]=='G')&&(ans[1]=='y'||ans[1]=='Y'))
     {ch=8;
     }
    if((ans[0]=='l'||ans[0]=='L')&&(ans[1]=='b'||ans[1]=='B'))
     {ch=9;
     }
    if((ans[0]=='l'||ans[0]=='L')&&(ans[1]=='g'||ans[1]=='G'))
     {ch=10;
     }
    if(ans[0]=='s'||ans[0]=='S')
     {ch=12;
     }
    if(ans[0]=='p'||ans[0]=='P')
     {ch=13;
     }
    if(ans[0]=='y'||ans[0]=='Y')
     {ch=14;
     }
    if(ans[0]=='w'||ans[0]=='W')
     {ch=15;
     }
    if(ch==col[colo])
     {setcolor(col[colo]);
      setfillstyle(SOLID_FILL,col[colo]);
      circle(100+ballx*100,80+(i-1)*80,30);
      floodfill(101+ballx*100,80+(i-1)*80,col[colo]);
      setcolor(GREEN);
      line(10,80+80*(i-1),30,80+80*(i-1));
      line(10,80+80*(i-1),30,110+80*(i-1));
      line(30,80+80*(i-1),40,95+80*(i-1));
      line(30,110+80*(i-1),50,110+80*(i-1));
      line(50,110+80*(i-1),90,50+80*(i-1));
      line(40,95+80*(i-1),70,50+80*(i-1));
      line(70,50+80*(i-1),90,50+80*(i-1));
      setfillstyle(SOLID_FILL,GREEN);
      setcolor(GREEN);
      floodfill(20,81+80*(i-1),GREEN);

     }
   if(ch!=col[colo])
    {setcolor(col[colo]);
     setfillstyle(SOLID_FILL,col[colo]);
     circle(100+ballx*100,80+(i-1)*80,30);
     floodfill(101+ballx*100,80+(i-1)*80,col[colo]);
     settextstyle(3,0,7);
     setcolor(RED);
     outtextxy(20,40+80*(i-1),"XxX");
    }
   }

 }

int balls()
 {cleardevice();

  gotoxy(1,1);
  cout<<"THE COLOR SCHEME IS :- ";
  for(int a=0;a<=11;a++)
   {if(a==0)
     {setcolor(col[a]);
      outtextxy(a*50,15,"B");
     }
    if(a==1)
     {setcolor(col[a]);
      outtextxy(a*50,15,"G");
     }
    if(a==2)
     {setcolor(col[a]);
      outtextxy(a*50,15,"R");
     }
    if(a==3)
     {setcolor(col[a]);
      outtextxy(a*50,15,"M");
     }
    if(a==4)
     {setcolor(col[a]);
      outtextxy(a*50,15,"BR");
     }
    if(a==5)
     {setcolor(col[a]);
      outtextxy(a*50,15,"GY");
     }
    if(a==6)
     {setcolor(col[a]);
      outtextxy(a*50,15,"LB");
     }
    if(a==7)
     {setcolor(col[a]);
      outtextxy(a*50,15,"LG");
     }
    if(a==8)
     {setcolor(col[a]);
      outtextxy(a*50,15,"S");
     }
    if(a==9)
     {setcolor(col[a]);
      outtextxy(a*50,15,"P");
     }
    if(a==10)
     {setcolor(col[a]);
      outtextxy(a*50,15,"Y");
     }
    if(a==11)
     {setcolor(col[a]);
      outtextxy(a*50,15,"W");
     }
   }

  for(int i=1;i<=5;i++)
   {colo=rand()%12;
    setfillstyle(SOLID_FILL,col[colo]);
    setcolor(col[colo]);
    ballx=rand()%5+1;
    pos[i]=ballx;
    sav[i]=colo;
    circle(100+ballx*100,80+(i-1)*80,30);
    floodfill(100+ballx*100,80+(i-1)*80,col[colo]);
   }
   delay(2000);
   cleardevice();
   show();
 }


int main()
  {randomize();
   int gm,gd=DETECT;
   initgraph(&gd,&gm,"c:\\turboc3\\bgi");
   balls();
   getch();
   closegraph();
   return 0;
  }