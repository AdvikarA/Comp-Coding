#include <fstream>
using namespace std;

int main() {
  ifstream fin ("blist.in");
  ofstream fout ("blist.out");
  int numofcows;
  int index; 
  bool locked = false; 
  int tbuckets =0; 
  int time = 0; 
  int bucketsavailible = 0; 
  fin >> numofcows;
  int s_time[numofcows];
  int t_time[numofcows]; 
  int buckets[numofcows];
  for (int i =0; i < numofcows; i++){
    fin >> s_time[i] >> t_time[i] >> buckets[i];
  }
  while(time < 1001){
    for(int i = 0; i < numofcows; i++){
      if(s_time[i] == time){
        if(buckets[i] > bucketsavailible){
          tbuckets += (buckets[i] - bucketsavailible);
        }
      }
      if(t_time[i] == time){
        bucketsavailible += buckets[i]; 
      }
    }
    time++; 
  }
  fout << tbuckets; 
}