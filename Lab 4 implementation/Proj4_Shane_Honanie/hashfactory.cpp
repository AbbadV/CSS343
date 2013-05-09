/*
 * hashfactory.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * hashfactory.cpp contains all the implementations of functions needed to 
 * create new Transaction and VideoStoreItem objects. Also, returns string 
 * for a mediatype char.
 */
#include "hashfactory.h"

//-----------------------------------------------------------------------------
// HashFactory
// Default constructor: Create objects that will be used in has factory
HashFactory::HashFactory()
{
   initInventory();
   movieInventory[2] = new ClassicMovie();
   movieInventory[3] = new DramaMovie();
   movieInventory[5] = new ComedyMovie();

   transactionInventory[1] = new Borrow();
   transactionInventory[7] = new History();
   transactionInventory[17] = new Return();

   mediaType[3] = "DVD";
}

//-----------------------------------------------------------------------------
// ~HashFactory
// deconstructor: deletes and NULLS all transaction and VideoStoreItemObjects
HashFactory::~HashFactory()
{
   for (int i = 0; i < MAX_COMMANDS; i++)
   {
      if (movieInventory[i] != NULL)
         delete movieInventory[i];
         movieInventory[i] = NULL;

      if (transactionInventory[i] != NULL)
         delete transactionInventory[i];
         transactionInventory[i] = NULL;
   }
}

//-----------------------------------------------------------------------------
// initInventory
// intialize arrays of objects to default values which represent empty
void HashFactory::initInventory()
{
   for(int i = 0; i < MAX_COMMANDS; i++)
   {
      movieInventory[i] = NULL;
      transactionInventory[i] = NULL;
      mediaType[i] = "";
   }
}

//-----------------------------------------------------------------------------
// hash
// Takes char as parameter. Char should be between A-Z and determines which
// index in array to insert 0-26
int HashFactory::hash(char ch)
{
   return ch-'A';
}

//-----------------------------------------------------------------------------
// getSubscript
// Takes char as parameter and calls the hash function and returns int value
int HashFactory::getSubscript(char ch)
{
   return hash(ch);
}

//-----------------------------------------------------------------------------
// createMovie
// Takes a char and istream reference object as its parameter. Determines if
// subscript is valid and then creates the proper movie object. Returns
// NULL if none exists for subscript.
VideoStoreItem* HashFactory::createMovie(char ch, istream& infile)
{
   string temp; //used to temporarly store discarded text

   int subscript = hash(ch); //subscript to attempt to create object in factory
   if (movieInventory[subscript] == NULL) //Error: discard line
   {
      getline(infile, temp, '\n'); //Discard line
      return NULL;
   }
   else
      return movieInventory[subscript]->create(); //Create Movie Object
}

//-----------------------------------------------------------------------------
// createTransaction
// Takes a char and a istream reference object as its parameter. Determines if
// subscript is calid and then creates the proper transation object. Returns
// NULL if none exists for subscript.
Transaction* HashFactory::createTransaction(char ch, istream& infile2)
{
   string temp; //used to temporarly store discarded text

   int subscript = hash(ch); 
   if (transactionInventory[subscript] == NULL) //Error: discard line
   {
      getline(infile2, temp, '\n');
      return NULL;
   }
   else //Create Transaction Object
      return transactionInventory[subscript]->create(); 
}

//-----------------------------------------------------------------------------
// getMediaType
// Takes a char as its paramter and returns a string for the type of media. If 
// no media exists for that subscript, then empty string is returned.
string HashFactory::getMediaType(char ch)
{
   return mediaType[hash(ch)];
}
