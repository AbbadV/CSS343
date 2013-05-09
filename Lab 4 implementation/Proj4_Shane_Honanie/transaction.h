/*
 * transaction.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * transaction.h contains all the declarations of functions needed to modify
 * and display a transaction object. Transaction contains a pointer to a 
 * VideoStoreItem. Transaction also stores mediatype and transaction type
 * needed for display.
 *
 *Assumptions:
 *-Should be used as a base class
 */

#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include "movie.h"
using namespace std;
class Customer;
class Transaction
{
  

public:
   
   Transaction();
   Transaction(const Transaction&);
   virtual ~Transaction();
   //set data for moie and media type
   virtual bool setData(string, VideoStoreItem*, Customer*);
   virtual void display() const; //display mediatype and transactiontype
   virtual Transaction* create(); //create new transaction object

   string getMediaTye(); //Get type of media
   string getTransType(); //default transType is transaction
   VideoStoreItem* getItem() const; //Pointer to VideoStoreItem 

protected:
   string transactiontype;
   string mediaType;
   VideoStoreItem* theItem;  
};
#endif
