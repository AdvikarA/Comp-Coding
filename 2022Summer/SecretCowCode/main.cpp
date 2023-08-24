#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std; 
char check(string s, int i){
    int length = s.size();
    if(i <= length){
        return s[i-1];
    }
    while(length * 2 < i){
        length *= 2;
    }
    cout << length << " " << i << "\n";
    if(length + 1 == i){
        return check(s, length);
    }
    else{
        return check(s, i-length-1);
    }
}
main(){
    ifstream fin ("cowcode.in");
    ofstream fout ("cowcode.out");
    string s; int n;
    fin >> s >> n;
    fout << (check(s, n));

}