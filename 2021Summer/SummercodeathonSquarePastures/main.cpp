#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;
int main() {
    ifstream fin("square.in");
    ofstream fout("square.out");
    int x1, x2, y1, y2, bx1, bx2, by1, by2;
    fin >> x1 >> y1 >> x2 >> y2; 
    fin >> bx1 >> by1 >> bx2 >> by2;
    int area = max(max(max(x2, bx2),max(x1, bx1))-min(min(x2, bx2),min(x1, bx1)),max(max(y2, by2),max(y1, by1))-min(min(y2, by2),min(y1, by1)));
    fout << pow(area, 2); 
}