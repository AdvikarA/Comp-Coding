#include <iostream>
using namespace std;
int main(){
    char g[3][3];
    char c[3][3];
    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            cin >> c[i][j];
        }
    }
    for(int i = 0; i <3; i++){
        for(int j = 0; j < 3; j++){
            cin >> g[i][j];
        }
    }
    int tig[26] = {0};
    int tic[26] = {0};


    int tip[26] = {0};
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < 26; i++){
        for(int row = 0; row < 3; row++){
            //tytytytyt
            for(int letter = 0; letter < 3; letter++){
                if(alpha[i] == c[row][letter]){
                    tic[i]++; 
                    if(c[row][letter] == g[row][letter]){
                        tip[i]++; 
                    }
                    //eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
                }
            }
        }
        for(int row = 0; row < 3; row++){
            for(int letter = 0; letter < 3; letter++){
                if(alpha[i] == g[row][letter]){
                    tig[i]++; 
                }
            }
        }
    }
    int green = 0;
    int yellow = 0; 
    for(int i = 0; i < 26; i++){



        green += tip[i]; 
        tic[i] -= tip[i];
        tig[i] -= tip[i];
        //eeee
        yellow += min(tig[i], tic[i]); 
    }
    for(int i = 0; i < 26; i++){
        //cout << alpha[i] << " " << timesinguess[i] << " " << timesincorrect[i] << " " << timesinpos[i] << "\n";
    }



    cout << green << "\n" << yellow;
}