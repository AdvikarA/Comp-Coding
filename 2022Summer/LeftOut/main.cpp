#include<iostream>
#include<fstream>
using namespace std;
char grid[1001][1001];
int n;
void flipRow(int x){
    for(int i = 0; i < n; i++){
        if(grid[x][i] == 'L'){
            grid[x][i] = 'R';
        }
        else{
            grid[x][i] = 'L';
        }
    }
}
void flipCol(int x){
    for(int i = 0; i < n; i++){
        if(grid[i][x] == 'L'){
            grid[i][x] = 'R';
        }
        else{
            grid[i][x] = 'L';
        }
    }
}
int main(){
    ifstream fin ("leftout.in");
    ofstream fout ("leftout.out");
    fin>> n;
    for(int i = 0; i < n; i++){
        string s;
        fin >> s; 
        for(int j = 0; j < n; j++){
            grid[i][j] = s[j];
        }
    }
    for(int i = 0; i < n; i++){
        if(grid[0][i] == 'L'){
            flipCol(i);
        }
    }
    for(int i = 1; i < n; i++){
        if(grid[i][0] == 'L'){
            flipRow(i);
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cout << grid[i][j] << " ";
        }
        //cout << "\n";
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 'L'){
                count++;
            }
        }
    }
    if(count == (n-1)*(n-1)){
        fout << 1 << " " << 1;
        return 0;
    }
    if(count == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 'L'){
                    fout << i+1 << " " << j+1 << "\n";
                    return 0; 
                }
            }
        }
    }
    if(count == n-1){
        for(int i = 0; i < n; i++){
            int check = 0;
            for(int j = 1; j < n; j++){
                if(grid[j][i] == 'L'){
                    check++;
                }
            }
            if(check == n-1){
                fout << i+1 << " " << 1;
                return 0; 
            }
        }
        for(int i = 0; i < n; i++){
            int check = 0;
            for(int j = 1; j < n; j++){
                if(grid[i][j] == 'L'){
                    check++;
                }
            }
            if(check == n-1){
                fout << i+1 << " " << 1;
                return 0; 
            }
        }
    }
    fout << -1 << "\n";
    return 0;

}