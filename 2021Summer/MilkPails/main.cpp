#include <iostream>
#include <fstream>
using namespace std;
int main() {
    ifstream fin ("pails.in");
    ofstream fout ("pails.out");
    long long maxans = 0;
    long long x, y, m; 
    fin >> x >> y >> m; 
    for(long long a = 0; a < m/x; a++){
        long long b = (m - a * x)/y; 

        maxans = max(maxans, a*x + b*y);
	
    }
    fout <<maxans; 
}