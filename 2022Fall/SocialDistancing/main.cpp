#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std; 
const int MAX = int(10e5); 
int n, m;
ifstream fin ("socdist.in");
ofstream fout ("socdist.out");
vector<pair<int, int>> grass; 
bool binary(int mid){
    cout << mid << "\n";
    int cows = 1;
    int pos = grass[0].first;
    //cout << "FIRST POS: " << pos << "\n";
    int gchunk = 0;
    int s = grass.size(); 
    for(int i = 0; i < m; i++){
        while(max(pos + mid, grass[i].first) <= grass[i].second){
            cows++;
            pos += mid; 
            pos = max(pos, grass[i].first);
            if(cows >= n){
                break;
            }
        }
        if(cows >= n){
            break;
        }
    }
    return(cows >= n); 

}
int main(){
    fin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b;
        fin >> a >> b;
        grass.push_back(make_pair(a, b)); 
    }
    sort(grass.begin(), grass.end());
    for(int i = 0; i < m-200; i++){
        //cout << grass[i].first << " " << grass[i].second << "\n";
    }
    int a = 0, b = MAX;
    while (a != b) {
        int mid = (a+b + 1)/2;
        if (binary(mid)) {
            a = mid;
        }
        else {
            b = mid-1;
        }
    }
    fout << a;
  
}