/*
 * comedymovie.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * comedymovie.cpp contains all the implementations of functions and data
 * members needed to modify and display ComedyMovie objects. Contains
 * overloaded equality operators to determine sort order.
 * Assumption: ComedyMovie inherits from Movie.
 */

#include "comedymovie.h"

//-----------------------------------------------------------------------------
// ComedyMovie
// Default constructor:takes no parameters, sets data members to default values
ComedyMovie::ComedyMovie() :Movie(), GENRE("COMEDY")
{}

//-----------------------------------------------------------------------------
// ComedyMovie
// deconstructor makes sure strings are deleted properly
ComedyMovie::~ComedyMovie()
{}

//-----------------------------------------------------------------------------
// setData
// Takes istream reference as a parameter. Sets the data for information about
// the Comedy Movie.
void ComedyMovie::setData(istream& infile)
{
   infile.get();                      // get (and ignore) blank before director
   getline(infile, director, ',');     // input director
   
   infile.get();                       // get (and ignore) blank before title
   getline(infile, title, ',');        // input title
   
   infile.get();                       // get (and ignore) blank before year
   infile >>  year;                   // input year
}

//-----------------------------------------------------------------------------
// operator<
// Overriden < operator determines the sort order for comedy movies.
// Sort Order: title, then date
bool ComedyMovie::operator<(const VideoStoreItem& rhs) const
{
   //Cast VideoStoreItem down to a ComedyMovie
   const ComedyMovie& aComedyMovie = static_cast<const ComedyMovie&>(rhs); 

   // Sort Order: title, then date
   if (title < aComedyMovie.title)
      return true;
   else if (title == aComedyMovie.title) //might need to do year/month instead of just year
      return year < aComedyMovie.year;
   else
      return false;  
}

//-----------------------------------------------------------------------------
// operator==
// Takes a videoStoreItem as parameter. Check if two ComedyMovies are equal
// determined by title and date.
bool ComedyMovie::operator==(const VideoStoreItem& rhs) const
{
   //Cast VideoStoreItem down to a ComedyMovie
   const ComedyMovie& aComedyMovie = static_cast<const ComedyMovie&>(rhs); 
   //Check if title and year are equal
   return (title == aComedyMovie.title && year == aComedyMovie.year);
}

//-----------------------------------------------------------------------------
// create
// return a new ComedyMovie object
VideoStoreItem* ComedyMovie::create()
{
   return new ComedyMovie(); //return ComedyMovie object
}

//-----------------------------------------------------------------------------
// setData2
//...
void ComedyMovie::setData2(istream& infile)
{
   infile.get();                       // get (and ignore) blank before title
   getline(infile, title, ',');   

   infile >> year;
}

//-----------------------------------------------------------------------------
// displayHeader
// display header is used when displaying all Comedy Movies. Describes the info
// that is outputted.
void ComedyMovie::displayHeader() const
{
   cout << GENRE << endl;
   cout << "*IN* *OUT*" << endl;
   cout << "DVD    DVD TITLE              DIRECTOR         YEAR" << endl;
}
