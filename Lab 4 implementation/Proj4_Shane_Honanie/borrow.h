/*
 * borrow.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * borrow.h contains all the declarations of functions and data members needed
 * to modify data and display a borrow object.
 * borrow inherits from transaction.
 */

#ifndef BORROW_H
#define BORROW_H
#include <iostream>
#include "videostoreitem.h"
#include "transaction.h"
using namespace std;
class Customer; //forward declaration
class Borrow : public Transaction
{
public:
   Borrow();
   Borrow(const Borrow&);
   virtual ~Borrow();
   //set data data members inherited from Transaction
   virtual bool setData(string, VideoStoreItem*, Customer*);
   virtual void display() const; //display mediatype and transactiontype
   virtual Transaction* create(); //Create Borrow object
};
#endif
