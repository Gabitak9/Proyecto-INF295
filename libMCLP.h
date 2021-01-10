

// ----------------------------------------------------------------------------
// Modules
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include<algorithm>
#include<iterator>

using namespace std;

// ----------------------------------------------------------------------------
// Global Var
int final_demand = 0;
//vector<int> final_solution;

// ----------------------------------------------------------------------------
// Functions

vector<int> backtracking(int n, vector<int> actual_solution, int i, int p, vector<vector<int>> neighbors, vector<int> demands, vector<int> best_solution) ;

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

    int total_demand = 0;

    for (int i = 0; i < count; i++){
        if (coverage[i]==1){
            total_demand += demands[i];
        }
    }

    return total_demand;    
}

int serversImplement(vector<int> servers, int count){

    int total_servers = 0;

    for (int i = 0; i < count; i++){
        total_servers += servers[i];
    }
    
    //cout << total_servers << endl;
    return total_servers;
}



vector<int> backtracking(int number_nodes, vector<int> actual_solution, int i, int p, vector<vector<int>> neighbors, vector<int> demands, vector<int> best_solution) 
{ 
    vector<int> final_solution(best_solution);

    if (i == number_nodes) {
        int aux = serversImplement(actual_solution,number_nodes); 
        if (aux<=p){
            vector<int> coverage_actual_solution = getCovergae(actual_solution,neighbors,number_nodes);
            int actual_demand = getTotalDemand(demands,coverage_actual_solution,number_nodes);
            if (actual_demand > final_demand)
            {
                final_demand = actual_demand;
                final_solution = actual_solution;
                
                //cout << final_demand << endl;
                //printVector(actual_solution,number_nodes);
            }
            return final_solution;
        }else{
            return final_solution;
        }  
    } 
    
    /* Left-side of the binary tree*/
    actual_solution[i] = 0; 
    final_solution = backtracking(number_nodes, actual_solution, i + 1,p,neighbors,demands,final_solution); 

  /* Right side of the binary tree*/
    actual_solution[i] = 1; 
    final_solution = backtracking(number_nodes, actual_solution, i + 1,p,neighbors,demands,final_solution); 

    return final_solution;
} 


vector<int> MCLP(int p, int number_nodes, vector<int> demands, vector<vector<int>> neighbors){

    /* Initial Solution */
    vector<int> blocked_nodes(number_nodes,0);
    vector<int> initial_solution(number_nodes,0);
    vector<int> final_solution(number_nodes,0);

    /* Backtracking */
    final_solution = backtracking(number_nodes,initial_solution,0,p,neighbors,demands,final_solution);
    
    return final_solution;
}

