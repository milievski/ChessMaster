/// \file Errors.h
///file for all error classes
/// \author Lukas Grasse
/// \date 24-11-2014

//includes
#include <stdexcept>
#include <string>

//macro guard
#ifndef ERRORS_H
#define ERRORS_H

//begin database_load_error class
class database_load_error : public std::runtime_error {
public:
/// \brief Constructor for database_load_error Class
///
///This is the Constructor for the database_load_error class. 
/// \param [in] msg The error message for the exception
database_load_error(const std::string& msg) : runtime_error(msg) {}
}; //end class

//begin tournament_error class
class tournament_error : public std::runtime_error {
public:
/// \brief Constructor for tournament_error Class
///
///This is the Constructor for the tournament_error class. 
/// \param [in] msg The error message for the exception
tournament_error(const std::string& msg) : runtime_error(msg) {}
}; //end class



#endif