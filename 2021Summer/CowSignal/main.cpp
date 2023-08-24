#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream fin ("cowsignal.in");
    ofstream fout ("cowsignal.out");
    int m, n, k;  
    fin>> m >> n >> k; 
    bool canvas[10][10]; 
    for(int i = 0; i < m; i++){
        char rows[10]; 
        fin>> rows; 
        for(int j = 0; j < n; j++){
            if(rows[j] == 'X'){
                canvas[i][j] = true; 
            }
            else{
                canvas[i][j] = false; 
            }

        }
    }
     for(int i = 0; i < m; i++){
        for(int u = 0; u < k; u++){
            for(int j = 0; j < n; j++){
                for(int f = 0; f < k; f++){
                    if(canvas[i][j] == true){
                        fout<< "X";
                    }
                    else{
                        fout<< "."; 
                    }
                }
            }
            fout<< endl; 
        }
     }
}