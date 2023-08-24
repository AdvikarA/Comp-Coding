#include<iostream>
#include<utility>
#include<fstream>
using namespace std;    
static bool grid[2000][2000];
static int ans = 0;
bool isComf(bool grid[2000][2000], int x, int y){
    int surround = 0;
    if(grid[x][y] == false){
        return false;
    }
    if(grid[x+1][y] == true){
        surround +=1;
    }
    if(grid[x-1][y] == true){
        surround +=1;
    }
    if(grid[x][y+1] == true){
        surround +=1;
    }
    if(grid[x][y-1] == true){
        surround +=1;
    }
    if(surround == 3){

        return true;
    }
    return false;
}
void makeNotComf(bool gridd[2000][2000], int x, int y){
    
    int n = 0;
    if(gridd[x+1][y] == false){
        grid[x+1][y] = true;
        ans++;
        int xx = x+1;
        int yy = y;
        if(isComf(grid, xx, yy)){
            makeNotComf(grid, xx, yy);
        }
        if(isComf(grid, xx+1, yy)){
            makeNotComf(grid, xx+1, yy);
        }
        if(isComf(grid, xx-1, yy)){
            makeNotComf(grid, xx-1, yy);
        }
        if(isComf(grid, xx, yy-1)){
            makeNotComf(grid, xx, yy-1);
        }
        if(isComf(grid, xx, yy+1)){
            makeNotComf(grid, xx, yy+1);
        }
    }
    if(gridd[x-1][y] == false){
        grid[x-1][y] = true;
        ans++;
        int xx = x-1;
        int yy = y;
        if(isComf(grid, xx, yy)){
            makeNotComf(grid, xx, yy);
        }
        if(isComf(grid, xx+1, yy)){
            makeNotComf(grid, xx+1, yy);
        }
        if(isComf(grid, xx-1, yy)){
            makeNotComf(grid, xx-1, yy);
        }
        if(isComf(grid, xx, yy-1)){
            makeNotComf(grid, xx, yy-1);
        }
        if(isComf(grid, xx, yy+1)){
            makeNotComf(grid, xx, yy+1);
        }
    }
    if(gridd[x][y+1] == false){
        grid[x][y+1] = true;
        ans++;
        int xx = x;
        int yy = y+1;
        if(isComf(grid, xx, yy)){
            makeNotComf(grid, xx, yy);
        }
        if(isComf(grid, xx+1, yy)){
            makeNotComf(grid, xx+1, yy);
        }
        if(isComf(grid, xx-1, yy)){
            makeNotComf(grid, xx-1, yy);
        }
        if(isComf(grid, xx, yy-1)){
            makeNotComf(grid, xx, yy-1);
        }
        if(isComf(grid, xx, yy+1)){
            makeNotComf(grid, xx, yy+1);
        }
    }
    if(gridd[x][y-1] == false){
        grid[x][y-1] = true;
        ans++;
        int xx = x;
        int yy = y-1;
        if(isComf(grid, xx, yy)){
            makeNotComf(grid, xx, yy);
        }
        if(isComf(grid, xx+1, yy)){
            makeNotComf(grid, xx+1, yy);
        }
        if(isComf(grid, xx-1, yy)){
            makeNotComf(grid, xx-1, yy);
        }
        if(isComf(grid, xx, yy-1)){
            makeNotComf(grid, xx, yy-1);
        }
        if(isComf(grid, xx, yy+1)){
            makeNotComf(grid, xx, yy+1);
        }
    }
}

int main(){
    
    ifstream fin("comfy.in");
    ofstream fout("comfy.out");
    int n; 
    cin >> n;
    for(int i = 0; i < n; i++){
        int x, y;        
        cin >> x >> y;
        x+=1000;
        y+=1000;
        if(grid[x][y] == true){
            ans--;
        }
        grid[x][y] = true;
        for(int i = 488; i < 505; i++){
            for(int j = 488; j <505; j++){
                //cout << grid[i][j] << " ";
            }
            //cout << "\n";
        }
        
        if(isComf(grid, x, y)){
            makeNotComf(grid, x, y);
            //cout << "a\n";

        }
        if(isComf(grid, x+1, y)){
            makeNotComf(grid, x+1, y);
            //cout << "b\n";

        }
        if(isComf(grid, x-1, y)){
            makeNotComf(grid, x-1, y);
            //cout << "c\n";

        }
        if(isComf(grid, x, y+1)){
            makeNotComf(grid, x, y+1);
            //cout << "d\n";

        }
        if(isComf(grid, x, y-1)){
            makeNotComf(grid, x, y-1);
            //cout << "e\n";

        }
        cout <<ans<<"\n";
    }
    
}
