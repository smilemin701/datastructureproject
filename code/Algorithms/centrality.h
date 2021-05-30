#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include "dijkstra.h"

using namespace std;

class Centrality{

    private:

    public:
    /**
    Returns the path between two nodes
    *@param a the adjacency list
    *@param b the source node - where the path starts
    *@param c the destination node - where the arrow is pointing
    */
    vector<int> singleNode_findPath(vector< vector<int> > adjacencylist, int source, int dest);

    /**
    Returns the path between multiple nodes
    *@param a the adjacency list
    *@param b the source node - where the path starts
    *@param c the number of nodes in the path
    */
    vector<vector<int>> findPath(vector< vector<int> > adjacencylist, int source, int num_nodes);

    /**
    Finds the centrality for a particular node
    *@param a the adjacency list
    *@param b the node we are finding centrality for
    *@param c the number of nodes in the path
    */
    int findCentrality(vector< vector<int> > adjacencylist, int node, int num_nodes);
    

   
};