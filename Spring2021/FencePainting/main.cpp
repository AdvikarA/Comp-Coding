#include <fstream>
using namespace std;
int main() {
  ifstream fin ("paint.in");
  ofstream fout ("paint.out");
  int a, b, c, d;
  int answer = 0; 
  fin >> a >> b; 
  fin >> c >> d;
  for (int i = 0; i < 100; i++){
    if (i >= a && i+1 <= b){
      answer++;
    }
    else if(i >= c && i+1 <= d){
      answer++;
    }
  }
  fout << answer;
}