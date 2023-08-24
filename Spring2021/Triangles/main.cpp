#include <fstream>
using namespace std;
int main() {
  ifstream fin ("triangles.in");
  ofstream fout ("triangles.out");
  long long n; 
  fin >> n; 
  long long a; 
  long long b; 
  long long area;
  long long biggestarea = 0; 
  pair<int,int> array_of_pairs[n];
  for(int i = 0 ; i < n; i++){
    fin >> a >> b;
    array_of_pairs[i] = make_pair(a,b);
  }
  for(int i = 0 ; i < n; i++){
    for(int j = 0; j < n; j++){
      for(int asd = 0; asd < n; asd++){
        if(array_of_pairs[i].first == array_of_pairs[j].first && array_of_pairs[i].second == array_of_pairs[asd].second){
          area = abs(array_of_pairs[i].first - array_of_pairs[asd].first)*abs(array_of_pairs[j].second - array_of_pairs[asd].second);
        }
        if(area > biggestarea){
          biggestarea = area; 
        }
      }
    }
  }
  fout << biggestarea; 
}