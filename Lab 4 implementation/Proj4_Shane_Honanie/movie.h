/*
 * movie.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * movie.h contains all the declarations of functions and data members needed
 * to modify data and display a movie object. This class is meant to be 
 * inherited from since it is abstract. 
 */

#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "videostoreitem.h"
using namespace std;

class Movie: public VideoStoreItem
{
public:
   static const int MAX_DIRECTOR_OUTPUT_CHAR = 15; //max director length
   static const int MAX_TITLE_OUTPUT_CHAR = 21; //max title length

   Movie();
   Movie(const Movie&);
   virtual ~Movie();

   virtual void setData(istream&); //set movie data
   virtual void setData2(istream&) = 0; //set temp movie data is abstract
   virtual void display() const; //display movie data
   virtual void displayHeader() const; //display header for inherited classes
   //equality operators must be overriden to determine sort order
   virtual bool operator==(const VideoStoreItem&) const = 0;
   virtual bool operator<(const VideoStoreItem&) const = 0;
   virtual VideoStoreItem* create() = 0; //create new movie object
   virtual string getItem() const;
   //get methods for data that all movies have
   string getDirector();
   string getTitle();
   int getYear();

   /*void setDirector(string);
   void setTitle(string);
   void setYear(int);*/
protected:
   //data that all movies have
   string director, title;
   int year;   
};

#endif
