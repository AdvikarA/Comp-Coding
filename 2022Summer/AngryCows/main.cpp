#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
bool works(vector<int> cows, int r, int k, int n){
    int count = 0;
    int pos = 0;
    int last = 0;
    while(last < n) {
        count++;
        int pos = last+1;
        while(pos < n && cows[pos] - cows[last] <= 2*r) {
            pos++;
        }
        last = pos;
    }
    if(count <= k){
        return true;
    }
    else{
        return false;
    }
    return true;
}
int main(){
    ifstream fin ("angry.in");
    ofstream fout ("angry.out");
    int n, k;
    fin >> n >> k;
    vector<int> cows;
    for(int i = 0; i < n; i++){
        int a; 
        fin >> a;
        cows.push_back(a);
    }
    int mid = 0;
    sort(cows.begin(), cows.end());
    int a = 0, b = 500000000;
    while (a != b) {
        mid = (a+b)/2;
        if (works(cows, mid, k, n)) {
            b = mid;
        }
        else {
            a = mid+1;
        }
    }
    fout << a;

}