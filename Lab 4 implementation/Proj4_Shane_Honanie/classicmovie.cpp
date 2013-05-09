/*
 * classicmovie.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * classicmovie.cpp contains all the implementations of functions and data
 * members needed to modify and display ClassicMovie objects. Contains
 * overloaded equality operators to determine sort order.
 * ClassicMovie inherits from Movie.
 */
#include "classicmovie.h"

//-----------------------------------------------------------------------------
// ClassicMovie
// Default constructor:takes no parameters, sets data members to default values
ClassicMovie::ClassicMovie() 
   :Movie(),actorFirstName(""), actorLastName(""), month(0), GENRE("CLASSIC")
{}

//-----------------------------------------------------------------------------
// ~ClassicMovie
// deconstructor: destroy strings properly
ClassicMovie::~ClassicMovie()
{}

//-----------------------------------------------------------------------------
// setData
// Takes istream reference as parameter. Sets the datamembers according to the
// input
void ClassicMovie::setData(istream& infile)
{
   infile.get();                      // get (and ignore) blank before director
   getline(infile, director, ',');    // input director
   
   infile.get();                      // get (and ignore) blank before title
   getline(infile, title, ',');       // input title
   
   infile.get();                      // get (and ignore) blank before actor
   infile >> actorFirstName >> actorLastName;   // input star's name
   infile >> month >> year;           // input month and year
}

//-----------------------------------------------------------------------------
// setData2
// ...
void ClassicMovie::setData2(istream& infile) 
{
   infile >> month;
   infile >> year;
   infile >> actorFirstName;
   infile >> actorLastName;
}

//-----------------------------------------------------------------------------
// display
// displays information about a classic movie
void ClassicMovie::display() const
{
   cout << left << setw(23) << title.substr(0, MAX_TITLE_OUTPUT_CHAR)
      << setw(17) << director.substr(0, MAX_DIRECTOR_OUTPUT_CHAR) 
      <<  setw(5) << year << right << setw(2) << month <<  "   " 
      << actorFirstName << " " << actorLastName << endl;
}

//-----------------------------------------------------------------------------
// operator<
// used to help determine the sort order of classic movies
bool ClassicMovie::operator<(const VideoStoreItem& rhs) const
{
   //Cast VideoStoreItem down to ClassicMovie
   const ClassicMovie& aClassicMovie = static_cast<const ClassicMovie&>(rhs); 

   //Sort Order: date, then famous actor
   if (year < aClassicMovie.year)
      return true;
   else if (year == aClassicMovie.year)
   {
      if (actorFirstName < aClassicMovie.actorFirstName)
         return true;
      else if (actorFirstName == aClassicMovie.actorFirstName)
         return (actorLastName < aClassicMovie.actorLastName);
      else 
         return false;
   }
   else 
      return false;
}

//-----------------------------------------------------------------------------
// operator==
// Check if two classic movies are equal by date and famousactor
bool ClassicMovie::operator==(const VideoStoreItem& rhs) const
{
   const ClassicMovie& aClassicMovie = static_cast<const ClassicMovie&>(rhs); 

   return (year == aClassicMovie.year && month == aClassicMovie.month && 
      actorFirstName == aClassicMovie.actorFirstName && 
      actorLastName == aClassicMovie.actorLastName);
}

//-----------------------------------------------------------------------------
// create
// Returns a new classmovie object
VideoStoreItem* ClassicMovie::create()
{
   return new ClassicMovie(); //return ClassicMovie object
}

//-----------------------------------------------------------------------------
// displayHeader
// used as header when displaying all ClassicMovies
void ClassicMovie::displayHeader() const
{
   cout << GENRE << endl;
   cout << "*IN* *OUT*" << endl;
   cout << "DVD    DVD TITLE              DIRECTOR         "
      "YEAR  MO  ACTOR" << endl;
}
