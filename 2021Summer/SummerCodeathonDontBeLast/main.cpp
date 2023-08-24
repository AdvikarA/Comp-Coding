#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main() {
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    int n; 
    fin >> n; 
    string cows[7] = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
    map<string, int>m;
    for(int i = 0; i < 7; i++){
        m[cows[i]] = 0;
    }
    for(int i = 0; i < n; i++){
        string s; 
        int milk;
        fin>> s >> milk; 
        int temp = m[s]; 
        m[s] += milk; 
    }
    int smallest = 10000; 
    int smol; 
    for(int i = 0; i < 7; i++){
        if(m[cows[i]] < smallest){
            smallest = m[cows[i]]; 
            smol = i;  
        }
    }
    int smallest2 = 10000; 
    string smol2;
    int mincount = 0; 
    int count = 1; 
    for(int i = 0; i < 7; i++){
        if(m[cows[i]] != smallest){
            if(m[cows[i]] < smallest2){
                smallest2 = m[cows[i]]; 
                smol2 = cows[i];
                //cout << smol2; 
                count = 1;    
            }
            else if(m[cows[i]] == smallest2){
                count++; 
            }
            //cout << count; 
        }
        else{
            mincount++;  
        }
    }
    if(mincount == 7){
        fout<< "Tie"; 
        return 0; 
    }
    if(count == 1){
        fout<<smol2<<"\n";
    }
    else{
        fout<< "Tie\n"; 
    }
}