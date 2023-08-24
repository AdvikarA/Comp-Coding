#include <fstream>
using namespace std; 
int main(){
    ifstream fin("square.in");
    ofstream fout("square.out"); 
    int r1x1, r1y1, r1x2, r1y2, r2x1, r2y1, r2x2, r2y2;
    fin >> r1x1 >> r1y1 >> r1x2 >> r1y2 >> r2x1 >> r2y1 >> r2x2 >> r2y2; 
    int side1 = abs(min(min(r1x1, r1x2), min(r2x1, r2x2))-(max(max(r1x1, r1x2), max(r2x1, r2x2))));
    int side2 = abs(min(min(r1y1, r1y2), min(r2y1, r2y2))-(max(max(r1y1, r1y2), max(r2y1, r2y2))));
    int ans = max(side1, side2) * max(side1, side2); 
    fout << ans; 

    //6 6 8 8
   // 1 8 4 9
}