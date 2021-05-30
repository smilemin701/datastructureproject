#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <list>
#include "BFS_path.h"

using namespace std;
//this is for betweeness centrality algorithm
// efficient  = O(V+E)
// it needs to pass the undirected graph

void BFS::BFS_algorithm(vector<vector<int>> adList, int src, int num_nodes){

    //adjacent nodes
    list<int> adNodes;
    //initialize all the vector lists
    for(int i = 0; i < num_nodes; i++) {
        predecessor.push_back(-1);
        visited.push_back(false);
        dist.push_back(INT_MAX);
    }

    visited[src] = true;
    dist[src] = 0;
    adNodes.push_back(src);

    while(!adNodes.empty()) {
        int u = adNodes.front();
        adNodes.pop_front();
        for (unsigned i = 0; i < adList[u].size(); i++) {
            //visting vertex
            int visitingV = adList[u][i];
            
            if(visitingV == -1) {
                continue;
            }
            if (!visited[visitingV]) {
                //add one as the graph is unweighted
                dist[visitingV] = dist[u] + 1;
                predecessor[visitingV] = u;
                //store all the adjacent nodes
                adNodes.push_back(visitingV);
                visited[visitingV] = true;
 

            }
        }

    }



}

BFS::~BFS() {
    visited.clear();
    predecessor.clear();
    dist.clear();
}

