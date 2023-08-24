#include <fstream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
  ifstream fin ("lifeguards.in");
  ofstream fout ("lifeguards.out");
  vector<int> possiblevalues; 
  int numbercows; 
  fin>> numbercows; 
  int nextnum; 
  int s_time[numbercows];
  int t_time[numbercows];
  for(int i=0; i<numbercows; i++){
    fin>> s_time[i] >> t_time[i];
  }
  for(int i = 0; i < numbercows; i++){
    for(int j = 0; j < numbercows-1; j++){
      if(i == j+1){
        continue; 
      }
      if(j+1 == numbercows){
        j = -1; 
      }
      if(s_time[i] > t_time[j+1] || t_time[i] < s_time[j+1]){
        possiblevalues.push_back((t_time[i] - s_time[i])+(t_time[j+1])-s_time[j+1]);
      }
      else if(s_time[i]<t_time[j+1]){
        possiblevalues.push_back( t_time[i] - s_time[j+1]);
      }
      else if(t_time[i]>s_time[j+1]){
        possiblevalues.push_back(t_time[j+1] - s_time[i]); 
      }
    }
  }
  int answer = *max_element(possiblevalues.begin(), possiblevalues.end());
  fout<< answer; 
}