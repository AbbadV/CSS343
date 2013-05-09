/*
 * bintree.h
 * Shane Honanie
 * 3/6/2012
 * 1164606
 * Lab 4
 * 
 * bintree.h contains all the declarations of functions and data members needed 
 * to create, modify,  and destroy a BST. A nested struct which holds 
 * pointers to VieoStoreItem and left/right ancestors. 
 *
 */
#ifndef BINTREE_H
#define BINTREE_H
#include "videostoreitem.h"

class BinTree 
{ 
   //Overloaded << operator
   //Displays contents of entire BST inorder
   friend ostream& operator<<(ostream&, const BinTree&);
   struct Node; 

public:
   BinTree(); // constructor
   BinTree(const BinTree&); // copy constructor
   ~BinTree(); // destructor, calls makeEmpty

   //Functions used to modify BST
   bool insert(VideoStoreItem*,const int);
   bool isEmpty() const; // true if tree is empty, otherwise false
   void makeEmpty(); // make the tree empty so isEmpty returns true 
   bool retrieve(const VideoStoreItem& dataItem, VideoStoreItem*& dataFound) const;
   void retrieveHelper(Node* curPtr, const VideoStoreItem & dataItem, VideoStoreItem*& dataFound) const;

   //Overloaded operators
  // BinTree& operator=(const BinTree&); 
 //  bool operator==(const BinTree&) const; 
 //  bool operator!=(const BinTree&) const;  
   
private:
   //Struct holds pointers to data and left/right ancestors
   struct Node
      {
         VideoStoreItem* theMovie; //Pointer to VideoStoreItem
         Node* leftChildPtr, *rightChildPtr; //Left/Right child pointers 
      };

   Node *root; // root of the tree
   
   // utility functions
   void inOrderDisplay(Node*) const; //Displays BST inorder
   bool isEqual(Node*, Node*) const; //Checks if two nodes equal
   void destroyTree(Node*&); //Destroy entire BST
};
#endif
