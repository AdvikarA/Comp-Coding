#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("socdist2.in");
    ofstream fout ("socdist2.out");
    int n; 
    fin >> n; 
    vector<pair<int, int>>v; 
    for(int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b;
        v.push_back(make_pair(a, b)); 
    }
    int k = 100000;
    sort(v.begin(), v.end());
    for(int i = 1; i < n; i++){
        if(v[i].second != v[i-1].second){
            k = min(k, v[i].first-v[i-1].first);
        }
    }
    int ans = 0; 
    for(int i = 0; i < n-1; i++){
        if(v[i+1].first-v[i].first > k-1 && v[i+1].second == 1){
            ans++; 
        }
        
    }
    fout << ans; 
}