#include<iostream.h>
#include<time.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>

/*
FOR OBJECTS
-1 = RESET OBJECT
 0 = EMPTY
 1 = TRIANGLE
 2 = SQUARE
 3 = CIRCLE
FOR OBJECT COLOR
 1 = GREEN (collect)
 2 = RED   (dodge)
 3 = BLUE  (optional)
*/

/*
GLOBAL VARIABLES
*/
int t=5;//for time b/w lanes(check delay in generate_lanes();)
int l=0;//for moving stripes
int x1=320,y1=400;//coordinates of car1
int x2=475,y2=400;//coordinates of car2
char move1;//for car1 movement

//VARIABLES FOR OBJECTS OF ROAD1
int obj1[5];//objects for road 1...object[type]
int obj1_x[5];//generated objects lane
int obj1_y[5];//for moving objects
int obj1_color[5];//object color(RED OR GREEN)

//VARIABLES FOR OBJECTS OF ROAD2
int obj2[5];//objects for road 2...object[type]
int obj2_x[5];//generated objects lane
int obj2_y[5];//for moving objects
int obj2_color[5];//object color(RED OR GREEN)


int obj1_separation=1000;
int obj2_separation=1000;
int obj1_speed=3;
int obj2_speed=3;

//VARIABLES FOR COLOR OF CAR1
int col_pri1=BLUE;//primary color of car
int col_sec1=DARKGRAY;//color of windows
int col_hl1=RED;//color of lights

//VARIABLES FOR COLOR OF CAR2
int col_pri2=GREEN;//primary color of car
int col_sec2=DARKGRAY;//color of windows
int col_hl2=YELLOW;//color of lights


/*
FUNCTION PROTOTYPES
*/

void car1(int x,int y,int col1,int col2,int col3);
void clear(int x);

void game_over()
 {cleardevice();
  closegraph();
  gotoxy(35,12);
  cout<<"GAME-OVER";
  getch();
  exit(0);
 }

void destroy_object(int i)
 {if(obj1[i]==1)
   {setcolor(BLACK);
    line(obj1_x[i],obj1_y[i]-30-obj1_speed,
	 obj1_x[i]-30,obj1_y[i]+30-obj1_speed);
    line(obj1_x[i]-30,obj1_y[i]+30-obj1_speed,
	 obj1_x[i]+30,obj1_y[i]+30-obj1_speed);
    line(obj1_x[i]+30,obj1_y[i]+30-obj1_speed,
	 obj1_x[i],obj1_y[i]-30-obj1_speed);
   }
  if(obj1[i]==2)
   {setcolor(BLACK);
    rectangle(obj1_x[i]-30,obj1_y[i]-30-obj1_speed,
	      obj1_x[i]+30,obj1_y[i]+30-obj1_speed);

   }
  if(obj1[i]==3)
   {setcolor(BLACK);
    circle(obj1_x[i],obj1_y[i]-obj1_speed,30);
   }

 if(obj2[i]==1)
   {setcolor(BLACK);
    line(obj2_x[i],obj2_y[i]-30-obj2_speed,
	 obj2_x[i]-30,obj2_y[i]+30-obj2_speed);
    line(obj2_x[i]-30,obj2_y[i]+30-obj2_speed,
	 obj2_x[i]+30,obj2_y[i]+30-obj2_speed);
    line(obj2_x[i]+30,obj2_y[i]+30-obj2_speed,
	 obj2_x[i],obj2_y[i]-30-obj2_speed);
   }
  if(obj2[i]==2)
   {setcolor(BLACK);
    rectangle(obj2_x[i]-30,obj2_y[i]-30-obj2_speed,
	      obj2_x[i]+30,obj2_y[i]+30-obj2_speed);

   }
  if(obj2[i]==3)
   {setcolor(BLACK);
    circle(obj2_x[i],obj2_y[i]-obj2_speed,30);
   }
 }

void check_collision1()
 {for(int i=1;i<=5;i++)
   {if((obj1_y[i]+30>=y1-54)&&(obj1_y[i]-30<=y1+39)&&(obj1_x[i]==x1))
     {if(obj1_color[i]==1||obj1_color[i]==3)
	{clear(x1);
	 obj1[i]=-1;
	 car1(x1,y1,col_pri1,col_sec1,col_hl1);
	}
      else
       {game_over();
       }
     }
    if(obj1_y[i]>=510)
     {if(obj1_color[i]==3||obj1_color[i]==2)
       obj1[i]=-1;
      else
       game_over();
     }
   }
 }

void generate_obj1()
 {for(int i=1;i<=5;i++)
   {if(obj1_color[i]==1)    //
     setcolor(GREEN);       //
    if(obj1_color[i]==2)    //      FOR SETTING COLOR
     setcolor(RED);         //
    if(obj1_color[i]==3)    //
     setcolor(BLUE);        //

    if(obj1[i]==1)     //triangle
     {line(obj1_x[i],obj1_y[i]-30,obj1_x[i]-30,obj1_y[i]+30);
      line(obj1_x[i]-30,obj1_y[i]+30,obj1_x[i]+30,obj1_y[i]+30);
      line(obj1_x[i]+30,obj1_y[i]+30,obj1_x[i],obj1_y[i]-30);

      destroy_object(i);
     }

    if(obj1[i]==2)
     {destroy_object(i);

      if(obj1_color[i]==1)    //
       setcolor(GREEN);     //
      if(obj1_color[i]==2)    //      FOR SETTING COLOR
       setcolor(RED);       //
      if(obj1_color[i]==3)    //
       setcolor(BLUE);      //

      rectangle(obj1_x[i]-30,obj1_y[i]-30,
		obj1_x[i]+30,obj1_y[i]+30);
     }

    if(obj1[i]==3)
     {destroy_object(i);

      if(obj1_color[i]==1)    //
       setcolor(GREEN);     //
      if(obj1_color[i]==2)    //      FOR SETTING COLOR
       setcolor(RED);       //
      if(obj1_color[i]==3)    //
       setcolor(BLUE);      //
      circle(obj1_x[i],obj1_y[i],30);
     }
   }
 }

void generate_obj2()
 {for(int i=1;i<=5;i++)
   {if(obj2_color[i]==1)    //
     setcolor(GREEN);       //
    if(obj2_color[i]==2)    //      FOR SETTING COLOR
     setcolor(RED);         //
    if(obj2_color[i]==3)    //
     setcolor(BLUE);        //

    if(obj2[i]==1)     //triangle
     {line(obj2_x[i],obj2_y[i]-30,obj2_x[i]-30,obj2_y[i]+30);
      line(obj2_x[i]-30,obj2_y[i]+30,obj2_x[i]+30,obj2_y[i]+30);
      line(obj2_x[i]+30,obj2_y[i]+30,obj2_x[i],obj2_y[i]-30);

      destroy_object(i);
     }

    if(obj2[i]==2)
     {destroy_object(i);

      if(obj2_color[i]==1)    //
       setcolor(GREEN);     //
      if(obj2_color[i]==2)    //      FOR SETTING COLOR
       setcolor(RED);       //
      if(obj2_color[i]==3)    //
       setcolor(BLUE);      //

      rectangle(obj2_x[i]-30,obj2_y[i]-30,
		obj2_x[i]+30,obj2_y[i]+30);
     }

    if(obj2[i]==3)
     {destroy_object(i);

      if(obj2_color[i]==1)    //
       setcolor(GREEN);     //
      if(obj2_color[i]==2)    //      FOR SETTING COLOR
       setcolor(RED);       //
      if(obj2_color[i]==3)    //
       setcolor(BLUE);      //
      circle(obj2_x[i],obj2_y[i],30);
     }
   }
 }


void random_obj1()
 {//randomize();
  for(int i=1;i<=5;i++)
   {if(obj1[i]==-1)
     {obj1[i]=random(3)+1;
      obj1_x[i]=180+(140*random(3));
      obj1_color[i]=random(3)+1;
      if(i==1)
       {obj1_y[i]=obj1_y[5]-obj1_separation;
       }
      else
       obj1_y[i]=obj1_y[i-1]-obj1_separation;
     }

   }
  generate_obj1();
 }

void random_obj2()
 {randomize();
  for(int i=1;i<=5;i++)
   {if(obj2[i]==-1)
     {obj2[i]=obj1[i];
      obj2_x[i]=310+(obj1_x[i]);
      obj2_color[i]=obj1_color[i];
      obj2_y[i]=obj1_y[i]-250;
     }
   }
  generate_obj2();
 }

void generate_lanes()
 {for(int i=1;i<3;i++)       //for lanes
   {for(int j=-2;j<=8;j++)   //for stripes
     {if(j%2==0)
       setcolor(BLACK);
      if(j%2!=0)
       setcolor(WHITE);
      line(110+i*140,j*60+l,110+i*140,(j+1)*60+l);
     }
   }

  /*for(i=1;i<3;i++)           //for lanes
   {for(int j=-2;j<=8;j++)   //for stripes
     {if(j%2==0)
       setcolor(BLACK);
      if(j%2!=0)
       setcolor(WHITE);
      line(340+i*90,j*60+l,340+i*90,(j+1)*60+l);
     }
   }   */

  l+=obj1_speed;         //for moving stripes forward
  delay(t);
  if(l>=120)             //reset lane
   l=0;

 }

void generate_trees()
 {for(int j=0;j<=5;j++)
   {setcolor(BROWN);
    for(int i=0;i<=80;i++)
     ellipse(55,0+i+j*170,250,290,30,40);
    setcolor(GREEN);
    for(i=0;i<=40;i++)
     ellipse(55,0+j*170,0,360,30,i);
    line(25,0+j*170,85,0+j*170);
   }
 }

void clear(int x)
 {setcolor(BLACK);
  for(int i=-35;i<=161;i++)
   {line(x-40,319+i,x+40,319+i);
   }
 }

void car1(int x,int y,int col1,int col2,int col3)
 {
  setcolor(col1);
  rectangle(x-12,y-12,x+12,y+12);
  setfillstyle(SOLID_FILL,col1);
  floodfill(x-11,y-11,col1);

  setcolor(col2);
  line(x-12,y-12,x-15,y-21);
  line(x+12,y-12,x+15,y-21);
  line(x+12,y+12,x+15,y+21);
  line(x-12,y+12,x-15,y+21);

  ellipse(x,y-21,0,180,15,9);
  ellipse(x,y+21,180,0,15,6);
  rectangle(x-12,y-12,x+12,y+12);
  setfillstyle(SOLID_FILL,col2);
  floodfill(x,y-20,col2);
  floodfill(x,y+20,col2);
  line(x-15,y-21,x-15,y+21);
  line(x+15,y-21,x+15,y+21);

  floodfill(x-13,y,col2);
  floodfill(x+13,y,col2);

  setcolor(col1);

  line(x-12,y-12,x-15,y-21);
  line(x+12,y-12,x+15,y-21);
  line(x+12,y+12,x+15,y+21);
  line(x-12,y+12,x-15,y+21);

  line(x-15,y-21,x-15,y+21);
  line(x+15,y-21,x+15,y+21);

  ellipse(x,y-21,0,180,15,9);
  ellipse(x,y+21,180,0,15,6);
  rectangle(x-12,y-12,x+12,y+12);

  ellipse(x,y-42,0,180,21,12);
  ellipse(x,y-42,0,180,21,9);

  line(x-21,y-42,x-21,y+33);
  line(x+21,y-42,x+21,y+33);

  ellipse(x,y+33,180,0,21,6);
  setfillstyle(SOLID_FILL,col1);
  floodfill(x,y-42,col1);

  setcolor(col3);
  ellipse(x,y-42,0,180,21,12);
  ellipse(x,y-42,0,180,21,9);
  setfillstyle(SOLID_FILL,col3);
  floodfill(x,y-53,col3);

  ellipse(x,y+33,200,250,21,6);
  ellipse(x,y+33,290,340,21,6);

  setcolor(col1);
  setfillstyle(SOLID_FILL,col1);
  ellipse(x,y-42,0,180,9,12);
  floodfill(x,y-53,col1);
  ellipse(x,y-42,0,180,21,12);
  ellipse(x,y-42,0,180,21,9);

  setcolor(BLACK);

  line(x-12,y-12,x-15,y-21);
  line(x+12,y-12,x+15,y-21);
  line(x+12,y+12,x+15,y+21);
  line(x-12,y+12,x-15,y+21);

  line(x-15,y-21,x-15,y+21);
  line(x+15,y-21,x+15,y+21);

  ellipse(x,y-21,0,180,15,9);
  ellipse(x,y+21,180,0,15,6);

 }

/////////////////////////////////////////////////////////
void main()
 {randomize();
  int gm,gd=DETECT;
  initgraph(&gd, &gm, "C:\\TurboC3\\bgi");

//  line(320,0,320,480);  //road separation

  /////////////////////////////////////
  ////////////////ROAD 1///////////////
  /////////////////////////////////////

  generate_trees();

  for(int i=1;i<=5;i++)   //
   {obj1[i]=-1;     //  initial reset of objects
  //  obj2[i]=-1;
   }

  /*obj1_y[1]=-1500;obj1_y[2]=-2000;obj1_y[3]=-2500;
  obj1_y[4]=-3000;obj1_y[5]=-3500;
  obj2_y[1]=-1500;obj2_y[2]=-2000;obj2_y[3]=-2500;
  obj2_y[4]=-3000;obj2_y[5]=-3500;
    */
  lab1:

  car1(x1,y1,col_pri1,col_sec1,col_hl1); //generates car at given coords
 // car1(x2,y2,col_pri2,col_sec2,col_hl2);
  random_obj1();
//  random_obj2();

  while(!kbhit())
   {
    generate_lanes();
    for(i=1;i<=5;i++)
     {obj1_y[i]+=obj1_speed;
     // obj2_y[i]+=obj2_speed;
     }
    generate_obj1();
   // generate_obj2();
    random_obj1();
   // random_obj1();
    check_collision1();
   }
  move1=getch();
  if((move1=='a'||move1=='A')&&x1>180)    //for moving left
   {clear(x1);  //removes car from previous location
    x1-=140;     //changes x co-ordinate
   }
  if((move1=='d'||move1=='D')&&x1<460)   //for moving right
   {clear(x1);  //removes car from previous location
    x1+=140;     //changes x co-ordinate
   }
  if((move1=='j'||move1=='J')&&x2>385)    //for moving left
   {clear(x2);  //removes car from previous location
    x2-=90;     //changes x co-ordinate
   }
  if((move1=='l'||move1=='L')&&x2<565)   //for moving right
   {clear(x2);  //removes car from previous location
    x2+=90;     //changes x co-ordinate
   }
  if(move1==' '||move1==32)
   {cleardevice();
    closegraph();             //escape sequence
    exit(0);
   }
  goto lab1;
  getch();
  cleardevice();
  closegraph();
 }