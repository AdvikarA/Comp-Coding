#include <iostream> 
#include <fstream> 
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("skidesign.in");
    ofstream fout ("skidesign.out");
    int n; fin >> n; 
    vector<int>hills;
    for(int i = 0; i < n; i++){
        int a; fin >> a;
        hills.push_back(a);
    }
    int ans = 240000000; 
    sort(hills.begin(), hills.end()); 
    for(int i = 1; i <= 83; i++){
        int dist = 0;
        for(int j = 0; j < n; j++){
            if(hills[j] < i){
                dist += (i- hills[j])*(i-hills[j]); 
                //cout << hills[j] << " " << i << "\n";
            }
            else if(hills[j] > i+17){
                dist += (hills[j]-(i+17))*(hills[j]-(i+17));
                //cout << hills[j] << " " << i+17 << "\n";
            }
        }
        ans = min(dist, ans);
    }
    fout << ans;
}