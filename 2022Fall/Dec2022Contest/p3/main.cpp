#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std; 
int main(){
    int n; 
    cin >> n; 
    int loop = n; 
    vector<int> ranges[300]; 
    bool arr[300];
    for(int i = 0; i < 300; i++){
        arr[i] = true; 
    }
    int values[n];
    for(int i = 0; i < n; i++){
        values[i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < loop; j++){
            int a;
            cin >> a;
            ranges[loop].push_back(a); 

        }
        loop--; 
    }
    int l = n; 
    int tracker = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < l; j++){
            int diff = ranges[l][j]-ranges[l][j-1];
            if(diff > 0){
                if(arr[j] == false){
                    
                    values[j] = values[j-1]-diff;
                } 
                else{
                    values[j] = values[j-1]+diff;
                }
            }
            else{
                arr[j] = false; 
                
            }
            
        }
        l--; 
        tracker++; 
    }
    for(int i = 0; i < n; i++){
        cout << values[i] << " "; 
    }
    
}