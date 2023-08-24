#include<iostream>
#include<fstream>
#include<vector>
#include <queue>
using namespace std;
int n;
int effected[100000];
int main(){
    ifstream fin ("planting.in");
    ofstream fout ("planting.out");
    fin >> n; 
    for(int i = 0; i < 100000; i++){
        effected[i] = 0;
    }
    int ans = 0;
    for(int i = 0; i < n-1; i++){
        int a, b;
        fin >> a >> b;
        a--;
        b--;
        effected[a]++;
        effected[b]++;
    }
    for(int i = 0; i < 100000; i++){
        ans = max(effected[i], ans); 
    }
    fout << ans+1;
    

    
}