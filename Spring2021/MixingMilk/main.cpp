#include <fstream>
using namespace std; 
long long bcapacity[3];
long long milk[3]; 
void next(int num, int nextnum){
  long long pour = min(milk[num], bcapacity[nextnum]-milk[nextnum]);
  milk[num] -= pour; 
  milk[nextnum] +=pour; 
}
int main() {
  ifstream fin ("mixmilk.in");
  ofstream fout ("mixmilk.out");
  
  for ( int i = 0; i < 3; i++){
    fin>> bcapacity[i] >> milk[i]; 
  }
  for(int i=0;i<100;++i){
		next(i%3, (i+1)%3); 
  }
	for(int i=0;i<3;++i)
		fout<< (milk[i]) << endl;  
}