#include <fstream>
using namespace std;
int main(){
    ifstream fin("lifeguards.in");
    ofstream fout("lifeguards.out");
    int n;
    fin >> n;
    int stime[n];
    int etime[n];
    for(int i = 0; i < n; i++){
        fin >> stime[i] >> etime[i];
    }
    int maxn = 0; 
    int t[1000] = {0}; 
    for(int i = 0; i < n; i++){
        int ans = 0; 
        for(int j = 0; j < n; j++){
            if(j != i){
                for(int s = stime[j]; s < etime[j]; s++){
                    t[s] = 1;  
                }
            }
        }
        for(int l = 0; l < 1000; l++){
            ans+= t[l]; 
            t[l] = 0; 
        }
        
        maxn = max(ans, maxn); 
    }
    fout << maxn; 
}