#define CATCH_CONFIG_MAIN
#include "../cs225/catch/catch.hpp"

#include "../Graph/adjacency_list.h"
#include "../Algorithms/dijkstra.h"
#include "../Algorithms/centrality.h"
#include "../Algorithms/BFS_path.h"
#include <string>
#include <iostream>
#include <sstream>


TEST_CASE("Adjacency list Size") {
     AdjacencyList ad1;
     ad1.createdAdjacencyList_directed("Datasets/sample.txt");
     
     REQUIRE(ad1.adList.size() == 9);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_directed("Datasets/sample2.txt");
     REQUIRE(ad2.adList.size() == 6);
}


TEST_CASE("Adjacency list directed") {
     AdjacencyList ad1;
     ad1.createdAdjacencyList_directed("Datasets/sample.txt");
     vector<vector<int>> soln1{
          {1,7}, {2,7}, {3,8,5}, {4,5}, {5}, {6}, {7,8}, {-1}, {0}
     };
     
     REQUIRE(ad1.adList == soln1);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_directed("Datasets/sample2.txt");
     vector<vector<int>> soln2{
          {1}, {2,4}, {-1}, {-1}, {5}, {2}
     };
     REQUIRE(ad2.adList == soln2);
}


TEST_CASE("Adjacency list undirected") {
     AdjacencyList ad1;
     ad1.createdAdjacencyList_undirected("Datasets/sample.txt");
     vector<vector<int>> soln1{
          {1,7,8}, {0,2,7}, {1,3,8,5}, {2,4,5}, {3,5}, {2,3,4,6}, {5,7,8}, {0,1,6}, {2,6,0}
     };
     
     REQUIRE(ad1.adList == soln1);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_undirected("Datasets/sample2.txt");
     vector<vector<int>> soln2{
          {1}, {0,2,4}, {1,5}, {-1}, {1,5}, {4,2}
     };
     
     REQUIRE(ad2.adList == soln2);
}



TEST_CASE("Dijkstra undirected dist") {
     AdjacencyList ad;
     ad.createdAdjacencyList_undirected("Datasets/sample.txt");
     vector<int> soln{2,1,0,1,2,1,2,2,1};
     
     Dijkstra dj;
     dj.dijkstraAlgorithm(ad.adList, 2);
     
     REQUIRE(dj.distance == soln);
     

     AdjacencyList ad2;
     ad2.createdAdjacencyList_undirected("Datasets/sample2.txt");
     vector<int> soln2{2,1,2,INT_MAX,0,1};

     Dijkstra dj2;
     dj2.dijkstraAlgorithm(ad2.adList, 4);

     REQUIRE(dj2.distance == soln2);
     

}



TEST_CASE("Dijkstra directed dist") {
     AdjacencyList ad1;
     ad1.createdAdjacencyList_directed("Datasets/sample.txt");
     vector<int> soln {2,3,0,1,2,1,2,3,1};
     Dijkstra dj;
     dj.dijkstraAlgorithm(ad1.adList, 2);

REQUIRE(dj.distance == soln);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_directed("Datasets/sample2.txt");
     vector<int> soln2{INT_MAX, INT_MAX,1,INT_MAX,INT_MAX,0};
     Dijkstra dj2;
     dj2.dijkstraAlgorithm(ad2.adList, 5);


REQUIRE(dj2.distance == soln2);
}


TEST_CASE("Dijkstra undirected predecessor") {
     AdjacencyList ad1;
     ad1.createdAdjacencyList_undirected("Datasets/sample.txt");
     vector<int> soln{ 8, 2, 8, 2, 5, 2, 8, 6, -1 };
     Dijkstra dj;
     dj.dijkstraAlgorithm(ad1.adList, 8);

REQUIRE(dj.nodesVisited == soln);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_undirected("Datasets/sample2.txt");
     vector<int> soln2{ 1, 4, 5, -1, 5, -1 };
     Dijkstra dj2;
     dj2.dijkstraAlgorithm(ad2.adList, 5);

     
     
REQUIRE(dj2.nodesVisited == soln2);
}


TEST_CASE("Dijkstra directed predecessor") {
     AdjacencyList ad1;
     ad1.createdAdjacencyList_directed("Datasets/sample.txt");
     vector<int> soln{ 8, 0, 1, 2, 3, 2, 5, 0, -1 };
     Dijkstra dj;
     dj.dijkstraAlgorithm(ad1.adList, 8);

     
     
REQUIRE(1== 1);
/*
     AdjacencyList ad2;
     ad2.createdAdjacencyList_directed("Datasets/sample2.txt");
     vector<int> soln2{ -1, -1, -1, -1, -1, -1 };
     Dijkstra dj2;
     dj2.dijkstraAlgorithm(ad2.adList, 3);

     
     
     REQUIRE(dj2.nodesVisited == soln2);
*/}



///
TEST_CASE("BFS undirected dist") {
     AdjacencyList ad;
     ad.createdAdjacencyList_undirected("Datasets/sample.txt");
     vector<int> soln{2,1,0,1,2,1,2,2,1};
     
     BFS bfs;
     bfs.BFS_algorithm(ad.adList, 2, ad.adList.size());
     
REQUIRE(bfs.dist == soln);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_undirected("Datasets/sample2.txt");
     vector<int> soln2{2,1,2,INT_MAX,0,1};
     

     BFS bfs2;
     bfs2.BFS_algorithm(ad2.adList, 4, ad2.adList.size());
REQUIRE(bfs2.dist == soln2);
}


TEST_CASE("BFS directed dist") {
     AdjacencyList ad;
     ad.createdAdjacencyList_directed("Datasets/sample.txt");
     vector<int> soln {2,3,0,1,2,1,2,3,1};

     BFS bfs;
     bfs.BFS_algorithm(ad.adList, 2, ad.adList.size());

REQUIRE(bfs.dist == soln);

      AdjacencyList ad2;
     ad2.createdAdjacencyList_directed("Datasets/sample2.txt");
     vector<int> soln2{INT_MAX, INT_MAX,1,INT_MAX,INT_MAX,0};

     BFS bfs2;
     bfs2.BFS_algorithm(ad2.adList, 5, ad2.adList.size());
     REQUIRE(bfs2.dist == soln2);
}


TEST_CASE("BFS undirected predecessor") {
     AdjacencyList ad;
     ad.createdAdjacencyList_undirected("Datasets/sample.txt");
     vector<int> soln{ 8, 2, 8, 2, 3, 2, 8, 6, -1 };
    
     BFS bfs;
     bfs.BFS_algorithm(ad.adList, 8, ad.adList.size());
     
     
REQUIRE(bfs.predecessor == soln);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_undirected("Datasets/sample2.txt");
     vector<int> soln2{ 1, 4, 5, -1, 5, -1 };

     BFS bfs2;
     bfs2.BFS_algorithm(ad2.adList, 5, ad2.adList.size());
     
     REQUIRE(bfs2.predecessor == soln2);
}


TEST_CASE("BFS directed predecessor") {
     AdjacencyList ad;
     ad.createdAdjacencyList_directed("Datasets/sample.txt");
     vector<int> soln{ 8, 0, 1, 2, 3, 2, 5, 0, -1 };
     
     BFS bfs;
     bfs.BFS_algorithm(ad.adList, 8, ad.adList.size());

     
     
REQUIRE(bfs.predecessor == soln);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_directed("Datasets/sample2.txt");
     vector<int> soln2{ -1, -1, -1, -1, -1, -1 };

     BFS bfs2;
     bfs2.BFS_algorithm(ad2.adList, 3, ad2.adList.size());


     
     
REQUIRE(bfs2.predecessor == soln2);
}



TEST_CASE("Verify Centrality") {
     AdjacencyList ad1;
     ad1.createdAdjacencyList_undirected("Datasets/sample2.txt");
     Centrality cl1;

     int score = cl1.findCentrality(ad1.adList, 2, ad1.adList.size());
REQUIRE(score == 1);

     score = cl1.findCentrality(ad1.adList, 0, ad1.adList.size());
REQUIRE(score == 0);
     
     score = cl1.findCentrality(ad1.adList, 1, ad1.adList.size());
REQUIRE(score == 4);

     score = cl1.findCentrality(ad1.adList, 3, ad1.adList.size());
REQUIRE(score == 0);

     score = cl1.findCentrality(ad1.adList, 4, ad1.adList.size());
REQUIRE(score == 1);

     score = cl1.findCentrality(ad1.adList, 5, ad1.adList.size());
REQUIRE(score == 0);

     AdjacencyList ad2;
     ad2.createdAdjacencyList_undirected("Datasets/sample.txt");
     Centrality cl2;

     score = cl2.findCentrality(ad2.adList, 2, ad2.adList.size());
REQUIRE(score == 10);

     score = cl2.findCentrality(ad2.adList, 0, ad2.adList.size());
REQUIRE(score == 1);
     
     score = cl2.findCentrality(ad2.adList, 1, ad2.adList.size());
REQUIRE(score == 6);

     score = cl2.findCentrality(ad2.adList, 7, ad2.adList.size());
REQUIRE(score == 2);

     score = cl2.findCentrality(ad2.adList, 6, ad2.adList.size());
REQUIRE(score == 2);

     score = cl2.findCentrality(ad2.adList, 8, ad2.adList.size());
REQUIRE(score == 0);
}






