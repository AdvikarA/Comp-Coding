#include <fstream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    ifstream fin ("lemonade.in");
    ofstream fout ("lemonade.out");
    int N;
    fin >> N; 
    vector<int> cows;
    for(int i = 0; i < N; i++){
        int a;
        fin>>a;
        cows.push_back(a);
    }
    sort(cows.rbegin(), cows.rend());
    int linelength = 0;
    for(int i = 0; i < N; i++){
        if(cows[i] >= linelength){
            linelength++;
        }
    }
    fout<<linelength;
}