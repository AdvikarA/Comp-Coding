#include <fstream>
#include <algorithm>
using namespace std; 
int main() {
    ifstream fin("teleport.in");
    ofstream fout("teleport.out");
    int a, b, x, y; 
    fin >> a >> b >> x >> y; 
    int dist = abs(a - b); 
    int shortcut1 = abs(a - x) + abs(y-b);
    int shortcut2 = abs(a-y) + abs(b-x); 
    int ans =  min(dist, shortcut1);
    fout << min(ans, shortcut2); 
}