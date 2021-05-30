#include "centrality.h"
#include "BFS_path.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>
#include <algorithm>


using namespace std;

/**
Returns the path between two nodes
*@param adjacencylist the adjacency list
*@param source the source node - where the path starts
*@param dest the destination node - where the arrow is pointing
*/
vector<int> Centrality::singleNode_findPath(vector< vector<int> > adjacencylist, int source, int dest) {
    //the source vertex itself stores -1 in its path.
    vector<int> singleNode_path;

    BFS bfs; 
    bfs.BFS_algorithm(adjacencylist, source, adjacencylist.size());
    vector<int> nodeVisited = bfs.predecessor;

    //if source node is the same as dest node, there is no path between them
    //path = -2 if they are source node;
    if (source == dest) {
        singleNode_path.push_back(-2);
        return singleNode_path;
    }
    int idx = dest;
    //the path vector is -1, if there is no path between source and destination nodes
    if (nodeVisited[idx] == -1) {
        singleNode_path.push_back(-1);  
        return singleNode_path;
    }

    while(idx != source) {
        idx = nodeVisited[idx];
        singleNode_path.push_back(idx);
    }

    reverse(singleNode_path.begin(), singleNode_path.end());
    return singleNode_path;
    // for example if the output is 8, 0, 1 for source = 8, dest = 2, (it does not show source code)
    // the path is 8 -> 0 -> 1 -> 2


}

/**
Returns the path between multiple nodes
*@param adjacencylist the adjacency list
*@param source the source node - where the path starts
*@param num_nodes the number of nodes in the path
*/
vector<vector<int>> Centrality::findPath(vector< vector<int> > adjacencylist, int source, int num_nodes) {
    vector<vector<int>> path;
    path.resize(num_nodes);
    for (int i = 0; i < num_nodes; i++) {
        vector<int> single_path = singleNode_findPath(adjacencylist, source, i);
        path[i] = single_path;
    }
    /*
    for(unsigned i = 0; i < path.size(); i++) {
        //displays entire path that has been travelled
        cout << "node: " << i << " path: ";
        for(unsigned j = 0; j < path[i].size(); j++) {
            cout << path[i][j] << ",";
        }
        cout<<endl;
        
    }
    */
    return path;
}

/**
Finds the centrality for a particular node
*@param a the adjacency list
*@param b the node we are finding centrality for
*@param c the number of nodes in the path
*/
int Centrality::findCentrality(vector< vector<int> > adjacencylist, int node, int num_nodes) {
    int score = 0;
    vector<vector<int>> path;
    //if reached node to find centrality for, continue
    for(int src = 0; src < num_nodes; src++) {
        if (src == node) {
            continue;
        }
        path = findPath(adjacencylist, src, num_nodes);

        for(unsigned j = 0; j < path.size(); j++) {
            if((int)j == src) {
                continue;
            }
            //increment centrality score if required node lies on path between other nodes
            for(int k = 0; k < path[j].size(); k++) {
                if (path[j][k] == node) {
                    score++;
                }
            }

        }
        
   
    }
    return score/2;
    
}

//u != v, != node that trying to find centrality






