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
#include <iomanip>

#include "libPrinter.h"
#include "libSetting.h"
#include "libEuclidian.h"
#include "libMCLP.h"

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

        vector<int> vect{ 1, 0, 0, 1, 0, 0, 1, 1, 0, 0 }; 

        /*Execution time -> start*/
        time_t start, end;
        time(&start);

        /* Welcome */
        printWelcome();

        /* Parse Args*/
        string file_nodos = argv[1];                                // Ccoordinates of each node
        string file_demandas = argv[2];                             // Demand of each node
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

        /*Get euclidian distances for each pair of node and set neighbors*/
        vector<vector<int>> vecinos(numero_nodos, vector<int> (numero_nodos, 0));
        vecinos = getNeighbors(coordenadas,numero_nodos,S);

        /*Call MCLP algorithm*/
        vector<int> mejor_solucion(numero_nodos,0);
        mejor_solucion = MCLP(p,numero_nodos,demandas,vecinos);
        printResults(mejor_solucion,numero_nodos,final_demand);

        /*Execution time -> end*/
        time(&end);

        /* Calculating total time taken by the program.*/ 
        double time_taken = double(end - start); 
        printExecTime(time_taken);
    }

    return 0;
}
