#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("cowjog.in");
    ofstream fout ("cowjog.out");
    int N, T;
    fin>>N>>T;
    vector<pair<long long, long long>> input;
    vector<long long> endpos;
    for(int i = 0; i < N; i++){
        long long a, b;
        fin >> a >> b;
        input.push_back(make_pair(a, b));
    }

    sort(input.rbegin(), input.rend());
    for(long long i = 0; i < N; i++){
        endpos.push_back(input[i].first + input[i].second*T);
    }
    
    long long ending = 9223372036854775807;
    long long groups = 0; 
    for(long long i = 0; i < N; i++){
        if(endpos[i] < ending){
            groups++;
            ending = endpos[i];
        }
    }
    fout << groups;

            

}