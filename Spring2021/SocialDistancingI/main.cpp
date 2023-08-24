#include <fstream>
using namespace std; 
#include <string>
int main() {
  ifstream fin ("socdist1.in");
  ofstream fout ("socdist1.out");
  long long max;
  fin>> max; 
  long long oldi = 0; 
  long long distance =0; 
  long long secondbig = 0; 
  int newd; 
  string stalls;
  long long d =0; 
  for(int i = 0; i < max; i++){
    fin>> stalls[i];
  }
  
  for(int i = 0; i < max; i++){
    if(i == max-1){
      if(stalls[max-1] == '0'){
        distance = max-oldi-1; 
        oldi = i;
        if(distance > d){
        secondbig = d; 
        d = distance; 
        }
        else if(distance > secondbig){
        secondbig = distance;  
        }
      }
    }
    if(stalls[i] == '1'){
      distance = i - oldi;
      oldi = i;
      if(distance > d){
        secondbig = d; 
        d = distance; 
      }
      else if(distance > secondbig){
        secondbig = distance;  
      }
    }
  }
  if(secondbig %2 == 0){
    secondbig = secondbig/2;
  }
  else{
    secondbig = (secondbig+1)/2;
  }
  if (secondbig ==0 && d != 0){
    fout<<d; 
  }
  else{
    fout<< secondbig; 
  }
}