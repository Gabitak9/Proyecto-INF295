/*
    MLCP Algorithm using Forward Checking
*/

// ----------------------------------------------------------------------------
// Libreries

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

#include "libPrinter.h"
#include "libSetting.h"

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
        /*ifstream file_nodos; file_nodos.open(argv[1]);*/
        string file_nodos = argv[1];
        string file_demandas = argv[2];
        int numero_nodos = getNumberNodes(file_nodos);
        int p = stoi(argv[3]);
        int S = stoi(argv[4]);
        printParameter(file_nodos,file_demandas,numero_nodos,p,S);

        /*Set coordinates array*/
        setCoordinate(file_nodos,numero_nodos);

        /*Set demand array*/

    }
    
     

    return 0;
}
