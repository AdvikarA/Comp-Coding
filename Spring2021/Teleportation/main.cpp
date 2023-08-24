#include <fstream>
#include <algorithm>
using namespace std; 
int main() {
  int posx;
  int posy;
  int tel1; 
  int tel2; 
  ifstream fin("teleport.in");
  ofstream fout("teleport.out");
  fin >> posx;
  fin >> posy; 
  fin >> tel1; 
  fin >> tel2;
  int distancetotravel = abs(posx - posy);
  int portalsaved = abs(tel1 - tel2); 
  distancetotravel = min(distancetotravel, abs(posx - tel1)+abs(posy - tel2));
  distancetotravel = min(distancetotravel, abs(posx - tel2)+abs(posy - tel1));

  fout << distancetotravel; 
}