#include <fstream>
using namespace std;
int main(){
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    int n; 
    fin >> n; 
    string a, b; 
    fin >> a >> b; 
    int ans = 0; 
    bool flipping = true; 
    for(int i = 0; i < n; i++){
        if(b[i] != a[i]){
            if(flipping){
                flipping = false;
                ans++;
            }
            else{
                continue;
            }
        }
        else{
            flipping = true;
        }
    }
    fout << ans; 
}