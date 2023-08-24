#include <iostream>
using namespace std;
int main() {
  long long n;
  cin >> n; 
  long long counter = 0; 
  long long nums[n]; 
  for(int i = 0; i < n; i++){
    cin >> nums[i]; 
  }
  for(int i = 0; i<n; i++){
    if(i == 0){
      continue;
    }
    else{
      while(nums[i] < nums[i-1]){
        nums[i]++; 
        counter++; 
      }
    }
  }
  cout << counter; 
}