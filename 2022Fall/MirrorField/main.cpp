#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int n, m; 
char field[1000][1000];
bool upseen[1000][1000];
bool downseen[1000][1000];
int bounces = 0;
int maxbounces = 0; 
int bounce(string in, char mirror, int x, int y){
    cout << "last bounce: " << bounces << " " << in << " " << mirror << " " << x <<" " << y << "\n";
    string out; 
    if(in == "north"){
        if(mirror == '/'){
            out = "east";
            if(upseen[y][x]){
                return -1;
            } 
            else{
                upseen[y][x] = true;
            }
            x++;
            bounces++;
            return bounce(out, field[y][x], x, y);
        }
        if(mirror == '\\'){
            out = "west";
            if(upseen[y][x]){
                return -1;
            } 
            else{
                upseen[y][x] = true;
            }
            x--;
            bounces++;
            return bounce(out, field[y][x], x, y);

        }
        if(mirror == '*'){
            return bounces;
        }
    }
    if(in == "south"){
        if(mirror == '/'){
            out = "west";
            if(downseen[y][x]){
                return -1;
            } 
            else{
                downseen[y][x] = true;
            }
            x--;
            bounces++;
            return bounce(out, field[y][x], x, y);
        }
        if(mirror == '\\'){
            out = "east";
            if(downseen[y][x]){
                return -1;
            } 
            else{
                downseen[y][x] = true;
            }
            x++;
            bounces++;
            return bounce(out, field[y][x], x, y);
        }
        if(mirror == '*'){
            return bounces;
        }
    }
    if(in == "east"){
        if(mirror == '/'){
            out = "north";
            if(downseen[y][x]){
                return -1;
            } 
            else{
                downseen[y][x] = true;
            }
            y--; 
            bounces++;
            return bounce(out, field[y][x], x, y);

        }
        if(mirror == '\\'){
            out = "south";
            if(upseen[y][x]){
                return -1;
            } 
            else{
                upseen[y][x] = true;
            }
            y++; 
            bounces++;
            return bounce(out, field[y][x], x, y);
        }
        if(mirror == '*'){
            return bounces;
        }
    }
    if(in == "west"){
        if(mirror == '/'){
            out = "south";
            if(upseen[y][x]){
                return -1;
            } 
            else{
                upseen[y][x] = true;
            }
            y++; 
            bounces++;
            return bounce(out, field[y][x], x, y);
        }
        if(mirror == '\\'){
            out = "north";
            if(downseen[y][x]){
                return -1;
            } 
            else{
                downseen[y][x] = true;
            }
            y--; 
            bounces++;
            return bounce(out, field[y][x], x, y);
        }
        if(mirror == '*'){
            return bounces;
        }
    }
}
int main(){
    ifstream fin ("mirror.in");
    ofstream fout ("mirror.out"); 
    

    fin >> n >> m; 
    for(int i = 0; i < n+2; i++){
        for(int j = 0; j < m+2; j++){
            if(i == 0){
                field[i][j] = '*'; 
            } 
            else if(i == n+1){
                field[i][j] = '*'; 
            }
            else if(j == 0){
                field[i][j] = '*'; 
            } 
            else if(j == m+1){
                field[i][j] = '*'; 
            }
            else{
                fin >> field[i][j]; 
                downseen[i][j] = false;
                upseen[i][j] = false;
            }
        }
    }
    for(int i = 1; i < n+1; i++){
        for(int j = 1; j < m+1; j++){
            bounces = 0;
            if(i == 1){
                if(j == 1){
                    //cout << bounce("south", field[i][j], j, i) << "\n"; 
                    maxbounces = max(maxbounces, bounce("south", field[i][j], j, i));
                    bounces = 0;

                    //cout << bounce("east", field[i][j], j, i) << "\n"; 
                    maxbounces = max(maxbounces, bounce("east", field[i][j], j, i));
                    bounces =0;
                }
                else if(j == m){
                    
                    //cout << bounce("south", field[i][j], j, i) << "\n"; 
                    maxbounces = max(maxbounces, bounce("south", field[i][j], j, i));
                    bounces = 0;

                    //cout << bounce("west", field[i][j], j, i) << "\n"; 
                   
                    maxbounces = max(maxbounces, bounce("west", field[i][j], j, i));
                }
                else{
                   
                    maxbounces = max(maxbounces, bounce("south", field[i][j], j, i));
                    bounces = 0;
                }
            }
            else if (i == n){
                if(j == 1){
                    
                    //cout << bounce("north", field[i][j], j, i) << "\n"; 
                    maxbounces = max(maxbounces, bounce("north", field[i][j], j, i));
                    bounces = 0;

                    //cout << bounce("east", field[i][j], j, i) << "\n"; 
                    maxbounces = max(maxbounces, bounce("east", field[i][j], j, i));
                    bounces = 0;
                }
                else if(j == m){
                    
                    maxbounces = max(maxbounces, bounce("north", field[i][j], j, i));
                    bounces = 0;

                    //cout << bounce("west", field[i][j], j, i) << "\n";
                    maxbounces = max(maxbounces, bounce("west", field[i][j], j, i));
                    bounces = 0;
                }
                else{
                    maxbounces = max(maxbounces, bounce("north", field[i][j], j, i));
                    bounces = 0;
                }
            }
            if(j == 1){
                bounces = 0;
                //cout << bounce("east", field[i][j], j, i) << "\n";
                maxbounces = max(maxbounces, bounce("east", field[i][j], j, i));
                bounces = 0;
            }
            else if(j == m){
                bounces = 0;
                //cout << bounce("west", field[i][j], j, i) << "\n";
                maxbounces = max(maxbounces, bounce("west", field[i][j], j, i));
                bounces = 0;
            }
        }
        cout << "\n";
    }
    fout << maxbounces << "\n";
}