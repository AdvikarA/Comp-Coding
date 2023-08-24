#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main(){
    ifstream fin("clumsy.in");
    ofstream fout("clumsy.out");
    string n;
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
    int ans = 0;
    for(int i = 1; i <= n.size(); i++){
        prefix[i] = prefix[i-1] + values[i];
        if(prefix[i] < 0){
            values[i] = 1; 
            ans++;
            prefix[i] = prefix[i-1] + values[i];
        }
     //   cout << prefix[i] << " ";
    }
    ans += prefix[n.size()]/2;
    fout<<ans;
    /**
    for(int i = 1; i <= n.size(); i++){
        
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
    **/

}