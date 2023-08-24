#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<map>
#include<utility>
using namespace std;
int main(){
    long long n; 
    ifstream fin ("bgm.in");
    ofstream fout ("bgm.out");
    fin >> n; 
    long long B[7] = {0};
    long long E[7] = {0};
    long long S[7] = {0};
    long long I[7] = {0};
    long long G[7] = {0};
    long long O[7] = {0};
    long long M[7] = {0}; 
    for(long long i = 0; i < n; i++){
        char a; int b;
        fin >> a >> b;
        if(a == 'B'){
            B[(b%7+7)%7]++; 
            cout << b << " " << (b%7+7)%7 << " " << (b%7) << "\n";
        }
        else if(a == 'E'){
            E[(b%7+7)%7]++;
        }
        else if(a == 'S'){
            S[(b%7+7)%7]++;
        }
        else if(a == 'I'){
            I[(b%7+7)%7]++; 
        }
        else if(a == 'G'){
            G[(b%7+7)%7]++;
        }
        else if(a == 'O'){
            O[(b%7+7)%7]++;
        }
        else if(a == 'M'){
            M[(b%7+7)%7]++;  
        }
    }
    long long ans = 0; 
    for(long long b = 0; b < 7; b++){
        for(long long e = 0; e < 7; e++){
            for(long long s = 0; s < 7; s++){
                for(long long i = 0; i < 7; i++){
                    for(long long g = 0; g < 7; g++){
                        for(long long o = 0; o < 7; o++){
                            for(long long m = 0; m < 7; m++){
                                if(((b+e+s+s+i+e)*(g+o+e+s)*(m+o+o))%7 == 0){
                                    ans += B[b] * E[e] * S[s] * I[i] * G[g] * O[o] * M[m]; 
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fout << ans;
}