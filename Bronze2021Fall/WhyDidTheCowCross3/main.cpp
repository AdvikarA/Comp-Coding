#include <fstream>
#include <vector>
#include <utility> 
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("cowqueue.in");
    ofstream fout ("cowqueue.out");
    int n;
    fin >> n; 
    vector<pair<int, int>>v; 
    for(int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b; 
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n-1; i++){
        if(v[i+1].first < v[i].first + v[i].second){
            v[i+1].first = v[i].first + v[i].second;
        }
    }
    fout << v[n-1].first + v[n-1].second;
}