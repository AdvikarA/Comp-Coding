#include<fstream>
#include<iostream>
using namespace std;
int main(){
    ifstream fin ("bcount.in");
    ofstream fout("bcount.out");
    int n; 
    fin >> n; 
    int q;
    fin>>q;
    int cows[n+1];
    int prefix1[n+1];
    int prefix2[n+1];
    int prefix3[n+1];
    cows[0] = 0;
    prefix1[0] = 0;
    prefix2[0] = 0;
    prefix3[0] = 0;

    for(int i = 1; i <= n; i++){
        fin >> cows[i];
        if(cows[i] == 1){
            prefix1[i] = prefix1[i-1] + 1;
        }
        else{
            prefix1[i] = prefix1[i-1] + 0;
        }
        if(cows[i] == 2){
            prefix2[i] = prefix2[i-1] + 1;
        }
        else{
            prefix2[i] = prefix2[i-1] + 0;
        }
        if(cows[i] == 3){
            prefix3[i] = prefix3[i-1] + 1;
        }
        else{
            prefix3[i] = prefix3[i-1] + 0;
        }
    }
    for(int i = 0; i < n+1; i++){
        //cout << prefix1[i]<<"\n";
    }
    for(int i = 0; i < q; i++){
        int a, b;
        fin >> a >> b;
     
        fout << prefix1[b] - prefix1[a-1] << " " << prefix2[b] - prefix2[a-1] << " " << prefix3[b] - prefix3[a-1] << "\n";
    }
    

}