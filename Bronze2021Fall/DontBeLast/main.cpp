#include <fstream>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("notlast.in");
    ofstream fout ("notlast.out");
    string jcows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    int n; 
    fin >> n;
    string cows[n];
    int milks[7] = {0};
    
    for(int i = 0; i < n; i++){
        int milk; 
        fin >> cows[i] >> milk; 
        for(int j = 0; j < 7; j++){
            if(cows[i] == jcows[j]){
                milks[j] += milk; 
            }
            
        }
    }
    int min = 1000000;
    for(int i = 0; i < 7; i++){
        if(milks[i] < min){
            min = milks[i]; 
        }
    }
    int min2 = 1000000;
    int key = -1;
    for(int i = 0; i < 7; i++){
        if(milks[i] < min2 && milks[i] != min){
            min2 = milks[i]; 
            key = i; 
        }
        else if(milks[i] == min2 && milks[i] != min){
            
            key = -1; 
            
        }
    }
    if(key == -1){
        fout << "Tie";
        return 0; 
    }
    fout << jcows[key]; 
    
}