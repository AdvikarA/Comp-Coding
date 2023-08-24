#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std; 
int main(){
    ifstream fin ("highcard.in");
    ofstream fout ("highcard.out");
    int n;
    fin>>n;
    vector<int>cowcards;
    for(int i = 0; i < n; i++){
        int a;
        fin>>a;
        cowcards.push_back(a);
    }
    bool taken[n*2];
    for(int i = 0; i <= n*2; i++){
        taken[i] = false;
    }
    
    sort(cowcards.rbegin(), cowcards.rend());
    
    int highest = 2*n;
    int ans = 0;
    for(int i = 0; i < n; i++){
        while(taken[highest] == true){
            //cout << "but " << highest << " is taken\n";
            highest--;
        }
        if(cowcards[i] != highest){
            
            ans++;
            taken[highest] = true;
            taken[cowcards[i]] = true;
            highest--;
        }
        else{
            taken[cowcards[i]] = true;
            highest--;
        }
        //cout << highest << " " << cowcards[i] << "\n";

    }
    //6 4 2
    
    fout<<ans;
}