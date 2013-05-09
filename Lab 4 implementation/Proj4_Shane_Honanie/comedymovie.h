/*
 * comedymovie.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * comedymovie.h contains all the declarations of functions and data
 * members needed to modify and display ComedyMovie objects. Contains
 * overloaded equality operators to determine sort order.
 * ComedyMovie inherits from Movie.
 */

#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H
#include <string>
#include "movie.h"
using namespace std;

class ComedyMovie: public Movie
{
   
public:
   ComedyMovie();
   ~ComedyMovie();
   ComedyMovie(const ComedyMovie&);

   virtual void setData(istream&); //set movie data
   virtual void setData2(istream&); //set temp movie data
//   virtual void display() const; //display movie data
   virtual bool operator==(const VideoStoreItem&) const;
   virtual bool operator<(const VideoStoreItem&) const;
   virtual VideoStoreItem* create(); //create new comedymovie object
   virtual void displayHeader() const; //header for comedy movie

private:
   const string GENRE; //genre set to comedy
};
#endif
