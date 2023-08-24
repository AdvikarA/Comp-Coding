#include <iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<math.h>
#include<algorithm>
using namespace std;
int main(){
    ifstream fin("marathon.in");
    ofstream fout("marathon.out");
    int n;
    fin>>n;
    vector<pair<int, int>> coords;
    vector<pair<int, int>> disttoskip;
    vector<pair<int, int>> finaldisttoskip;
    vector<int>skippeddist;
    for(int i = 0; i<n; i++){
        int a, b;
        fin>>a>>b;
        coords.push_back(make_pair(a, b));
    }
    int dist = 0;
    for(int i = 1; i <n; i++){
        int xs = abs(coords[i].first - coords[i-1].first);
        int ys = abs(coords[i].second - coords[i-1].second);
        cout<<"dist addeD: "<<xs+ys<<"\n";
        dist+=(xs+ys);
    }
    int skippa;
    int dif=0;
    for(int i = 1; i <n-1; i++){
        int xs = abs(coords[i].first - coords[i-1].first);
        int ys = abs(coords[i].second - coords[i-1].second);
        int xss = abs(coords[i+1].first - coords[i].first);
        int yss = abs(coords[i+1].second - coords[i].second);
        int skipx = abs(coords[i+1].first - coords[i-1].first);
        int skipy = abs(coords[i+1].second - coords[i-1].second);
        skippa=(skipx+skipy);
        dif = min(dif, skippa-(xs+ys+xss+yss));
    }
    //cout<<dist<<"\n";
    dist+=dif;
    fout<<dist;

}