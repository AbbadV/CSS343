/*
 * businessmanager.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * businessmanager.cpp contains all the implementations of functions and data
 * members needed to create and modify customer accounts and transactions.
 * Also contains array on BinTree objects which hold Movie Objects by genre.
 * Can alo display all movie data for each genre and determine how many
 * copies are in and out. Reads all the data from file.
 * 
 */
#include "businessmanager.h"
      
//-----------------------------------------------------------------------------
// BusinessManager
// default constructor, set name to empty string
BusinessManager::BusinessManager()
   :businessName("")
{}

//-----------------------------------------------------------------------------
// BusinessManager
// constructor, set the name of business to string parameter
BusinessManager::BusinessManager(string nameIn)
   :businessName(nameIn)
{}

//-----------------------------------------------------------------------------
// ~BusinessManager
// Used to properly delete strings
BusinessManager::~BusinessManager()
{}

//-----------------------------------------------------------------------------
// createAccounts
// Takes an istream reference as parameter. Sets the data for the customers
void BusinessManager::createAccounts(istream& infile2)
{
   for(;;)
   {
      Customer* newCustomer = new Customer(); //create new customer object
      newCustomer->setData(infile2); //set customer data

      if (infile2.eof()) 
      {
         delete newCustomer; //delete if at end
         newCustomer = NULL;
         break;
      }
      //Assign customer Data to customer array
      customerAccounts[newCustomer->getCustomerID()] = *newCustomer;
      delete newCustomer; //delete after assignment
      newCustomer = NULL;
   }
}

//-----------------------------------------------------------------------------
// stockShelves
// Takes an istream reference as its parameter. inserts VideoStoreItem into
// an array of BST.
void BusinessManager::stockShelves(istream& infile)
{
   char movieCode = ' ';

   for(;;)
   {
      infile >> movieCode; // get media code

      if (infile.eof()) break; //check if at end

      //create new Video Store object using factory
      VideoStoreItem* newMoviePtr = factory.createMovie(movieCode, infile);


      if (newMoviePtr != NULL) //If media code not found then delete
      {
         newMoviePtr->setData(infile); //set movie data

         bool success = movieInventory[factory.getSubscript(movieCode)].insert(newMoviePtr, MAX_COPIES);
         if (!success)
            delete newMoviePtr; //Not able to insert
      }
      
      newMoviePtr = NULL; //Null and delete pointer
      delete newMoviePtr;
   }
}

//-----------------------------------------------------------------------------
// readCommans
// read the commands from a file which determine transactions and display.
// B- Borrow, R - Return, S - Dislay all categories of business, H - display
// customer data.
void BusinessManager::readCommands(istream& infile3)
{
   char actionCode = ' ';
   char movieCode = ' ';
   char mediaCode = ' ';
   int customerID = 0;
   bool found = false;
   string mediaType = "";
   char EOL = '\n'; //end of line
   VideoStoreItem* movieLocation = NULL;
   Customer* tempCustomer = NULL;
   VideoStoreItem *tempMoviePtr = NULL;

   for(;;)
   {
      infile3 >> actionCode;
      if (infile3.eof()) break; //Check if end of input

      if(actionCode == 'S')
      {
         display();
         actionCode = ' ';
      }
      else if(infile3.get() == EOL) //Do I need FIX
      {
         actionCode = ' ';
      }
      else
      {  //create trans object
         Transaction* newTransactionPtr = 
            factory.createTransaction(actionCode, infile3); 

         if (newTransactionPtr != NULL) //If no actionCode exists
         {
            infile3 >> customerID;
            if (infile3.eof()) break; //Check if end of input

            if(customerFound(customerID)) //Check if customer exists
            {
               tempCustomer = &customerAccounts[customerID];
               //set data
               bool isHistory = newTransactionPtr->setData
                  (mediaType, movieLocation, tempCustomer);

               //If NOT EOL or is display history
               if(infile3.get() != EOL && isHistory)
               {
                  infile3 >> mediaCode;
                  //get media code from factory
                  mediaType = factory.getMediaType(mediaCode);

                  if(mediaType != "")
                  {
                     infile3 >> movieCode; //get movie genre

                     //create new movie object used for comaprison
                     tempMoviePtr = factory.createMovie(movieCode, infile3);

                     if (tempMoviePtr != NULL)
                     {
                        tempMoviePtr->setData2(infile3);
                         //Retrieve VideoStoreItem* in BST
                        found = movieInventory[factory.getSubscript(movieCode)]
                        .retrieve(*tempMoviePtr, movieLocation);

                        if(found == false) //if movie is not found
                        {
                           cout << "ERROR: Invalid Movie " 
                              << tempMoviePtr->getItem() << endl;
                        }
                        delete tempMoviePtr; //Delete after using as search key
                        tempMoviePtr = NULL;

                        bool found2 = newTransactionPtr->setData(mediaType, 
                           movieLocation, tempCustomer);

                        //check if movie found and mediatype exists
                        if (found && mediaType != "") 
                        {
                           //Add transaction to customer account
                           customerAccounts[customerID].addTransaction
                              (*newTransactionPtr);
                        }
                        delete newTransactionPtr;
                        newTransactionPtr = NULL;
                     }
                     else
                     {
                        cout << "ERROR: Genre: " << movieCode << " not found" 
                           << endl;

                        //Check if transaction was deleted
                        if(newTransactionPtr != NULL)
                        {
                           delete newTransactionPtr;
                           newTransactionPtr = NULL;
                        }
                        //discard rest of line
                        string temp;
                        getline(infile3, temp, EOL);
                        delete tempMoviePtr;
                        tempMoviePtr = NULL; 
                     }

                  }
                  else
                  {
                     //discard rest of line
                     string temp;
                     getline(infile3, temp, EOL);

                     cout << "ERROR: Invalid Media Code: " 
                        << mediaCode << endl;

                     if (newTransactionPtr != NULL)
                        delete newTransactionPtr;
                     newTransactionPtr = NULL;
                  }

               }
               else
               {
                  if (newTransactionPtr != NULL)
                     delete newTransactionPtr;
                  newTransactionPtr = NULL;
               }
            }
            else
            {
               cout << "ERROR: Customer ID: " << customerID 
                  << " not found" << endl;

               if (newTransactionPtr != NULL)
                  delete newTransactionPtr;
               newTransactionPtr = NULL;

               //discard rest of line
               string temp;
               getline(infile3, temp, EOL);
            }
         }
         else
         {
            cout << "ERROR: Action Code: " << actionCode 
               << " not found" << endl;

            if (newTransactionPtr != NULL)
               delete newTransactionPtr;
            newTransactionPtr = NULL;
         }
      }
   found = false;
   customerID = 0;
   movieLocation = NULL;
   tempCustomer = NULL;
   tempMoviePtr = NULL;
   }  
} 

//-----------------------------------------------------------------------------
// display
// display the information of the business including name of business and
// categories of business such as movie genres
void BusinessManager::display() const
{
   //Business Header
   if(businessName != "")
   {
      cout << "--------------------------------------------------------------" 
         << endl;
      cout << "Inventory for " << businessName << endl;
      cout << "--------------------------------------------------------------" 
         << endl;
   }

   //Display al categories of business that arent empty and exist
   for (int i = 0; i < MAX_COMMANDS; i++)
   {
      if (!movieInventory[i].isEmpty())
      {
         cout << movieInventory[i]; //Display all movies
      }
   }
}

//-----------------------------------------------------------------------------
// getBusinessName
// return name of the business
string BusinessManager::getBusinessName() const
{
   return businessName;
}

//-----------------------------------------------------------------------------
// customer
// takes an int as its parameter and returns bool value wether the customer
//exists in the database.
bool BusinessManager::customerFound(int numberIn) const
{
	if(customerAccounts[numberIn].getCustomerID() == 0) //Customer not found
		return false;
	else
		return true;
}

