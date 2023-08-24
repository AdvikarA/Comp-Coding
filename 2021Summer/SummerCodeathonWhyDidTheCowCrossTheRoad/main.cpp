#include<fstream>
using namespace std;
int main(){
    ifstream fin("crossroad.in");
    ofstream fout("crossroad.out"); 
    int cows[10]; 
    for(int i = 0; i < 10; i++){
        cows[i] = 2; 
    }
    int n; 
    fin >> n;
    int ans = 0; 
    for(int i = 0; i < n; i++){
        int x, y;
        fin >> x >> y; 
        if(cows[x-1] == 2){
            cows[x-1] = y; 
        }
        else{
            if(cows[x-1] != y){
                ans++; 
                cows[x-1] = y; 
            }
        }
    }
    fout << ans; 
}