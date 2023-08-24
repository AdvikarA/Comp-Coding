#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("paint.in");
    ofstream fout ("paint.out");
    int ans = 0; 
    int fence[100] = {0}; 
    int a, b, c, d; 
    fin >> a >> b >> c >> d; 
    for(int i = a; i < b; i++){
        fence[i] = 1; 
    }
    for(int i = c; i < d; i++){
        fence[i] = 1; 
    }
    for(int i = 0; i < 100; i++){
        ans+=fence[i]; 
    }
    fout << ans; 
}