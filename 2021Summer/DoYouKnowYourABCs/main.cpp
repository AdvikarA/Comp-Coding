#include <iostream>
#include <algorithm> 
using namespace std; 
int main() {
  int abcs[7];
  for (int i = 0; i < 7; i++){
    cin >> abcs[i];
  }
  sort(abcs, abcs+7);
  int a = abcs[0];
  int b = abcs[1];
  int c = abcs[6] - a - b; 
  cout << a << ' '<< b << ' ' << c;  
   
}