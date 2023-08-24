#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("combo.in");
    ofstream fout ("combo.out");
    int n;
    fin>>n;
    int noverlap = 250;
    if(n<5){
        noverlap = 2 * (pow(n, 3));
        
    }
    int f1, f2, f3;
    int c1, c2, c3;
    fin >> f1 >> f2 >> f3 >> c1 >>c2 >> c3;
    int d1 = n - max(f1, c1) + min(f1, c1);
    d1 = min(d1, abs(f1-c1));
    int D1 = 5-d1;
    D1 = max(0, D1);
    if(n<5){
        D1 = n;
    }
    int d2 = n - max(f2, c2) + min(f2, c2);
    d2 = min(d2, abs(f2-c2));
    int D2 = 5-d2;
    if(n<5){
        D2 = n;
    }
    D2 = max(0, D2);
    int d3 = n - max(f3, c3) + min(f3, c3);
    d3 = min(d3, abs(f3-c3));
    int D3 = 5-d3;
    if(n<5){
        D3 = n;
    }
    D3 = max(0, D3);
    //cout<<noverlap<<"d\n";
    //cout<<D1<<D2<<D3<<"\n";
    //cout<<D1*D2*D3; 
    int ans = noverlap - (D1 * D2 * D3);
    if(n<5){
        ans = noverlap/2;
    }
    fout<<ans;
}