#include <fstream>
#include <string>
using namespace std;
int barn_i, barn_j, rock_i, rock_j, lake_i, lake_j;
 
int main()
{
  ifstream fin("buckets.in");
  ofstream fout("buckets.out");
  for (int i=0; i<10; i++) {
    string spaces;
    fin >> spaces;
    for (int j=0; j<10; j++) {
      if (spaces[j] == 'B'){
        barn_i = i; barn_j = j; 
      }
      if (spaces[j] == 'R') { 
        rock_i = i; rock_j = j; 
      }
      if (spaces[j] == 'L'){
        lake_i = i; lake_j = j; 
      }
    }
  }
  int dist_br = abs(barn_i - rock_i) + abs(barn_j - rock_j);
  int dist_bl = abs(barn_i - lake_i) + abs(barn_j - lake_j);
  int dist_rl = abs(rock_i - lake_i) + abs(rock_j - lake_j);

  // Check for special case where rock is between barn and lake  
  if ((barn_i==lake_i || barn_j==lake_j) && dist_bl == dist_br + dist_rl)
    fout << dist_bl + 1 << "\n";
  else
    fout << dist_bl - 1 << "\n";
 
  return 0;

}