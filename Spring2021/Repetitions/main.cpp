#include <iostream>
using namespace std; 
int main() {
  string n;  
  cin >> n; 
  long long count = 1;
  long long maxcount = 1; 
  long long len = n.length(); 
  for (int i = 0; i < len; i++){
    if(n[i] == n[i+1]){
      count +=1; 
    }
    else{
      if(count > maxcount){
        maxcount = count; 
      }
      count = 1; 
    }
  }
  cout << maxcount; 
}