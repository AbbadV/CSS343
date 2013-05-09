/*
 * dramamovie.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * dramamovie.h contains all the declarations of functions and data
 * members needed to modify and display DramaMovie objects. Contains
 * overloaded equality operators to determine sort order.
 * DramaMovie inherits from Movie.
 */

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H
#include <string>
#include "movie.h"
using namespace std;

class DramaMovie: public Movie
{
public:
   DramaMovie();
   ~DramaMovie();
   DramaMovie(const DramaMovie&);

   virtual void setData(istream&); //set movie data
   virtual void setData2(istream&); //set temp movie data
 //  virtual void display() const; //display movie data
   //Equality operators determine sort order for Drama movie
   virtual bool operator==(const VideoStoreItem&) const;
   virtual bool operator<(const VideoStoreItem&) const;
   virtual VideoStoreItem* create(); //create new dramamovie object
   virtual void displayHeader() const; //display header for drama

private:
   const string GENRE; //genre set to drama
};
#endif
