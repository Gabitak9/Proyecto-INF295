#include <iostream>
#include <string>

using namespace std;

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
