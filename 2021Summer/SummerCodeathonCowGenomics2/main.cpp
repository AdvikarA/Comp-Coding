#include <fstream>
using namespace std;
int main(){
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    int n, m;
    fin >> n >> m;
    char cow1[n][m];
    char cow2[n][m];

    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin >> cow1[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin >> cow2[i][j];
        }
    }
    int ans = 0; 
    for (int i = 0; i < m; i++){
        int count2 = 0; 
        for(int j = 0; j < n; j++){
            int count = 0; 
            for(int k = 0; k < n; k++){
                //fout << cow1[j][i] << cow2[k][i] << "\n";
                if(cow1[j][i] != cow2[k][i]){
                    count++; 
                }
            }
            if(count == n){
                count2++; 
            }
        }
        if(count2 == n){
            ans++; 
        }
    }
    fout << ans; 
}