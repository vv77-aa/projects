#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<process.h>


void main()
{char move;
					randomize();

 int gd=DETECT,gm,ran2[4][4],c=1,d=1,no=1,en,ti=10000,lol=0,lev=1;

 initgraph(&gd,&gm,"C:\\TurboC3\\BGI");



 setbkcolor(BLACK);

 omg:

 if(lol>=1)
   {clrscr();
    ti-=2000;
    gotoxy(10,2);
    cout<<"THE GAME HAS BECOME A BIT FASTER \n";
   }
   no=1;
   c=1;
   d=1;

 cleardevice();

 setcolor(BLUE);

 rectangle(200,100,390,290);
 rectangle(210,110,260,160);
 rectangle(270,110,320,160);
 rectangle(330,110,380,160);
 rectangle(210,170,260,220);
 rectangle(270,170,320,220);
 rectangle(330,170,380,220);
 rectangle(210,230,260,280);
 rectangle(270,230,320,280);
 rectangle(330,230,380,280);


 for(int i=1;i<=3;i++)
   {for(int j=1;j<=3;j++)
       ran2[i][j]=random(9)+1;
   }

 for(i=30;i<=44;i+=7)
   {for(int j=9;j<=17;j+=4)
      {gotoxy(i,j);cout<<ran2[c][d];
       d++;
      }
    d=1;
    c++;
   }
 delay(ti);

 for(i=30;i<=44;i+=7)
   {for(int j=9;j<=17;j+=4)
      {gotoxy(i,j);cout<<" ";
      }                                   }

for(int j=1;j<=3;j++)
  {for(int i=1;i<=3;i++)
     {gotoxy(20,23);cout<<"ENTER THE No. PRESENT IN THE BOX "<<no<<endl;
      gotoxy(40,24);cin>>en;
      if(en==ran2[i][j])
	 {no++;gotoxy(30+7*(i-1),9+4*(j-1));cout<<en;
	  setcolor(GREEN);
	  rectangle(210+60*(i-1),110+60*(j-1),260+60*(i-1),160+60*(j-1));

	 }

      if(no==10)
	{gotoxy(20,25);
	 cout<<"CONGRATS!!! :D U WON THE GAME !!\n";
	 sound(200);delay(500);nosound();delay(500);
	 sound(300);delay(500);nosound();delay(500);
	 sound(400);delay(500);nosound();delay(500);
	 getch();
	 lol++;
	 getch();
	 goto omg;
	}
      if(en!=ran2[i][j])
	{setcolor(RED);
	 rectangle(210+60*(i-1),110+60*(j-1),260+60*(i-1),160+60*(j-1));
	 line(210+60*(i-1),110+60*(j-1),260+60*(i-1),160+60*(j-1));
	 line(260+60*(i-1),110+60*(j-1),210+60*(i-1),160+60*(j-1));
	 gotoxy(25,4);textcolor(RED+BLINK);
	 settextstyle(4,HORIZ_DIR,5);
	 setcolor(RED);
	 outtextxy(150,3,"Ga/|/|3 oV3R ");
	 setcolor(BLUE);
	 gotoxy(30+7*(i-1),9+4*(j-1));cout<<ran2[i][j];
	 gotoxy(10,5);
	 cout<<"SRY!! WRONG No. Y_Y TRY AGAIN LATER ";
	 sound(100);delay(500);nosound();delay(500);
	 sound(100);delay(500);nosound();delay(500);
	 sound(100);delay(500);nosound();delay(500);
	 getch();
	 exit(0);
	}
     }
  }
 getch();

 closegraph();

}