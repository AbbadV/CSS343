/*
 * bintree.cpp
 * Shane Honanie
 * 1/202012
 * 1164606
 * Lab 2
 * 
 * bintree.cpp contains all the implementations of functions and data members
 * needed to create, modify, compare, and destroy a BST. Also, provded are
 * functions to build array of NodeData* from the BST or turn BST into
 * an array of NodeData*
 *
 * BinTree is not tied to any particular data type. It is assumed the user will
 * provide implementation for NodeData which will determine the data to be
 * acted upon. NodeData must have proper comparison operators to
 * determine order of data in BST. NodeData will also need a member called
 * data and a copy constructor.
 */

#include "bintree.h"

//----------------------------------------------------------------------------
// BinTree
// Default constructor:  No parameters, creates empty BST with root as NULL

BinTree::BinTree()
   :root(NULL)
{ }

//----------------------------------------------------------------------------
// BinTree
// Copy constructor: Takes a reference to a BinTree object as its 
// parameter, then creates an exact (deep) copy.

BinTree::BinTree(const BinTree& tree)
{
   copyTree(tree.root, root); 
}

//----------------------------------------------------------------------------
// ~BinTree
// Destructor: Calls makeEmpty to destroy the entire BST

BinTree::~BinTree()
{
   makeEmpty(); 
}

//----------------------------------------------------------------------------
// isEmpty
// Returns whether the BST is empty

bool BinTree::isEmpty() const
{
   return (root == NULL);
}

//----------------------------------------------------------------------------
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

		delete treePtr->data; //delete NodeData
      treePtr->data = NULL;
		delete treePtr; //Delete Node
      treePtr = NULL;
   }
}


//----------------------------------------------------------------------------
// operator=
// overloaded =: Make LHS become an exact (deep) copy of RHS BinTree object

BinTree& BinTree::operator=(const BinTree& rhs)
{
   if (this != &rhs)
   { 
      destroyTree(root);  // deallocate left-hand side
      copyTree(rhs.root, root);  // copy right-hand side
   }
   return *this;
}

//----------------------------------------------------------------------------
// operator==
// overloaded ==: Return true if two BST have same structure and data
// Uses is Equal as a helper for the recursive part

bool BinTree::operator==(const BinTree& rhs) const
{
   if(root == NULL && rhs.root == NULL) //Both are empty BST
      return true;
   else
      return isEqual(root, rhs.root); //Else compare recursively
}

bool BinTree::isEqual(Node* left, Node* right) const
{

   //Check whether the node data is the same
   //Safeguard against crash from comparison of empty BST, checks if NULL
  if ((left != NULL && right != NULL) && (*left->data == *right->data))  
     return true;

  //Return false when reached the end
  if ((left == NULL) || (right == NULL))  
     return false;

  //Check data and recursively search tree
  return ((left->data == right->data) && isEqual(left->leftChildPtr,  right->leftChildPtr ) && isEqual (left->rightChildPtr, right->rightChildPtr));
} 

//----------------------------------------------------------------------------
// operator!=
// overloaded !=: Return true if two BST do NOT have same structure and data

bool BinTree::operator!=(const BinTree& rhs) const
{
   return !(*this == rhs);
}

//----------------------------------------------------------------------------
// insert
// Inserts a new Node* into BST and makes that its data ptr, point to
// a NodeData*
// Code used with permission from Dr. Carol Zander, with slight modification

bool BinTree::insert(NodeData* dataptr) 
{
   Node* ptr = new Node;    // exception is thrown if memory is not allocated
   ptr->data = dataptr; //Link to current NodeData
   dataptr = NULL; //Disconnect
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
         if (*ptr->data == *current->data) //Duplicate found, dont allow insert
         {	
            delete ptr; //Handle duplicate properly
            ptr = NULL;
            return false;
         }
         else if (*ptr->data < *current->data) 
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
            if (current->rightChildPtr == NULL) 
            {             // at leaf, insert right
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

//----------------------------------------------------------------------------
// retrieve
// Returns true if dataItem is found in BST and sets dataFound to pointer
// to the location found. Uses retrieveHelper as a helper for recursive part.

bool BinTree::retrieve(const NodeData & dataItem, NodeData*& dataFound) const
{
   retrieveHelper(root, dataItem, dataFound);

   if (dataFound != NULL) //Check is dataFound was changed
      return true;
   else 
      return false; //If dataFound was not found then return false
}

void BinTree::retrieveHelper(Node* curPtr, const NodeData & dataItem, NodeData*& dataFound) const
{
   if (curPtr == NULL) //Not Found
      dataFound = NULL;

   else if (dataItem == *curPtr->data) //Item Found
   {
      dataFound = curPtr->data;
   }
   else if(dataItem < *curPtr->data) //Check left
   {
      retrieveHelper(curPtr->leftChildPtr, dataItem, dataFound);
   }
   else //Check right
   {
      retrieveHelper(curPtr->rightChildPtr, dataItem, dataFound);
   }
}

//----------------------------------------------------------------------------
// copyTree
// Utility function that makes an exact copy of the BST
// Code used from Frank Carrano, with permission and slight modification

void BinTree::copyTree(Node *treePtr, Node *& newTreePtr) const
{
   // preorder traversal
   if (treePtr != NULL) // copy node
   {  
      //Create new Node object for copy
      newTreePtr = new Node; 
      //Create new NodeData* object for copy and use existing data
      NodeData *temp = new NodeData(*treePtr->data); 
      newTreePtr->data = temp; //set data to be the same
      //go left in BST
      copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
      //go right in BST
      copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
   }
   else
   {
      newTreePtr = NULL;  // copy empty tree
   }
}


//---------------------------------------------------------------------------
// displaySideways 
// Displays a binary tree as though you are viewing it from the side
// hard coded displaying to standard output.
// Code from Dr. Carol Zander, used with permission

void BinTree::displaySideways() const 
{
   sideways(root, 0);
}

void BinTree::sideways(Node* current, int level) const 
{
   if (current != NULL) {
      level++;
      sideways(current->rightChildPtr, level);

      // indent for readability, 4 spaces per depth level 
      for(int i = level; i >= 0; i--) {
          cout << "    ";
      }

      cout << *current->data << endl;      // display data
      sideways(current->leftChildPtr, level);
   }
}

//---------------------------------------------------------------------------
// getDepth
// Returns an int value that represents the depth of that dataItem in BST.
// Solves depth for general trees where depth 1 is at the root and every child
// down is 1 greater than the previous. Zero is returned if not found.

int BinTree::getDepth(const NodeData& dataItem) const
{
   int count = 1; //start at 1
   bool dataFound = false;
   Node *temp = root;

   if (isEmpty()) //Empty Tree, depth is zero
      return 0;

   while((temp!= NULL)) //Set temp to position of data in BST
   {
      if (dataItem == *temp->data) //Stop search when data found
      {
         dataFound = true;
         break;
      }
      else if(dataItem < *temp->data) //Search Left
      {
         temp = temp->leftChildPtr;
         count++; 
      }
      else 
      {
         temp = temp->rightChildPtr;  //Search Right
         count++; 
      }
   }

   if (!dataFound) //No data match, return 0
      return 0;

   return count;
}

//---------------------------------------------------------------------------
// bstreeToArray
// Traverse tree inorder and stores Nodedata* in tempArray. Then makeEmpty
// is called to leave the tree empty. Uses a helper  to detrmine location 
// to store data.

void BinTree::bstreeToArray(NodeData* tempArray[])
{
   bstreeToArrayHelper(root, tempArray);
   makeEmpty(); //Make BST empty
}

int BinTree::bstreeToArrayHelper(Node* curPtr, NodeData *tempArray[])
{
	if(curPtr == NULL) //No data
		return 0;

   //Set location of left
	int left = bstreeToArrayHelper(curPtr->leftChildPtr, tempArray);

   NodeData *temp; 
   temp = curPtr->data; // save the pointer to NodeData object to temp
   curPtr->data = NULL; // disconnect NodeData from Node
   *(tempArray + left) = temp; //tempArray points to temp
   temp = NULL; //Disconnect 
   
   //set location of right
	int right = bstreeToArrayHelper(curPtr->rightChildPtr, tempArray + left + 1);
 
	return left + right + 1; //Return position
}

//---------------------------------------------------------------------------
// arrayToBSTree
// Takes the NodeData* in tempArray and uses that data build a BST. Leaves
// tempArray filled with NULLS. Uses a helper funtion.
// ARRAYSIZE hardcoded as size of 100 here and in lab2.cpp
// Must know size of array to use this function

void BinTree::arrayToBSTree(NodeData* tempArray[]) 
{
   int high = 0;

   for(int i = 0; i < 100; i++) //Count how many indexs of array are used
   {
      if (tempArray[i] != NULL)
         high++;
      else
         tempArray[i] = NULL;
   }

   //Recursively call helper function to perform calculations
   arrayToBSTreeHelper(tempArray, root, 0, high-1); 
}

void BinTree::arrayToBSTreeHelper(NodeData* tempArray[], const Node* curPtr, int low, int high) 
{
   if (low > high) //end
     curPtr = NULL;
   else
   {
      int root = (low + high) / 2; //Location of data to insert recursively at root

      NodeData *temp;
      temp = tempArray[root]; //set temp to point to NodeData* in array
      tempArray[root] = NULL; //disconnect tempArray from the Nodedata

      insert(temp); //insert NodeData to BST

      //check left array
      arrayToBSTreeHelper(tempArray, curPtr, low, root-1); 
      //check right array
      arrayToBSTreeHelper(tempArray, curPtr, root+1, high);
   }
}
 
//---------------------------------------------------------------------------
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
   if (curPtr != NULL) //Traverse inorder and print data
   {  
      inOrderDisplay(curPtr->leftChildPtr);
      cout <<*curPtr->data << " ";
      inOrderDisplay(curPtr->rightChildPtr);
   }
}
