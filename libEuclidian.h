/*
    MLCP Algorithm using Forward Checking
    module of the euclidian distance functions
*/

// ----------------------------------------------------------------------------
// Modules
#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

// ----------------------------------------------------------------------------
// Functions

int euclidianDistance(int x1, int x2, int y1, int y2){
    /*
    euclidianDistance() get de euclidian distance of a pair of nodes
    */

    double x = x1 - x2;
	double y = y1 - y2;
	double dist;

	dist = pow(x, 2) + pow(y, 2);
	dist = sqrt(dist);                  

	return dist;

}

vector<vector<int>> getNeighbors(vector<vector<int>> coordinates, int number_nodes, int coverage_ratio){
    /*
    getNeighbors() obtains the nodes that cover its demand given the construction of a node
    */

    cout << "- Calculando vecinos ...";

    vector<vector<int>> distances(number_nodes, vector<int> (number_nodes, 0));

    for (int i = 0; i < number_nodes; i++){
        
        for (int j = 0; j < number_nodes; j++){

            int x1 = coordinates[i][0];
            int y1 = coordinates[i][1];
            int x2 = coordinates[j][0];
            int y2 = coordinates[j][1];

            /*Get euclidian distance of two nodes*/
            double euclidian_distance = euclidianDistance(x1, x2, y1, y2);

            /* If this distance is less than coverage_ratio,
            then the nodes are neighbors */
            if (euclidian_distance <= coverage_ratio){
                distances[i][j] = 1;
            } else {distances[i][j] = 0;}
            
        } 
    }
    
    cout << "OK" << endl;

    return distances;

}