#include <fstream>
#include <iostream>
#include "nodedata.h"

using namespace std;

struct EdgeNode; // forward reference for the compiler

struct GraphNode 
{ // structs used for simplicity, use classes if desired
   EdgeNode* edgeHead; // head of the list of edges
   NodeData* data; //Contains description
   bool visited; //flag to signal if visited
};

struct EdgeNode 
{
   int adjGraphNode; // subscript of the adjacent graph node
   EdgeNode* nextEdge; //The next node
};

class GraphL 
{
public:
   GraphL();
   ~GraphL();
   void insert(int,int); //insert a Node/Edge
   void buildGraph(ifstream&); //Build the Graph from txt file
   void displayGraph(); //Display DFS graph
   void depthFirstSearch(); //Initiate the DFS algorithm
   void dfs(int); //Recursive method to find DFS
   void initArrayVisited(); //Set all visited to false

private:
   GraphNode* adjList; // array of GraphNodes
   int sizeOfArray; //Size of current array
   void removeNode(int); //Remove First Node at specified index

};
