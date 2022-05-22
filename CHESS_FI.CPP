#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<graphics.h>

//global_variables
int a[8][8],p1_color=15,p2_color=BLACK,turn=1,check=0;
char move;

/*if check=1
     check on 1st player
  if check=2
     check on 2nd player
*/

/*pieces_code
  0=empty
  1=pawn_p1
  2=rook_p1
  3=horse_p1
  4=bishop_p1
  5=queen_p1
  6=king_p1
  11=pawn_p2
  12=rook_p2
  13=horse_p2
  14=bishop_p2
  15=queen_p2
  16=king_p2

  20=moveable position
*/

//func_prototypes
void reset();               //for initial reset of chess pieces
void board();               //creates the board
void ch_ck();               //checks for check
void put_pieces();          //puts the chess pieces on the board
void selection();           //selects the piece to be moved
void movement(int x,int y); //for moving the chess pieces

void pawn(int x,int y,int col);
void rook(int x,int y,int col);
void horse(int x,int y,int col);
void bishop(int x,int y,int col);
void king(int x,int y,int col);
void queen(int x,int y,int col);

void pawn_move(int x,int y);
void rook_move(int x,int y);
void horse_move(int x,int y);
void bishop_move(int x,int y);
void queen_move(int x,int y);
void king_move(int x,int y);
//func body

void reset()
 {for(int i=2;i<=5;i++)
   {for(int j=0;j<=7;j++)
    {a[i][j]=0;
    }
   }

   for(i=0;i<=7;i++)
   a[6][i]=1;
  a[7][0]=2;a[7][7]=2;
  a[7][1]=3;a[7][6]=3;
  a[7][2]=4;a[7][5]=4;
  a[7][3]=5;a[7][4]=6;

  for(i=0;i<=7;i++)
   a[1][i]=11;
  a[0][0]=12;a[0][7]=12;
  a[0][1]=13;a[0][6]=13;
  a[0][2]=14;a[0][5]=14;
  a[0][3]=15;a[0][4]=16;


 }

void board()
 {for(int i=0;i<=7;i++)
   {for(int j=0;j<=7;j++)
     {if((i+j)%2==0)
       {setcolor(DARKGRAY);
	rectangle(i*60+80,j*60,i*60+140,j*60+60);
	setfillstyle(SOLID_FILL,DARKGRAY);
	floodfill(i*60+81,j*60+1,DARKGRAY);
       }
      else
       {setcolor(BROWN);
	rectangle(i*60+80,j*60,i*60+140,j*60+60);
	setfillstyle(SOLID_FILL,BROWN);
	floodfill(i*60+81,j*60+1,BROWN);
       }
     }
   }
  ch_ck();
  put_pieces();
 }

void ch_ck()
 {check=0;
  if(turn%2!=0)
   {for(int k=0;k<=7;k++)
     {for(int l=0;l<=7;l++)
       {if(a[k][l]==11)
	  {if(a[k+1][l+1]==6&&l>=1)
	     check=1;
	   if(a[k+1][l-1]==6&&l<=7)
	     check=1;

	  }

	if(a[k][l]==12)
	  {for(int i=k-1;;i--)
	    {if(a[i][l]>0)
	       break;
	     if(i<=0)
	       break;
	    }
	   if(i>=0&&a[i][l]==6)
	     check=1;
	   for(i=k+1;;i++)
	    {if(a[i][l]>0)
	       break;
	     if(i>=7)
	       break;
	    }
	   if(i<=7&&a[i][l]==6)
	     check=1;
	   for(int j=l-1;;j--)
	    {if(a[k][j]>0)
	       break;
	     if(j<=0)
	       break;
	    }
	   if(j>=0&&a[k][j]==6)
	     check=1;

	   for(j=l+1;;j++)
	    {if(a[k][j]>0)
	       break;
	     if(j>=7)
	       break;
	    }
	   if(j<=7&&a[k][j]==6)
	     check=1;
	  }

	 if(a[k][l]==13)
	  {if((k>=2&&l>=1)&&(a[k-2][l-1]==6))
	     check=1;
	   if((k>=2&&l<=6)&&(a[k-2][l+1]==6))
	     check=1;
	   if((k>=1&&l>=2)&&(a[k-1][l-2]==6))
	     check=1;
	   if((k<=6&&l>=2)&&(a[k+1][l-2]==6))
	     check=1;
	   if((k<=5&&l>=1)&&(a[k+2][l-1]==6))
	     check=1;
	   if((k<=5&&l<=6)&&(a[k+2][l+1]==6))
	     check=1;
	   if((k<=6&&l<=5)&&(a[k+1][l+2]==6))
	     check=1;
	   if((k>=1&&l<=5)&&(a[k-1][l+2]==6))
	     check=1;
	  }

	 if(a[k][l]==14)
	  {for(int i=1;i<=7;i++)
	    {if(k-i<0||l-i<0)
	       break;
	     if(a[k-i][l-i]>=11&&a[k-i][l-i]<=16)
		break;
	     if(a[k-i][l-i]==6)
	       check=1;
	    }
    for(i=1;i<=7;i++)
     {if(k-i<0||l+i>7)
       break;
      if(a[k-i][l+i]>=11&&a[k-i][l+i]<=16)
       break;
      if(a[k-i][l+i]==6)
       check=1;
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l+i>7)
       break;
      if(a[k+i][l+i]>=11&&a[k+i][l+i]<=16)
       break;
      if(a[k+i][l+i]==6)
       check=1;
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l-i<0)
       break;
      if(a[k+i][l-i]>=11&&a[k+i][l-i]<=16)
       break;
      if(a[k+i][l-i]==6)
       check=1;
     }
	  }

    if(a[k][l]==15)
      {for(int i=k-1;;i--)
     {if(a[i][l]>0)
       break;
      if(i<=0)
       break;
     }
    if(i>=0&&a[i][l]==6)
     check=1;
    for(i=k+1;;i++)
     {if(a[i][l]>0)
       break;
      if(i>=7)
       break;
     }
    if(i<=7&&(a[i][l]==6))
     check=1;
    for(int j=l-1;;j--)
     {if(a[k][j]>0)
       break;

      if(j<=0)
       break;
     }
    if(j>=0&&(a[k][j]==6))
     check=1;

   for(j=l+1;;j++)
     {if(a[k][j]>0)
       break;
      if(j>=7)
       break;
     }
   if(j<=7&&(a[k][j]==6))
    check=1;

   for(i=1;i<=7;i++)
     {if(k-i<0||l-i<0)
       break;
      if(a[k-i][l-i]>=11&&a[k-i][l-i]<=16)
       break;
      if(a[k-i][l-i]==6)
       {check=1;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(k-i<0||l+i>7)
       break;
      if(a[k-i][l+i]>=11&&a[k-i][l+i]<=16)
       break;
      if(a[k-i][l+i]==6)
       {check=1;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l+i>7)
       break;
      if(a[k+i][l+i]>=11&&a[k+i][l+i]<=16)
       break;
      if(a[k+i][l+i]==6)
       {check=1;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l-i<0)
       break;
      if(a[k+i][l-i]>=11&&a[k+i][l-i]<=16)
       break;
      if(a[k+i][l-i]==6)
       {check=1;
	break;
       }
     }
      }
       }
     }}
   if(turn%2==0)
  {for(int k=0;k<=7;k++)
     {for(int l=0;l<=7;l++)
       {
if(a[k][l]==1)
	  {if((a[k+1][l+1]==16)&&l>=0)
	   check=2;
	   if((a[k+1][l-1]==16)&&l<=7)
	   check=2;

	  }

	if(a[k][l]==2)
	  {for(int i=k-1;;i--)
	    {if(a[i][l]>0)
	       break;
	     if(i<=0)
	       break;
	    }
	   if(i>=0&&a[i][l]==16)
	     check=2;
	   for(i=k+1;;i++)
	    {if(a[i][l]>0)
	       break;
	     if(i>=7)
	       break;
	    }
	   if(i<=7&&a[i][l]==16)
	     check=1;
	   for(int j=l-1;;j--)
	    {if(a[k][j]>0)
	       break;
	     if(j<=0)
	       break;
	    }
	   if(j>=0&&a[k][j]==16)
	     check=2;

	   for(j=l+1;;j++)
	    {if(a[k][j]>0)
	       break;
	     if(j>=7)
	       break;
	    }
	   if(j<=7&&a[k][j]==16)
	     check=2;
	  }

	 if(a[k][l]==3)
	  {if((k>=2&&l>=1)&&(a[k-2][l-1]==16))
	     check=2;
	   if((k>=2&&l<=6)&&(a[k-2][l+1]==16))
	     check=2;
	   if((k>=1&&l>=2)&&(a[k-1][l-2]==16))
	     check=2;
	   if((k<=6&&l>=2)&&(a[k+1][l-2]==16))
	     check=2;
	   if((k<=5&&l>=1)&&(a[k+2][l-1]==16))
	     check=2;
	   if((k<=5&&l<=6)&&(a[k+2][l+1]==16))
	     check=2;
	   if((k<=6&&l<=5)&&(a[k+1][l+2]==16))
	     check=2;
	   if((k>=1&&l<=5)&&(a[k-1][l+2]==16))
	     check=2;
	  }

	 if(a[k][l]==4)
	  {for(int i=1;i<=7;i++)
	    {if(k-i<0||l-i<0)
	       break;
	     if(a[k-i][l-i]>=1&&a[k-i][l-i]<=6)
		break;
	     if(a[k-i][l-i]==16)
	       check=2;
	    }
    for(i=1;i<=7;i++)
     {if(k-i<0||l+i>7)
       break;
      if(a[k-i][l+i]>=1&&a[k-i][l+i]<=6)
       break;
      if(a[k-i][l+i]==16)
       check=2;
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l+i>7)
       break;
      if(a[k+i][l+i]>=1&&a[k+i][l+i]<=6)
       break;
      if(a[k+i][l+i]==16)
       check=2;
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l-i<0)
       break;
      if(a[k+i][l-i]>=1&&a[k+i][l-i]<=6)
       break;
      if(a[k+i][l-i]==16)
       check=2;
     }
	  }

    if(a[k][l]==5)
   {for(int i=k-1;;i--)
     {if(a[i][l]>0)
       break;
      if(i<=0)
       break;
     }
    if(i>=0&&a[i][l]==16)
     check=2;
    for(i=k+1;;i++)
     {if(a[i][l]>0)
       break;
      if(i>=7)
       break;
     }
    if(i<=7&&(a[i][l]==16))
     check=2;
    for(int j=l-1;;j--)
     {if(a[k][j]>0)
       break;

      if(j<=0)
       break;
     }
    if(j>=0&&(a[k][j]==16))
     check=2;

   for(j=l+1;;j++)
     {if(a[k][j]>0)
       break;
      if(j>=7)
       break;
     }
   if(j<=7&&(a[k][j]==16))
    check=2;

   for(i=1;i<=7;i++)
     {if(k-i<0||l-i<0)
       break;
      if(a[k-i][l-i]>=1&&a[k-i][l-i]<=6)
       break;
      if(a[k-i][l-i]==16)
       {check=2;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(k-i<0||l+i>7)
       break;
      if(a[k-i][l+i]>=1&&a[k-i][l+i]<=6)
       break;
      if(a[k-i][l+i]==16)
       {check=2;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l+i>7)
       break;
      if(a[k+i][l+i]>=1&&a[k+i][l+i]<=6)
       break;
      if(a[k+i][l+i]==16)
       {check=2;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(k+i>7||l-i<0)
       break;
      if(a[k+i][l-i]>=1&&a[k+i][l-i]<=6)
       break;
      if(a[k+i][l-i]==16)
       {check=2;
	break;
       }
     }
      }
	      }}}
 }

void put_pieces()
 {for(int i=0;i<=7;i++)
   {for(int j=0;j<=7;j++)
     {if(a[i][j]==1)
       pawn(j*60+110,i*60+30,p1_color);
      if(a[i][j]==2)
       rook(j*60+110,i*60+30,p1_color);
      if(a[i][j]==3)
       horse(j*60+110,i*60+30,p1_color);
      if(a[i][j]==4)
       bishop(j*60+110,i*60+30,p1_color);
      if(a[i][j]==5)
       queen(j*60+110,i*60+30,p1_color);
      if(a[i][j]==6)
       king(j*60+110,i*60+30,p1_color);

      if(a[i][j]==11)
       pawn(j*60+110,i*60+30,p2_color);
      if(a[i][j]==12)
       rook(j*60+110,i*60+30,p2_color);
      if(a[i][j]==13)
       horse(j*60+110,i*60+30,p2_color);
      if(a[i][j]==14)
       bishop(j*60+110,i*60+30,p2_color);
      if(a[i][j]==15)
       queen(j*60+110,i*60+30,p2_color);
      if(a[i][j]==16)
       king(j*60+110,i*60+30,p2_color);
     }
   }
  selection();
 }

void selection()
 {int col,row;
  if(turn%2!=0)
   {for(int i=0;i<=7;i++)
     {for(int j=0;j<=7;j++)
       {if(a[i][j]==6)
	 {row=i;
	  col=j;
	 }
       }
     }
    lab1:
    setcolor(GREEN);
    rectangle(col*60+80,row*60,col*60+140,row*60+60);
    move=getch();

    if((move=='a'||move=='A')&&col>0)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      col--;
     }

    if((move=='d'||move=='D')&&col<7)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      col++;
     }

    if((move=='w'||move=='W')&&row>0)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      row--;
     }

    if((move=='s'||move=='S')&&row<7)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      row++;
     }
    if(move==' ')
     exit(0);

    if(move==13)
     {if(a[row][col]==1)
       pawn_move(col,row);
      if(a[row][col]==2)
       rook_move(col,row);
      if(a[row][col]==3)
       horse_move(col,row);
      if(a[row][col]==4)
       bishop_move(col,row);
      if(a[row][col]==5)
       queen_move(col,row);
      if(a[row][col]==6)
       king_move(col,row);
     }
    goto lab1;
   }
  else
   {for(int i=0;i<=7;i++)
     {for(int j=0;j<=7;j++)
       {if(a[i][j]==16)
	 {row=i;
	  col=j;
	 }
       }
     }
    lab3:
    setcolor(GREEN);
    rectangle(col*60+80,row*60,col*60+140,row*60+60);
    move=getch();

    if((move=='a'||move=='A')&&col>0)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      col--;
     }

    if((move=='d'||move=='D')&&col<7)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      col++;
     }

    if((move=='w'||move=='W')&&row>0)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      row--;
     }

    if((move=='s'||move=='S')&&row<7)
     {if((row+col)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      rectangle(col*60+80,row*60,col*60+140,row*60+60);
      row++;
     }
    if(move==' ')
     exit(0);

    if(move==13)
     {if(a[row][col]==11)
       pawn_move(col,row);
      if(a[row][col]==12)
       rook_move(col,row);
      if(a[row][col]==13)
       horse_move(col,row);
      if(a[row][col]==14)
       bishop_move(col,row);
      if(a[row][col]==15)
       queen_move(col,row);
      if(a[row][col]==16)
       king_move(col,row);
     }
    goto lab3;
   }
 }

void pawn_move(int x,int y)
 {if(turn%2!=0)
   {if(a[y-1][x]==0)
     {a[y-1][x]=20;
      if(y==6&&a[y-2][x]==0)
       {a[y-2][x]=20;
       }
     }
    if((a[y-1][x+1]>=11&&a[y-1][x+1]<=16)&&x<=7)
     a[y-1][x+1]+=20;
    if((a[y-1][x-1]>=11&&a[y-1][x-1]<=16)&&x>=0)
     a[y-1][x-1]+=20;
   }
  else
   {if(a[y+1][x]==0)
     {a[y+1][x]=20;
      if(y==1&&a[y+2][x]==0)
       {a[y+2][x]=20;
       }
     }
    if((a[y+1][x+1]>=1&&a[y+1][x+1]<=6)&&x>=0)
     a[y+1][x+1]+=20;
    if((a[y+1][x-1]>=1&&a[y+1][x-1]<=6)&&x<=7)
     a[y+1][x-1]+=20;
   }
  movement(x,y);
 }

void rook_move(int x,int y)
 {if(turn%2!=0)
   {for(int i=y-1;;i--)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i<=0)
       break;
     }
    if(i>=0&&(a[i][x]>=11&&a[i][x]<=16))
     a[i][x]+=20;
    for(i=y+1;;i++)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i>=7)
       break;
     }
    if(i<=7&&(a[i][x]>=11&&a[i][x]<=16))
     a[i][x]+=20;
    for(int j=x-1;;j--)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j<=0)
       break;
     }
    if(j>=0&&(a[y][j]>=11&&a[y][j]<=16))
     a[y][j]+=20;

   for(j=x+1;;j++)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j>=7)
       break;
     }
   if(j<=7&&(a[y][j]>=11&&a[y][j]<=16))
    a[y][j]+=20;
   }
  else
   {for(int i=y-1;;i--)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i<=0)
       break;
     }
    if(i>=0&&(a[i][x]>=1&&a[i][x]<=6))
     a[i][x]+=20;
    for(i=y+1;;i++)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i>=7)
       break;
     }
    if(i<=7&&(a[i][x]>=1&&a[i][x]<=6))
     a[i][x]+=20;
    for(int j=x-1;;j--)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j<=0)
       break;
     }
    if(j>=0&&(a[y][j]>=1&&a[y][j]<=6))
     a[y][j]+=20;

   for(j=x+1;;j++)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j>=7)
       break;
     }
   if(j<=7&&(a[y][j]>=1&&a[y][j]<=6))
    a[y][j]+=20;
   }

  movement(x,y);
 }

void horse_move(int x,int y)
 {if(turn%2!=0)
   {if((y>=2&&x>=1)&&(a[y-2][x-1]==0||(a[y-2][x-1]>=11&&a[y-2][x-1]<=16)))
     a[y-2][x-1]+=20;
    if((y>=2&&x<=6)&&(a[y-2][x+1]==0||(a[y-2][x+1]>=11&&a[y-2][x+1]<=16)))
     a[y-2][x+1]+=20;
    if((y>=1&&x>=2)&&(a[y-1][x-2]==0||(a[y-1][x-2]>=11&&a[y-1][x-2]<=16)))
     a[y-1][x-2]+=20;
    if((y<=6&&x>=2)&&(a[y+1][x-2]==0||(a[y+1][x-2]>=11&&a[y+1][x-2]<=16)))
     a[y+1][x-2]+=20;
    if((y<=5&&x>=1)&&(a[y+2][x-1]==0||(a[y+2][x-1]>=11&&a[y+2][x-1]<=16)))
     a[y+2][x-1]+=20;
    if((y<=5&&x<=6)&&(a[y+2][x+1]==0||(a[y+2][x+1]>=11&&a[y+2][x+1]<=16)))
     a[y+2][x+1]+=20;
    if((y<=6&&x<=5)&&(a[y+1][x+2]==0||(a[y+1][x+2]>=11&&a[y+1][x+2]<=16)))
     a[y+1][x+2]+=20;
    if((y>=1&&x<=5)&&(a[y-1][x+2]==0||(a[y-1][x+2]>=11&&a[y-1][x+2]<=16)))
     a[y-1][x+2]+=20;
   }
  else
   {if((y>=2&&x>=1)&&(a[y-2][x-1]==0||(a[y-2][x-1]>=1&&a[y-2][x-1]<=6)))
     a[y-2][x-1]+=20;
    if((y>=2&&x<=6)&&(a[y-2][x+1]==0||(a[y-2][x+1]>=1&&a[y-2][x+1]<=6)))
     a[y-2][x+1]+=20;
    if((y>=1&&x>=2)&&(a[y-1][x-2]==0||(a[y-1][x-2]>=1&&a[y-1][x-2]<=6)))
     a[y-1][x-2]+=20;
    if((y<=6&&x>=2)&&(a[y+1][x-2]==0||(a[y+1][x-2]>=1&&a[y+1][x-2]<=6)))
     a[y+1][x-2]+=20;
    if((y<=5&&x>=1)&&(a[y+2][x-1]==0||(a[y+2][x-1]>=1&&a[y+2][x-1]<=6)))
     a[y+2][x-1]+=20;
    if((y<=5&&x<=6)&&(a[y+2][x+1]==0||(a[y+2][x+1]>=1&&a[y+2][x+1]<=6)))
     a[y+2][x+1]+=20;
    if((y<=6&&x<=5)&&(a[y+1][x+2]==0||(a[y+1][x+2]>=1&&a[y+1][x+2]<=6)))
     a[y+1][x+2]+=20;
    if((y>=1&&x<=5)&&(a[y-1][x+2]==0||(a[y-1][x+2]>=1&&a[y-1][x+2]<=6)))
     a[y-1][x+2]+=20;
   }
  movement(x,y);
 }

void bishop_move(int x,int y)
 {if(turn%2!=0)
   {for(int i=1;i<=7;i++)
     {if(y-i<0||x-i<0)
       break;
      if(a[y-i][x-i]>=1&&a[y-i][x-i]<=6)
       break;
      if(a[y-i][x-i]==0)
       a[y-i][x-i]=20;
      if(a[y-i][x-i]>=11&&a[y-i][x-i]<=16)
       {a[y-i][x-i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y-i<0||x+i>7)
       break;
      if(a[y-i][x+i]>=1&&a[y-i][x+i]<=6)
       break;
      if(a[y-i][x+i]==0)
       a[y-i][x+i]=20;
      if(a[y-i][x+i]>=11&&a[y-i][x+i]<=16)
       {a[y-i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x+i>7)
       break;
      if(a[y+i][x+i]>=1&&a[y+i][x+i]<=6)
       break;
      if(a[y+i][x+i]==0)
       a[y+i][x+i]=20;
      if(a[y+i][x+i]>=11&&a[y+i][x+i]<=16)
       {a[y+i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x-i<0)
       break;
      if(a[y+i][x-i]>=1&&a[y+i][x-i]<=6)
       break;
      if(a[y+i][x-i]==0)
       a[y+i][x-i]=20;
      if(a[y+i][x-i]>=11&&a[y+i][x-i]<=16)
       {a[y+i][x-i]+=20;
	break;
       }
     }
   }
  else
   {for(int i=1;i<=7;i++)
     {if(y-i<0||x-i<0)
       break;
      if(a[y-i][x-i]>=11&&a[y-i][x-i]<=16)
       break;
      if(a[y-i][x-i]==0)
       a[y-i][x-i]=20;
      if(a[y-i][x-i]>=1&&a[y-i][x-i]<=6)
       {a[y-i][x-i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y-i<0||x+i>7)
       break;
      if(a[y-i][x+i]>=11&&a[y-i][x+i]<=16)
       break;
      if(a[y-i][x+i]==0)
       a[y-i][x+i]=20;
      if(a[y-i][x+i]>=1&&a[y-i][x+i]<=6)
       {a[y-i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x+i>7)
       break;
      if(a[y+i][x+i]>=11&&a[y+i][x+i]<=16)
       break;
      if(a[y+i][x+i]==0)
       a[y+i][x+i]=20;
      if(a[y+i][x+i]>=1&&a[y+i][x+i]<=6)
       {a[y+i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x-i<0)
       break;
      if(a[y+i][x-i]>=11&&a[y+i][x-i]<=16)
       break;
      if(a[y+i][x-i]==0)
       a[y+i][x-i]=20;
      if(a[y+i][x-i]>=1&&a[y+i][x-i]<=6)
       {a[y+i][x-i]+=20;
	break;
       }
     }
   }
  movement(x,y);
 }

void queen_move(int x,int y)
 {if(turn%2!=0)
   {for(int i=y-1;;i--)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i<=0)
       break;
     }
    if(i>=0&&(a[i][x]>=11&&a[i][x]<=16))
     a[i][x]+=20;
    for(i=y+1;;i++)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i>=7)
       break;
     }
    if(i<=7&&(a[i][x]>=11&&a[i][x]<=16))
     a[i][x]+=20;
    for(int j=x-1;;j--)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j<=0)
       break;
     }
    if(j>=0&&(a[y][j]>=11&&a[y][j]<=16))
     a[y][j]+=20;

   for(j=x+1;;j++)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j>=7)
       break;
     }
   if(j<=7&&(a[y][j]>=11&&a[y][j]<=16))
    a[y][j]+=20;

   for(i=1;i<=7;i++)
     {if(y-i<0||x-i<0)
       break;
      if(a[y-i][x-i]>=1&&a[y-i][x-i]<=6)
       break;
      if(a[y-i][x-i]==0)
       a[y-i][x-i]=20;
      if(a[y-i][x-i]>=11&&a[y-i][x-i]<=16)
       {a[y-i][x-i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y-i<0||x+i>7)
       break;
      if(a[y-i][x+i]>=1&&a[y-i][x+i]<=6)
       break;
      if(a[y-i][x+i]==0)
       a[y-i][x+i]=20;
      if(a[y-i][x+i]>=11&&a[y-i][x+i]<=16)
       {a[y-i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x+i>7)
       break;
      if(a[y+i][x+i]>=1&&a[y+i][x+i]<=6)
       break;
      if(a[y+i][x+i]==0)
       a[y+i][x+i]=20;
      if(a[y+i][x+i]>=11&&a[y+i][x+i]<=16)
       {a[y+i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x-i<0)
       break;
      if(a[y+i][x-i]>=1&&a[y+i][x-i]<=6)
       break;
      if(a[y+i][x-i]==0)
       a[y+i][x-i]=20;
      if(a[y+i][x-i]>=11&&a[y+i][x-i]<=16)
       {a[y+i][x-i]+=20;
	break;
       }
     }
   }
  else
   {for(int i=y-1;;i--)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i<=0)
       break;
     }
    if(i>=0&&(a[i][x]>=1&&a[i][x]<=6))
     a[i][x]+=20;
    for(i=y+1;;i++)
     {if(a[i][x]>0)
       break;
      a[i][x]=20;
      if(i>=7)
       break;
     }
    if(i<=7&&(a[i][x]>=1&&a[i][x]<=6))
     a[i][x]+=20;
    for(int j=x-1;;j--)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j<=0)
       break;
     }
    if(j>=0&&(a[y][j]>=1&&a[y][j]<=6))
     a[y][j]+=20;

   for(j=x+1;;j++)
     {if(a[y][j]>0)
       break;
      a[y][j]=20;
      if(j>=7)
       break;
     }
   if(j<=7&&(a[y][j]>=1&&a[y][j]<=6))
    a[y][j]+=20;

   for(i=1;i<=7;i++)
     {if(y-i<0||x-i<0)
       break;
      if(a[y-i][x-i]>=11&&a[y-i][x-i]<=16)
       break;
      if(a[y-i][x-i]==0)
       a[y-i][x-i]=20;
      if(a[y-i][x-i]>=1&&a[y-i][x-i]<=6)
       {a[y-i][x-i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y-i<0||x+i>7)
       break;
      if(a[y-i][x+i]>=11&&a[y-i][x+i]<=16)
       break;
      if(a[y-i][x+i]==0)
       a[y-i][x+i]=20;
      if(a[y-i][x+i]>=1&&a[y-i][x+i]<=6)
       {a[y-i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x+i>7)
       break;
      if(a[y+i][x+i]>=11&&a[y+i][x+i]<=16)
       break;
      if(a[y+i][x+i]==0)
       a[y+i][x+i]=20;
      if(a[y+i][x+i]>=1&&a[y+i][x+i]<=6)
       {a[y+i][x+i]+=20;
	break;
       }
     }
    for(i=1;i<=7;i++)
     {if(y+i>7||x-i<0)
       break;
      if(a[y+i][x-i]>=11&&a[y+i][x-i]<=16)
       break;
      if(a[y+i][x-i]==0)
       a[y+i][x-i]=20;
      if(a[y+i][x-i]>=1&&a[y+i][x-i]<=6)
       {a[y+i][x-i]+=20;
	break;
       }
     }
   }
  movement(x,y);
 }

void king_move(int x,int y)
 {if(turn%2!=0)
   {if((a[y-1][x-1]==0||(a[y-1][x-1]>=11&&a[y-1][x-1]<=16))&&(x>0&&y>0))
     a[y-1][x-1]+=20;
    if((a[y-1][x]==0||(a[y-1][x]>=11&&a[y-1][x]<=16))&&(y>0))
     a[y-1][x]+=20;
    if((a[y-1][x+1]==0||(a[y-1][x+1]>=11&&a[y-1][x+1]<=16))&&(x<7&&y>0))
     a[y-1][x+1]+=20;
    if((a[y][x+1]==0||(a[y][x+1]>=11&&a[y][x+1]<=16))&&(x<7))
     a[y][x+1]+=20;
    if((a[y+1][x+1]==0||(a[y+1][x+1]>=11&&a[y+1][x+1]<=16))&&(x<7&&y<7))
     a[y+1][x+1]+=20;
    if((a[y+1][x]==0||(a[y+1][x]>=11&&a[y+1][x]<=16))&&(y<7))
     a[y+1][x]+=20;
    if((a[y+1][x-1]==0||(a[y+1][x-1]>=11&&a[y+1][x-1]<=16))&&(x>0&&y<7))
     a[y+1][x-1]+=20;
    if((a[y][x-1]==0||(a[y][x-1]>=11&&a[y][x-1]<=16))&&(x>0))
     a[y][x-1]+=20;
   }
  else
   {if((a[y-1][x-1]==0||(a[y-1][x-1]>=1&&a[y-1][x-1]<=6))&&(x>0&&y>0))
     a[y-1][x-1]+=20;
    if((a[y-1][x]==0||(a[y-1][x]>=1&&a[y-1][x]<=6))&&(y>0))
     a[y-1][x]+=20;
    if((a[y-1][x+1]==0||(a[y-1][x+1]>=1&&a[y-1][x+1]<=6))&&(x<7&&y>0))
     a[y-1][x+1]+=20;
    if((a[y][x+1]==0||(a[y][x+1]>=1&&a[y][x+1]<=6))&&(x<7))
     a[y][x+1]+=20;
    if((a[y+1][x+1]==0||(a[y+1][x+1]>=1&&a[y+1][x+1]<=6))&&(x<7&&y<7))
     a[y+1][x+1]+=20;
    if((a[y+1][x]==0||(a[y+1][x]>=1&&a[y+1][x]<=6))&&(y<7))
     a[y+1][x]+=20;
    if((a[y+1][x-1]==0||(a[y+1][x-1]>=1&&a[y+1][x-1]<=6))&&(x>0&&y<7))
     a[y+1][x-1]+=20;
    if((a[y][x-1]==0||(a[y][x-1]>=1&&a[y][x-1]<=6))&&(x>0))
     a[y][x-1]+=20;
   }
  movement(x,y);
 }

void movement(int x,int y)
 {int x1=x,y1=y;
  lab2:
  setcolor(GREEN);
  rectangle(x*60+80,y*60,x*60+140,y*60+60);
  move=getch();

  if((move=='w'||move=='W')&&y>0)
     {if((x+y)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
     // if(a[x][y]>=20)
     //  setcolor(RED);
      rectangle(x*60+80,y*60,x*60+140,y*60+60);
      y--;
     }
  if((move=='s'||move=='S')&&y<7)
     {if((x+y)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      //if(a[x][y]>=20)
      // setcolor(RED);
      rectangle(x*60+80,y*60,x*60+140,y*60+60);
      y++;
     }
  if((move=='a'||move=='A')&&x>0)
     {if((x+y)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
     // if(a[x][y]>=20)
       //setcolor(RED);
      rectangle(x*60+80,y*60,x*60+140,y*60+60);
      x--;
     }
  if((move=='d'||move=='D')&&x<7)
     {if((x+y)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      //if(a[x][y]>=20)
      // setcolor(RED);
      rectangle(x*60+80,y*60,x*60+140,y*60+60);
      x++;
     }
  if(move==13)
   {if(a[y][x]<20)
     {for(int i=0;i<=7;i++)
       {for(int j=0;j<=7;j++)
	 {if(a[j][i]>=20)
	   a[j][i]-=20;
	 }
       }
      board();
     }
    if(a[y][x]==20)
     {a[y][x]=a[y1][x1];
      a[y1][x1]=0;
     }
    if(a[y][x]>20)
     {a[y][x]=a[y1][x1];
      a[y1][x1]=0;
      if((x+y)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      for(int i=0;i<60;i++)
       line(x*60+80,y*60+i,x*60+140,y*60+i);
     }
    for(int i=0;i<=7;i++)
     {for(int j=0;j<=7;j++)
       {if(a[j][i]==20)
	 a[j][i]=0;
	if(a[j][i]>20)
	 a[j][i]-=20;
       }
     }
    for(i=0;i<60;i++)
     {if((x1+y1)%2==0)
       setcolor(DARKGRAY);
      else
       setcolor(BROWN);
      line(x1*60+80,y1*60+i,x1*60+140,y1*60+i);
     }


    ch_ck();
    turn++;
    if(check==1&&turn%2==0)
      {a[y1][x1]=a[y][x];
       a[y][x]=0;
       turn--;
      }
    if(check==2&&turn%2!=0)
      {a[y1][x1]=a[y][x];
       a[y][x]=0;
       turn--;
      }

    board();
   }
  if(move==8)
   {for(int i=0;i<=7;i++)
      {for(int j=0;j<=7;j++)
	{if(a[j][i]==20)
	  a[j][i]=0;
	 if(a[j][i]>20)
	  a[j][i]-=20;
	}
      }
    board();
   }
  if(move==' ')
   exit(0);
  goto lab2;
 }

//chess piece functions

void pawn(int x,int y,int col)
{setcolor(col);
 circle(x,y-10,3);     //top
 arc(x,y-1,0,180,6); //top 2

 rectangle(x-7,y-1,x+7,y+2);              //top3
 line(x-5,y-2,x-5,y+14);      //left side
 line(x+5,y-2,x+5,y+14);                 //right side
 line(x-5,y+14,x-8,y+19);   // left bottom
 line(x+5,y+14,x+8,y+19);   //           right bottom
 line(x-8,y+19,x+8,y+19);    //  base
 line(x-5,y+14,x+5,y+14);   //ll to base

 setfillstyle(SOLID_FILL,col);
 floodfill(x-1,y-11,col);
 floodfill(x-1,y-2,col);
 floodfill(x-6,y,col);
 floodfill(x+6,y,col);
 floodfill(x-1,y,col);
 floodfill(x+2,y+6,col);
 floodfill(x+2,y+16,col);
}

void rook(int x,int y,int col)
{setcolor(col);
 rectangle(x-7,y-25,x-10,y-15 ); //top1
 rectangle(x-1,y-25,x+2,y-15);//top 2
 rectangle(x+7,y-25,x+10,y-15);  //top3
 rectangle(x-10,y-15,x+10,y-5);        //middle
 line(x-10,y-5,x-10,y+15);//side1
 line(x+10,y-5,x+10,y+15);//side2
 //arc(x,y+25,0,180,15);//bottom 1
 //rectangle(x-17,y+25,x+18,y+30);//bottom2
 line(x-10,y+15,x-15,y+25);//bottom line 1
 line(x+10,y+15,x+15,y+25);         //bottom line 2
 line(x-15,y+25,x+15,y+25);                  //bottom line 3
 setfillstyle(SOLID_FILL,col);
 floodfill(x-9,y-19,col);
 floodfill(x,y-19,col);
 floodfill(x+9,y-19,col);
 floodfill(x,y-10,col);
 floodfill(x,y+10,col);
}

void horse(int x,int y,int col)
{setcolor(col);
 rectangle(x-8,y-8,x+8,y+8)  ;  // body
 setfillstyle(SOLID_FILL,col);
 floodfill(x-7,y-7,col);
}

void bishop(int x,int y,int col)
{setcolor(col);
 circle(x,y-21,3);     //top
 ellipse(x,y-5,0,180,7,13);
 line (x-8,y-4,x-5,y-2);//bend left
 line(x+7,y-4,x+4,y-2);  // bend right
 ellipse(x,y,0,360,10,12);                      //middle  top
 line(x-6,y,x-6,y+19);      //left side
 line(x+6,y,x+6,y+19);                 //right side
 line(x-6,y+19,x-9,y+24);   // left bottom
 line(x+6,y+19,x+9,y+24);   //           right bottom
 line(x-9,y+24,x+9,y+24);    //  base
 line(x-6,y+19,x+6,y+19);   //ll to base

 setfillstyle(SOLID_FILL,col);
 floodfill(x,y-17,col);
 floodfill(x-1,y-21,col);
 floodfill(x-3,y-2,col);
 floodfill(x-7,y,col);
 floodfill(x+8,y,col);
 floodfill(x+2,y-3,col);
 floodfill(x-3,y,col);
 floodfill(x,y+6,col);
 floodfill(x,y+16,col);
 floodfill(x-5,y+21,col);
}


void king(int x,int y,int col)
{setcolor(col);
 line(x,y-25,x-2,y-20); // top right
 line(x,y-25,x+2,y-20);  // top left
 rectangle(x-2,y-20,x+2,y-10);   //vertical top
 rectangle(x-5,y-17,x+5,y-14);   //  horizontal top
 ellipse(x,y-9,0,360,8,2); //top base
 line (x-4,y-9,x-2,y-2) ;   //top base left
 line(x+4,y-9,x+2,y-2);      // top base right
 rectangle   (x-2,y-2,x+2,y+3); //middle top
 ellipse (x,y+4,0,360,8,2); //middle
 rectangle (x-4,y+3,x+4,y+20); // middle body
 line(x-4,y+20,x-8,y+25);  // base left
 line(x+4,y+20,x+8,y+25); // base right
 rectangle(x-10,y+25,x+10,y+28);   // base base

 setfillstyle(SOLID_FILL,col);
 floodfill(x,y-24,col);
 floodfill(x,y-15,col);
 floodfill(x-3,y-16,col);
 floodfill(x+3,y-16,col);
 floodfill(x,y-23,col);
 floodfill(x,y-12,col);
 floodfill(x,y-19,col);
 floodfill(x,y-9,col);
 floodfill(x-5,y-9,col);
 floodfill(x+5,y-9,col);
 floodfill(x,y-5,col);
 floodfill(x,y,col);
 floodfill(x,y+5,col);
 floodfill(x-5,y+4,col);
 floodfill(x+5,y+4,col);
 floodfill(x,y+15,col);
 floodfill(x,y+23,col);
 floodfill(x,y+27,col);
}

void queen(int x,int y,int col)
{setcolor(col);
 circle(x,y-20,4);    //top
 ellipse(x,y-15,0,360,10,2);               //top base
 arc(x-8,y-11,240,90,4) ;                   // left
 arc(x+7,y-11,90,240,4);                   // right
 ellipse(x,y-7,0,360,10,2);                // middle base
 line (x-5,y-6,x-5,y+14);                   // left side
 line(x+5,y-6,x+5,y+14);                      // right side
 line(x-5,y+14,x-9,y+17);                     //left base1
 line(x+5,y+14,x+9,y+17);                  // right base  1
 line(x-9,y+17,x+9,y+17);                  //base     1
 line(x-7,y+17,x-12,y+20);              //left base2
 line(x+7,y+17,x+12,y+20);            //right base 2
 line(x-12,y+20,x+12,y+20);              // base 2

 setfillstyle(SOLID_FILL,col);
 floodfill(x,y-20,col);
 floodfill(x,y-15,col);
 floodfill(x,y-10,col);
 floodfill(x,y-7,col);
 floodfill(x,y+4,col);
 floodfill(x,y+16,col);
 floodfill(x+5,y+18,col);
}

void main()
 {int gm,gd=DETECT;
  initgraph(&gd, &gm, "C:\\TurboC3f\\bgi");
  settextstyle(3,0,6);
  char choice;
  setcolor(RED);
  outtextxy(150,150,"1. CONTINUE");
  outtextxy(150,225,"2. PLAY");
  outtextxy(150,300,"3. QUIT");
  choice=getch();
  if(choice=='1')  
   {
    board();
   }
  if(choice=='2')
   {reset();
    board();
   }
  if(choice=='3')
   exit(0);

  reset();
  board();
  getch();
 }
