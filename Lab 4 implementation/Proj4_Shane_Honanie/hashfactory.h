/*
 * hashfactory.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * hashfactory.h contains all the declarations of functions needed to create
 * new Transaction and VideoStoreItem objects. Also, returns string for a 
 * mediatype char.
 */

#ifndef HASHFACTORY_H
#define HASHFACTORY_H
#include <iostream>
#include <string>
#include "classicmovie.h"
#include "dramamovie.h"
#include "comedymovie.h"
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
class Movie;
class Transaction;

using namespace std;

class HashFactory
{
   public:
      HashFactory();
      ~HashFactory();

      VideoStoreItem* createMovie(char, istream&); //create new VideoStoreItem
      Transaction* createTransaction(char,istream&); //create new Transaction

      int getSubscript(char); //get array subscript from letter
      string getMediaType(char); //get mediatype from letter
      static const int MAX_COMMANDS = 26; //Max letters

   private:
      //Depending on the subscript returned from letter, factory will
      //create the specified object if it exists or return NULL
      VideoStoreItem* movieInventory[MAX_COMMANDS]; 
      Transaction* transactionInventory[MAX_COMMANDS];
      string mediaType[MAX_COMMANDS];

      int hash(char); //return int subscript from char
      void initInventory(); //set initial values in arrays
};
#endif
