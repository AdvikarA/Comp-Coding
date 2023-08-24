#include <iostream>
using namespace std; 
#include <algorithm>
#include <math.h>
int main() {
  long long max;
  long long index =0;
  long long combo =0;
  long long perms = 1; 
   
  cin >> max;
  long long maxlist[max];
  long long heights[max];
  for(int i = 0; i<max; i++){
    cin >> maxlist[i];
  }
  for(int i = 0; i<max; i++){
    cin >> heights[i];
  }
  sort(maxlist, maxlist+max); 
  for(int i = max-1; i >= 0; i--){
    for(int j = 0; j < max; j++){
      if(maxlist[i] <= heights[j]){
        combo = combo + 1; 
      }
    }
    combo= combo- index; 
    index = index + 1; 
    perms = perms * combo;
    combo = 0; 
  } 
  cout << perms; 
}