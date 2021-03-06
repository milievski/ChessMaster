#include "ChessBoardQT.h"
#include "../Definitions.h"

ChessBoardQT::ChessBoardQT(ChessBoard *oldGame, QWidget *parent) : QDialog(parent)
{

  if(oldGame == 0)
    CBoard = new ChessBoard();
  else
    CBoard = oldGame;
   //QPalette Pal(palette());
   //Pal.setColor(QPalette::Background, Qt::black);
  this-> setStyleSheet("background-color:#2C1913");



   //sets up clocks
  initTime = true;
  Timer_c = new QTClock(false, 1000, this);
  connect(Timer_c, SIGNAL(tick(const int &)), this, SLOT(getTime(const int &)));
  timeBlack_l = "";
  timeBlack_l = "";


  timeBlacks = 0;
  timeWhites = 0;

  timeBlackm = 30;
  timeWhitem = 30;


   //this->setAutoFillBackground(true);
   //this->setPalette(Pal);
  picked = false;
  pickedx = -2;
  pickedy = -2;
  QRect rec = QApplication::desktop()->screenGeometry();
  screenHeight = rec.height();
  screenWidth = rec.width();

  const int size = 128;
  BoardSize = (screenHeight-100)/8;
  selecterBox = QImage("QTMenu/Art/selecterBox.png");
  selecterBox = selecterBox.scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
  SpriteSheet = new QImage("QTMenu/Art/newSpriteSheetjpg.png");

	for(int x = 0; x < 6;x ++) // filling the pice sprites up with images
	{
		BlackSprites.push_back(QImage());
		WhiteSprites.push_back(QImage());
	}
	//king
	BlackSprites[0] = SpriteSheet->copy(4*size,0*size ,size ,size );
  BlackSprites[0] = BlackSprites[0].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);  
  WhiteSprites[0] = SpriteSheet->copy(1*size,0*size ,size ,size );
  WhiteSprites[0] = WhiteSprites[0].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);  
	//Queen
  BlackSprites[1] = SpriteSheet->copy(4*size,1*size ,size ,size );
  BlackSprites[1] = BlackSprites[1].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);  
  WhiteSprites[1] = SpriteSheet->copy(1*size,1*size ,size ,size );
  WhiteSprites[1] = WhiteSprites[1].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio); 
	//Bishop
  BlackSprites[2] = SpriteSheet->copy(5*size,1*size ,size ,size );
  BlackSprites[2] = BlackSprites[2].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
  WhiteSprites[2] = SpriteSheet->copy(2*size,1*size ,size ,size );
  WhiteSprites[2] = WhiteSprites[2].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
	//Knight
  BlackSprites[3] = SpriteSheet->copy(3*size,1*size ,size ,size );
  BlackSprites[3] = BlackSprites[3].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
  WhiteSprites[3] = SpriteSheet->copy(0*size,1*size ,size ,size );
  WhiteSprites[3] = WhiteSprites[3].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
	//Rook
  BlackSprites[4] = SpriteSheet->copy(3*size,0*size ,size ,size );
  BlackSprites[4] = BlackSprites[4].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
  WhiteSprites[4] = SpriteSheet->copy(0*size,0*size ,size ,size );
  WhiteSprites[4] = WhiteSprites[4].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
	//Pawn
  BlackSprites[5] = SpriteSheet->copy(5*size,0*size ,size ,size );
  BlackSprites[5] = BlackSprites[5].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);
  WhiteSprites[5] = SpriteSheet->copy(2*size,0*size ,size ,size );
  WhiteSprites[5] = WhiteSprites[5].scaled((screenHeight-100)/8, (screenHeight-100)/8, Qt::KeepAspectRatio);

  BoardPosX = 50;
  BoardPosY = 50;


  DeadBoardBlackXIndex = 0;
  DeadBoardWhiteXIndex = 0;
  DeadBoardBlackYIndex = 50;
  DeadBoardWhiteYIndex = 300;
  DeadBoardStartX = 860;
  //setting up boarder box for deadboard and timers...
  whiteDeadBoard = new QImage("QTMenu/Art/BoarderBox.png");
  BlackDeadBoard = new QImage("QTMenu/Art/BoarderBox.png");
  TimeBackground = new QImage("QTMenu/Art/timeBackground.png");
  whiteTimer =  new QImage("QTMenu/Art/BoarderBox.png");
  blackTimer = new QImage("QTMenu/Art/BoarderBox.png");
  blacksTurn_i = new QImage("QTMenu/Art/blackPlayersTurn.png");
  whitesTurn_i = new QImage("QTMenu/Art/whitePlayersTurn.png");
  turnIndicator_i = new QImage("QTMenu/Art/playersTurnSelector.png");
  chatBox_i = new QImage("QTMenu/Art/textBoxBox.png");
  this-> setStyleSheet("background-color:#2d1606");

}
void ChessBoardQT::keyPressEvent(QKeyEvent *e) {
  if(e->key() == Qt::Key_Escape)
  {

    int temp = 1;
    this->setFocus();
    emit newWindowFunction(temp);
    update();
    ////std::cout << "ECS\n"; 

  }
}

void ChessBoardQT::paintEvent(QPaintEvent *PE)
{
 QPainter paint(this); 
 QImage BoardImage("QTMenu/Art/chessBoard.jpg");
 QFont font("League Gothic",28, true );
 font.setBold(true);
 paint.setFont(font);
 BoardImage = BoardImage.scaled(screenHeight-100, screenHeight-100, Qt::KeepAspectRatio);
 paint.drawImage(BoardPosX,BoardPosY, BoardImage);
   paint.drawImage(865,230, *TimeBackground); //placement of the time background
   paint.drawImage(1470,50, *blacksTurn_i);
   paint.drawImage(1470,300, *whitesTurn_i);
   paint.drawImage(865,490, *chatBox_i);

   if(colorMove%2 == 0)
    paint.drawImage(1470,300, *turnIndicator_i);
  else
    paint.drawImage(1470,50, *turnIndicator_i);


  if(picked)
  {
    paint.drawImage(50+(pickedx * BoardSize) - BoardSize, 50+(pickedy * BoardSize)-BoardSize, selecterBox);
  }


  int tempCheck = 0, colour;
  Piece *tempPiece;
  string type;
  for(int y =0; y < 8; y++)
  {
    for(int x = 0; x < 8; x++)
    {

     tempPiece = CBoard->getPiece(x,y);
     type = tempPiece->getType();
     colour = tempPiece->getColor();
     if(x != pickedy-1 || y != pickedx-1)
   		if(colour == 1)//black
   		{
   			
   			if (type == "Queen")
   				paint.drawImage(BoardPosX + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[0]);
   			if (type == "King")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[1]);
   			if (type == "Bishop")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[2]);
   			if (type == "Knight")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[3]);
   			if (type == "Rook")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[4]);
   			if (type == "Pawn")
   				paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), BlackSprites[5]);

   		}
   		else // white
   		{
        if (type == "Queen")
          paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[0]);
        if (type == "King")
          paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[1]);
        if (type == "Bishop")
          paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[2]);
        if (type == "Knight")
          paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[3]);
        if (type == "Rook")
          paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[4]);
        if (type == "Pawn")
          paint.drawImage(BoardPosY + (y * BoardSize), BoardPosX + (x*BoardSize), WhiteSprites[5]);
      }


      if(picked)
      {
         if(pickedColor == 1)//black
         {

          if (pickedType == "Queen")
           paint.drawImage(pickedDrawy, pickedDrawx, BlackSprites[0]);
         if (pickedType == "King")
           paint.drawImage(pickedDrawy, pickedDrawx, BlackSprites[1]);
         if (pickedType == "Bishop")
           paint.drawImage(pickedDrawy, pickedDrawx, BlackSprites[2]);
         if (pickedType == "Knight")
           paint.drawImage(pickedDrawy, pickedDrawx, BlackSprites[3]);
         if (pickedType == "Rook")
           paint.drawImage(pickedDrawy, pickedDrawx, BlackSprites[4]);
         if (pickedType == "Pawn")
           paint.drawImage(pickedDrawy, pickedDrawx, BlackSprites[5]);

       }
         else // white
         {
          if (pickedType == "Queen")
            paint.drawImage(pickedDrawy, pickedDrawx, WhiteSprites[0]);
          if (pickedType == "King")
            paint.drawImage(pickedDrawy, pickedDrawx, WhiteSprites[1]);
          if (pickedType == "Bishop")
            paint.drawImage(pickedDrawy, pickedDrawx, WhiteSprites[2]);
          if (pickedType == "Knight")
            paint.drawImage(pickedDrawy, pickedDrawx, WhiteSprites[3]);
          if (pickedType == "Rook")
            paint.drawImage(pickedDrawy, pickedDrawx, WhiteSprites[4]);
          if (pickedType == "Pawn")
            paint.drawImage(pickedDrawy, pickedDrawx, WhiteSprites[5]);
        }
      }


    }

  }
  std::vector< Piece* >  DeadBoard = CBoard->getDeadBoard();

  paint.drawImage(DeadBoardStartX+  DeadBoardBlackXIndex+5, DeadBoardBlackYIndex , *BlackDeadBoard);
  paint.drawImage(DeadBoardStartX+ DeadBoardWhiteXIndex+5, DeadBoardWhiteYIndex, *whiteDeadBoard);

  for(int i = 0; i < DeadBoard.size(); i++){
   type = DeadBoard[i]->getType();

   colour = DeadBoard[i]->getColor();
      if(colour == 1)//black
      {

       if (type == "Queen")
        paint.drawImage(DeadBoardStartX+  DeadBoardBlackXIndex, DeadBoardBlackYIndex , BlackSprites[0]);
      if (type == "King")
        paint.drawImage(DeadBoardStartX+  DeadBoardBlackXIndex, DeadBoardBlackYIndex , BlackSprites[1]);
      if (type == "Bishop")
        paint.drawImage(DeadBoardStartX+  DeadBoardBlackXIndex, DeadBoardBlackYIndex , BlackSprites[2]);
      if (type == "Knight")
        paint.drawImage(DeadBoardStartX+  DeadBoardBlackXIndex, DeadBoardBlackYIndex , BlackSprites[3]);
      if (type == "Rook")
        paint.drawImage(DeadBoardStartX+  DeadBoardBlackXIndex, DeadBoardBlackYIndex , BlackSprites[4]);
      if (type == "Pawn")
        paint.drawImage(DeadBoardStartX+  DeadBoardBlackXIndex, DeadBoardBlackYIndex , BlackSprites[5]);
      DeadBoardBlackXIndex += (BoardSize-30);
      if (DeadBoardBlackXIndex/(BoardSize-30) == 8){
        DeadBoardBlackYIndex += (BoardSize-30);
        DeadBoardBlackXIndex = 0;
      }
    }
         else // white
         {
          if (type == "Queen")
           paint.drawImage(DeadBoardStartX+ DeadBoardWhiteXIndex, DeadBoardWhiteYIndex, WhiteSprites[0]);
         if (type == "King")
           paint.drawImage(DeadBoardStartX+ DeadBoardWhiteXIndex, DeadBoardWhiteYIndex, WhiteSprites[1]);
         if (type == "Bishop")
           paint.drawImage(DeadBoardStartX+ DeadBoardWhiteXIndex, DeadBoardWhiteYIndex, WhiteSprites[2]);
         if (type == "Knight")
           paint.drawImage(DeadBoardStartX+ DeadBoardWhiteXIndex, DeadBoardWhiteYIndex, WhiteSprites[3]);
         if (type == "Rook")
           paint.drawImage(DeadBoardStartX+ DeadBoardWhiteXIndex, DeadBoardWhiteYIndex, WhiteSprites[4]);
         if (type == "Pawn")
           paint.drawImage(DeadBoardStartX+ DeadBoardWhiteXIndex, DeadBoardWhiteYIndex, WhiteSprites[5]);

         DeadBoardWhiteXIndex += (BoardSize-30);
         if (DeadBoardWhiteXIndex/(BoardSize-30) == 8){
           DeadBoardWhiteYIndex += (BoardSize-30);
           DeadBoardWhiteXIndex = 0;
         }
       }

     }
     if (DeadBoardWhiteYIndex != 300){
       DeadBoardWhiteYIndex -= (BoardSize-30);
     }
     DeadBoardWhiteXIndex = 0;

     if (DeadBoardBlackYIndex != 50){
       DeadBoardBlackYIndex -= (BoardSize-30);
     }
     DeadBoardBlackXIndex = 0;

     paint.drawText(950,280, timeWhite_l);
     paint.drawText(1250,280, timeBlack_l);
   }
/* -- the piece will follow the mouse currsor when the mouse moves and the button is pressed -- */
   void ChessBoardQT::mouseMoveEvent(QMouseEvent *e) 
   {
    if(e->buttons() == Qt::LeftButton && picked)
    {
     pickedDrawx = e->y() - (BoardSize/2);
     pickedDrawy = e->x() - (BoardSize/2);
     update();
   }  
 }

/*-- detects when left mouse button is pressed and will pick up the piece -- */
 void ChessBoardQT::mousePressEvent(QMouseEvent *p)
 {
  if(p->buttons() == Qt::LeftButton )//&& !picked)
{
  hitBoxDetect(p->x(), p->y()); 
  pickedDrawx = p->y() - (BoardSize/2);
  pickedDrawy = p->x() - (BoardSize/2);
  ////std::cout << "presed at (" << p->x() << "," << p->y() << ")\n";
  update();
}  
}


/* -- puts the piece down when the mouse button is released-- */
void   ChessBoardQT::mouseReleaseEvent(QMouseEvent *r)
{
  if(r->button() == 1)// && picked)
{
  hitBoxDetect(r->x(), r->y());
  ////std::cout << "released at < " <<  r->button() << " > (" << r->x() << "," << r->y() << ")\n";
  pickedx = -2;
  pickedy = -2;
  picked = false;
  update();
}  
}


void ChessBoardQT::loadCreatePlayer(const string &name, RegisteredPlayer* &p)
{

   Database data;
   //DOES PLAYEREXIST IS ALWAYS RETURNING TRUE, KILLS FUNCTIONALITY HERE
   if(data.doesPlayerExist(name))
   {
     
      p->restoreMemento(data.loadPlayer(name));
   }
   else
   {
      //SAVED PLAYERS IS NOT CREATING ANY FILES EITHER
      p = new RegisteredPlayer(name);    
      // data.savePlayer(p->generateMemento(), name);
      // p->restoreMemento(data.loadPlayer(name));
   }
   
}

void ChessBoardQT::hitBoxDetect(int x, int y)
{
   int hit = BoardSize; // hit is the distance between each piece on the board
   x += 50; // 50 is the offset of how far the board is from the top left corner
   y += 50; // 50 is the offset of how far the board is from the top left corner

   pickedDrawx = x;
   pickedDrawy = y;
   int boardx = x / hit;
   int boardy = y / hit;
   if(!picked)
   {
    picked = false;
    if(boardx > 0 && boardy >0 && boardx < 9 && boardy < 9)
    {
         //////std::cout << "\n\n\n" << CBoard->getPiece(boardy-1,boardx-1)->getType();
     if("Empty" != CBoard->getPiece(boardy-1,boardx-1)->getType())
     {
      pickedx = boardx;
      pickedy = boardy;
      pickedType = CBoard->getPiece(boardy-1,boardx-1)->getType();
      pickedColor = CBoard->getPiece(boardy-1,boardx-1)->getColor();
      update();
      picked = true;
    }
  }

}
else
{
  if(boardx > 0 && boardy >0 && boardx < 9 && boardy < 9)
  {
    int moveRet = CBoard->movePiece(pickedy-1, pickedx-1, boardy-1, boardx-1);
    if(5 == moveRet)
    {
          //update();
      MessageWindow_W = new QTDisplayWindow("       King is in check!");
      MessageWindow_W->show();
    }
    if (moveRet == 3 )
    {
          //add to stats
      Database data;
      RegisteredPlayer* p1;
      RegisteredPlayer* p2;
      loadCreatePlayer(RegisteredPlayer1, p1);
      loadCreatePlayer(RegisteredPlayer2, p2);



      if(colorMove%2 == 0 )
      {
        if(RegisteredPlayer1 != "")
        {
          p1->incrementGamesWon();
          p1->setElo();
          data.savePlayer(p1->generateMemento(), RegisteredPlayer1);
        }
        if(RegisteredPlayer2 != "")
        {
          p2->incrementGamesLost();
          p2->setElo();
          data.savePlayer(p2->generateMemento(), RegisteredPlayer1);
        }
      }
    else
    {
      if(RegisteredPlayer1 != "")
      {
        p1->incrementGamesLost();  
        p1->setElo();
        data.savePlayer(p1->generateMemento(), RegisteredPlayer1);
      }
      if(RegisteredPlayer2 != "")
      {
        p2->incrementGamesWon();
        p2->setElo();
        data.savePlayer(p2->generateMemento(), RegisteredPlayer2);
      }
    }

    
    int temp = 8;
    emit newWindowFunction(temp);
    close();



       
  }
  if (moveRet == 2 ){
    int temp = 12;
    emit newWindowFunction(temp);
    close();
  }
}
picked = !picked;
}

       //  case 0: // invalid move
       //  case 1: // valid move
       //  case 2: // stale mate
       //  case 3: // kind is dead!
       //  case 5: // in check

}


//helper function for below
QString ChessBoardQT::IntToString(int min, int sec)
{
 QString ret = "";

 if (min / 10 != 0){
  ret+= (min/10)+48;
}
ret+=(min%10)+48;
ret+=":";
ret+=(sec/10)+48;
ret+=(sec%10)+48;
return ret;
}

void ChessBoardQT::getTime(const int &time)
{
  if (initTime){
    initTime = false;
    timeWhite_l = IntToString(timeWhitem,timeWhites);
    timeBlack_l = IntToString(timeBlackm,timeBlacks);
    update();
    return;
  }

  if (colorMove%2 == 0)
  {
    if (timeWhites == 0){
      timeWhitem--;
      timeWhites = 59;
      if (timeWhitem == -1)
          {//TODO End game here
          }

        }
        else{
          timeWhites--;
        }
        timeWhite_l = IntToString(timeWhitem,timeWhites);
      }
      else
      {
        if (timeBlacks == 0){
          timeBlackm--;
          timeBlacks = 59;
          if (timeBlackm == -1)
          {//TODO End game here
          }

        }
        else{
          timeBlacks--;
        }
        timeBlack_l = IntToString(timeBlackm,timeBlacks);
      }
      update();

    }


    void ChessBoardQT::saveGameSlot()
    {
      ////std::cout << "this is where it would save the game, this string is very unique... for debuging =D";
      Database data;
      data.saveGame(CBoard->getGameHistory(), saveGameLabel);


  //vector<string> ChessBoard::getGameHistory()
  //void saveGame(vector<string> gameHistory, string gameName);
    }