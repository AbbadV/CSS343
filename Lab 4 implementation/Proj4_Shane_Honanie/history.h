/*
 * history.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * history.h purpose is to display all of the customers history if it is passed
 * a non-null customer object
 */

#ifndef HISTORY_H
#define HISTORY_H
#include <iostream>
#include "videostoreitem.h"
#include "transaction.h"
using namespace std;
class Customer;
class History : public Transaction
{  
public: 
   History();
   History(const History&);
   virtual ~History();
   //set data displays customers history
   virtual bool setData(string, VideoStoreItem*, Customer*);
   virtual Transaction* create(); //create new history object
};
#endif
