#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin("moocrypt.in");
    ofstream fout("moocrypt.out");
    int n, m;
    fin >> n >> m;
    char puzzle[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            fin>>puzzle[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //cout<<puzzle[i][j];
        }
    }
    long long ans[26][26];
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            ans[i][j] = 0;
        }
    }
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int M = 0; M < 26; M++){
        for(int o = 0; o < 26; o++){
            
            if(M != o && M != 12 && o != 14){
                for(int row = 0; row < n; row++){
                    for(int forwhor = 0; forwhor < m-2; forwhor++){
                        //cout<<puzzle[row][forwhor]<<puzzle[row][forwhor+1]<<puzzle[row][forwhor+2]<<"\n";
                        if(puzzle[row][forwhor] == alpha[M] && puzzle[row][forwhor+1] == alpha[o] && puzzle[row][forwhor+2] == alpha[o]){
                            ans[M][o]++;
                            //cout<<"DING\n";
                        }
                    }
                    for(int backhor = 2; backhor < n; backhor++){
                        //cout<<puzzle[row][forwhor]<<puzzle[row][forwhor+1]<<puzzle[row][forwhor+2]<<"\n";
                        if(puzzle[row][backhor] == alpha[M] && puzzle[row][backhor-1] == alpha[o] && puzzle[row][backhor-2] == alpha[o]){
                            ans[M][o]++;
                            //cout<<"DING\n";
                        }
                    }
                }
                for(int forvert = 0; forvert < n-2; forvert++){
                    for(int col = 0; col < m; col++){
                        if(puzzle[forvert][col] == alpha[M] && puzzle[forvert+1][col] == alpha[o] && puzzle[forvert+2][col] == alpha[o]){
                            ans[M][o]++;
                            //cout<<"DING\n";
                        }
                    }                
                }
                for(int backvert = 2; backvert < n; backvert++){
                    for(int col = 0; col < m; col++){
                        //cout<<"col: "<<col<<"\n";
                        if(puzzle[backvert][col] == alpha[M] && puzzle[backvert-1][col] == alpha[o] && puzzle[backvert-2][col] == alpha[o]){
                            ans[M][o]++;
                            //cout<<"DING\n";
                            //cout<<alpha[m]<<alpha[o]<<" " << backvert<<" "<<col<<"ss\n";
                        }
                    }                
                }
                for(int row = 0; row < n - 2; row++){
                    for(int col = 0;  col < m - 2; col++){
                        if(puzzle[row][col] == alpha[M] && puzzle[row+1][col+1] == alpha[o] && puzzle[row+2][col+2] == alpha[o]){
                            ans[M][o]++;
                            //cout<<"DING\n";
                            //cout<<alpha[m]<<alpha[o]<<" " << backvert<<" "<<col<<"ss\n";
                        }
                    }
                }
                for(int row = 2; row < n; row++){
                    for(int col = 2;  col < m; col++){
                        if(puzzle[row][col] == alpha[M] && puzzle[row-1][col-1] == alpha[o] && puzzle[row-2][col-2] == alpha[o]){
                            ans[M][o]++;
                            //cout<<"DING\n";
                            //cout<<alpha[M]<<alpha[o]<<"ss\n";
                        }
                    }
                }
                for(int row = 2; row < n; row++){
                    for(int col = 0; col < n-2; col++){
                        if(puzzle[row][col] == alpha[M] && puzzle[row-1][col+1] == alpha[o] && puzzle[row-2][col+2] == alpha[o]){
                            ans[M][o]++;
                        }
                    }
                }
                for(int row = 0; row < n-2; row++){
                    for(int col = 2; col < n; col++){
                        if(puzzle[row][col] == alpha[M] && puzzle[row+1][col-1] == alpha[o] && puzzle[row+2][col-2] == alpha[o]){
                            ans[M][o]++;
                        }
                    }
                }    
            }
            
        }
    }
    long long count = 0;
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
            if(ans[i][j]>count){
                cout<<alpha[i]<<alpha[j]<<"\n";

            }
            count = max(count, ans[i][j]);
        }
    }
    fout<<count;
}