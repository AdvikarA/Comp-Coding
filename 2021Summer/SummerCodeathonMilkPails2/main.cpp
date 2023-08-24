#include <fstream>
using namespace std;
int main(){
    ifstream fin("pails.in");
    ofstream fout("pails.out");
    int x, y, m;
    int ans = 0; 
    fin >> x >> y >> m; 
    for(int i = 0; i <= m/x; i++){
        for(int j = 0; j <= m/y; j++){
            if((i*x + j*y) <= m){
                ans = max(ans, (i*x + j*y)); 
            }
        }
    }
    fout << ans; 
}