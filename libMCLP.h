#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void backtracking(int n, vector<int> actual_solution, int i, int p, vector<vector<int>> neighbors, vector<int> demands, int actual_demand) ;

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

void backtracking(int n, vector<int> actual_solution, int i, int p, vector<vector<int>> neighbors, vector<int> demands, int actual_demand) 
{ 
    if (i == n) {
        int aux = serversImplement(actual_solution,n); 
        if (aux<=p){
            vector<int> coverage_actual_solution = getCovergae(actual_solution,neighbors,n);
            int demand_actual_solution = getTotalDemand(demands,coverage_actual_solution,n);
            if (demand_actual_solution > actual_demand)
            {
                //printVector(actual_solution,n);
                //cout << demand_actual_solution << endl;
                actual_demand = demand_actual_solution;
                cout << actual_demand << endl;
            }
            return;
        }else{
            return;
        }  
    } 
  
    actual_solution[i] = 0; 
    backtracking(n, actual_solution, i + 1,p,neighbors,demands,actual_demand); 
  
    actual_solution[i] = 1; 
    backtracking(n, actual_solution, i + 1,p,neighbors,demands,actual_demand); 
} 


vector<int> MCLP(int p, int number_nodes, vector<int> demands, vector<vector<int>> neighbors){

    /* Initial Solution */
    vector<int> blocked_nodes(number_nodes,0);
    vector<int> best_solution(number_nodes,0);
    vector<int> actual_solution(number_nodes,0);

    /* Backtracking */
    backtracking(number_nodes,actual_solution,0,p,neighbors,demands,0);
    
    return best_solution;
}

