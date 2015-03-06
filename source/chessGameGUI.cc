	
#include "chessGameGUI.h"
#include "Menu/GenericMenu.h"
#include "Menu/EndMenu.h"
#include "Menu/PauseMenu.h"
#include "ChessBoard.h"
#include "Board.h"
#include <cassert>
#include <unistd.h>
#include "Definitions.h"
#include "Players/RegisteredPlayer.h"
#include <vector>
using std::vector;

#include <string>
using std::string;

#include <utility>
using std::pair;

GenericMenu* chessGameGUI::menufunc(string &opt, status* &info)
{
  if( info->isReplay() )//checks if the user picked replay
  {
    moves = info->getReplayVector(); // gets the history vector that will be used to replay
    Replayer(info); // calls replayer function to watch the game
  }
  if (!info->isLoad())// checks if load false which chooses weather to display end game or just continue to game
  {
    sleep(5);
    info->setLoad(true);
    return new EndMenu;

  }
	int c[2] = {0,0}, cur[2], des[2], selected[2];
  bool selectCheck = false;
  char choice;

  ChessBoard* map = info->getGame();
  while(true)
  {
    system("clear");
    Cprint("red", "bold");
    drawBoard(map, c, selected);
    cin >> choice;
    if (choice == 27)
    {
       info->setBoard(map);
      return new PauseMenu;
    }
    else if(choice == 'u')
    {
       map->undo();
    }
    else if(choice == 's' && c[0] != 7)
    {
       c[0]++;
       assert(c[0] < 8 && "PLAYER INCREMENTED BEYOND BOUNDS");
    }
    else if(choice == 'w' && c[0] != 0)
    {
       c[0]--;
        assert(c[0] >= 0 && "PLAYER DECREMENTED BEllOW BOUNDS");
    }
    else if(choice == 'a' && c[1] != 0)
    {
       c[1]--;
        assert(c[1] >= 0 && "PLAYER DECREMENTED BELLOW BOUNDS");
    }
    else if(choice == 'd' && c[1] != 7)
    {
       c[1]++;
        assert(c[1] < 8 && "PLAYER INCREMENTED BEYOND BOUNDS");
    }
    else if(choice == 'm')
    {
      if (selectCheck == false)
      {
        cur[0] = c[0];
        cur[1] = c[1];
        selected[0] = c[0];
        selected[1] = c[1];
        selectCheck = true;
      }
      else if(selectCheck == true)
      {
        des[0] = c[0];
        des[1] = c[1];
        selected[0] = -1;
        selected[1] = -1;
        selectCheck = false;

        Database data;
        RegisteredPlayer* p1 = info->getP1();
        RegisteredPlayer* p2 = info->getP2();
       switch (map->movePiece(cur[0],cur[1], des[0], des[1]))
       {
        case 0: break;// invalid move

        case 1: break; // valid move

        case 2: // stale mate
        system("clear");
        cerr << "Stale Mate!!!";
        sleep(1);
        return new EndMenu; 
        break;

        case 3: // kind is dead!

 

   


        info->setBoard(new ChessBoard);
         

        if(colorMove%2 == 0)
        {
        p1->incrementGamesWon();
        p2->incrementGamesLost();
        p1->setElo();
        p2->setElo();
        //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
        data.savePlayer(p1->generateMemento(), info->getP1Name());
          //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
        data.savePlayer(p2->generateMemento(), info->getP2Name());
    
        }
        else
        {
        p1->incrementGamesLost();  
        p2->incrementGamesWon();
        p1->setElo();
        p2->setElo();
        //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
        data.savePlayer(p1->generateMemento(), info->getP1Name());
          //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
        data.savePlayer(p2->generateMemento(), info->getP2Name());
    
        }
        return new EndMenu;
        break;

        case 5: // in check
        system("clear");
        cerr  << endl << "Your in check!";
        sleep(2);
        system("clear");
        break;

        default: break;
       }
      }
    }
  }
}

void chessGameGUI::Cprint(string color, string type)
{
  printf("\033[0m");
  if (color == "default") // clear
    printf("\033[0m");

  if (color == "red") // red 31
    printf("\033[00;31m");

  if (color == "green") // green 32
    printf("\033[00;32m");

  if (color == "blue") // blue 34
    printf("\033[00;34m");

  if (color == "magenta") // magenta 35
    printf("\033[00;35m");

  if (color == "cyan") // cyan 36
    printf("\033[00;36m");

  if (color == "grey") // grey 37
    printf("\033[00;37m");

  if (type == "bold") // bold 1
    printf("\033[1m");

  if (type == "slash") // slash 9
    printf("\033[9m");

  }
 // needs board to compile... 
  void chessGameGUI::drawBoard(ChessBoard* &Dmap, int cursor[], int select[])
  {
    int row = 0, col = 0;
    Cprint("green", "bold");
    string type;
    Cprint("green", "slash");
    cout<<endl<<"|                               |"<<endl;
    Cprint("green", "bold");
    Piece* piece;
    for(int  j = 0; j < 8; j++)
    {

      for (int i = 0; i < 33; i++)
      {


        if (0 == i % 2 && 0 != i % 4)
        { 
          piece = Dmap->getPiece(row, col);
	         
          if(piece->getColor() == 1)
          {
            Cprint("red", "bold");
          }
          else
          {
            Cprint("blue", "bold");
          }	      

          type = piece->getType();
          cerr << "";
	        switch(type.at(0)) //I Changed this from the the sequence of if else.
		      { //switch cannot use a string, so using the first character 
            case 'R':
              cout << 'R'; break;
            case 'K':          
		          if(type == "Knight")//If not a knight, it is a king
              {
                cout << 'N'; break;
              }
              else
                cout << 'K'; break;
            case 'B':
              cout << 'B'; break;
            case 'Q':
              cout << 'Q'; break;
            case 'P':       
              cout << 'P'; break;
            case 'E':
              cout << ' '; break;
            default: 
              assert(false && "INVALID PIECE ERROR: SWITCHED TO DEFAULT IN ChessGameGUI.cc");
            break;
          }

          Cprint("green", "bold");

          col++;  
          if(col == 8) 
          {
            col = 0;
            row++;
          }
        }
        else if( 0 != i % 2)// displays cursor and/or selected piece
        {
          if((cursor[1] == (i) / 4 && 0 != (i+1) % 4 && cursor[0] == j ))
          {
            Cprint("magenta", "bold");
            cout << '[';
            Cprint("green", "bold");    
          }
          else if((cursor[1] == (i-1) / 4 && 0 != (i-1) % 4 && cursor[0] == j ))
          {
            Cprint("magenta", "bold");
            cout << ']';
            Cprint("green", "bold");
          }
          else if((select[1] == (i) / 4 && 0 != (i+1) % 4 && select[0] == j ))
          {
            Cprint("cyan", "bold");
            cout << '[';
            Cprint("green", "bold");
          }
          else if((select[1] == (i-1) / 4 && 0 != (i-1) % 4 && select[0] == j ))
          {
            Cprint("cyan", "bold");
            cout << ']';
            Cprint("green", "bold");
          }
          else 
          {
            cout << ' ';
          }
        }
        
        else if (piece == nullptr)
        {
          cout << " ";
        }
        else
        {
          cout << '|';
          if(i==32) 
          {
            Cprint("green", "slash");
            cout<<endl<<"|                               |"<<endl;
            Cprint("green", "bold");
          }
        }
      }
    } 
    Cprint("green", "slash");
    cout<<endl        <<"|                               |" << endl <<"|";// displays whos turn it is...

    if(colorMove%2 == 1)
      Cprint("red", "slash");
    else
      Cprint("blue", "slash");

    cout               <<"|||||||||||||||||||||||||||||||";
    Cprint("green", "slash");
    cout<< "|" << endl<<"|                               |" << endl;
    Cprint("green", "bold");
  }

  void chessGameGUI::Replayer(status *info)
  {



    ChessBoard* map = new ChessBoard;
    int size= moves.size();
    int c[2] = {1,1}, current[2], destination[2], selected[2];


    //chesks if this replay is meant to load or replay the game.
    if(info->isLoad())
    {
      for(int x = 0; x < size; x++)
      {
        //converts string from memory to coordinate changes.
        current[1] = CoordinateReturn(moves[x].at(0))-1;
        current[0] = (moves[x].at(1) - '0') ;
        destination[1] = CoordinateReturn(moves[x].at(3)-1);
        destination[0] = (moves[x].at(4) - '0') ;
        //moves the pieces with the corrdinate loaded from file
        map->movePiece(current[0], current[1], destination[0], destination[1]);
      }
      // updates the board to the map that was just loaded into status.
      info->setBoard(map);
      // turns replay off.
      info->Replay();
    }

    if (!info->isLoad())
    {
    for(int x = 0; x < size; x++)
    {
      //converts string from memory to coordinate changes.
      current[1] = CoordinateReturn(moves[x].at(0))-1;
      current[0] = (moves[x].at(1) - '0') ;
      destination[1] = CoordinateReturn(moves[x].at(3)-1);
      destination[0] = (moves[x].at(4) - '0') ;
      bool checkEqual = false;
      //moves the cursor to the current location (visualy pleasing)
      while(!checkEqual)
      {
      system("clear");
      if (c[0] < current[0])
        c[0]++;
      else if (c[0] > current[0])
        c[0]--;
      else if (c[1] < current[1])
        c[1]++;
      else if (c[1] > current[1])
        c[1]--;
      else if (c[1] == current[1] && c[0] == current[0])
        checkEqual = true;
      drawBoard(map, c, selected);
      usleep(200000);
      }
      checkEqual = false;
      selected[0] = c[0];
      selected[1] = c[1];
      //moves the cursor to the destination location (visualy pleasing)
      while(!checkEqual)
      {
      system("clear");
      if (c[0] < destination[0])
        c[0]++;
      else if (c[0] > destination[0])
        c[0]--;
      else if (c[1] < destination[1])
        c[1]++;
      else if (c[1] > destination[1])
        c[1]--;
      else if (c[1] == destination[1] && c[0] == destination[0])
        checkEqual = true;
      drawBoard(map, c, selected);
      usleep(200000);
      }

      selected[0] = -1;
      selected[1] = -1;
      system("clear");
      //moves the piece!
    map->movePiece(current[0], current[1], destination[0], destination[1]);
    //draws the board.
    drawBoard(map, c, selected);
    }
      info->setBoard(new ChessBoard);
      info->Replay();
    }
}

  int chessGameGUI::CoordinateReturn(char co)
  {
    switch(co)
    {
      case 'a':
      return 1;
      case 'b':
      return 2;
      case 'c':
      return 3;
      case 'd':
      return 4;
      case 'e':
      return 5;
      case 'f':
      return 6;
      case 'g':
      return 7;
      case 'h':
      return 8;
      default:
      return 0;
    }
  }

