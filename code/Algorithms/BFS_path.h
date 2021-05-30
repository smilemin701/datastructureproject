#pragma once
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
class BFS{
    private:

    public:
    void BFS_algorithm(vector<vector<int>> adList, int src, int num_nodes);
    ~BFS();
    vector<int> dist;
    vector<int> predecessor;
    vector<int> visited;
};