/*
 * videostoreitem.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * videostoreitem.cpp contains all the declarations of functions needed to 
 * create, modify, and display a VideoStoreItem object. Contains functions 
 * to set number of copies of one item and get amount of items in stock.
 *
 *ASSUMPTIONS:
 *-This is a Base Class that is abstract, must be inherited from
 *-Abstract functions must be overidden
 */
#include "videostoreitem.h"

//-----------------------------------------------------------------------------
// VideoStoreItem
// constructor sets data memebrs to defalt values
VideoStoreItem::VideoStoreItem()
	:numberOfCopies(-1), maxCopies(0) //-1 Means no copies available
{}

//-----------------------------------------------------------------------------
// ~VideoStoreItem
// deconstructor: used to delete strings properly
VideoStoreItem::~VideoStoreItem()
{}

//-----------------------------------------------------------------------------
// decreaseCopies
// derease the amount of copies
void VideoStoreItem::decreaseCopies()
{
	if (numberOfCopies != 0) //Check if minimum of zero
      numberOfCopies = numberOfCopies - 1;
}

//-----------------------------------------------------------------------------
// increaseCopies
// increase number of copies
void VideoStoreItem::increaseCopies()
{
	if (numberOfCopies != maxCopies) //Check if at max
      numberOfCopies = numberOfCopies + 1;
}

//-----------------------------------------------------------------------------
// getAmountIn
// return the current number of copies
int VideoStoreItem::getAmountIn()
{
   return numberOfCopies;
}

//-----------------------------------------------------------------------------
// getAmountOut
// return the number of copies out
int VideoStoreItem::getAmountOut()
{
   return maxCopies - numberOfCopies;
}

//-----------------------------------------------------------------------------
// setMaxCopies
// set the max nuber of copies
void VideoStoreItem::setMaxCopies(const int amountIn)
{
   maxCopies = amountIn;

   if(numberOfCopies < 0) //check if copies have been previously set
      numberOfCopies = maxCopies;
}
