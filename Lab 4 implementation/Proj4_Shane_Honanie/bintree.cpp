/*
 * bintree.cpp
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * bintree.cpp contains all the implementations of functions and data members
 * needed to create, modify, compare, and destroy a BST. Bintree was modified
 * specifically to hold and handle VideoStoreItemObjects.
 */

#include "bintree.h"
#include <iomanip>

//-----------------------------------------------------------------------------
// BinTree
// Default constructor:  No parameters, creates empty BST with root as NULL

BinTree::BinTree()
   :root(NULL)
{ }

//-----------------------------------------------------------------------------
// ~BinTree
// Destructor: Calls makeEmpty to destroy the entire BST

BinTree::~BinTree()
{
   if (root != NULL)
      makeEmpty(); 
}

//-----------------------------------------------------------------------------
// isEmpty
// Returns whether the BST is empty

bool BinTree::isEmpty() const
{
   return (root == NULL);
}

//-----------------------------------------------------------------------------
// makeEmpty
// Call destroyTree to destroy the BST. destroyTree is a helper with does the
// recursive work. destroyTree code is from Frank Caranno, used with 
// permission and slight modification

void BinTree::makeEmpty()
{
   destroyTree(root); //destroy entire BST
}

void BinTree::destroyTree(Node *& treePtr)
{
   // postorder traversal
   if (treePtr != NULL)
   {  
      destroyTree(treePtr->leftChildPtr); //destroy left
      destroyTree(treePtr->rightChildPtr); //destroy right

		delete treePtr->theMovie; //delete NodeData
      treePtr->theMovie = NULL;
		delete treePtr; //Delete Node
      treePtr = NULL;
   }
}

//-----------------------------------------------------------------------------
// operator!=
// overloaded !=: Return true if two BST do NOT have same structure and data

//bool BinTree::operator!=(const BinTree& rhs) const
//{
//   return !(*this == rhs);
//}

//-----------------------------------------------------------------------------
// insert
// Inserts a new Node* into BST and makes that its data ptr, point to
// a NodeData*
// Code used with permission from Dr. Carol Zander, with slight modification

bool BinTree::insert(VideoStoreItem* newMoviePtr,const int amountIn) 
{
   Node* ptr = new Node;    // exception is thrown if memory is not allocated
   ptr->theMovie = newMoviePtr; //Link to current NodeData
   ptr->theMovie->setMaxCopies(amountIn);
   newMoviePtr = NULL; //Disconnect
   ptr->leftChildPtr = ptr->rightChildPtr = NULL;
   if (isEmpty()) 
   {
      root = ptr; //Empty, set as root
   }
   else 
   {
      Node* current = root;
      bool inserted = false;

      // if data is less than current data, insert in left subtree,
      // otherwise insert in right subtree
      while (!inserted) 
      {
         if (*ptr->theMovie == *current->theMovie) //Duplicate, dont insert
         {	
            delete ptr; //Handle duplicate properly
            ptr = NULL;
            return false;
         }
         else if (*ptr->theMovie < *current->theMovie) 
         {
            if (current->leftChildPtr == NULL) // at leaf, insert left
            {            
               current->leftChildPtr = ptr;
               inserted = true;
            }
            else
               current = current->leftChildPtr;               // one step left
         }
         else {
            if (current->rightChildPtr == NULL) // at leaf, insert right
            {             
               current->rightChildPtr = ptr;
               inserted = true;
            }
            else
               current = current->rightChildPtr;              // one step right
         }
      }
   }
   return true;
}

bool BinTree::retrieve(const VideoStoreItem& dataItem, 
   VideoStoreItem*& dataFound) const
{
   retrieveHelper(root, dataItem, dataFound);

   if (dataFound != NULL) //Check is dataFound was changed
      return true;
   else 
      return false; //If dataFound was not found then return false
}

void BinTree::retrieveHelper(Node* curPtr, 
   const VideoStoreItem& dataItem, VideoStoreItem*& dataFound) const
{
   if (curPtr == NULL) //Not Found
      dataFound = NULL;

   else if (dataItem == *curPtr->theMovie) //Item Found
   {
      dataFound = curPtr->theMovie;
   }
   else if(dataItem < *curPtr->theMovie) //Check left
   {
      retrieveHelper(curPtr->leftChildPtr, dataItem, dataFound);
   }
   else //Check right
   {
      retrieveHelper(curPtr->rightChildPtr, dataItem, dataFound);
   }
}

//-----------------------------------------------------------------------------
// operator<<
// overloaded <<: Displays the data from BST inorder. Uses helper function
// inorderDisplay to recursively traverse tree and print data.

ostream& operator<<(ostream& output, const BinTree& bst)
{
   bst.inOrderDisplay(bst.root); //call inOrderDisplay
   output << endl;
   return output;
}

void BinTree::inOrderDisplay(Node *curPtr) const
{
   if (curPtr == root)
   {
      curPtr->theMovie->displayHeader();
   }

   if (curPtr != NULL) //Traverse inorder and print data
   {  
      inOrderDisplay(curPtr->leftChildPtr);
      cout << right << setw(3) << curPtr->theMovie->getAmountIn() 
         << setw(3) << curPtr->theMovie->getAmountOut() << " ";
      curPtr->theMovie->display();
      inOrderDisplay(curPtr->rightChildPtr);
   }
}
