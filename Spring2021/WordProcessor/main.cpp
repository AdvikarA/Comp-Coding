#include <fstream>
#include <string> 
using namespace std; 

int main() {
  int n; 
  int k;
  int charsinline = 0; 
  ifstream fin("word.in");
	ofstream fout("word.out");
  fin >> n >> k; 
  string words[n]; 
  for (int i = 0; i < n+1; i++){
    fin >> words[i];
    if(i == 0){
      fout << words[i];
      charsinline += words[i].size();
    }
    else{
      if(words[i].size() + charsinline <= k){
        fout  << ' ' << words[i];
        charsinline += words[i].size();
      }
      else{
        fout << endl << words[i];
        charsinline = words[i].size(); 
      }
    }

  }

  
}