#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
bool deleted[3000];
int visited[3000];
vector<int> adj[3000];
void floodfilldelete(int node){    
    //cout << node << " ";
    if(deleted[node]){
        //cout << "GONE\n";
        return;
    }
    deleted[node] = true;
    for(int i = 0; i < adj[node].size(); i++){

        floodfilldelete(adj[node][i]);
    }
}
void floodfill(int node, int color){    
    //cout << node << " ";
    if(visited[node] || deleted[node]){
        //cout << "GONE\n";
        return;
    }
    visited[node] = color;
    for(int i = 0; i < adj[node].size(); i++){

        floodfill(adj[node][i], color);
    }
}
int main(){
    ifstream fin ("closing.in");
    ofstream fout ("closing.out");
    int n, m;
    fin >> n >> m; 
     
   
    for(int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        a--;
        b--;
        //cout << a << b << "\n";
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            //cout << adj[i][j] << " ";
        }
        //cout << "\n";
    }        
    for(int j = 0; j < 3000; j++){
            deleted[j] = false;
        } 
    for(int j = 0; j < 3000; j++){
            visited[j] = 0;
        } 
    for(int j = 0; j < n; j++){
        //cout << deleted[j] << " " << visited[j] << "\n";
    }    
    int color = 1;

    
    
    
    int node = 0;
    while(deleted[node]){
        node++;
    }
    floodfill(node, color);
    //if(i!=n-1){
        bool y = true;
        for(int j = 0; j < n; j++){
            if(!visited[j] && !deleted[j]){
                y = false;
            }
        }
        if(y){
            fout << "YES\n";
        }
        else{
            fout << "NO\n"; 
        }
    //}        
        //deleted[toDel] = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3000; j++){
            visited[j] = 0;
        } 
        for(int j = 0; j < n; j++){
            //cout << deleted[j] << " " << visited[j] << "\n";
        }    
        int color = 1;

        int toDel;
        fin >> toDel; 
        toDel--;
        
        //cout << "TODEL: " << toDel<<"\n";
        deleted[toDel] = true; 
        int node = 0;
        while(deleted[node]){
            node++;
        }
        floodfill(node, color);
        if(i!=n-1){
            bool y = true;
            for(int j = 0; j < n; j++){
                if(!visited[j] && !deleted[j]){
                    y = false;
                }
            }
            if(y){
                fout << "YES\n";
            }
            else{
                fout << "NO\n"; 
            }
        }        
        //deleted[toDel] = true;
        

    }
}