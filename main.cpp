/*
    MLCP Algorithm using Forward Checking
*/

// ----------------------------------------------------------------------------
// Libreries

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

#include "libPrinter.h"
#include "libSetting.h"
#include "libEuclidian.h"

using namespace std;

// ----------------------------------------------------------------------------
// Main

int main(int argc, char const *argv[])
{
    /* code */
    if (argc!=5){

        cout << "Invalid number of arguments";
        return 0;

    } else {

        /* Welcome */
        printWelcome();

        /* Parse Args*/
        string file_nodos = argv[1];                                // Ccoordinates of each node
        string file_demandas = argv[2];                             // File with demand of each node
        int numero_nodos = getNumberNodes(file_nodos);              // Number of nodes
        int p = stoi(argv[3]);                                      // Number of servers
        int S = stoi(argv[4]);                                      // Coverage ratio
        printParameter(file_nodos,file_demandas,numero_nodos,p,S);

        /*Set coordinates array*/
        vector<vector<int> > coordenadas(numero_nodos, vector<int> (2, 0));
        coordenadas = setCoordinate(file_nodos,numero_nodos);

        /*Set demand array*/
        vector<int> demandas;
        demandas = setDemands(file_demandas,numero_nodos);

        /*Get euclidian distances for each node*/
        vector<vector<int>> vecinos(numero_nodos, vector<int> (numero_nodos, 0));
        vecinos = getNeighbors(coordenadas,numero_nodos,S);
    
    }
    
     

    return 0;
}
