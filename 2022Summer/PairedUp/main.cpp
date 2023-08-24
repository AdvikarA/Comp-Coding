#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("pairup.in");
    ofstream fout ("pairup.out");
    int n; 
    fin>>n; 
    vector<pair<int, int>> input;
    for(int i = 0; i < n; i++){
        int a, b;
        fin>>a>>b;
        input.push_back(make_pair(b, a));
    }
    int num = 0;
    sort(input.begin(), input.end());
    for(int i = 0; i < n; i++){
        num += input[i].second;
        //cout<<input[i].second<<"\n";
    }
    //cout<<num<<"\n";
    int paira = 0;
    int pairb = n-1;
    int a =0;
    int b = 0;
    int biggest = 0;
    while(num != 0){
        a++;
        b++;
        num-=2;
        //cout<<"front: "<<input[paira].first<<"\n";
        //cout<<"back: "<<input[pairb].first<<"\n";
        //cout<<"front: "<<a<<" "<<input[paira].second<<"\n";
        //cout<<"back: "<<pairb<<" "<<input[pairb].second<<"\n";
        //cout<<paira<<" "<<pairb<<"\n";
        biggest = max(biggest, input[paira].first + input[pairb].first);

        if(a == input[paira].second){
            paira++;
            a = 0;
        }
        if(b == input[pairb].second){
            pairb--;
            b = 0;
        }

        //cout<<biggest<<"\n";
    }
    fout<<biggest;
}