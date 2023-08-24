#include <iostream>
#include <algorithm> 
using namespace std; 
int main() {
  long long n;
  long long sum = 0;
  cin >> n; 
  for (int i = 1; i < n; i++){
    int tmp; cin >> tmp;
    sum += tmp; 
  }
  cout << (n*(n+1)/2) - sum; 
}