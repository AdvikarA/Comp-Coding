#include <fstream>
#include <string>
using namespace std; 
int single_solve(string rows[3], char i){
    int ans = 0; 
    for(int o = 0; o < 3; o++){
        int count = 0; 
        for(int k = 0; k < 3; k++){
            if(rows[o][k] == i){
                count++; 
            }
        }
        if(count == 3){
            ans++; 
        }
    }
    for(int o = 0; o < 3; o++){
        int count = 0; 
        for(int k = 0; k < 3; k++){
            if(rows[k][o] == i){
                count++; 
            }
        }
        if(count == 3){
            ans++; 
        }
    }
    if(rows[0][0] == i && rows[1][1] == i && rows[2][2] == i){
        ans++; 
    }
    if(rows[0][2] == i && rows[1][1] == i && rows[2][0] == i){
        ans++; 
    }
    if (ans > 0){
        ans = 1; 
    }
    return ans; 
}
int solve(string rows[3], char i, char j){
int ans = 0; 
    for(int o = 0; o < 3; o++){
        int count = 0; 
        int counti = 0;
        int countj = 0; 
        for(int k = 0; k < 3; k++){
            if(rows[o][k] == i || rows[o][k] == j){
                count++; 
                if(rows[o][k] == i){
                    counti++; 
                }
                if(rows[o][k] == j){
                    countj++; 
                }
            }
            
        }
        if(count == 3){
            ans++; 
        }
        if(counti == 3 || countj == 3){
            ans--; 
        }
    }
    for(int o = 0; o < 3; o++){
        int count = 0; 
        int countj = 0;
        int counti = 0; 
        for(int k = 0; k < 3; k++){
            if(rows[k][o] == i || rows[k][o] == j){
                count++; 
                if(rows[k][o] == i){
                    counti++; 
                }
                if(rows[k][o] == j){
                    countj++; 
                }
            }
        }
        if(count == 3){
            ans++; 
        }
        if(counti == 3 || countj == 3){
            ans--; 
        }
    }
    if((rows[0][0] == i || rows[0][0] == j) && (rows[1][1] == i || rows[1][1] == j) && (rows[2][2] == i || rows[2][2] == j)){
        ans++; 
        if((rows[0][0] == i) && (rows[1][1] == i) && (rows[2][2] == i)){
            ans--; 
        }
        else if((rows[0][0] == j) && (rows[1][1] ==j) && (rows[2][2] == j)){
            ans--; 
        }
    }
    if((rows[0][2] == i || rows[0][2] == j) && (rows[1][1] == i || rows[1][1] == j) && (rows[2][0] == i || rows[2][0] == i)){
        ans++; 
        if((rows[0][2] == i) && (rows[1][1] == i) && (rows[2][0] == i)){
            ans--; 
        }
        else if((rows[0][2] == j) && (rows[1][1] ==j) && (rows[2][0] == j)){
            ans--; 
        }
    }
    //fout << i << " " << j << " " << ans << "\n"; 
    if (ans > 0){
        ans = 1; 
    }
    return ans;
}
int main() {
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");
    int ans = 0;
    int ans2 = 0;  
    string rows[3];
    for(int i = 0; i < 3;i++){
        fin >> rows[i]; 
    }
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    for(int i = 0; i < 26; i++){
        ans += single_solve(rows, alpha[i]);
        for(int j = i+1; j < 26; j++){
            ans2 += solve(rows, alpha[i], alpha[j]); 
        }
    }
    fout << ans << "\n"; 
    fout << ans2; 
}