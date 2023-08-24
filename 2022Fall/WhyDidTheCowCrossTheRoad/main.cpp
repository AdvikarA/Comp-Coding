#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
int main(){
    int n, c;
    ifstream fin ("helpcross.in");
    ofstream fout ("helpcross.out"); 
    fin >> n >> c; 
    vector<int>chickens;
    for(int i = 0; i < n; i++){
        int a; fin >> a;
        chickens.push_back(a);
    }
    sort(chickens.begin(), chickens.end()); 
    vector<pair<int, int>>cowtimes;
    for(int i = 0; i < c; i++){
        int a, b;
        fin >> a >>b;
        cowtimes.push_back(make_pair(b, a)); 
    }
    sort(cowtimes.begin(), cowtimes.end()); 
    bool crossed[c];
    for(int i = 0; i < c; i++){
        crossed[i] = false;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < c; j++){
            if(chickens[i] >= cowtimes[j].second && chickens[i] <= cowtimes[j].first && crossed[j] != true){
                cout << chickens[i] << " is in " << cowtimes[j].first << " " << cowtimes[j].second << "\n";
                crossed[j] = true;
                break;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < c; i++){
        if(crossed[i] == true){
            ans++;
        }
    }
    fout << ans;
}