#include <fstream>
#include <string>
using namespace std;
int main() {
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int n, m; 
    fin>> n >> m; 
    char seq[n][m]; 
    char seq1[n][m]; 

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin>> seq[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin>> seq1[i][j];
        }
    }
    int ans = 0; 
    for(int j = 0; j < m; j++){
        int counter = 0; 
        for(int i = 0; i < n; i++){
            int count = 0;
            for(int k = 0; k < n; k++){
                //cout << seq[i][j] << " " << seq1[k][j] << "\n"; 
                if(seq[i][j] == seq1[k][j]){
                    continue; 
                }
                else{
                    count++;
                }
                if(count == n){
                    counter++; 
                }
                if(counter == n){
                    ans++; 
                }
                //cout<<count<< " " << counter<<"\n";

            }
        }
    }
    fout<< ans; 
}