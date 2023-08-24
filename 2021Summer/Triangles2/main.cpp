#include <fstream>
using namespace std; 
int main() {
    ifstream fin ("triangles.in");
    ofstream fout ("triangles.out");
    int n; 
    fin >> n; 
    int high = 0; 
    int xdist, ydist; 
    int x[n]; 
    int y[n]; 
    for(int i = 0; i < n; i++){
        fin >> x[i] >> y[i]; 
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(x[i] == x[j]){
                ydist = abs(y[i] - y[j]); 
            }
            if(y[i] == y[j]){
                xdist = abs(x[i] - x[j]); 
            }
            high = max(high, xdist*ydist);
        }
    }
    fout << high; 
}