# CPSC 3770 - Checkmate
Hello
###To run this game please change your screen resolution to 1600 by 900 all other resolution will not work at this time

## Discription
This is our implementation of a chess game implemented in C++, with the QT extension library. 
The backend of this game was implemented as a group project for 2720 Practical Software Development.
The front end including all the art was creating for our Project for 3770 Human Computer Interaction.

Please Note that all the art that you see was created by us.

## Installation
To install the game go to the source file and type make. Once it have finished making (may take some time) you can launch the game with the following command ./checkMate.

Please Note that this game has the following dependences:
 - g++11
 - qt at least version 4.8
 - c++0x

## Rules
The Rules for this chess game differ in one what from the original game and that is it is up to the player to capture the opponents king. Thus there is no checkmate in this game. 

## Directory Structure

##### source/
 - most source and header files
 - type "make" to create executable

##### source/QTMenu -(Most of the Implementation for this project)- 
 - contains all source and headers for all QTMenus and Windows
 - contains all the art that was created by us

##### source/piece/
 - contains source and headers for piece class

##### source/rules/
 - contains source and headers for rules class

##### source/players/
 - contains source and headers for players class 

##### source/menus
 - contains source and headers for consal based menu class 

### doxygen/
 - directory for generating doxygen documentation
 
##### design/
 - the object-oriented design, may not be updated during devlopment
 - coding conventions document
 - Workload Delegation document

##### tests/
 - directory for cppunit tests and manual test documentation 
 
##### proposal/
 - original submitted script 

##### testDir/
 - unit test source 
   test_results/
   	- the results from the tests
