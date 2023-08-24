#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std; 
int main(){
    int n; cin>>n; 
    int nodes[n];
    int target = 0;
    for(int i = 0; i < n; i++){
        cin >> nodes[i]; 
        target += nodes[i];
    }
    target /= n; 
    vector<vector<int>> adj;
    for(int i = 0; i < n; i++){
        adj.push_back({}); 
    }
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b; 
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1); 
    }
    
    
    int totalnodes = n; 
    cout << "\n";
    for(int i = 0; i < n; i++){
        if(adj[i].size() == 1){
            if(nodes[i] < target){
                cout << adj[i][0]+1 << " " << i+1 << " " << target - nodes[i] << "\n"; 
                nodes[adj[i][0]] -= (target - nodes[i]);
                nodes[i] = target; 
                
            }
            if(nodes[i] > target){
                cout << i+1 << " " << adj[i][0]+1 << " " << nodes[i] - target << "\n"; 
                nodes[adj[i][0]] += (nodes[i] - target); 
                nodes[i] = target; 
                
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(nodes[i] == target){
            adj.erase(adj.begin(), adj.begin()+i); 
        }
    }
    cout << "SIZE: " <<adj.size();
    /**
    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            if(nodes[i]!=target){
                if(nodes[i] > target){
                    cout << i+1 << " " << adj[i][j]+1 << " " << nodes[i] - target; 
                    nodes[adj[i][j]] += (nodes[i] - target); 
                    nodes[i] = target; 
                }
            }
        }
    }
    **/
    
}