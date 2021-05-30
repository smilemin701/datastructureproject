#include <string>
#include <sstream>
#include <iostream>
#include "Graph/adjacency_list.h"
#include "Algorithms/dijkstra.h"
#include "Algorithms/centrality.h"
#include "Algorithms/BFS_path.h"
using namespace std;

int main() {

  std::string filename;
  std::cout << "" << std::endl;
  std::cout << "Input the path to the dataset here: " << std::endl;
  std::cin >> filename;

  AdjacencyList ad;
    //ad.createdAdjacencyList_directed("Datasets/sample.txt");
    ad.createdAdjacencyList_directed(filename);
  int Product1ID;
  int Product2ID;

  cout << "" << std::endl;
  cout << "Enter Product ID of first product below: " << std::endl;
  cin >> Product1ID;
  if (Product1ID < 0 || Product1ID >= (int) ad.adList.size()) {    
    std::cout << "Please check if you are entering the right Product ID" << std::endl;
    exit(1);
  } else {
  //if (Product1ID > 0 && Product1ID < (int) ad.adList.size()){
      std::cout << "Product ID entered has been entered into the system and is being processed." << std::endl;
  }

  cout << "" << std::endl;
  cout << "Enter Product ID of second product below:  " << std::endl;
  cin >> Product2ID;
  if (Product2ID < 0 || Product2ID >= (int) ad.adList.size()) {    
    std::cout << "Please check if you are entering the right Product ID" << std::endl;
    exit(1);
  } else {
  //if (Product2ID > 0 && Product2ID < (int) ad.adList.size()) {
      std::cout<< "Product ID entered has been entered into the system and is being processed." << std::endl;
  }

    int option;
    do {
    std::cout << "" << std::endl;
    std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
    std::cout << "{  Select one of the following algorithms  }" << std::endl;
    std::cout << "{                                          } " << std::endl;
    std::cout << "{   1. Dijkstra's Algorithm                }" << std::endl;
    std::cout << "{   2. Breadth First Search                }" << std::endl;
    std::cout << "{   3. Betweenness Centrality              }" << std::endl;
    std::cout << "{   4. Return to exit program              }" << std::endl;
    std::cout << "{                                          } " << std::endl;
    std::cout << " ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ " << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter the number of the algorithm that you would like to use: "<< std::endl;

    //User will enter an integer to choose one of the options
    Centrality cl;
    Dijkstra ds;
    BFS bfs;
    std::cin >> option;
    switch(option)
    {
      case 1: { 
                 std::cout << "Dijkstra's Algorithm is being run" << std::endl;
                 ds.dijkstraAlgorithm(ad.adList, Product1ID);
                 vector<int> nodeVisited = ds.nodesVisited;
                 vector<int> path;
                 if (Product1ID == Product2ID) {
                   cout<<"You have entered the same ID"<<endl;
                 } else {
                   if(nodeVisited[Product2ID] == -1){
                     cout<<"Path does not exist"<<endl;
                   }else{
                      int idx = Product2ID;
                      while(idx != Product1ID){
                        idx = nodeVisited[idx];
                        path.push_back(idx);
                      }
                      reverse(path.begin(), path.end());
                      cout<<"path: ";
                      for(int i = 0; i < (int) path.size(); i++) {
                        cout<<path[i]<<" -> ";
                      }
                      cout<<Product2ID;
                      cout<<endl;
                     }
                 }
    //the path vector is -1, if there is no path between source and destination nodes
                
                break;
              }
      case 2: { 
                std::cout << " " << std::endl;
                std::cout << "BFS is being run:" << std::endl;
                bfs.BFS_algorithm(ad.adList, Product1ID, ad.adList.size());
                cout<<"Distance from node '"<< Product1ID << "' to node '"<< Product2ID << "' : " <<bfs.dist[Product2ID] << endl;
                cout<<endl;
            
                //distance[i] i = destination node
                //bfs.path(3)
                //distance[i]
  
                
                break;
              }
      case 3: { 
                std::cout << "Betweenness Centrality Score is being calculated" << std::endl;
                int score = cl.findCentrality(ad.adList, Product1ID, ad.adList.size());
                cout<<score<<endl;
                break;               
              }
      case 4: { 
                std::cout << "Returning to previous page in 3..2..1" << std::endl;
                exit(1);
              }
      default: std::cout<< "There is no such option. Try again." << std::endl;
    } 
  }
  while(option != 4);
}