/// \file
///Author Marco Illievski/Brandon Robertson
///
#ifndef RULE_H
#define RULE_H
#include "../Piece/Piece.h"
#include <algorithm>
class Piece;

//******************************************************************************
/// Rule is an Abstract base class
//******************************************************************************
class Rule
{


//******************************************************************************
/// Pure Virtual, will force sub-classes to check for validity of a move
//
/// \return int 
//******************************************************************************
   virtual int validMove(vector<vector<Piece*> > &b, int ix, int iy, int dx, int dy)=0;

};


#endif
