/*
 * customer.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * customer.cpp holds all relavent information for the customer. This includes
 * information used to identify a customer, handle rental information, handle
 * transaction information, and handle history information.
 */
#include "customer.h"

//-----------------------------------------------------------------------------
// Customer
// Default constructor: sets data members to default values
Customer::Customer()
   :customerID(0), firstName(""), lastName("")
{
   transactionHistory.reserve(10);
}

//-----------------------------------------------------------------------------
// Customer
// Default constructor: sets data members to default values
Customer::Customer(istream& infile)
{
   setData(infile);
}

Customer::Customer(const Customer& rhs)
{
   customerID = rhs.customerID;
   firstName = rhs.firstName;
   lastName = rhs.lastName;
}
//-----------------------------------------------------------------------------
// ~Customer
// deconstructor: deletes all the transaction pointers from the vector
Customer::~Customer()
{
   for (int i = 0; i < (int)transactionHistory.size(); i++)
   {
     // delete transactionHistory[i];
    //  transactionHistory[i] = NULL; //Delete transaction
   }
}

//-----------------------------------------------------------------------------
// setData
// Takes istream referance as parameter and sets the customer information.
void Customer::setData(istream& infile)
{
   infile >> customerID; //read customer ID number
   if (infile.eof()) return;

   infile.get();
   infile >> lastName; //read last name

   infile.get();
   infile >> firstName; //read firstname
}

//-----------------------------------------------------------------------------
// getCustomerID
// return the ID of the customer
int Customer::getCustomerID() const
{
   return customerID;
}

//-----------------------------------------------------------------------------
// getFirstName
// return the first name of the customer
string Customer::getFirstName() const
{
   return firstName;
}

//-----------------------------------------------------------------------------
// getLastName
// return the last name of the customer
string Customer::getLastName() const
{
   return lastName;
}

//-----------------------------------------------------------------------------
// operator==
// Check if two customers are the same by comparing customerID which is
//unique for each customer
bool Customer::operator==(const Customer& rhs) const
{
   return (customerID == rhs.customerID);
}

//-----------------------------------------------------------------------------
// operator!=
// Check if two customers are the different by comparing customerID which is
//unique for each customer
bool Customer::operator!=(const Customer& rhs) const
{
   return (customerID != rhs.customerID);
}

//-----------------------------------------------------------------------------
// addTransaction
// Takes a pointer to a transaction object as its only parameter. Add the 
//transaction object to the vector which holds all transactions for one
// customer
void Customer::addTransaction(Transaction newTrans)
{
   transactionHistory.push_back(newTrans); //Add transaction pointer to vector
}

//-----------------------------------------------------------------------------
// displayAllHistory
// Displays all transactions for one customer as well as the customers info
void Customer::displayAllHistory() const
{
   cout << "   *** Customer ID = " << customerID << " " << lastName << " " 
      << firstName << endl;
   if (transactionHistory.size() > 0)
   {
      for(int i = 0; i < (int)transactionHistory.size(); i++)
      {
         transactionHistory[i].display();
         transactionHistory[i].getItem()->display();
      }
      cout << endl;
   }
   else
      cout << "No Customer History" << endl << endl;
}
