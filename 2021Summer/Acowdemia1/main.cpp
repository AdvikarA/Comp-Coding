#include <iostream>
#include <algorithm>
using namespace std; 
typedef long long ll; 
ll maxoc(ll i, ll n, ll list[]){
  int occurence = 0; 
  for(int j = 0; j < n; j++){
    if(i <= list[j]){
      occurence++; 
    }
  }
  return occurence; 
}
int main() {
  ll n, l; 
  cin >> n >> l; 
  ll work[n]; 
  ll max = 0; 
  for(int i = 0; i < n; i++){
    cin >> work[i]; 
  }
  ll occurence = 0; 
  ll counter = 0; 
  sort(work, work+n); 
  if(l != 0){
    for(int i =0; i < l; i++){
      for(int j = 0; j < n; j++){
        work[j]+=1; 
        l-=1; 
        occurence = maxoc(work[j], n, work);
        if(occurence > max){
          if(work[j] > max){
            max = work[j]; 
          } 
        }
      }
    }
  }
  else{
    for(int i = 0; i <n; i++){
      occurence = maxoc(work[i], n, work);
      if(occurence > max){
        if(work[i] > max){
          max = work[i]; 
        } 
      }
    }
    
  }
  cout << max; 
}
