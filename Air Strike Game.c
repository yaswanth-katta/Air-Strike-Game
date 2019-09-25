#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <process.h>

int x1=35;
int level=2;
int key;
char name[100];
int score=0;
void loading();
void Delay();
void Score(int );
void Instructions();
void Cursor_change(int x, int y);
void Edges();
void ExitGame();
void Enemies();
void GunMoving();
void Bullets(int ,int );

int main()
{
    printf("\n\t\tEnter your name: ");
    gets(name);
    printf("\n\tpress any key to continue\n");
    getch();
    system("cls");

	Instructions();

	system("cls");

	loading();

	system("cls");

	Edges();

	Enemies(11,2);
	Cursor_change(13,50);

	GunMoving();

	return 0;
}
// Instruction for the game
void Instructions()
{
  Cursor_change(13,10);
  printf("Welcome to AIR STRIKE game\n\n\t(Press any key to continue)\n\n");
  getch();
  system("cls");
  printf("\tRules are:\n\n");
  printf("1.Use arrow keys(left,right) to move the Gun\n");
  printf("\n2.We provide the enemies in top of the boarder, you can kill them.\n");
  printf("3.If level increased then score will update \n");
  printf("\n4.If you kill the enemies then increase your game level and Score as well \n");
  printf("\n5.You have only one life..\n\n\t\tAll the Best\n\n");
  printf("\n\tPress any key to continue\n");
  getch();
}

void loading()
{
    int i,j;
    system("cls");
    Cursor_change(20,10);
    printf("Loading...");

    Cursor_change(15,11);
    for(i=0;i<=20;i++)
    {
       for(j=0;j<=100000000;j++);
       printf("%c",177);
    }
    printf("\t\n\n\t..Press any key to Continue..\n");
    getch();

}

void Edges()
{
   system("cls");
   int i;
   for(i=10;i<71;i++)
   {
      Cursor_change(i,10);
      printf("-");
      Cursor_change(i,30);
      printf("_");
   }
   for(i=10;i<31;i++)
   {
      Cursor_change(10,i);
      printf("|");
      Cursor_change(70,i);
      printf("|");
   }
   Cursor_change(20,8);
   printf("SCORE : 0");

   Cursor_change(55,8);
   printf("LEVEL : 1");

   Cursor_change(13,32);
   printf("If you want to exit press 'esc' button");
}

void Score(int score)
{
   Cursor_change(28,8);
   printf(" %d",score);  //print the score

   Cursor_change(63,8);
   printf("%d",level-1);

}

void Cursor_change(int x,int y)
{
     COORD coord;
 coord.X = x;
 coord.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Enemies(int x,int level)
{
    int i,j;
    for(i=0;i<level;i++){   //this loop is represent enemies of the line(level)
            x++;            // x is represent the line
             //Cursor_change(11,x);
            for(j=11;j<70;j+=2){
                    if(x%2==0)  //if even level is comes then in between enemies can maintain the gap
                        j=j+2;
                Cursor_change(j,x);
                printf("%c",127);
            }
    }

}

void GunMoving()
{
       // static int x=35,y=29;
       int count=0,count1=0;
        Cursor_change(x1,29);
        printf("%c",6);
        Bullets(x1,28);

        while(1)              //infinite loop
        {
            if(kbhit())               //check for a key is pressed
            {
                key=getch();
                if(key==77)      //move right
                {
                    Cursor_change(x1,29);
                    printf(" ");         //To clear the previous gun(Symbol)

                    if(x1!=69)
                       x1++;

                     Cursor_change(x1,29);
                     printf("%c",6);
                     Bullets(x1,28);

                     if(x1==69)  //if right edge touches the gun then count become '1'
                        count=1;
                }

                if(key==75)          //move left
                {
                    Cursor_change(x1,29);
                    printf(" ");

                    if(x1!=11)
                        x1--;

                    Cursor_change(x1,29);
                    printf("%c",6);
                    Bullets(x1,28);

                    if(x1==11)  // if left edge touches the gun then then count1 becomes '1'
                        count1=1;
                }
                if(count==1&&count1==1){  //if counts become '1' the re call the enemies function
                    score=score+10;
                    Score(score);
                    level++;
                    Enemies(11,level); score++;
                    count=0;count1=0;
                    if(level==10)
                        level=2;
                }

                if(key==27){     //exit when esc pressed
                    ExitGame();
                    Cursor_change(10,32);
                     exit(0);
                }
            }
    }
}

void Bullets(int spaces,int line)
{
    Cursor_change(spaces,line);
    printf("*");
    Delay();

    while(line!=11)       // '11' is the starting of the edge line
    {
        Cursor_change(spaces,line);
        printf(" ");

       line--;
       Cursor_change(spaces,line);
       printf("*");
       Delay();

       if(line==11)
       {
            Cursor_change(spaces,line);
            printf(" ");
       }
    }

}

void Delay()
{
  double i;
  for(i=0;i<=1000000;i++);
}

void ExitGame()
{
   system("cls");
    printf("\n\t%s your score is: %d",name,score);
    printf("\n\n\tPress any key to continue\n\n");
}

