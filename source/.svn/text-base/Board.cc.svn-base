#include "Board.h"
#include <cassert>
#include "Definitions.h"

Board::Board(int h, int w) : height{h}, width{w}
{

   for (int i = 0; i < height; i++)
   {
      vector<Piece*> temp;
      for (int y= 0; y < width; y++)
         temp.push_back(new EmptyPiece);
      gamePieces.push_back(temp);
   }
   history.clear();
   colorMove = 0;
}
Board::~Board()
{

   for (int i = 0; i < height; i++)
   {
     gamePieces[i].clear();
   }

}

Piece* Board::getPiece(int x, int y)
{
   return gamePieces[x][y];
}
void Board::setPiece(int x, int y, Piece* p)
{
delete gamePieces[x][y];
   gamePieces[x][y] = p;

}
void Board::setNull(int x, int y)
{
   gamePieces[x][y] = new EmptyPiece;
}
int Board::getHeight()
{
   return height;
}
void Board::setHeight(int newHeight)
{
   height = newHeight;
}


int Board::getWidth()
{
   return width;

}
void Board::setWidth(int newWidth)
{
   width = newWidth;

}
int Board::movePiece (int ix,int iy, int dx, int dy)
{
   Piece* Movepiece = getPiece(ix,iy);
   int ret = Movepiece->validMove(gamePieces,ix,iy,dx,dy);
   if (ret == 1 && ret )
      MoveHistory(ix,iy,dx,dy,true);
   if (ret == 5)
      MoveHistory(ix,iy,dx,dy,true);
   return ret;
}

void Board::MoveHistory(int cur1, int cur2, int des1, int des2, bool onOrOff)
{
   if (onOrOff)
   {
      string temp = "";
      temp += convertToChar(cur2);
      temp += cur1 + '0';
      temp += '-';
      temp += convertToChar(des2);
      temp += des1 + '0';
      temp += '-';
      temp += (gamePieces[des1][des2]->getType()).at(2);
      temp += (gamePieces[des1][des2]->getColor()) + '0';

      history.push_back(temp);
   }
   else if (history.size() > 0 && !onOrOff)
   {
         colorMove++;
         string temp = history[history.size() - 1];
         int x, y, x1, y1, Color;
         x = temp.at(1) - '0';
         y = convertToChar(temp.at(0)) - '0';
         x1 = temp.at(4) - '0';
         y1 = convertToChar(temp.at(3)) - '0';
         Color = temp.at(7) - '0';


         
         setPiece(x,y, gamePieces[x1][y1]);

         switch(temp.at(6)) 
         {
            case 'w': gamePieces[x1][y1] = new PawnPiece(Color); break;
            case 'n': gamePieces[x1][y1] = new KingPiece(Color); break;
            case 'e': gamePieces[x1][y1] = new QueenPiece(Color);  break;
            case 'o': gamePieces[x1][y1] = new RookPiece(Color); break;
            case 'i': gamePieces[x1][y1] = new KnightPiece(Color);  break;
            case 's': gamePieces[x1][y1] = new BishopPiece(Color);  break;
            case 'p': gamePieces[x1][y1] = new EmptyPiece(Color);  break;
         }
         
         history.pop_back();
         std::cerr << "";
   }
}

char Board::convertToChar(int con)
{
   switch(con)
   {
      case 0: return 'a';
      case 1: return 'b';
      case 2: return 'c';
      case 3: return 'd';
      case 4: return 'e';
      case 5: return 'f';
      case 6: return 'g';
      case 7: return 'h';

      case 'a': return '0';
      case 'b': return '1';
      case 'c': return '2';
      case 'd': return '3';
      case 'e': return '4';
      case 'f': return '5';
      case 'g': return '6';
      case 'h': return '7';
      default:
      return '0';
   }
}

vector<string> Board::getBoardHistory()
{
   std::cout << "board  " << history.size() << std::endl;
   return history;
}