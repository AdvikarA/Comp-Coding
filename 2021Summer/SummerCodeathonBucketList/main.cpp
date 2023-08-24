#include <fstream>
using namespace std; 
int main() {
    ifstream fin("blist.in");
    ofstream fout("blist.out");
    int N; 
    fin >> N; 
    int ans = 0; 
    int time[1000] = {0}; 
    for(int i = 0; i < N; i++){
        int s, t, b; 
        fin >> s >> t >> b; 
        for(int j = s; j <= t; j++){
            time[j]+=b; 
        }
    }
    for(int i = 0; i < 1000; i++){
        //fout << time[i] << "\n";
        ans = max(ans, time[i]);
    }
    fout << ans; 
}