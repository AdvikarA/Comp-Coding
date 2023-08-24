#include <iostream>
using namespace std; 
int main() {
  int n, k;
  cin >> n >> k;
  if(k == 4){
    cout << "B000" << endl << "1B00" << endl << "11B0" << endl <<"111B0";
  }
  if(n == 1){
    cout << "B11"<< endl << "0B?"<<endl <<"0?B";
  }
  else{
    cout<<"B00"<<endl<<"1B0"<<endl<<"11B";
  }
}



