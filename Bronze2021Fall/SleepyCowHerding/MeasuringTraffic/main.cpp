#include <fstream>

using namespace std;

int main() {
  ifstream fin("traffic.in");
  ofstream fout("traffic.out");
  int n; fin >> n;
  string type[n]; int low[n], high[n];
  for(int a=0; a<n; a++){
    fin >> type[a] >> low[a] >> high[a];
  }
  int ans1 = -999999999, ans2 = 999999999;
  for(int a=n-1; a>=0; a--){
    if(type[a] == "none"){
      ans1 = max(low[a], ans1);
      ans2 = min(high[a], ans2);
    } else if (type[a] == "on"){
      ans1 -= high[a];
      ans2 -= low[a];
      ans1 = max(ans1, 0);
    } else if (type[a] == "off"){
      ans1 += low[a];
      ans2 += high[a];
    }
  }
  fout << ans1 << " " << ans2 << "\n";
  ans1 = -999999999, ans2 = 999999999;
  for(int a=0; a<n; a++){
    if(type[a] == "none"){
      ans1 = max(low[a], ans1);
      ans2 = min(high[a], ans2);
    } else if (type[a] == "on"){
      ans1 += low[a];
      ans2 += high[a];
    } else if (type[a] == "off"){
      ans1 -= high[a];
      ans2 -= low[a];
      ans1 = max(ans1, 0);
    }
  }
  fout << ans1 << " " << ans2 << "\n";
  
}