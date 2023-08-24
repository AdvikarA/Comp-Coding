#include <fstream>
using namespace std;
bool visible[2000][2000];

int main() {
  ifstream fin ("billboard.in");
  ofstream fout ("billboard.out");
  int x1, y1, x2, y2;
  for (int i = 0; i <3; i++){
    fin >> x1 >> y1 >> x2>> y2;
    x1 +=1000;
    y1 +=1000;
    x2+=1000;
    y2+=1000;
    for (int x = x1; x < x2; x++){
      for (int y = y1; y < y2; y++){
        if (i < 2){
          visible[x][y] = 1; 
        }
        else{
          visible[x][y] = 0;
        }
      }
    }
  }
  int answer=0;
  for (int x = 0; x < 2000; x++){
    for ( int y = 0; y < 2000; y++){
      answer += visible[x][y]; 
    }
  }
  fout<<answer; 
}