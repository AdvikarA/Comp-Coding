#include <fstream>
#include <iostream>
using namespace std;
int main(){
    ifstream fin ("hps.in");
    ofstream fout ("hps.out");
    int n;
    fin >> n;
    int H[n+1];
    int P[n+1];
    int S[n+1];
    int prefixH[n+1];
    int prefixP[n+1];
    int prefixS[n+1];
    H[0]=0;
    P[0]=0;
    S[0]=0;
    prefixH[0]=0;
    prefixP[0]=0;
    prefixS[0]=0;

    for(int i = 1; i <= n; i++){
        char a; fin>>a;
        if(a == 'H'){
            H[i] = 1;
        }
        else{
            H[i] = 0;
        }
        if(a == 'P'){
            P[i] = 1;
        }
        else{
            P[i] = 0;
        }
        if(a == 'S'){
            S[i] = 1;
        }
        else{
            S[i] = 0;
        }
        prefixH[i] = prefixH[i-1] + H[i];
        prefixP[i] = prefixP[i-1] + P[i];
        prefixS[i] = prefixS[i-1] + S[i];
        //cout << prefixS[i-1] << " " << S[i] << "\n";
    }
    for(int i = 0; i < n+1; i++){
        //cout<<prefixS[i]<<"\n";
    }
    //cout<<"here";
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int Hdistfirst = prefixH[i]-prefixH[0];
        int Pdistfirst = prefixP[i]-prefixP[0];
        int Sdistfirst = prefixS[i]-prefixS[0];
        int Hdistlast = prefixH[n] - prefixH[i-1];
        int Pdistlast = prefixP[n] - prefixP[i-1];
        int Sdistlast = prefixS[n] - prefixS[i-1];
        int hall = prefixH[n];
        int pall = prefixP[n];
        int sall = prefixS[n];
        //cout<<"OOO: "<< prefixH[n] << " " << prefixH[i-1]<<"\n";
        ans = max(ans, Hdistfirst+Pdistlast);
        ans = max(ans, Hdistfirst+Sdistlast);
        //cout<<Hdistfirst-Pdistlast<<"\n";
        ans = max(ans, Pdistfirst+Hdistlast);
        ans = max(ans, Pdistfirst+Sdistlast);
        ans = max(ans, Sdistfirst+Hdistlast);
        ans = max(ans, Sdistfirst+Pdistlast);
        ans = max(ans, hall);
        ans = max(ans, pall);
        ans = max(ans, sall);


    }
    fout<<ans;
    

}