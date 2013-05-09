/*
 * bintree.h
 * Shane Honanie
 * 1/20/2012
 * 1164606
 * Lab 2
 * 
 * bintree.h contains all the declarations of functions and data members needed 
 * to create, modify, compare, and destroy a BST. A nested struct which holds 
 * pointers to data and left/right ancestors. Also, provded are
 * functions to build array of NodeData* from the BST or turn BST into
 * an array of NodeData*
 *
 * BinTree is not tied to any particular data type. It is assumed the user will
 * provide implementation for NodeData which will determine the data to be
 * acted upon. NodeData must have proper comparison operators overloaded to
 * determine order of data in BST. NodeData will also need a member called
 * data and a copy constructor.
 */

#include "nodedata.h"

class BinTree 
{ 
   //Overloaded << operator
   //Displays contents of entire BST inorder
   friend ostream& operator<<(ostream&, const BinTree&);

public:
   BinTree(); // constructor
   BinTree(const BinTree&); // copy constructor
   ~BinTree(); // destructor, calls makeEmpty

   //Functions used to modify BST
   bool insert(NodeData*);
   bool retrieve(const NodeData &, NodeData*&) const;
   int getDepth(const NodeData &) const; //Find depth of data in BST
   bool isEmpty() const; // true if tree is empty, otherwise false
   void makeEmpty(); // make the tree empty so isEmpty returns true 
   void displaySideways() const; // provided, displays the tree sideways  
   void bstreeToArray(NodeData* []); //Puts BST into array of NodeData*
   void arrayToBSTree(NodeData* []); //Puts NodeData* array into BST

   //Overloaded operators
   BinTree& operator=(const BinTree&); 
   bool operator==(const BinTree&) const; 
   bool operator!=(const BinTree&) const;  
   
private:

   //Struct holds pointers to data and left/right ancestors
   struct Node
      {
         NodeData* data; //Pointer to data contained in NodeData
         Node* leftChildPtr, *rightChildPtr; //Left/Right child pointers 
      };

   Node *root; // root of the tree
   
   // utility functions
   void inOrderDisplay(Node*) const; //Displays BST inorder
   bool isEqual(Node*, Node*) const; //Checks if two nodes equal
   void sideways(Node*, int) const; // provided, helper for displaySideways()
   int bstreeToArrayHelper(Node*, NodeData* []); //bstToArray helper
   void retrieveHelper(Node*, const NodeData&, NodeData*&) const; //Helper
   void arrayToBSTreeHelper(NodeData* [], const Node*, int, int);
   void copyTree(Node*, Node*&) const; //Make a copy of BST
   void destroyTree(Node*&); //Destroy entire BST
};
