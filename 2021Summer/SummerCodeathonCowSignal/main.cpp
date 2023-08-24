#include <fstream>
using namespace std; 
int main(){
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int x, y, z;
    fin >> x >> y >> z; 
    char grid[x][y];
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            fin >> grid[i][j]; 
        }
    }
    for(int i = 0; i < x; i++){
        for(int j = 0; j < z; j++){
            for(int k = 0; k < y; k++){
                for(int l = 0; l < z; l++){
                    fout << grid[i][k]; 
                }
            }
            fout << "\n"; 
        }
    }
}