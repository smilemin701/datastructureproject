//Add code here


#include "Graph/adjacency_list.h"
#include "Algorithms/dijkstra.h"
#include "Algorithms/centrality.h"
#include "Algorithms/BFS_path.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <cmath> 

#include <cstdlib>
#include <stdlib.h>     
#include <time.h>

#include "Image.h"
#include "cs225/PNG.h"

using namespace std;

int main()
{
   
  
    cs225::PNG ori,cover, result3;
    ori.readFromFile("amzn.png");
    cover.readFromFile("amzn-cover.png");
    result3 = reset_to_ori(ori, cover);
    result3.writeToFile("amzn.png");

       
    
    cs225::PNG png, png2, result, result2;
    vector< pair <int,int> > coordinate;
    srand (time(NULL));
    for(int i = 0; i < 5; i++) {
        png.readFromFile("amzn.png");
        int hor, vert;

        hor = rand() % 1800 + 200;
        vert = rand() % 1300 + 150;
        for(int i = 0; i < coordinate.size(); i++) {
            while(abs(coordinate[i].first- hor) < 500 || abs(coordinate[i].second- vert) < 500) {
                hor = rand() % 1800 + 200;
                vert = rand() % 1200 + 250;
            }
        }
        cout<<hor<<", "; 
        cout<<vert<<", ";
        cout<<endl;


        result = createSpotlight(png, hor, vert, i);
        result.writeToFile("amzn.png");
        
        coordinate.push_back(make_pair(hor, vert));
    }

cout<<endl;

    for(int i = 1; i < coordinate.size(); i++) {

        png2.readFromFile("amzn.png");
        result2 = connectNode(png2, coordinate[i-1].first, coordinate[i-1].second, coordinate[i].first, coordinate[i].second);
        result2.writeToFile("amzn.png");
        
    }


    
    
    return 0;
  
}



