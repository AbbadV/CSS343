#include "graphl.h"
#include "iomanip"

//---------------------------------------------------------------------------
// GraphL
// default constructor: Creates an empty graph and sets the sizeOfArray to 0

GraphL::GraphL()
   : sizeOfArray(0)
{}

//---------------------------------------------------------------------------
// GraphL
// destructor: Deletes all the NodeData, EdgeNode, and GraphNode data

GraphL::~GraphL()
{
   if (sizeOfArray > 0)
   {
      for(int i = 1; i < sizeOfArray+1 ;i++)
      {
         while (adjList[i].edgeHead != NULL) //Remove 1st node until empty
            removeNode(i);

         delete adjList[i].data;
         adjList[i].data = NULL;
      }

      sizeOfArray = 0;
      delete [] adjList;
      adjList = NULL;
   }
}

//---------------------------------------------------------------------------
// insert
// Takes two int's as arguements which represent the originNode and 
// adjacentNode index's. Then insert then into the array of linked lists
// in the proper position.

void GraphL::insert(int originNode, int adjacentNode)
{
   EdgeNode *newEdgeNode = new EdgeNode; //Create EdgeNode
   newEdgeNode->adjGraphNode = adjacentNode; //set to adjacent node

   if (adjList[originNode].edgeHead == NULL) //Empty List
   {
      newEdgeNode->nextEdge = NULL; //disconnect head from old edge
      adjList[originNode].edgeHead = newEdgeNode;  //set to new edge
   }
   else //Non-Empty
   {
      //connect to old edge
      newEdgeNode->nextEdge = adjList[originNode].edgeHead; 
      //disconnect head from old edge and set to new edge
      adjList[originNode].edgeHead = newEdgeNode; 
   }
}

//---------------------------------------------------------------------------
// buildGraph
// Takes a .txt file as its parameter with proper formtting to create
// the graph. See Description header for correct format of .txt file

void GraphL::buildGraph(ifstream& infile) 
{   
   int originNode = 0, adjacentNode = 0;

   infile >> sizeOfArray; //set Size of Array 
   infile.get();

   if (sizeOfArray > 0)
   {   
      adjList = new GraphNode[sizeOfArray+1];

      //Assign NodeData's data to GraphNode and set to default values
      for(int i = 1; i < sizeOfArray+1; i++) 
      {
         adjList[i].data = new NodeData;
         adjList[i].data->setData(infile);
         adjList[i].visited = false;
         adjList[i].edgeHead = NULL;
      }

      for (;;) 
      {
         infile >> originNode >> adjacentNode;

         if (infile.eof()) break;           // no more lines of data

         if (originNode == 0 || adjacentNode == 0) //End of data
            break;  

         insert(originNode, adjacentNode); //Insert into linked list
      }
   }
}

//---------------------------------------------------------------------------
// depthFirstSearch
// From 1 to n, calls dfs to performs Depth First Search

void GraphL::depthFirstSearch()
{
   initArrayVisited(); //Set all visited to false to ensure dfs will work

   cout << "Depth-first ordering: ";

   for(int v = 1; v < sizeOfArray; v++) //From 1 to n, walk through array
   {
      if(adjList[v].visited == false) //Check if visited
      {
         dfs(v); //Call dfs to perform depth first search
      }
   }

   cout << endl;
}


//---------------------------------------------------------------------------
// dfs
// Takes an int as parameter which represents the index of the source node.
// Outputs the source node and recursively calls itself whith the adjacent 
// node as its parameter.

void GraphL::dfs(int v)
{
   adjList[v].visited = true; //mark v
   cout << v << " "; 

   for(EdgeNode *tempEdge = adjList[v].edgeHead; tempEdge != NULL; 
      tempEdge = tempEdge->nextEdge)
   {
      //Check if adjacent node is visited, then go to if not
      if (adjList[tempEdge->adjGraphNode].visited == false) 
      {
         dfs(tempEdge->adjGraphNode); //go to adjacent node
      }
   }
}

//---------------------------------------------------------------------------
// displayGraph
// Displays the Name of the Node, the edge's source and adjacent node.

void GraphL::displayGraph()
{
   cout << "Graph:" << endl;

   for(int i = 1; i < sizeOfArray+1; i++) 
   {
      cout << left << "Node " << setw(15) << i;
      cout << setw(50) << *adjList[i].data << endl; //Output Description

      if (adjList[i].edgeHead != NULL)
      {
         EdgeNode *temp; //used to traverse nodes
         temp = adjList[i].edgeHead; //start at head

         while (temp != NULL) 
         {
            cout << "      edge " << i << " " << temp->adjGraphNode << endl;

            temp = temp->nextEdge; //go to next node
         }
      }
   }
}

//---------------------------------------------------------------------------
// removeNode
// Remove the first node in list from the specified index

void GraphL::removeNode(int index)
{
   EdgeNode *cur;

   //Disconnect the first Node in list
   cur = adjList[index].edgeHead;
   adjList[index].edgeHead = adjList[index].edgeHead->nextEdge;

   //Return node to system
   cur->nextEdge = NULL;
   delete cur;
   cur = NULL;
}

//---------------------------------------------------------------------------
// initArrayVisited
// Sets all values in the array to false.

void GraphL::initArrayVisited()
{
   for (int i = 1;i < sizeOfArray; i++)
   {
      adjList[i].visited = false;
   }
}
