#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <list>

using namespace std;
class AdjacencyList{
    private:
    map< int, vector<int> > map_;
    //this is the map containg head as integer and edges connected to head as vector list.


    public:
    /**
    * Inserts vertex at the root node
    * @param head the head of the node
    * @param nodes number of nodes that are connected to the root node
    * 
    * For example in a graph 3 -> 2 -> 1 (this means edge 3 is connected to edge 2 and 1), head is 3.
    * and nodes connected to head will be node 1 and 2.
    * */
    void insertVertex(int head, int nodes); 

    /**
    * Creates an directed adjacency list named as the input filename. This list goes through the parsing.
    * @param fileName the name of the desired adjacency list
    * */
    void createdMap_directed(string filename);

    /**
    * This function goes through the map and creates the directed adjacency list in the form of a nested vector.
    * @param filename the name of the map which is to be converted to an adjacency list
    * */
    void createdAdjacencyList_directed(string filename);


    void createdMap_undirected(string fileName);

    void createdAdjacencyList_undirected(string filename);

    ~AdjacencyList();


    vector< vector<int> > adList;
    int size;
    
    

};
