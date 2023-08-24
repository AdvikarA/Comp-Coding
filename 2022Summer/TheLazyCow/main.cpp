#include<iostream>
#include<fstream>
#include <utility>
#include<vector>
#include<algorithm>
using namespace std;
int grass[1000001];
int patch[1000001];
int ppatch[1000001];    
#define int long long
main(){
    ifstream fin ("lazy.in");
    ofstream fout ("lazy.out");
    int n, k;
    fin >> n >> k;
    //cout<<n<<k;
    //out<<"a";
    for(int i = 0; i < 1000001; i++){
        grass[i] = 0;
        //cout<<grass[i]<<"\n";
    }
    
    for(int i = 0; i < n; i++){
        int a, b;
        fin>>a>>b;
        //cout << a << b<<"\n";
        grass[b] = a; 
    }
    //cout<<"A";

    
    
    ppatch[0] = 0;
    patch[0] = 0;
    for(int i = 1; i <= 1000000; i++){
        ppatch[i] = ppatch[i-1] + grass[i];
        //cout<<ppatch[i]<<" " << i <<"\n";
    }
    int ans = 0;
    
    bool solved = false;
    if(2*k >= 1000000){
        ans = ppatch[1000000];
        solved = true;
    }
    if(!solved){
        for(int i = 1; i <= 1000000-2*k; i++){
            //cout<<"A";
            int total = ppatch[i+2*k] - ppatch[i-1];
            //cout << ppatch[i+2*k] << " " << ppatch[i-1] << " ";
            //cout<<i+2*k << " "<<i-1<<"\n";
            if(total != ans && total != 0){
                //cout<<total<<" \n";
            }
            ans = max(ans, total);
            //cout << ans << "\n";;
        }
    }
    fout << ans;



}