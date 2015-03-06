//*****************************************************************************
/// Game.cc
///
/// \author Zackery Shortt
/// \date November 12, 2014
//*****************************************************************************

#include "Players/Player.h"
#include "Chat.h"
#include "Game.h"
#include "Board.h"

Game::Game() : gameOver(false)
{
}

Game::~Game()
{
}

Board* Game::getBoard()
{
   return *b;
}

void Game::setBoard(Board b)
{
   this->b = b;
}

Player* Game::getPlayer1()
{
   return p1;
}

void Game::setPlayer1(Player* p)
{
   this->p1 = p;
}

Player* Game::getPlayer2()
{
   return p2;
}

void Game::setPlayer2(Player* p)
{
   this->p2 = p;
}

GameChat* Game::getChat()
{
   return *bchat;
}

void Game::newGame()
{
   this = new Game;
}

bool Game::checkGameOver()
{
   return gameOver;
}

void setGameOver()
{
   gameOver = true;
}
