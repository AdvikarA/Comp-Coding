#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    ifstream fin ("cownomics.in"); 
    ofstream fout ("cownomics.out");
    int N;
    int M;
    fin>> N >> M; 
    int ans = 0;
    char spot[N*M];
    char plain[N*M];
    for(int a=0; a<N; a++){
        for(int b=0; b<M; b++){
          fin>> spot[b + M*a]; 
        }
    }
     for(int a=0; a<N; a++){
        for(int b=0; b<M; b++){
          cin >> plain[b + M*a];
        }
    }
    int count = 0;
    for(int i=0; i<M; i++){
      for(int j=0; j<N; j++){
        for(int k=0; k<N; k++){
          if(spot[i + M*j] == plain[i + M*k]){
            count += 1;
          }
        }
      }
      if(count == 0){
        ans += 1;
      } 
      count = 0;
    }
    fout<< ans; 
  
}