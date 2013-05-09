/*
 * return.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * return.cpp contains all the implementations of functions and data 
 * members needed to modify data and display a return object.
 * return inherits from transaction.
 */
#include "return.h"

//-----------------------------------------------------------------------------
// Return
// default constructor: transactiontype to return
Return::Return() :Transaction()
{
   transactiontype = "Return";
}

//-----------------------------------------------------------------------------
// Return
// copy constructor: take a return object as its parameter and creates a deep
// copy
Return::Return(const Return& rhs)
{
   transactiontype = rhs.transactiontype;
   mediaType = rhs.mediaType;
   theItem = rhs.theItem;
}

//-----------------------------------------------------------------------------
// ~Return
// deconstructor: used to delete strings properly
Return::~Return()
{}

//-----------------------------------------------------------------------------
// setData
// takes string, VideoStoreItem, and Customer is its parameters. Sets the media
// movie for return object. Also decrease copy of movies since it is being
// borrowed. returns true to indiciate a stored transaction
bool Return::setData(string media, VideoStoreItem* newMovie, 
   Customer* theCustomer)
{
   if(newMovie != NULL)
   {
      mediaType = media;
      theItem = newMovie;   

      if (mediaType != "")
         theItem->increaseCopies(); //increase copies
   }
   return true; //return true to indicate stored transaction
}

//-----------------------------------------------------------------------------
// display
// displays the mediatype and transactiontype for return object
void Return::display() const
{
   cout << mediaType << " " << transactiontype << " ";
}

//-----------------------------------------------------------------------------
// create
// return a new return object
Transaction* Return::create()
{
   return new Return();
}
