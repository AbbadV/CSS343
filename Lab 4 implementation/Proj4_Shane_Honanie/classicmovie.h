/*
 * classicmovie.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * classicmovie.h contains all the declarations of functions and data
 * members needed to modify and display ClassicMovie objects. Contains
 * overloaded equality operators to determine sort order.
 * ClassicMovie inherits from Movie.
 */

#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H
#include <string>
#include "movie.h"
using namespace std;

class ClassicMovie: public Movie
{
public:
   ClassicMovie();
   ~ClassicMovie();
   ClassicMovie(const ClassicMovie&);

   virtual void setData(istream&); //set movie data
   virtual void setData2(istream&); //set temp movie data
   virtual void display() const; //display ClassicMovie Data
   //Equality operators determine sort order
   virtual bool operator==(const VideoStoreItem&) const;
   virtual bool operator<(const VideoStoreItem&) const;
   virtual VideoStoreItem* create(); //create classicmovie object

   //void setFirstName(string);
   //void setlastName(string);
   /*void setMonth(int);*/
   virtual void displayHeader() const; //display classicmovie header
   

private:
   string actorFirstName, actorLastName; //Movie Data
   int month;
   const string GENRE; //genre is set to classic
};
#endif
