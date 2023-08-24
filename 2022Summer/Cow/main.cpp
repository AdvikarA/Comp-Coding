#include <iostream>
#include <fstream>
using namespace std;
#define int long long
main(){
    ifstream fin ("cow.in");
    ofstream fout ("cow.out");
    int n; 
    fin >> n; 
    int C[n+1];
    int O[n+1];
    int W[n+1];
    int pC[n+1];
    int pCO[n+1];
    int pCOW[n+1];
    C[0] = 0;
    O[0] = 0;
    W[0] = 0;
    pC[0] = 0;
    pCO[0] = 0;
    pCOW[0] = 0;
    for(int i = 1; i <= n; i++){
        char A;
        fin>>A; 
        C[i] = 0;
        O[i] = 0;
        W[i] = 0;
        if(A == 'C'){
            C[i] = 1;
        }
        else if(A == 'O'){
            O[i] = 1;
        }
        else if(A == 'W'){
            W[i] = 1;
        }
        pC[i] = pC[i-1] + C[i];
    }
    for(int i = 0; i <=n; i++){
        //cout<<pC[i]<< " ";
    }
    for(int i = 1; i <= n; i++){
        if(O[i] == 1){
            pCO[i] = pCO[i-1] + pC[i];
        }
        else{
            pCO[i] = pCO[i-1];
        }
    }
    for(int i = 1; i <= n; i++){
        if(W[i] == 1){
            pCOW[i] = pCOW[i-1] + pCO[i];
        }
        else{
            pCOW[i] = pCOW[i-1];
        }
    }
    for(int i = 0; i <=n; i++){
        //cout<<W[i]<< " ";
    }
    int ans = pCOW[n];
    fout << ans;
}