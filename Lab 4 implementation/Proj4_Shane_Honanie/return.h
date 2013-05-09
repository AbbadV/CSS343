/*
 * return.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * return.h contains all the declarations of functions and data members needed
 * to modify data and display a return object.
 * return inherits from transaction.
 */

#ifndef RETURN_H
#define RETURN_H
#include "videostoreitem.h"
#include "transaction.h"
using namespace std;
class Customer;
class Return : public Transaction
{
public:
   Return();
   Return(const Return&);
   virtual ~Return();
   //set data for return object
   virtual bool setData(string, VideoStoreItem*, Customer*);
   virtual void display() const; //display meditype and transactiontype
   virtual Transaction* create(); //create new return object
};
#endif
