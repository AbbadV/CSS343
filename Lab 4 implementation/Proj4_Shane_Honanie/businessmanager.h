/*
 * businessmanager.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * businessmanager.h contains all the declarations of functions and data
 * members needed to create and modify customer accounts and transactions.
 * Also contains array on BinTree objects which hold Movie Objects by genre.
 * Can alo display all movie data for each genre and determine how many
 * copies are in and out. Reads all the data from file.
 * 
 */

#ifndef BUSINESSMANAGER_H
#define BUSINESSMANAGER_H
#include "customer.h"
#include "bintree.h"
#include "movie.h"
#include "hashfactory.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
const int MAX_COPIES = 10; //Max of each VideoStoreItem
const int MAX_COMMANDS = 26; //Max Letters for Genre
const int MAX_ACCOUNTS = 10000; //Max Customer Accounts
   
class BusinessManager 
{
public:
   BusinessManager();
   BusinessManager(string);
   ~BusinessManager();
   BusinessManager(const BusinessManager&);
   
   void stockShelves(istream& ); //Add movies to inventory
   void createAccounts(istream& ); //Add customer accounts
   void readCommands(istream& ); //Perform commands 
   void display() const; //Display inventory (list of movies sorted by genre)
   bool customerFound(int) const;
   string getBusinessName() const;

private:
   Customer customerAccounts[MAX_ACCOUNTS]; //array of customer accounts
   //factory to create transaction and videostoreitem objects. 
   HashFactory factory; 
   BinTree movieInventory[MAX_COMMANDS];//array of movies by genre
   string businessName; //Name of the business
};
#endif
