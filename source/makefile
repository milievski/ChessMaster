OBJS = main.o Tournament.o Chat.o MainMenu.o PauseMenu.o EndMenu.o LeaderBoard.o TournamentMenu.o LoginMenu.o status.o Board.o chessGameGUI.o Definitions.o Database.o PawnPiece.o RookPiece.o ChessBoard.o KingPiece.o QueenPiece.o BishopPiece.o KnightPiece.o Player.o RegisteredPlayer.o EmptyPiece.o BishopMove.o CastlingMove.o CheckTurn.o ConsecutiveMove.o FriendlyPiece.o KingInCheck.o KingMove.o KnightMove.o NotEnoughPieces.o PawnCapture.o PawnMove.o PieceInWay.o Promotion.o QueenMove.o RookMove.o 

SRCS = main.cpp 

CC = g++11
CFLAGS = -Wall -g -std=c++11


chessGame: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ 


Definitions.o: Definitions.cc
	$(CC) $(CFLAGS) -c $<

BishopMove.o: Rules/BishopMove.cc
	$(CC) $(CFLAGS) -c $<

CastlingMove.o: Rules/CastlingMove.cc
	$(CC) $(CFLAGS) -c $<

CheckTurn.o: Rules/CheckTurn.cc
	$(CC) $(CFLAGS) -c $<

ConsecutiveMove.o: Rules/ConsecutiveMove.cc
	$(CC) $(CFLAGS) -c $<

FriendlyPiece.o: Rules/FriendlyPiece.cc
	$(CC) $(CFLAGS) -c $<

KingInCheck.o: Rules/KingInCheck.cc
	$(CC) $(CFLAGS) -c $<

KingMove.o: Rules/KingMove.cc
	$(CC) $(CFLAGS) -c $<

KnightMove.o: Rules/KnightMove.cc
	$(CC) $(CFLAGS) -c $<

NotEnoughPieces.o: Rules/NotEnoughPieces.cc
	$(CC) $(CFLAGS) -c $<

PawnCapture.o: Rules/PawnCapture.cc
	$(CC) $(CFLAGS) -c $<

PawnMove.o: Rules/PawnMove.cc
	$(CC) $(CFLAGS) -c $<

PieceInWay.o: Rules/PieceInWay.cc
	$(CC) $(CFLAGS) -c $<

Promotion.o: Rules/Promotion.cc
	$(CC) $(CFLAGS) -c $<

QueenMove.o: Rules/QueenMove.cc
	$(CC) $(CFLAGS) -c $<

RookMove.o: Rules/RookMove.cc
	$(CC) $(CFLAGS) -c $<




LeaderBoard.o: Menu/LeaderBoard.cc
	$(CC) $(CFLAGS) -c $<

EndMenu.o: Menu/EndMenu.cc
	$(CC) $(CFLAGS) -c $<

MainMenu.o: Menu/MainMenu.cc
	$(CC) $(CFLAGS) -c $<	

PauseMenu.o: Menu/PauseMenu.cc
	$(CC) $(CFLAGS) -c $<

TournamentMenu.o: Menu/TournamentMenu.cc
	$(CC) $(CFLAGS) -c $<

LoginMenu.o: Menu/LoginMenu.cc
	$(CC) $(CFLAGS) -c $<

status.o: status.cc
	$(CC) $(CFLAGS) -c $<

Board.o: Board.cc
	$(CC) $(CFLAGS) -c $<

ChessBoard.o: ChessBoard.cc
	$(CC) $(CFLAGS) -c $<

e chessGameGUI.o: chessGameGUI.cc
	$(CC) $(CFLAGS) -c $<

PawnPiece.o: Piece/PawnPiece.cc
	$(CC) $(CFLAGS) -c $<

RookPiece.o: Piece/RookPiece.cc
	$(CC) $(CFLAGS) -c $<

KingPiece.o: Piece/KingPiece.cc
	$(CC) $(CFLAGS) -c $<

QueenPiece.o: Piece/QueenPiece.cc
	$(CC) $(CFLAGS) -c $<

KnightPiece.o: Piece/KnightPiece.cc
	$(CC) $(CFLAGS) -c $<

BishopPiece.o: Piece/BishopPiece.cc
	$(CC) $(CFLAGS) -c $<


EmptyPiece.o: Piece/EmptyPiece.cc
	$(CC) $(CFLAGS) -c $<

Player.o: Players/Player.cc
	$(CC) $(CFLAGS) -c $<

RegisteredPlayer.o: Players/RegisteredPlayer.cc
	$(CC) $(CFLAGS) -c $<

#Game.o: Game.cc
#	$(CC) $(CFLAGS) -c $<

#ChessGame.o: ChessGame.cc
#	$(CC) $(CFLAGS) -c $<

%.o: %.cc
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *~ *% *# .#*

clean-all:
	rm -f *.o *~ *% *# .#*
	rm ./chessGame