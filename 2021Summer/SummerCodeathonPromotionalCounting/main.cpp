#include <fstream>
using namespace std; 
int main() {
    ifstream fin ("promote.in");
    ofstream fout ("promote.out"); 
    int b1, b2, s1, s2, g1, g2, p1, p2; 
    fin >> b1 >> b2;
    fin >> s1 >> s2;
    fin >> g1 >> g2; 
    fin >> p1 >> p2; 
    int gTop = p2-p1; 
    g1 -= gTop; 
    int sTog = g2-g1; 
    s1 -= sTog; 
    int bTos = s2-s1; 
    
    fout << bTos << "\n" << sTog << "\n" << gTop; 
}