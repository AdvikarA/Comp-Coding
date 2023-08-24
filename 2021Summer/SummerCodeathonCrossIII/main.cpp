#include <fstream>
using namespace std; 
typedef long long ll; 
int main() {
    ifstream fin("cowqueue.in"); 
    ofstream fout("cowqueue.out"); 
    ll n; 
    fin>> n; 
    ll start[n];
    ll dur[n]; 
    for(ll i = 0; i < n; i++){
        fin >> start[i] >> dur[i];
    }
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n-1; j++){
            if(start[j] > start[j+1]){
                ll temp1 = start[j];
                ll temp2 = dur[j]; 
                start[j] = start[j+1]; 
                dur[j] = dur[j+1]; 
                dur[j+1] = temp2; 
                start[j+1] = temp1; 
            }
        }
    }
    ll time = 0; 
    for(ll i = 0; i < n; i++){
        if(start[i] > time){
            time = start[i]; 
        }
        time += dur[i]; 
    }
    fout << time; 
}