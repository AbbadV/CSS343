/*
 * history.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * history.cpp purpose is to display all of the customers history if it is passed
 * a non-null customer object
 */
#include "history.h"
#include "customer.h"

//-----------------------------------------------------------------------------
// History
// default constructor sets History as transactiontype
History::History() :Transaction()
{
   transactiontype = "History"; //const
}

//-----------------------------------------------------------------------------
// History
// copy constructor: takes a History reference as its parameter and creates a
// deep copy
History::History(const History& rhs)
{
   transactiontype = rhs.transactiontype;
   mediaType = rhs.mediaType;
   theItem = rhs.theItem;
}

//-----------------------------------------------------------------------------
// ~History
// used to properly delete strings
History::~History()
{}

//-----------------------------------------------------------------------------
// setData
// Dsiplays customers history
//returns false to signal it is not a stored transaction
bool History::setData(string media, VideoStoreItem* newMovie, Customer* theCustomer)
{
   theCustomer->displayAllHistory(); //display customers history
   return false; //return false to signal not a stored transaction
}

//-----------------------------------------------------------------------------
// create
// return a new history object
Transaction* History::create()
{
   return new History();
}
