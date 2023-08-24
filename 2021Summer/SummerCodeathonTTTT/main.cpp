#include <fstream>
using namespace std;
bool checkCell(char i, char j, char cell){
    return i == cell || j == cell; 
}
int main(){
    ifstream fin("tttt.in");
    ofstream fout("tttt.out");
    char board[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            fin >> board[i][j];
        }
    }
    int ans = 0; 
    for(char i = 'A'; i <= 'Z'; i++){
        bool ggs = false; 
        for(int l = 0; l < 3; l++){
            int a = 0; 
            for(int j = 0; j < 3; j++){
                if(board[l][j] == i){
                    a++;
                }
                if(a == 3){
                    ggs = true; 
                }
            }
        }
        for(int l = 0; l < 3; l++){
            int a = 0; 
            for(int j = 0; j < 3; j++){
                if(board[j][l] == i){
                    a++;
                }
                if(a == 3){
                    ggs = true; 
                }
            }
        }
        if(board[0][0] == i && board[1][1] == i && board[2][2] == i){
            ggs = true;
        }
        if(board[0][2] == i && board[1][1] == i && board[2][0] == i){
            ggs = true;
        }
        if(ggs){
            ans++; 
        }
    }
    int sans = 0; 
    int bans = 0; 
    for(char i = 'A'; i <= 'Z'; i++){
        for(char p = i+1; p<= 'Z'; p++){
            sans = 0; 
            for(int l = 0; l < 3; l++){
                int a = 0; 
                int b = 0;
                int c = 0; 
                for(int j = 0; j < 3; j++){
                    if(checkCell(i, p, board[l][j])){
                        a++;
                    }
                    if(board[l][j] == i){
                        b++;
                    }
                    else if(board[l][j] == p){
                        c++; 
                    }
                    if(a == 3){
                        sans++; 

                    }
                    if(b == 3 || c == 3){
                        sans--; 
                    }
                }
            }
            for(int l = 0; l < 3; l++){
                int a = 0; 
                int b = 0;
                int c = 0; 
                for(int j = 0; j < 3; j++){
                    if(checkCell(i, p, board[j][l])){
                        a++;
                    }
                    if(board[j][l] == i){
                        b++;
                    }
                    else if(board[j][l] == p){
                        c++; 
                    }
                    if(a == 3){
                        sans++; 

                    }
                    if(b == 3 || c == 3){
                        sans--; 
                    }
                }
            }
            if(checkCell(i, p, board[0][0]) && checkCell(i, p, board[1][1]) && checkCell(i, p, board[2][2])){
                if((board[0][0] == i && board[1][1] == i && board[2][2] == i) || (board[0][0] == p && board[1][1] == p && board[2][2] == p)){
                    sans--;
                }
                sans++;

            }
            if(checkCell(i, p, board[0][2]) && checkCell(i,p, board[1][1]) && checkCell(i, p, board[2][0])){
                if((board[0][2] == i && board[1][1] == i &&  board[2][0] == i) || (board[0][2] == p && board[1][1] == p &&  board[2][0] == p)){
                    sans--;
                }
                sans++;
            }
            //fout << i << " " << p << sans << "\n";
            if(sans > 0){
                bans +=1; 
            }
        }
    }
    fout << ans << "\n" << bans;
}