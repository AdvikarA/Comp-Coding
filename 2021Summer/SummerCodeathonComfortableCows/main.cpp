#include <iostream>
#include <fstream>
using namespace std; 
bool IsComfortable(int grid[1000][1000], int xxx, int yyy){
    int adjcows = 0; 
    if((grid[xxx+1][yyy]) == 1){
        adjcows++; 
    }
    if((grid[xxx-1][yyy]) == 1){
        adjcows++; 
    }
    if((grid[xxx][yyy+1]) == 1){
        adjcows++; 
    }
    if((grid[xxx][yyy-1]) == 1){
        adjcows++; 
    }
    if(adjcows == 3){
        return true; 
    }
    return false; 
}
int main() {
    int n; 
    cin >> n; 
    int x[n];
    int y[n];
    int ans; 
    int grid[1000][1000] = {0}; 
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i]; 
       // cout << x << y; 
        ans = 0; 
       grid[x[i]][y[i]] = 1; 

        for(int t = 0; t <= i; t++){
            if(IsComfortable(grid, x[t], y[t]) == true){
                ans++; 
            }
        }
        if(i == 0){
	    cout << ans;     
	}
	else{
	    cout << "\n" << ans;
	}
        
    }
    
}



//IsComfortable()
    //if element in adj boxes have cow  
        //adj cows++
    //if adj cows == 3
        //cow is said to be comfortable
        //return true
    //else
        //return false

//get n
//do thing n times
    //add new cow to grid
    //ans = 0
    //get coords
    //check every element in grid
        //if there is a cow, make it 1
    //check every box with cow
        //if IsComfortable == true
            //ans++
    