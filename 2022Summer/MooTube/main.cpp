#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
using namespace std;
int n; 
int ans = 0;
vector<pair<int, int>> adj[5000];
vector<bool> visited(5000);
int k, v, sol;

void dfs (int v) {
	visited[v] = true;
	for (auto x: adj[v]) {
		if (visited[x.first]) continue;
		if (x.second >= k) {
            //cout << x.second  << " s " << k << "\n";
			sol++;
			dfs(x.first);
		}
	}
}

int main(){
    ifstream fin ("mootube.in");
    ofstream fout ("mootube.out");
    int Q;
    fin >> n >> Q;
    for(int i = 0; i < n-1; i++){
        int p, q, r;
        fin >> p >> q >> r; 
        p--;
        q--;
        adj[p].push_back(make_pair(q, r)); 
        adj[q].push_back(make_pair(p, r)); 
    }
    for(int j = 0; j < 5000; j++){
            visited[j] = false;
        } 
    for(int i = 0; i < Q; i++){
        fin >> k >> v;
        v--;
		sol = 0;
		vector<bool> vS(n + 1);
		visited = vS;

		dfs(v);

		fout << sol << '\n';
        
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < adj[i].size(); j++){
            //cout << adj[i][j].first << " " << adj[i][j].second << "    ";
        }
        //cout << "\n";
    }
}