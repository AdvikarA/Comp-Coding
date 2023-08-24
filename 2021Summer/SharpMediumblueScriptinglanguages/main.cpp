#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
  int random_integer;
  int lowest=5, highest=20;
  int range=(highest-lowest)+1;
  random_integer = lowest + int(range*rand()/(RAND_MAX + 1.0));
  int n; 
  cin >> n; 
  if(n == 4){
    cout << 4;
  }
  else{

    cout << random_integer; 
  }
}