#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("berries.in");
    ofstream fout ("berries.out");
    int N, K;
    fin >> N >> K; 
    vector<int> Trees;
    for(int i = 0; i < N; i++){
        int a; fin >> a;
        Trees.push_back(a);
    }
    sort(Trees.rbegin(), Trees.rend()); 
    vector<int> topKTrees;
    vector<int> finalTrees;

    for(int i = 0; i < K; i++){
        topKTrees.push_back(Trees[i]); 
        finalTrees.push_back(Trees[i]);
    }
    for(int i = 0 ; i < topKTrees.size(); i++){
        cout << topKTrees[i]; 
    }
    int biggest = topKTrees[0];         
    int mod = biggest % i; 

    for(int i = 0; i < biggest; i++){
        int n = int(biggest/i);
        finalTrees.push_back(n);

    }
    

}