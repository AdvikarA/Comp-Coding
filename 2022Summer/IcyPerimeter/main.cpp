#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int n; 
int area;
int perimeter; 
char grid[1001][1001];
bool visited[1001][1001];
void floodfill(int x, int y){
    if(grid[x][y] != '#' || visited[x][y]){
        return; 
    }
    visited[x][y] = true;
    area++; 
    if(x>=1){
        if(grid[x-1][y] != '#'){
            perimeter++;
        }
        floodfill(x-1, y);
    }
    if(y>=1){
        if(grid[x][y-1] != '#'){
            perimeter++;
        }
        floodfill(x, y-1);
    }
    if(x<=999){
        if(grid[x+1][y] != '#'){
            perimeter++;
        }
        floodfill(x+1, y);
    }
    if(y<=999){
        if(grid[x][y+1] != '#'){
            perimeter++;
        }
        floodfill(x, y+1);
    }
    if(x == 0&&y==0){
        perimeter+=2;
        
    }
    else if(x == 1000 && y==1000){
        perimeter+=2;
        
    }
    else if(x == 0){
        perimeter++;
    }
    else if(x == 1000){
        perimeter++;
    }
    else if(y == 0){
        perimeter++;
    }
    else if(y == 1000){
        perimeter++;
    }
    
}
int main(){
    ifstream fin ("perimeter.in");
    ofstream fout ("perimeter.out");
    fin >> n; 
    for(int i = 0; i < n; i++){
        string s; fin >> s;
        for(int j = 0; j < n; j++){
            grid[i][j] = s[j]; 
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            visited[i][j] = false;
        }
    }
    int finalarea = 0;
    int finalperimeter = 2147483647;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            //cout << grid[i][j] << " ";
            area = 0;
            perimeter = 0;
            if(grid[i][j] == '#' && !visited[i][j]){
                floodfill(i, j);
            }
            //cout << area << " " << perimeter << "\n";
            if(area > finalarea){
                finalarea = area; 
                finalperimeter = perimeter;
            }
            else if(area == finalarea){
                if(perimeter < finalperimeter){
                    finalperimeter = perimeter;
                }
            }
        }
    }
    fout << finalarea << " " << finalperimeter << "\n";

}