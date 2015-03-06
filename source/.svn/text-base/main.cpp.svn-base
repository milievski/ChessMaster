//******************************************************************************
/// \auth michael wilson, Brandon Robertson
/// \brief main program function
/// \date Nov 11, 2014
//******************************************************************************
#include <iostream>
#include <string>
using std::string;
#include <cstdlib>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
//#include "Game.h"
//#include "ChessBoard.h"
#include "Menu/GenericMenu.h"
#include "Menu/MainMenu.h"
#include "Menu/PauseMenu.h"
#include "Menu/EndMenu.h"
#include "Menu/LeaderBoard.h"
#include "Menu/TournamentMenu.h"
#include "Menu/LoginMenu.h"
#include "chessGameGUI.h"
#include "status.h"

int colorMine = 0;

using namespace std;

//void drawBoard(Board* Dmap, int cursor[], int select[]);
//void move(Board* Dmap, int a1, int a2, int b1, int b2);
//void startUpMsg();
//void helper();

int main()
{
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    status* info = new status();
    GenericMenu* menupointer = new MainMenu;
    GenericMenu* temp = NULL;
    string menu = "Main";
    printf("\033[00;32m");
    // map is the char array that makes up the chess board!
    // for testing purpose at the moment.

    while (menu != "exit")
    {
      temp = menupointer->menufunc(menu, info);
      delete menupointer;
      menupointer = temp;
      temp = NULL; 
    }
    delete info;  
    delete menupointer;
    return 0;
  }


//******************************************************************************
///drawBoard is the function designed to draw the board, calling it will draw a /// board
///param[in] dmap is the board to be drawn
///param[in] cursor is the current position of the cursor?
///param[in] select is what piece was selected by the player using the cursor
//******************************************************************************
/* this is new
void drawBoard(Board* Dmap, int cursor[], int select[])
{
int row = 0, col = 0;
printf("\033[00;32m");
printf("\033[09;32m");
cout<<endl<<"|                               |"<<endl;
printf("\033[00;32m");
Piece* piece;
for(int  j = 0; j < 8; j++)
{
    for (int i = 0; i < 33; i++)
    {
      piece = Dmap->getPiece(row, col);

        if (0 == i % 2 && 0 != i % 4)
        {
          if(piece->getColor() == 1)
            printf("\033[00;31m");
          else
            printf("\033[00;34m");


          switch(piece->getType())
          {
            case "Rook":
              cout << 'R';
            break;
            case "Knight":
              cout << 'N';
            break;
            case "Bishop":
              cout << 'B';
            break;
            case "Queen":
              cout << 'Q';
            break;  
            case "King":
              cout << 'K';
            break;       
            case "Pawn":
              cout << 'P';
            break; 
            default:
              cout << ' ';
            break;                                                               
          }
          printf("\033[00;32m");
            row++;
        }
        else if( 0 != i % 2)
        {
            if((cursor[1] == (i) / 4 && 0 != (i+1) % 4 && cursor[0] == j ))
            {
                printf("\033[22;35m");
                cout << '[';
                printf("\033[00;32m");
            }
            else if((cursor[1] == (i-1) / 4 && 0 != (i-1) % 4 && cursor[0] == j ))
            {
                printf("\033[22;35m");
                cout << ']';
                printf("\033[00;32m");
            }
            else if((select[0] == (i) / 4 && 0 != (i+1) % 4 && select[0] == j ))
            {
                printf("\033[1;36m");
                cout << '[';
                printf("\033[00;32m");
            }
            else if((select[1] == (i-1) / 4 && 0 != (i-1) % 4 && select[0] == j ))
            {
                printf("\033[1;36m");
                cout << ']';
                printf("\033[00;32m");
            }
        }
        else 
        {
            cout << '|';
            if(i==32) 
            {
                printf("\033[09;32m");
                cout<<endl<<"|                               |"<<endl;
                printf("\033[00;32m");
            }
        }
    }
} 
}
*/














/*
//******************************************************************************
// need information on how and where the selection menu works, cant implement
// game unless known.
//******************************************************************************

   //startUpMsg();
    struct termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~ICANON;
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
    printf("\033[00;32m");
    // map is the char array that makes up the chess board!
    // for testing purpose at the moment.
    Board* map = new ChessBoard;
    int cx = 0, cy=0;
    bool gameloop = false;
    bool menuloop = true;
    bool pauseflag = false;
    bool selectCheck = false;
    int cur1, des1;
    int cur2, des2;
    int sel1, sel2;
    char x;
    GenericMenu* menupointer= new MainMenu;
    while (menuloop == true || gameloop == true) //if both are false, then exit
    {
        if (menuloop == true)
       menupointer->menufunc(menuloop,gameloop);
       while(gameloop == true)// enter a game
       {
    system("clear");
    drawBoard(map, cx, cy, sel1, sel2);
    helper();
    cin >> x;
    if(x == 27) //pause menu
    {
       menupointer = new PauseMenu;
         menuloop= true;
       break;      
    }
    if(x == 's' && cx != 7)
    {
       cx++;
    }
    else if(x == 'w' && cx != 0)
    {
       cx--;
    }
    else if(x == 'a' && cy != 0)
    {
       cy--;
    }
      else if(x == 'd' && cy != 7)
      {
         cy++;
      }
      else if(x == 'e')
      {
        
         menupointer = new EndMenu;
         menuloop = true;
         break;
      }
      else if(x == 't')
      {
        
         menupointer = new TournamentMenu;
         menuloop = true;
         break;
      }
    else if(x == 'l')
      {
         menupointer = new LeaderBoard;
         menuloop = true;
         break;
      }
    else if(x == 'm')
    {
       if (selectCheck == false)
       {
            if(map[cx][cy] != 0)
            {
              cur1 = cx;
              cur2 = cy;
              sel1 = cx;
              sel2 = cy;
              selectCheck = true;
            }
       }
       else
       {
                des1 = cx;
                des2 = cy;
                sel1 = -1;
                sel2 = -1;
                selectCheck = false;
                move(map,cur1,cur2, des1, des2);
       }
    }
        }
       
    
    }
    return 0;
}





void drawBoard(int Dmap[][8], int x, int y, int sx, int sy)
{
int row = 0, col = 0;
printf("\033[00;32m");
printf("\033[09;32m");
cout<<endl<<"|                               |"<<endl;
printf("\033[00;32m");
for(int  j = 0; j < 8; j++)
{
    for (int i = 0; i < 33; i++)
    {
        if (0 == i % 2 && 0 != i % 4)
        {
          if(Dmap[col][row] < 7)
            {
                printf("\033[00;31m");
                    switch(Dmap[col][row])
                    {
                        case 1:
                            cout << 'R';
                        break;
                        case 2:
                            cout << 'N';
                        break;
                        case 3:
                            cout << 'B';
                        break;
                        case 4:
                            cout << 'Q';
                        break;  
                        case 5:
                            cout << 'K';
                        break;       
                        case 6:
                            cout << 'P';
                        break; 
                        default:
                        break;                                                               
                    }
                printf("\033[00;32m");
            }
            else if(Dmap[col][row] > 6)
            {
                printf("\033[00;34m");
                    switch(Dmap[col][row])
                    {
                       case 8:
                            cout << 'R';
                        break;
                        case 9:
                            cout << 'N';
                        break;
                        case 10:
                            cout << 'B';
                        break;
                        case 11:
                            cout << 'Q';
                        break;  
                        case 12:
                            cout << 'K';
                        break;       
                        case 7:
                            cout << 'P';
                        break; 
                        default:
                        break;     
                    }
                printf("\033[00;32m");
            }
            else if(Dmap[x][y] == 0)
            {
                printf("\033[22;35m");
                cout << 'X';
                printf("\033[00;32m");
            }
            else if(Dmap[col][row] == 0)
            {
              cout << " ";
            }
            row++;
        }
        else if( 0 != i % 2)
        {
            if((y == (i) / 4 && 0 != (i+1) % 4 && x == j ))
            {
                printf("\033[22;35m");
                cout << '[';
                printf("\033[00;32m");
            }
            else if((y == (i-1) / 4 && 0 != (i-1) % 4 && x == j ))
            {
                printf("\033[22;35m");
                cout << ']';
                printf("\033[00;32m");
            }
            else if((sy == (i) / 4 && 0 != (i+1) % 4 && sx == j ))
            {
                printf("\033[1;36m");
                cout << '[';
                printf("\033[00;32m");
            }
            else if((sy == (i-1) / 4 && 0 != (i-1) % 4 && sx == j ))
            {
                printf("\033[1;36m");
                cout << ']';
                printf("\033[00;32m");
            }
            else
            {
                cout << ' ';
            }
        }
        else 
        {
            cout << '|';
            if(i==32) 
            {
                printf("\033[09;32m");
                cout<<endl<<"|                               |"<<endl;
                printf("\033[00;32m");
            }
        }
    }
}
}

void move(int Dmap[][8], int a1, int a2, int b1, int b2)
{
    int temp;
    //if (true) // test if is valid move
    {
        Dmap[b1][b2] = Dmap[a1][a2];
        Dmap[a1][a2] = 0;
    }
    
}

void startUpMsg()
{
   printf("\033[01;31m");
   cout<<"Welcome to Checkmates Wonderfully Fantastic Chess Game Project"<<endl
       <<"To give you a some ease of learning,"
       <<"this message is displayed to"
       <<"help you familiarize with the controls,"<<endl
       <<"please also ensure you have caps lock disabled"<<endl;


   cout<<"While in any of the menu's, you may use the";
   printf("\033[01;34m");cout<<" 'w'";
   printf("\033[01;31m");cout<<" and";
   printf("\033[01;34m");cout<<" 's'";
   printf("\033[01;31m");cout<<" keys to"<<endl
           <<"respectively change what menu item is selected, when you are"<<endl
           <<"happy with what you have selected, pressing";
   printf("\033[01;34m");cout<<" 'm'";
   printf("\033[01;31m");cout<<" will work for"<<endl
           <<"an enter key"<<endl;
   printf("\033[01;32m");
   cout<<"While playing in the the game, you will find a purple cursor"<<endl
       <<"simply move the cursor using";
   printf("\033[01;34m");cout<< " WASD ";
   printf("\033[01;32m");cout<<"and make a selection using ";
   printf("\033[01;34m");cout<< "'m'"<<endl;
   printf("\033[01;32m");cout<<"set the cursor to a destination and press";
   printf("\033[01;34m");cout<<" 'm'";
   printf("\033[01;32m");;cout<<" again to move a piece"<<endl
           <<"You may press";
   printf("\033[01;34m");" 'p'";
   printf("\033[01;31m");
   cout<<" at anytime in a game to go to the pause menu"<<endl<<endl;

   cout<<"PRESS ";
   printf("\033[01;34m");cout<<"'m'";
   printf("\033[01;31m");cout<<" TO CONTINUE";
   while(1)
   {
   char x;
   cin>>x;
   if(x == 'm')
   {
      return;
   }
   }
}
          
void helper()
{
  cout << endl;
  printf("\033[01;32m");
  cout << "  -up = w" << endl
       << "  -down = s" << endl
       << "  -left = a" << endl
       << "  -right = d" << endl
       << "  -Pause Menu = esc" << endl
       << "  -LeaderBoard = l" << endl
       << "  -End Menu = e" << endl
       << "  -Tournament = t" << endl;
       printf("\033[00;32m");
}
*/
