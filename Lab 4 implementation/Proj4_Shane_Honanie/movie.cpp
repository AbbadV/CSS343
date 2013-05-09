/*
 * movie.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * movie.cpp contains all the implementations of functions and data members 
 needed to modify data and display a movie object. This class is meant to be 
 * inherited from since it is abstract. 
 */
#include "movie.h"

//-----------------------------------------------------------------------------
// Movie
// default constructor: initializes data members to default values
Movie::Movie()
: VideoStoreItem(), director(""), title(""), year(0)
{}
//-----------------------------------------------------------------------------
// ~Movie
// used to properly delete strings
Movie::~Movie()
{}

//-----------------------------------------------------------------------------
// setData
// takes an istream reference as its only parameter. Sets director, title, and
// year for Movie object.
void Movie::setData(istream& infile)
{

   infile.get();                       // get (and ignore) blank before director
   getline(infile, director, ',');     // input director
   
   infile.get();                       // get (and ignore) blank before title
   getline(infile, title, ',');        // input title
   
   infile.get();                       // get (and ignore) blank before year
   infile >>  year;                   // input year

}

//-----------------------------------------------------------------------------
// getDirector
// return director name
string Movie::getDirector()
{
   return director;
}

//-----------------------------------------------------------------------------
// getTitle
// return title of movie
string Movie::getTitle()
{
   return title;
}

//-----------------------------------------------------------------------------
// getYear
// return year of movie
int Movie::getYear()
{
   return year;
}

//-----------------------------------------------------------------------------
// displayHeader
// used for displaying categories of movies, if subclass does not override, 
// this will be used because all movies have these data
void Movie::displayHeader() const
{
   cout << "*IN* *OUT*" << endl;
   cout << "DVD    DVD TITLE              DIRECTOR         YEAR" << endl;
}

//-----------------------------------------------------------------------------
// display
// display the information about movie such as title, direcor, year
void Movie::display() const
{
   cout << left << setw(23) << title.substr(0, MAX_TITLE_OUTPUT_CHAR) 
      << setw(17) << director.substr(0, MAX_DIRECTOR_OUTPUT_CHAR) 
      <<  setw(5) << year << endl;
}

//-----------------------------------------------------------------------------
// getItem
// return item name which in this case is title of movie
string Movie::getItem() const
{
   return title;
}




