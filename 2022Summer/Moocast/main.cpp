#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include <algorithm>
using namespace std;
vector<int> adj[200];
bool visited[200]; 
int ans = 0; 
int final = 0;
void floodfill(int node){
    if (visited[node] == true) {
        return;
    }
    ans++;
    visited[node] = true;
    // transitions
    for (auto i : adj[node]) {
        floodfill (i);
    }

}
int main(){
    ifstream fin ("moocast.in");
    int n; 
    vector<pair<int, int>> coords;
    vector<int> powers;
    fin >> n; 
    for(int i = 0; i < n; i++){
        int a, b, c;
        fin >> a >> b >> c;
        coords.push_back(make_pair(a, b));
        powers.push_back(c);
    }
    for(int i = 0; i < 200; i++){
        visited[i] = false;
    }
    for(int i = 0; i < n; i++){
        int x1 = coords[i].first; 
        int y1 = coords[i].second;
        for(int j = 0; j < n; j++){
            if(i != j){
                int x2 = coords[j].first;
                int y2 = coords[j].second;
                if(powers[i]*powers[i] >= (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1)){
                    adj[i].push_back(j);
                }
            }

        }
    }
    for(int i = 0; i<n; i++){
        for(int i = 0; i < 200; i++){
            visited[i] = false;
        }
            ans = 0;
            floodfill(i);
            final = max(final, ans);
        
    }
    for(int i = 0; i < n; i++){
        //cout << "cow " << i << "\n";
        for(int j = 0; j < adj[i].size(); j++){
          //  cout << adj[i][j] << " ";
        }
        //cout << "\n";
    }
    ofstream fout ("moocast.out");
    fout << final; 
}