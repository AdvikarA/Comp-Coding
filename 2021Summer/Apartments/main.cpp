#include <iostream>
#include <set>
using namespace std; 
int main() {
  long long n, m, k; 
  long long temp; 
  long long ans = 0; 
  multiset<long long> price; 
  cin >> n >> m >>k; 
  long long want[n]; 
  for(int i = 0; i < n; i++){
    cin >> want[i]; 
  }
  for(int i = 0; i < m; i++){
    cin >> temp; 
    price.insert(temp); 
  }
  for(int i = 0; i < m; i++){
    auto it = price.lower_bound(want[i]-k);
    if(it == price.end()){
      continue; 
    }
    else if(*it > want[i]+k){
      continue; 
    }
    else{
      ans++; 
      price.erase(it); 
    }
  }
  cout << ans; 
}

// 30
//25
//35
