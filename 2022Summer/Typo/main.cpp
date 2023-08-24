#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream fin("typo.in");
    ofstream fout("typo.out");
    string n;
    int ans = 0;
    fin >> n; 
    int values[n.size()+1];
    int prefix[n.size()+1];
    prefix[0] = 0;
    values[0] = 0;
    for(int i = 0; i < n.size(); i++){
        if(n[i] == '('){
            values[i+1] = 1;
        }
        else{
            values[i+1] = -1; 
        }
    } 
    for(int i = 1; i <= n.size(); i++){
        prefix[i] = prefix[i-1] + values[i];
    }
    for(int i = 0; i <= n.size(); i++){
        //cout << prefix[i] <<" ";
    }
    int lastneg = n.size()+1; 
    for(int i = 1; i <= n.size(); i++){
        //cout << values[i-1]<<" ";
        if(prefix[i] < 0){
            lastneg = min(lastneg, i);
        }
        
        //cout << lastneg << "\n";
        if(values[i] == 1){
            if(prefix[n.size()]-2==0 && lastneg >= i && i != 1){
                ans++;
            }
        }
        if(values[i] == -1){
            if(prefix[n.size()]+2==0 && lastneg >= i && i != n.size()){
                ans++;
            }
        }
    }
    fout << ans;

}