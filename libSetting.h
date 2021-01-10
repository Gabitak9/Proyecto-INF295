/*
    MLCP Algorithm using Forward Checking
    module of the functions to load data
*/

// ----------------------------------------------------------------------------
// Modules
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// ----------------------------------------------------------------------------
// Functions

int getNumberNodes(string filename){
    /*
    getNumberNodes() obtain the total number of nodes
    */

    int number_nodes;
    ifstream file_nodes(filename);

    if (file_nodes.good()){
        string sLine;
        getline(file_nodes, sLine);
        number_nodes = stoi(sLine);
    }
    
    return number_nodes;

}

vector<vector<int>> setCoordinate(string filename, int number_nodes){
    /*
    setCoordinate() obtain the vector with the coordinates of each node
    */

    cout << "- Cargando coordenadas ... ";

    vector<vector<int>> coordinates(number_nodes, vector<int> (2, 0));
    
    ifstream file(filename);
    string str;
    int count;

    while (getline(file, str)) {

        if (count != 0){

            vector <string> pair;
            stringstream check1(str);

            string intermediate; 

            while(getline(check1, intermediate, ' ')) { 
                pair.push_back(intermediate); 
            } 
            
            int x = stoi(pair[0]);
            int y = stoi(pair[1]);

            coordinates[count-1][0] = x;
            coordinates[count-1][1] = y;

            count++;

        }else{count++;}
        
    }

    cout << "OK" << endl;

    return coordinates;

}

vector<int> setDemands(string filename, int number_nodes){
    /*
    setDemands() obtain the vector with the demand of each node
    */

    cout << "- Cargando demandas ... ";

    vector<int> demands(number_nodes,0);

    ifstream file(filename);
    string str;
    int count;

    while (getline(file, str)) {

        int demand = stoi(str);
        demands[count] = demand;
        count++;

    }

    cout << "OK" << endl;

    return demands;

}