#include <iostream>
#include <fstream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    ifstream fin ("reststops.in");
    ofstream fout ("reststops.out");
    long long L, N;
    long long farmerspeed, cowspeed;
    fin >> L >> N >> farmerspeed >> cowspeed;
    vector<pair<long long, long long>> stops;
    for(long long i = 0; i < N; i++){
        long long a, b;
        fin >> a >> b;
        stops.push_back(make_pair(b, a));
    }
    sort(stops.rbegin(), stops.rend());
    for(long long i = 0; i < N; i++){
       cout << stops[i].first << " " << stops[i].second << "\n";
    }
    long long biggest = 0;
    long long ans = 0;
    for(long long i = 0; i < N; i++){
        if(stops[i].second > biggest){
            long long secondsahead = (farmerspeed*(stops[i].second-biggest))-(cowspeed*(stops[i].second-biggest));
            //cout << (stops[i].first * secondsahead) << " " << biggest<< "\n";
            ans += (stops[i].first * secondsahead);
            biggest = stops[i].second;
        }
    }
    fout << ans;

}