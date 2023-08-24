#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    int n; 
    fin>> n; 
    int b[n], a[n], g[n];
    int count = 0; 
    for(int i = 0; i < n; i++){
        fin >> b[i] >> a[i] >> g[i]; 
    }
    for(int i = 1; i <= 3; i++){
        int location = i; 
        int ans = 0; 
        for(int j = 0; j < n; j++){
            if(location == b[j]){
                location = a[j];
            }
            else if(location == a[j]){
                location = b[j]; 
            }
            if(g[j] == location){
                ans++; 
            }
        }
        count = max(count, ans); 
    }
    fout << count;
}