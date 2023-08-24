#include <iostream>
#include <fstream>
using namespace std; 
int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int N, M; 
    int ans = 0; 
    int distance = 0; 
    fin >> N >> M; 
    int limits[100] = {0};
    int currseg = 0; 
    for(int i = 0; i < N; i++){
        int segment, limit;
        fin >> segment >> limit; 

        for(int j = 0; j < segment; j++){
            limits[currseg] = limit; 
            currseg++; 
        }
    }
    currseg = 0; 
    int speeds[100];
    for(int i = 0; i < M; i++){
        int segment, speed;
        fin >> segment >> speed; 

        for(int j = 0; j < segment; j++){
            speeds[currseg] = speed; 
            currseg++; 
        }
    }
    for (int i = 0; i < 100; i++)
    {
        int difference = speeds[i] - limits[i];
        ans = max(difference, ans);
    }
    fout << ans; 
    
}