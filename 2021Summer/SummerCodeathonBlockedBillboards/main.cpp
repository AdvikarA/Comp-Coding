#include <iostream>
#include <fstream>
using namespace std; 
int main() {
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int sum = 0; 
    bool kookw[2000][2000];
    for(int x = 0; x < 2000; x++){
        for(int y = 0; y < 2000; y++){
            kookw[x][y] = 0; 
        }
    }
    int blx1, b1y1, b1x2, b1y2, b2x1, b2y1, b2x2, b2y2, tx1, ty1, tx2, ty2; 
    fin >> blx1 >> b1y1 >> b1x2 >> b1y2;
    fin >> b2x1 >> b2y1 >> b2x2 >> b2y2;
    fin >> tx1 >> ty1 >> tx2 >> ty2;

    for(int i = blx1; i < b1x2; i++){
        for(int j = b1y1; j < b1y2; j++){
            kookw[i][j] = 1; 
        }
    }  
    for(int i = b2x1; i < b2x2; i++){
        for(int j = b2y1; j < b2y2; j++){
            kookw[i][j] = 1; 
        }
    } 
    for(int i = tx1; i < tx2; i++){
        for(int j = ty1; j < ty2; j++){
            kookw[i][j] = 0; 
        }
    }   
    for(int x = 0; x < 2000; x++){
        for(int y = 0; y < 2000; y++){
            sum += kookw[x][y]; 
        }
    }
    fout << sum; 
}