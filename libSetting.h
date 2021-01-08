#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iterator>
#include <vector>

using namespace std;

struct CoordinatePair
{
    int x;
    int y;
};

int getNumberNodes(string filename){

    int number_nodes;
    ifstream file_nodes(filename);
    if (file_nodes.good()){
        string sLine;
        getline(file_nodes, sLine);
        number_nodes = stoi(sLine);
    }
    return number_nodes;

}

void setCoordinate(string filename, int number_nodes){
    
    ifstream file(filename);
    string str;
    int count;

    while (getline(file, str)) {

        if (count != 0){

            vector <string> tokens;
            stringstream check1(str);

            string intermediate; 

            while(getline(check1, intermediate, ' ')) { 
                tokens.push_back(intermediate); 
            } 
            
            int x = stoi(tokens[0]);
            int y = stoi(tokens[1]);

            cout << x << " -- " << y << endl;

            count++;

        }else{count++;}
        
        
    }

}