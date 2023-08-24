#include <fstream>
using namespace std;
int main(){
    ifstream fin ("diamond.in");
    ofstream fout ("diamond.out");
    int maxn = 0; 
    int n, k; 
    fin >> n >> k; 
    int diamonds[n]; 
    for(int i = 0; i < n; i++){
        fin >> diamonds[i];
    }
    for(int i = 0; i < n; i++){
        int ans = 1; 
        for(int j = 0; j < n; j++){
            if(i != j && diamonds[i] <= diamonds[j]){
                if((diamonds[j]-diamonds[i]) <= k){
                    ans++; 
                }
            }
        }
        maxn = max(ans, maxn); 
    }
    fout << maxn; 
}
