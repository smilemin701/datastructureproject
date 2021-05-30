#pragma once	
#include <iostream>	
#include <vector>	
#include <fstream>	
#include <string>	
#include <map>	

using namespace std;	

struct MinHeapNode{	
    int vertex;	
    int distance;	
};	

struct MinHeap{	
    int size;	
    int capacity;	
    int *pos;	
    struct MinHeapNode ** array;	
};	


class Dijkstra{	
    int basic();	

    private:	

    public:	

    struct MinHeapNode* newHeapNode(int vertex, int distance);

    /**
    *Creates a Min Heap
    * @param capacity size of the heap
    */
    struct MinHeap* makeHeap(int capacity);	

    /**	
    Swaps two of the nodes that are inside the Min Heap.	
    @param a ID of the first node you want to swap	
    @param b ID of the second node you want to swap	
    */  	
    void swap(struct MinHeapNode** v1, struct MinHeapNode** v2);	

    /**	
    * Update nodes' positions after executing the swap	
    * @param cnode node that is swapped	
    * @param index index of the position	
    */	
    void heapify(struct MinHeap* minHeap, int index);	

    /**	
    * Checks if the minheap is empty. If true, returns 1	
    * @param cnode node that is to be checked	
    * */    	
    int checkForEmpty(struct MinHeap* minHeap);	

    /**	
    * Finds the minimum node	
    * @param cnode heap from which minimum node is to be found	
    * */	
    struct MinHeapNode* findMin(struct MinHeap* minHeap);	

    /**	
    * Decreases distance of a given vertex	
    * @param cnode minheap	
    * @param name id of vertex	
    * @param distance initial distance	
    * */	
    void decreasedistance(struct MinHeap* minHeap, int v, int distance);	

    /**	
    * Checks if vertex is inside heap	
    * @param cnode minheap	
    * @param name given vertex to check	
    * */   	
    bool insideHeap(struct MinHeap * minHeap, int v);	

    /**	
    * Main algorithm to find shortest distance	
    * @param graph the adjacency list on which we want to run the algorithm on	
    * @param ver the place from which we want to calculate shortest distances	
    * */	
    void dijkstraAlgorithm(vector< vector<int> > adjacncylist, int source);	

    ~Dijkstra();

    //The predecessor
    //each index stores nodes that were visited previously for shortest path
    vector<int> nodesVisited;	
    //each index stores shortest distance from source node
    //for example distance[3] stores distance between node 3 and source node
    vector<int> distance;	

};