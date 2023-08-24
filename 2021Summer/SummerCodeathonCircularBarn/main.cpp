#include <fstream>
#include <map>
using namespace std;
int main(){
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int n; 
    fin >> n;
    int bans = 2147483647; 
    int capacity[n]; 
    map<int, bool>seen;
    for(int i = 0; i < n; i++){
        fin >> capacity[i];
    }
    
    for(int i = 0; i < n; i++){
        int door = i; 
        int ans = 0;
        for(int j = 0; j < n; j++){
            if(door == n){
                door = 0; 
            }
            ans+= capacity[door]*j; 
            door++; 
        }
        bans = min(bans, ans);
    }
    fout << bans; 
    

}
