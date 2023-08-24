#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin("trapped.in");
    ofstream fout("trapped.out");
    int n;
    fin>>n;
    vector<pair<int, int>> haybales;
    vector<long long> hayPos;
    vector<long long> haySize;
    for(int i = 0; i < n; i++){
        long long a, b;
        fin>>a>>b;
        haybales.push_back(make_pair(b, a));
        //pos is first
    }
    int ans = 0;
    sort(haybales.begin(), haybales.end());
    for(int i = 0; i < n; i++){
     //   cout<<haybales[i].first << " "<<haybales[i].second<<"\n";
    }
    //cout<<totaldist;
    for(int i = 0; i < n-1; i++) {
      int areaOfInterval = haybales[i+1].first - haybales[i].first;
      int leftmostBale = i;
      int rightmostBale = i+1;
      // while Bessie could still be trapped
      while(leftmostBale >= 0 && rightmostBale <= n-1) {
        bool broke = false;
        int currDist = haybales[rightmostBale].first - haybales[leftmostBale].first;
        if(currDist > haybales[leftmostBale].second) {
          leftmostBale--;
          broke = true;
        }
        if(currDist > haybales[rightmostBale].second) {
          rightmostBale++;
          broke = true;
        }
        // Bessie couldn't break through either the left or the right bale, so stop
        if(!broke) {
          break;
        }
      }
      // Bessie couldn't break out
      if(leftmostBale >= 0 && rightmostBale <= n-1) {
        ans += areaOfInterval;
      }
    }
    fout<<ans;
}