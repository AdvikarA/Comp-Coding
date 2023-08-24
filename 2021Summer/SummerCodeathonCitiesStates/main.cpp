#include <fstream>
#include <map>
#include <utility>
#include <string.h>
#include <vector>
using namespace std; 
int main() {
    ifstream fin("citystate.in");
    ofstream fout("citystate.out"); 
    int n;
    fin >> n; 
    //map<string, string>loco; 
    pair<string, string>loco[n]; 
    map<int, string>num; 
    for(int i = 0; i < n; i++){
        string city; 
        fin >> city;
        string code; 
        fin >> code; 
        loco[i] = make_pair(city, code);
        //loco[city] = code; 
        num[i] = city; 
    }
    int ans = 0; 
    for(int i = 0; i < n; i++){
        string sub = num[i].substr(0,2);
        for(int j = i+1; j<n; j++){
            string sub2 = num[j].substr(0,2); 
            if(sub == loco[j].second && sub2 == loco[i].second){
                ans++; 
            }
        }
    }
    fout << ans; 
}