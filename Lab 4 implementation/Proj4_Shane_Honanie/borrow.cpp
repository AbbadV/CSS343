/*
 * borrow.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * borrow.cpp contains all the implementations of functions and data members 
 * needed to modify data and display a borrow object. 
 * Assumption: Borrow inherits from Transaction.
 */

#include "borrow.h"

//-----------------------------------------------------------------------------
// Borrow
// Default constructor:  No parameters, sets Borrow as transactionType

Borrow::Borrow() :Transaction()
{
   transactiontype = "Borrow"; //type of transaction used for display
}

//-----------------------------------------------------------------------------
// Borrow
// Copy constructor:  Takes reference to Borrow object as parameter. Makes a
//deep copy of a Borrow object.

Borrow::Borrow(const Borrow& rhs)
{
   transactiontype = rhs.transactiontype;
   mediaType = rhs.mediaType;
   theItem = rhs.theItem;
}

//-----------------------------------------------------------------------------
// ~Borrow
// destructor:  Deletes theItem if it exists, destructor is virtual

Borrow::~Borrow()
{}

//-----------------------------------------------------------------------------
// setData
// SetData tales a string, VideoStoreItem*, and Customer* as its parameters.
// If theItem is not NULL, replaces data with input and decrease numberOfCopies
bool Borrow::setData(string media, VideoStoreItem* newItem, Customer* theCustomer)
{
   if (newItem != NULL) //Dont do anything if item is NULL
   {
      mediaType = media; //Set Data
      theItem = newItem;

      if (mediaType != "") //Check if invalid data
         theItem->decreaseCopies(); //Decrease numberOfCopies
   }
   return true;
}

//-----------------------------------------------------------------------------
// display
// displays' the mediaType such as "DVD" and transactionType which is "Borrow"

void Borrow::display() const
{
  cout << mediaType << " " << transactiontype << " "; //used for display
}

//-----------------------------------------------------------------------------
// create
// Returns a new Borrow Object

Transaction* Borrow::create()
{
   return new Borrow(); //return Borrow Object
}

