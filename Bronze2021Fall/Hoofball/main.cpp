#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> pos;
int n;
int check(int i){
    if(i == 0){
        return i+1; 
    }
    else if(i == n-1){
        return i-1;
    }
    else if(pos[i+1] - pos[i] < pos[i] - pos[i-1] ){
        return i+1;  

    }
    else{
        return i-1;  
    }
}
int main(){
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");
    fin >> n;
    for(int i = 0; i < n; i++){
        int a;
        fin >> a;
        pos.push_back(a);
    }
    int ans = 0;
    int pptm[n] = {0}; 
    sort(pos.begin(), pos.end()); 
    for(int i = 0; i < n; i++){
        pptm[check(i)]++; 
    }
    for(int i = 0; i < n; i++){
        //fout << pptm[i] << " ";
        if(pptm[i] == 0){
            ans++; 
        }
        if(i < check(i) && check(check(i)) == i && pptm[i] == 1 && pptm[check(i)] == 1){
            ans++;
        }
    }
    fout << ans;
}