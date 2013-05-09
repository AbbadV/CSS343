#include "nodedata.h"

const int MAXNODES = 101; //101 since index 0 is not used

struct TableType 
{
   bool visited; // whether node has been visited
   int dist; // shortest distance from source known so far
   int path; // previous node in path of min dist
};
   
class GraphM 
{
   public:
      GraphM();
      void buildGraph(ifstream&); //insert all data
      void insertEdge(const int,const int, const int);  //insert cost 
      void findShortestPath(); //Perform Dijkstra's Algorithm
      void displayAll() const; //Display all data
      void display(const int,const int) const; //Display from/to node data
      void initArrayVisited(); //Set all value in array to not visited
      void getPath(const int,const int) const; //Print path from/to node
      void getPathData(const int, const int) const; //Print description's 
      int findNext(TableType [], int,int); //find smallest unmarked v

   private:    
      NodeData data[MAXNODES]; // data for graph nodes information
      int C[MAXNODES][MAXNODES]; // Cost array, the adjacency matrix
      int size; // number of nodes in the graph
      TableType T[MAXNODES][MAXNODES]; // stores visited, distance, path
      void removeEdge(const int,const int); //Remove cost
};
