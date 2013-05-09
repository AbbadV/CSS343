/*
 * dramamovie.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * dramamovie.cpp contains all the implementations of functions and data
 * members needed to modify and display DramaMovie objects. Contains
 * overloaded equality operators to determine sort order.
 * Assumption: DramaMovie inherits from Movie.
 */

#include "dramamovie.h"

//-----------------------------------------------------------------------------
// DramaMovie
// Default constructor:takes no parameters, sets data members to default values
DramaMovie::DramaMovie() :Movie(), GENRE("DRAMA")
{}

//-----------------------------------------------------------------------------
// ~DramaMovie
// deconstructor: Makes sure strings are deleted properly
DramaMovie::~DramaMovie()
{}

//-----------------------------------------------------------------------------
// setData
// Takes an istream reference object as its only parameter. Then sets the data
// for a Drama movie object.
void DramaMovie::setData(istream& infile)
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
// Determines the sort order for drama movies which is director, then title
bool DramaMovie::operator<(const VideoStoreItem& rhs) const
{
   //Cast VideoStoreItem down to a DramaMovie object
   const DramaMovie& aDramaMovie = static_cast<const DramaMovie&>(rhs); 

   //Sort Order is directer, then title
   if (director < aDramaMovie.director)
      return true;
   else if (director == aDramaMovie.director)
      return (title < aDramaMovie.title);
   else
      return false;
}

//-----------------------------------------------------------------------------
// operator==
// Takes a videoStoreItem reference as its only parameter. Checks if two 
//DramaMovie objects are the same determined by dirctor, then title
bool DramaMovie::operator==(const VideoStoreItem& rhs) const
{
   //Cast VideoStoreItem down to a DramaMovie object
   const DramaMovie& aDramaMovie = static_cast<const DramaMovie&>(rhs); 

   //Retrn true if same determined by sort order: director, then title
   return (title == aDramaMovie.title && director == aDramaMovie.director);
}

//-----------------------------------------------------------------------------
// create
// return a new DramaMovie object
VideoStoreItem* DramaMovie::create()
{
   return new DramaMovie(); //return a drama movie object
}

//-----------------------------------------------------------------------------
// setData2
// ...
void DramaMovie::setData2(istream& infile)
{
   infile.get();                       // get (and ignore) blank before title
   getline(infile, director, ',');   

   infile.get();                       // get (and ignore) blank before title
   getline(infile, title, ',');   
}

//-----------------------------------------------------------------------------
// displayHeader
// display header is ued when displaying all drama movies, describes info
void DramaMovie::displayHeader() const
{
   cout << GENRE << endl;
   cout << "*IN* *OUT*" << endl;
   cout << "DVD    DVD TITLE              DIRECTOR         YEAR" << endl;
}

