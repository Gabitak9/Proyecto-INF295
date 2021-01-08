#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> getCovergae(vector<int> servers, vector<vector<int>> neighbors, int count){

    vector<int> coverage(count,0);
    int is_neighbor;

    for (int i = 0; i < count; i++){

        if (servers[i] == 1) {

            for (int j = 0; j < count; j++){
                is_neighbor = neighbors[i][j];
                if (is_neighbor == 1 and coverage[j] == 0){
                    coverage[j] = 1;
                } 
            }    
        }
    }

    return coverage;

}

int getTotalDemand(vector<int> demands, vector<int> coverage, int count){

    int total_demand;

    for (int i = 0; i < count; i++){
        if (coverage[i]==1){
            total_demand += demands[i];
        }
    }

    return total_demand;    

}