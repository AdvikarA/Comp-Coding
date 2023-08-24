#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std; 
int main() {
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int n; 
    fin >> n; 
    long long ans = 0;
    int x_coords[n];
    int y_coords[n]; 
    for(int i = 0; i < n; i++){
        fin>> x_coords[i] >> y_coords[i]; 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i != j){
                for(int k = 0; k < n; k++){
                    if(k != i && k != j){
                        if((x_coords[i] == x_coords[j] || x_coords[i] == x_coords[k])&&(y_coords[i] == y_coords[j] || y_coords[i] == y_coords[k])){
                            long long area = abs(y_coords[j] - y_coords[i]) * abs(x_coords[k] - x_coords[i]);
                            ans = max(area, ans);
                        }
                    }
                }
            }
        }
    }
    fout << ans; 
}