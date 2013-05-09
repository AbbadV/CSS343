/*
 * customer.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * customer.h holds all relavent information for the customer. This includes
 * information used to identify a customer, handle rental information, handle
 * transaction information, and handle history information.
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "movie.h"
#include <iostream>
#include "transaction.h"
//#include "borrow.h"
//#include "return.h"
#include <string>
#include <vector>
using namespace std;
//class Transaction;
class Customer 
{
public:
   Customer();
   Customer(istream&);
   ~Customer();
   Customer(const Customer&);
   
   void setData(istream&); //set the customers data
   void displayAllHistory() const; //Displays all of the customers history
   void addTransaction(Transaction); //Add transaction to customer account
   int getCustomerID() const; //Return ID of customer
   string getFirstName() const; //get function for first name
   string getLastName() const; //get function for last name
   virtual bool operator==(const Customer&) const;
   virtual bool operator!=(const Customer&) const;

private:
   string firstName, lastName; //Name of Customer
   int customerID; //Customer ID
   vector<Transaction>transactionHistory; //Transaction History
};
#endif
