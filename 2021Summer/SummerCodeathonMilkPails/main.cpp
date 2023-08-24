#include <fstream>
#include <algorithm>
using namespace std; 
int main() {
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int X, Y, M; 
    int maxs = 0; 
    fin>> X >> Y >> M; 
    int a = M/Y; 
    int b = M/X; 
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            int sum = Y*i + X*j; 
            if(sum <= M){
                maxs = max(sum, maxs); 
            }
        }
    }
    fout<< maxs; 
}