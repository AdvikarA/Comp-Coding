#include <iostream>
using namespace std; 
#include <string>
int main() {
  string alpha;
  cin >> alpha;
  string hum;
  int lettercount = 0; 
  cin >> hum;
  int outerloop = 0; 
  int n = hum.size();
  int answer; 
  while (lettercount < n){
      for(int j = 0; j < alpha.size();j++ ){
        if(hum[lettercount] == alpha[j]){
          lettercount +=1; 
        }
      }
      outerloop +=1; 
  }
  cout << outerloop; 
}