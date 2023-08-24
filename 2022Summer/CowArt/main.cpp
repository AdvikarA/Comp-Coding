#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
using namespace std;
int n;
bool visited[102][102];
char c[102][102];
void floodfill (int x, int y, int region, char exp){
// base case
    //cout << c[x][y] << " " <<  exp << "\n";
    if (visited[x][y] || c[x][y] != exp) {
        return;
    }
    visited[x][y] = region;
    // transitions
    if(x>=1){
        floodfill(x-1, y, region, exp);
    }
    if(y>=1){
        floodfill(x, y-1, region, exp);
    }
    if(x<=98){
        floodfill(x+1, y, region, exp);
    }
    if(y<=98){
        floodfill(x, y+1, region, exp);
    }
}

int main(){
    ifstream fin ("cowart.in");
    ofstream fout ("cowart.out");
    fin >> n;
    for(int i = 0; i < n; i++){
        string s;
        fin >> s;
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
            c[i][j] = s[j]; 
        }
    }
    int regionhuman = 1;
    for (int i=0; i<n; i++) {
        for(int j = 0; j <n; j++){
            if (!visited[i][j]) {
                char exp = c[i][j];
                //cout << i << " " << j << "\n";

                floodfill (i,j, regionhuman, exp);
                regionhuman++;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = 0;
        }
    }
    int regioncow = 1;
    for (int i=0; i<n; i++) {
        for(int j = 0; j <n; j++){
            visited[i][j] = 0;
            if(c[i][j] == 'G'){
                c[i][j] = 'R';
            }
        }
    }
    for (int i=0; i<n; i++) {
        for(int j = 0; j <n; j++){
            //cout << c[i][j] << " ";
        }
        //cout << "\n";
    }
    for (int i=0; i<n; i++) {
        for(int j = 0; j <n; j++){
            if (!visited[i][j]) {
                char exp = c[i][j];
                //cout << exp << " " << j << "\n";

                floodfill (i,j, regioncow, exp);
                regioncow++;
            }
        }
    }
    fout << regionhuman-1<<" "<<regioncow-1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cout << c[i][j] << " ";
        }
        //cout << "\n";
    }

}