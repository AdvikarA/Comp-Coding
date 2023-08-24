#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
int main(){
    ifstream fin ("measurement.in");
    ofstream fout ("measurement.out");
    int n; 
    fin >> n;
    map <string, int> cows; 
    cows["Bessie"] = 7;
    cows["Elsie"] = 7;
    cows["Mildred"] = 7;
    int maxcownum = 7; 
    bool oldb = true;
    bool olde = true;
    bool oldm = true; 
    vector <pair<int, string>> cowlist;
    vector <pair<int, string>> changes;
    for(int i = 0; i < n; i++){
        int num;
        string cow, change; 
        fin >> num >> cow >> change;
        cowlist.push_back(make_pair(num, cow));
        changes.push_back(make_pair(num, change));
    }
    int ans = 0; 
    sort(cowlist.begin(), cowlist.end());
    sort(changes.begin(), changes.end());
    for(int j = 0; j < 100; j++){
        for(int i = 0; i < n; i++){
            if(cowlist[i].first == j){
                if(changes[i].second[0] == '+'){
                    string test = changes[i].second;
                    test.erase(0, 1);
                    cows[cowlist[i].second] += stoi(test);
                }
                else{
                    string test = changes[i].second;
                    test.erase(0, 1);
                    cows[cowlist[i].second] -= stoi(test);
                }
            }
        }
        bool changed = false; 
        maxcownum = max(cows["Bessie"], max(cows["Elsie"], cows["Mildred"])); 

        //fout << " " << maxcownum << " " << cows["Bessie"] << " " << cows["Elsie"] << " " << cows["Mildred"]  << " " << oldb << " " << olde << " " << oldm <<"\n";
        bool newb;
        if(cows["Bessie"] == maxcownum){
            newb = true; 
        }
        else{
            newb = false; 
        }
        bool newe;
        if(cows["Elsie"] == maxcownum){
            newe = true; 
        }
        else{
            newe = false; 
        }
        bool newn;
        if(cows["Mildred"] == maxcownum){
            newn = true; 
        }
        else{
            newn = false; 
        }
        if(oldb != newb || olde != newe || oldm != newn) {
            ans++;
        }
        oldb = newb;
        olde = newe;
        oldm = newn;
    }
    fout << ans; 
}