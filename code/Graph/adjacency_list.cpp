//Add code here
#include "adjacency_list.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <list>

using namespace std;


/**
 * Inserts vertex at the root node
 * @param head the head of the node
 * @param nodes number of nodes that are connected to the root node
 * 
 * For example in a graph 3 -> 2 -> 1 (this means edge 3 is connected to edge 2 and 1), head is 3.
 * and nodes connected to head will be node 1 and 2.
 * */
void AdjacencyList::insertVertex(int head, int nodes) {
    //graph[head].push_back(nodes);
    adList[head].push_back(nodes);

}

/**
 * Creates an directed adjacency list named as the input filename. This list goes through the parsing.
 * @param fileName the name of the desired adjacency list
 * */
void AdjacencyList::createdMap_directed(const string fileName) {

   ifstream data(fileName);

    //divide the txt file into each line and store in vector named one_line
    vector<string> one_line;
    string line;
    if (data.is_open()) {
        while (getline(data, line)) {
            one_line.push_back(line);
        }
    }

    int head;
    //use loop to individually store the two numbers seperated by "tab"
    for(unsigned i = 0; i < one_line.size(); i++) {
        //parse the string in vector. String is in the form of "id [tab] id"
        string unpar = one_line[i];

        std::string delimiter = "	";
    
        size_t pos = 0;
        std::string token;

        //go through the while loop to find the nodes and insert them into the map. 
        while ((pos = unpar.find(delimiter)) != std::string::npos) {
            token = unpar.substr(0, pos);
            int intToken = stoi(token);
            head = intToken;
            unpar.erase(0, pos + delimiter.length());
           
        }
        int intToken = stoi(unpar);
        //insert the nodes in the header accordingly. 
        if (map_.find(head) == map_.end()) {
            vector <int> nodes;
            nodes.push_back(intToken);
            map_[head] = nodes;
 

        } else {
            map_[head].push_back(intToken);

        }

        //the graph is saved in map in form of map
    }
    size = head + 1;
}


/**
 * This function goes through the map and creates the directed adjacency list in the form of a nested vector.
 * @param filename the name of the map which is to be converted to an adjacency list
 * */
void AdjacencyList::createdAdjacencyList_directed(string filename) {
    createdMap_directed(filename);
    adList.resize(size);
    for(int i = 0; i < size; i++) {
        if(map_.find(i) != map_.end()) {
            adList[i] = map_[i];
        } else {
            adList[i].push_back(-1);
        }
    }
}


void AdjacencyList::createdMap_undirected(string fileName) {

   ifstream data(fileName);

    //divide the txt file into each line and store in vector named one_line
    vector<string> one_line;
    string line;
    if (data.is_open()) {
        while (getline(data, line)) {
            one_line.push_back(line);
        }
    }

    int head;
    //use loop to individually store the two numbers seperated by "tab"
    for(unsigned i = 0; i < one_line.size(); i++) {
        //parse the string in vector. String is in the form of "id [tab] id"
        string unpar = one_line[i];

        std::string delimiter = "	";
    
        size_t pos = 0;
        std::string token;

        //go through the while loop to find the nodes and insert them into the map. 
        while ((pos = unpar.find(delimiter)) != std::string::npos) {
            token = unpar.substr(0, pos);
            int intToken = stoi(token);
            head = intToken;
            unpar.erase(0, pos + delimiter.length());
           
        }
        int intToken = stoi(unpar);
        vector <int> nodes;
        //insert the nodes in the header accordingly. 
        if (map_.find(head) == map_.end()) {
            nodes.push_back(intToken);
            map_[head] = nodes;
            if(map_.find(intToken) == map_.end()) {
                vector <int> nodes1;
                nodes1.push_back(head);
                map_[intToken] = nodes1;
            } else {
                map_[intToken].push_back(head);
            }
 

        } else {
            map_[head].push_back(intToken);
            if(map_.find(intToken) == map_.end()) {
                vector <int> nodes1;
                nodes1.push_back(head);
                map_[intToken] = nodes1;
            } else {
                map_[intToken].push_back(head);
            }

        }

        //the graph is saved in map in form of map
    }
    size = head + 1;
}

void AdjacencyList::createdAdjacencyList_undirected(string filename) {
    createdMap_undirected(filename);
    adList.resize(size);
    for(int i = 0; i < size; i++) {
        if(map_.find(i) != map_.end()) {
            adList[i] = map_[i];
        } else {
            adList[i].push_back(-1);
        }
    }
}

AdjacencyList::~AdjacencyList(){
    adList.clear();
}