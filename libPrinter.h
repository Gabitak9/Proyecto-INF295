/*
    MLCP Algorithm using Forward Checking
    module of the functions that print information
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

void printWelcome() {

    cout << "|----------------------------------------------------------------|" << endl;
    cout << "|             MLCP algorithm using Forward Checking              |" << endl;
    cout << "|----------------------------------------------------------------|" << endl;

}

void printParameter(string file_nodos, string file_demandas, int number_nodes, int p, int S){

    cout << "[*] Archivo de Nodos: " << file_nodos << endl;
    cout << "[*] Archivo de Demandas: " << file_demandas << endl;
    cout << "[*] Número de Nodos: " << number_nodes << endl;
    cout << "[*] Parámetro p: " << p << endl;
    cout << "[*] Parámetro S: " << S << endl;
    cout << "------------------------------------------------------------------" << endl;
    
}

void printExecTime(double time_taken){

    cout << "------------------------------------------------------------------" << endl;
    cout << "Tiempo de ejecución : " << fixed << time_taken << setprecision(5); cout << " sec " << endl; 

}

void printNeighbors(vector<vector<int>> neighbors, int count){

    cout << "------------------------------------------------------------------" << endl;
    for (int i = 0; i < count; i++){
        for (int j = 0; j < count; j++){
            cout << neighbors[i][j] << " ";
        }
        cout << "\n";
    }
}

void printVector(vector<int> vector, int count) {

    for (int i = 0; i < count; i++){
        cout << vector[i] << " ";
    }
    cout << "\n";
}

void printResults(vector<int> vector, int count, int demand) {

    cout << "------------------------------------------------------------------" << endl;
    cout << "SOLUCIÓN FINAL:" <<endl;
    cout << "[*] Demanda total cubierta: " << demand << endl;
    cout << "[*] Nodos a constuir: ";
    for (int i = 0; i < count; i++){
        if(vector[i] == 1){
        cout << i << " ";
        }
    }
    cout << "\n";

}