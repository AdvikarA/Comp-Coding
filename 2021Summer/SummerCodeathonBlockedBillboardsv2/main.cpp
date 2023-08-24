#include <fstream>
using namespace std; 
int main(){
    ifstream fin("billboard.in");
    ofstream fout("billboard.out");
    int b1x1, b1y1, b1x2, b1y2;
    fin >> b1x1 >> b1y1 >> b1x2 >> b1y2;
    int b2x1, b2y1, b2x2, b2y2;
    fin >> b2x1 >> b2y1 >> b2x2 >> b2y2;
    int tx1, ty1, tx2, ty2;
    fin >> tx1 >> ty1 >> tx2 >> ty2;
    int grid[2000][2000] = {0}; 
    for(int i = b1x1+1000; i < b1x2+1000; i++){
        for(int j = b1y1+1000; j<b1y2+1000; j++){
            grid[i][j] = 1; 
        }
    }
    for(int i = b2x1+1000; i < b2x2+1000; i++){
        for(int j = b2y1+1000; j<b2y2+1000; j++){
            grid[i][j] = 1; 
        }
    }
    for(int i = tx1+1000; i < tx2+1000; i++){
        for(int j = ty1+1000; j<ty2+1000; j++){
            grid[i][j] = 0; 
        }
    }
    int ans = 0; 
    for(int i = 0; i < 2000; i++){
        for(int j = 0; j < 2000; j++){
            ans += grid[i][j]; 
        }
    }
    fout << ans;
}