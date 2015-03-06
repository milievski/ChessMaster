/// \file TournamentTester.h 
///header file for TournamentTest class


//macro guard
#ifndef TOURNAMENT_TESTER_H
#define TOURNAMENT_TESTER_H
#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../source/Tournament.h"


/// Class to test Tournament
///using a fixture and a test suite
class TournamentTest : public CppUnit::TestFixture {
// the macros to create the test suite
CPPUNIT_TEST_SUITE(TournamentTest);

CPPUNIT_TEST(testGetNumPlayers);
CPPUNIT_TEST(testGetCurrentMatch);
CPPUNIT_TEST(testGetTournamentSize);
CPPUNIT_TEST(testGetNextMatch);
CPPUNIT_TEST(testGetMatchWinner);
CPPUNIT_TEST(testSetMatchWinner);

CPPUNIT_TEST_SUITE_END();

public:
///Create variables to be used in testing
void setUp(); 

///Clean up any allocated variables
void tearDown(); 


///Testing get num players
void testGetNumPlayers();



///Testing get current match
void testGetCurrentMatch();

///Testing get tournament size
void testGetTournamentSize();

///Testing get next match
void testGetNextMatch();

///Testing get match winner
void testGetMatchWinner();

///Testing set match winner
void testSetMatchWinner();

private:

//2
Tournament* tourneyA;

//4
Tournament* tourneyB;

//8
Tournament* tourneyC;

//empty
Tournament* tourneyD;

//bad constructor
Tournament* tourneyE;

//map constructor
Tournament* tourneyF;

};
#endif