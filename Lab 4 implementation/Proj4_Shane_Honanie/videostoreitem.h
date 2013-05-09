/*
 * videostoreitem.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * videostoreitem.h contains all the declarations of functions needed to 
 * create, modify, and display a VideoStoreItem object. Contains functions 
 * to set number of copies of one item and get amount of items in stock.
 *
 *ASSUMPTIONS:
 *-This is a Base Class that is abstract, must be inherited from
 *-Abstract functions must be overidden
 */

#ifndef VIDEOSTOREITEM_H
#define VIDEOSTOREITEM_H
#include <iostream>
using namespace std;

class VideoStoreItem
{
public:
	VideoStoreItem();
   VideoStoreItem(const VideoStoreItem&);

   virtual ~VideoStoreItem();
   virtual void setData(istream&) = 0;
   virtual void setData2(istream&) = 0;
   virtual void display() const = 0;
   virtual void displayHeader() const= 0;
   virtual string getItem() const = 0;
   void setMaxCopies(const int);
   void increaseCopies();
   void decreaseCopies();
   int getAmountIn();
   int getAmountOut();

   virtual bool operator==(const VideoStoreItem&) const = 0;
   virtual bool operator<(const VideoStoreItem&) const = 0;
   virtual VideoStoreItem* create() = 0;

private:
	int maxCopies;
   int numberOfCopies;
};

#endif
