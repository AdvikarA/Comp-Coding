#include <fstream>
#include <map>
using namespace std;
int calcwin(string c1, string c2){
    if(c1 == "hoof"){
        if(c2 == "scissors"){
            return 1; 
        }
        
    }
    else if(c1 == "paper"){
        if(c2 == "hoof"){
            return 1; 
        }
    }
    else if(c1 == "scissors"){
        if(c2 == "paper"){
            return 1; 
        }
    }
    return 0; 
}
int main(){
    ifstream fin("hps.in");
    ofstream fout("hps.out"); 
    int n; 
    fin >> n; 
    int cow1[n]; 
    int cow2[n]; 
    int maxans = 0; 
    for(int i = 0; i < n; i++){
        fin >> cow1[i] >> cow2[i]; 
    }
    for(int i = 1; i <= 3; i++){
        map<int, string>m; 
        m[i] = "hoof";
        for(int j = 1; j <= 3; j++){
            if(i != j){
                m[j] = "paper";
            }
            for(int k = 1; k <= 3; k++){
                if(k != j && k != i){
                    m[k] = "scissors";
                }
                int ans = 0; 
                for(int l = 0; l < n; l++){
                    ans += calcwin(m[cow1[l]], m[cow2[l]]); 
                    maxans = max(maxans, ans); 
                }
            }
        }
    }
    fout << maxans; 
}