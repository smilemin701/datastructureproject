#include "dijkstra.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
 
using namespace std;
 

struct MinHeapNode* Dijkstra::newHeapNode(int v, int distance)
{
    struct MinHeapNode* heapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    heapNode -> vertex = v;
    heapNode -> distance = distance;
    return heapNode;
}
 
/**
*Creates a Min Heap
* @param size size of the heap
*/ 
struct MinHeap* Dijkstra::makeHeap(int size)
{
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap -> pos = (int *)malloc(size * sizeof(int));
    minHeap -> size = 0;
    minHeap -> size = size;
    minHeap -> array = (struct MinHeapNode**) malloc(size * sizeof(struct MinHeapNode*));
    return minHeap;
}
/**
Swaps two of the nodes that are inside the Min Heap.
*@param firstnode ID of the first node you want to swap
*@param secondnode ID of the second node you want to swap
*/
void Dijkstra::swap(struct MinHeapNode** firstnode, struct MinHeapNode** secondnode) {
    struct MinHeapNode* result = *firstnode;
    *firstnode = *secondnode;
    *secondnode = result;
}
/**
* Update nodes' positions after executing the swap
* @param cnode node that is swapped
* @param index index of the position
*/
void Dijkstra::heapify(struct MinHeap* cnode, int index) {
    int smaller;
    int oneside;
    int twoside;
    smaller = index;
    oneside = 2 * index + 1;
    twoside = 2 * index + 2;
    if (twoside < cnode -> size && cnode -> array[twoside] -> distance < cnode -> array[smaller]->distance ) {
      smaller = twoside;
    }
    if (oneside < cnode -> size && cnode -> array[oneside] -> distance < cnode -> array[smaller]->distance) {
        smaller = oneside;
    }
    if (smaller != index) {
        MinHeapNode *firstnode = cnode -> array[smaller];
        MinHeapNode *othernode = cnode -> array[index];
        cnode -> pos[firstnode -> vertex] = index;
        cnode -> pos[othernode -> vertex] = smaller;
        //Executes the swapping
        swap(&cnode -> array[smaller], &cnode -> array[index]);
        heapify(cnode, smaller);
    }
}
/**
* Checks if the minheap is empty. If true, returns 1
* @param cnode node that is to be checked
* */
int Dijkstra::checkForEmpty(struct MinHeap* cnode)
{
    return cnode -> size == 0;
}
/**
* Finds the minimum node
* @param cnode heap from which minimum node is to be found
* */
struct MinHeapNode* Dijkstra::findMin(struct MinHeap* cnode)
{
    if (checkForEmpty(cnode)) {
        return NULL;
    }
    struct MinHeapNode* toreturn = cnode -> array[0];
    // Replace current node with recent node
    struct MinHeapNode* finalnode = cnode -> array[cnode -> size - 1];
    cnode -> array[0] = finalnode;
    // Changes position of recent node
    cnode -> pos[toreturn -> vertex] = cnode -> size-1;
    cnode -> pos[finalnode -> vertex] = 0;
    --cnode -> size;
    heapify(cnode, 0);
    return toreturn;
}
/**
* Decreases distance of a given vertex
* @param cnode minheap
* @param name id of vertex
* @param distance initial distance
* */
void Dijkstra::decreasedistance(struct MinHeap* cnode, int name, int distance) {
    // Find the position as index
    int i = cnode -> pos[name];
    // Change distance value of the given node
    cnode -> array[i] -> distance = distance;
    while (i && cnode -> array[i] -> distance < cnode -> array[(i - 1) / 2] -> distance) {
       
        cnode -> pos[cnode -> array[i] -> vertex] = (i - 1) / 2;
        cnode -> pos[cnode -> array[(i-1)/2] -> vertex] = i;
        swap(&cnode -> array[i], &cnode -> array[(i - 1) / 2]);
        // shifts to the parent index
        i = (i - 1) / 2;
    }
}
/**
* Checks if vertex is inside heap
* @param cnode minheap
* @param name given vertex to check
 * */
bool Dijkstra::insideHeap(struct MinHeap *cnode, int name)
{
   if (cnode -> pos[name] < cnode -> size) {
    return true;
   } else {
    return false;
   }
}
 
/**
* Main algorithm to find shortest distance
* @param graph the adjacency list on which we want to run the algorithm on
* @param ver the place from which we want to calculate shortest distances (source vertex)
* */
void Dijkstra::dijkstraAlgorithm(vector< vector<int> > adjacencylist, int ver)
{
    
    // Find the number of vertices in the adjacency list
    int num_nodes = adjacencylist.size();
    nodesVisited.resize(num_nodes);
    distance.resize(num_nodes);
    struct MinHeap* minHeap = makeHeap(num_nodes);
    // Initialize all the vector list to initial value
    // Distance to infinity
    for (int v = 0; v < num_nodes; ++v)
    {
        distance[v] = INT_MAX;
        nodesVisited[v] = -1;
        minHeap -> array[v] = newHeapNode(v, distance[v]);
        minHeap -> pos[v] = v;
    }
    minHeap -> array[ver] = newHeapNode(ver, distance[ver]);
    minHeap -> pos[ver] = ver;
    distance[ver] = 0;
    decreasedistance(minHeap, ver, distance[ver]);
    minHeap -> size = num_nodes;
    //traverse using BFS
    // First start with the source node and traverse its adjacent nodes
    //Then traverse adjacent nodes' adjacent nodes
    while (!checkForEmpty(minHeap))
    {
        // Find the node with minimum distance
        struct MinHeapNode* minHeapNode = findMin(minHeap);
      
 
        int u = minHeapNode -> vertex;
        vector<int> adjNodes = adjacencylist[u];

        //Goes through the adjacent nodes of the source vertex and update its distance value
        for (unsigned i = 0; i < adjNodes.size(); i++)
        {
 
            int v = adjNodes[i];
            //if the new distance is less than the current distance, update the distance and nodesVisited
            if (insideHeap(minHeap, v) && distance[u] != INT_MAX && 1 + distance[u] < distance[v])
            {
                distance[v] = distance[u] + 1;
                nodesVisited[v] = u;
 
                decreasedistance(minHeap, v, distance[v]);
            }
           
        }
    }

 
}

Dijkstra::~Dijkstra(){
    nodesVisited.clear();
    distance.clear();
}
