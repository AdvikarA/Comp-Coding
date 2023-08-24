#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
vector<int> adj[100000];
int visited[100000];   
vector<pair<int, int>> cows; 
int minx, maxx, miny, maxy;
void floodfill(int node, int color){
    if (visited[node]) {
        return;
    }
    int x  = cows[node].first;
    int y = cows[node].second;
    minx = min(minx, x);
    maxx = max(maxx, x);
    miny = min(miny, y);
    maxy = max(maxy, y); 
    visited[node] = color;
// transitions
    for (auto i : adj[node]) {
        floodfill (i, color);
    }


}
int main(){
    ifstream fin ("fenceplan.in");
    ofstream fout ("fenceplan.out");
    int n, m;
    fin >> n >> m;
    for(int i = 0; i < n; i++){
        int a, b;
        fin >> a>> b;
        cows.push_back(make_pair(a, b));
    }
    for(int i = 0; i < 100000; i++){
        visited[i] = 0; 
    }
    int ans = 2147483647; 
    for(int i = 0; i < m; i++){
        int a, b;
        fin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int color = 1;
    for (int i=0; i<n; i++) {
        minx = 100000000;
        miny = 100000000;
        maxx = 0;
        maxy = 0;
        if (!visited[i]) {
            floodfill (i, color);
            color++;
        }
        int area = 2147483647;
        if(minx != 100000000 && miny != 100000000 && maxx != 0 && maxy != 0)
        {
            area = (maxx-minx)*2 + (maxy-miny)*2;
        }
        //cout << minx << " " << maxx << " " << miny << " " << maxy << "\n";

        ans = min(area, ans);
    }
    fout << ans;
}