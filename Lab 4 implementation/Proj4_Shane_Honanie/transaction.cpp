/*
 * transaction.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * transaction.cpp contains all the declarations of functions needed to modify
 * and display a transaction object. Transaction contains a pointer to a 
 * VideoStoreItem. Transaction also stores mediatype and transaction type
 * needed for display.
 *
 *Assumptions:
 *-Should be used as a base class
 */

#include "transaction.h"

//-----------------------------------------------------------------------------
// Transaction
// default constructor: initialize data members to default values
Transaction::Transaction()
   :theItem(NULL), mediaType(""), transactiontype("Transaction")
{}

//-----------------------------------------------------------------------------
// Transaction
// copy constructor: takes a transaction object as its parameter. Creates a
// deep copy.
Transaction::Transaction(const Transaction& rhs)
{
   transactiontype = rhs.transactiontype;
   mediaType = rhs.mediaType;
   theItem = rhs.theItem;
}

//-----------------------------------------------------------------------------
// ~Transaction
// deconstructor: used to properly delete strings
Transaction::~Transaction()
{}

//-----------------------------------------------------------------------------
// setData
// takes a string, VideoStoreItem and customer as parameters. Sets the media
// and item and return true to signal stored transaction
bool Transaction::setData(string media, VideoStoreItem* newItem, 
   Customer* theCustomer)
{
   mediaType = media;
   theItem = newItem;   
   return true; //return true to indicate stored transaction
}

//-----------------------------------------------------------------------------
// display
// display the mediaType and transactionType
void Transaction::display() const
{
   cout << mediaType << " " << transactiontype << " ";
}

//-----------------------------------------------------------------------------
// create
// return a new transaction object
Transaction* Transaction::create()
{
   return new Transaction();
}

//-----------------------------------------------------------------------------
// getMediaType
// return the media type
string Transaction::getMediaTye()
{
   return mediaType;
}

//-----------------------------------------------------------------------------
// getTransType
// return the TransTyepe
string Transaction::getTransType()
{
   return transactiontype;
}

//-----------------------------------------------------------------------------
// getItem
// return theItem
VideoStoreItem* Transaction::getItem() const
{
   return theItem;
}
