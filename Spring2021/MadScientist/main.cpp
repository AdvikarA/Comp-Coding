#include <iostream>
#include <fstream>
using namespace std;
int main() {
  ifstream fin ("breedflip.in");
  ofstream fout ("breedflip.out"); 
  long long answer = 0;
  bool usemachine = false; 
  long long len; 
  fin>> len; 
  string want; 
  string given; 
  fin>> want >> given;
  for(int i=0; i<len; i++){
    if(want[i] != given[i]){
      if (usemachine == false){
        answer +=1; 
        usemachine = true; 
      }
      else{
        continue; 
      }
      
    }
    else{
      usemachine = false; 
      
    }
  }
  if (answer == 0){
    answer = 1; 
  }
  fout<< answer;
}