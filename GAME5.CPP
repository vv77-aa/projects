#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
#include<dos.h>
#include<graphics.h>
#include<stdlib.h>

int x=1,player=1;
			//row1 mat1 =210,50,230,150//add 75 to x for next 3
int mat[4][16];         //row2 mat1 =135,200,155,300//add 75
int x1[4];              //row3 mat1 =60,350,80,450//add 75

void matches();
void high();
void matsel(int &a);
void startscr();

void startscr()
 {char choice;
  int cood=0;
  /*for(int f=1;f<=800;f++)
   {cleardevice();
    line(160-200+f,30,140-200+f,60);
    line(160-200+f,90,140-200+f,60);
    circle(150-200+f,60,10);
    line(139-200+f,59,95-200+f,35);
    line(139-200+f,61,95-200+f,85);
    arc(139-200+f,60,150,210,51);
    line(90-200+f,38,80-200+f,37);
    line(89-200+f,42,79-200+f,41);
    line(90-200+f,78,80-200+f,79);
    line(89-200+f,74,79-200+f,75);
    delay(10);
   }*/
  for(int e=1;e<=7;e++)
   {cleardevice();
    settextstyle(3,HORIZ_DIR,e);
    setcolor(BLUE);
    outtextxy(e*10,e*10,"WELCOME!!!_V_");
    delay(300);
   }

  lel:

  cleardevice();
  outtextxy(70,70,"WELCOME!!!_V_");
  outtextxy(120,200,"NEW GAME");
  outtextxy(120,280,"INSTRUCTIONS");
  outtextxy(120,360,"QUIT ");

  rectangle(100,210+cood*80,639,270+cood*80);
  choice=getch();
  if(choice=='s')
   {if(cood!=2)
     {cood++;
      goto lel;
     }
   }
  if(choice=='w')
   {if(cood!=0)
     {cood--;
      goto lel;
     }
   }
  if(choice==13)
   {if(cood==0)
     {cleardevice();
      high();
     }
    if(cood==2)
     {cleardevice();
      outtextxy(70,70,"QUITTING IS ");
      outtextxy(70,170,"PROHABITTED");
      outtextxy(70,270,"SHUT UP & PLAY");
      getch();
      high();
     }
    if(cood==1)
     {cleardevice();
      outtextxy(70,70,"YOU AINT GETTIN");
      outtextxy(170,200,"ANYTHING!!");
      getch();
      high();
     }
   }

  getch();
  exit(0);


 }

void matches()
  {setcolor(RED);                                   //
   setfillstyle(SOLID_FILL,RED);                    //

   for(int a=1;a<=3;a++)
    {for(int b=1;b<=15;b++)
      {if(a==1&&b>3)
	break;
       if(a==2&&b>5)
	break;
       if(a==3&&b>7)
	break;
       if(mat[a][b]==1)
	{rectangle(210-(a-1)*75+75*(b-1),50+(a-1)*150,230-(a-1)*75+(b-1)*75,150+(a-1)*150);
	 floodfill(210-(a-1)*75+75*(b-1)+1,50+(a-1)*150+1,RED);
	}

      }						    //
    }					   //

  }

void high()
 {char row;
  int down=1;

  lol1:


  cleardevice();
  setcolor(GREEN);                                     //
  setfillstyle(SOLID_FILL,GREEN);                      //   row highlight
  rectangle(30,40+(down-1)*150,560,160+(down-1)*150);  //
  floodfill(70,100+(down-1)*150,GREEN);                //

  matches();

  gotoxy(1,1);
  cout<<"ENTER 's' OR 'w' TO GO UP OR DOWN THE ROW...";
  row=getch();

  if((row=='s'&&down==3)||row=='w'&&down==1)
   {goto lol1;
   }

  if(row=='s')
   {down++;
    goto lol1;
   }

  if(row=='w')
   {down--;
    goto lol1;
   }

  if(row==' ')
   {exit(0);
   }

  if(row==13)
   {matsel(down);
   }

  else
   goto lol1;

 }

void matsel(int &a)
 {int m=0;
  char sel;

  lol2:

  cleardevice();

  if(a==1)
   {lol4:
      setcolor(YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      rectangle(205+m*75,40,235+m*75,160);
      floodfill(215+m*75,100,YELLOW);


    matches();

    gotoxy(1,1);
    cout<<"USE 'a' & 'd'TO SELECT AND THEN PRESS ENTER TO REMOVE OR PRESS SPACE TO FINISH..";

    lol3:



    sel=getch();

    if((sel=='d'&&m==2)||(sel=='a'&&m==0))
     {goto lol2;
     }

    if(sel=='d')
     {m++;
      goto lol2;
     }

    if(sel=='a')
     {m--;
      goto lol2;
     }

    if(sel==32)
     {for(int j=1;j<=3;j++)
       {for(int k=1;k<=15;k++)
	 {if(j==1&&k>3)
	   break;
	  if(j==2&&k>5)
	   break;
	  if(j==3&&k>7)
	   break;
	  if(mat[j][k]==1)
	   goto wow1;

	 }
       }
       cleardevice();
       gotoxy(30,12);
       cout<<"PLAYER "<<((player+1)%2)+1<<"WINS!!!! CONGRATS";
       getch();
       exit(0);
      wow1:
      gotoxy(1,1);
      cout<<"NEXT PLAYER'S TURN...";
      player++;
      high();
     }

    if(sel==13)
     {if(mat[a][m+1]==0)
       {sound(200);
	delay(500);
	nosound();
	delay(500);
	sound(200);
	delay(500);
	nosound();
       }
      mat[a][m+1]=0;

      setcolor(BLACK);
      setfillstyle(SOLID_FILL,BLACK);
      floodfill(210+m*75,100,BLACK);

      goto lol4;
     }
    else
     goto lol2;
   }
  if(a==2)
   {lol8:

    setcolor(YELLOW);
    setfillstyle(SOLID_FILL,YELLOW);
    rectangle(130+m*75,190,160+m*75,310);
    floodfill(131+m*75,191,YELLOW);

    matches();

    gotoxy(1,1);
    cout<<"USE 'a' & 'd'TO SELECT AND THEN PRESS ENTER TO REMOVE OR PRESS SPACE TO FINISH..";

    lol7:



    sel=getch();

    if((sel=='d'&&m==4)||(sel=='a'&&m==0))
     {goto lol2;
     }

    if(sel=='d')
     {m++;
      goto lol2;
     }

    if(sel=='a')
     {m--;
      goto lol2;
     }

    if(sel==32)
     {for(int j=1;j<=3;j++)
       {for(int k=1;k<=15;k++)
	 {if(j==1&&k>3)
	   break;
	  if(j==2&&k>5)
	   break;
	  if(j==3&&k>7)
	   break;
	  if(mat[j][k]==1)
	   goto wow2;

	 }
       }
       cleardevice();
       gotoxy(30,12);
       cout<<"PLAYER "<<((player+1)%2)+1<<"WINS!!!! CONGRATS";
       getch();
       exit(0);
      wow2:
      gotoxy(1,1);
      cout<<"NEXT PLAYER'S TURN...";
      high();
     }

    if(sel==13)
     {if(mat[a][m+1]==0)
       {sound(200);
	delay(500);
	nosound();
	delay(500);
	sound(200);
	delay(500);
	nosound();
       }
      mat[a][m+1]=0;

      setcolor(BLACK);
      setfillstyle(SOLID_FILL,BLACK);
      floodfill(135+m*75,250,BLACK);

      goto lol8;
     }
   }
  else
   goto lol2;
   if(a==3)
   {lol9:

      setcolor(YELLOW);
      setfillstyle(SOLID_FILL,YELLOW);
      rectangle(55+m*75,340,85+m*75,460);
      floodfill(56+m*75,341,YELLOW);

    matches();

    gotoxy(1,1);
    cout<<"USE 'a' & 'd'TO SELECT AND THEN PRESS ENTER TO REMOVE OR PRESS SPACE TO FINISH..";

    lol10:



    sel=getch();

    if((sel=='d'&&m==6)||(sel=='a'&&m==0))
     {goto lol2;
     }

    if(sel=='d')
     {m++;
      goto lol2;
     }

    if(sel=='a')
     {m--;
      goto lol2;
     }

    if(sel==32)
     {for(int j=1;j<=3;j++)
       {for(int k=1;k<=15;k++)
	 {if(j==1&&k>3)
	   break;
	  if(j==2&&k>5)
	   break;
	  if(j==3&&k>7)
	   break;
	  if(mat[j][k]==1)
	   goto wow3;

	 }
       }
       cleardevice();
       gotoxy(30,12);
       cout<<"PLAYER "<<((player+1)%2)+1<<" WINS!!!! CONGRATS";
       getch();
       exit(0);
      wow3:
      gotoxy(1,1);
      cout<<"NEXT PLAYER'S TURN...";
      high();
     }

    if(sel==13)
     {if(mat[a][m+1]==0)
       {sound(200);
	delay(500);
	nosound();
	delay(500);
	sound(200);
	delay(500);
	nosound();
       }
      mat[a][m+1]=0;

      setcolor(BLACK);
      setfillstyle(SOLID_FILL,BLACK);
      floodfill(61+m*75,360,BLACK);

      goto lol9;
     }
    else
     goto lol2;
    }

 }

int main()
  {int gm,gd=DETECT;

   for(int a=1;a<=3;a++)
    {for(int b=1;b<=15;b++)
      {mat[a][b]=1;
      }
    }

   initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
   startscr();
   high();
   cleardevice();
   return 0;
  }