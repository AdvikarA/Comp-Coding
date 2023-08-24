#include <iostream>
#include <algorithm> 
using namespace std; 
int main() {
    long long n; 
    cin >> n;
    long long loop = 0; 
    bool ns = true; 
    long long arr[n];
    for(int i = 0; i<n; i++){
        arr[i] = i+1; 
    }
    
    bool running = true; 
    sort(arr, arr+n); 
    do{
        loop = 0; 
        for(int i = 0; i < n; i++){
            if(i != n-1){
                if(abs(arr[i] - arr[i+1])==1){
                    continue; 
                    loop = 0; 
                }
                else{
                    loop++; 
                }
            }
        }
        if(loop == n -1){
            for(int j = 0; j < n; j++){
		if(j == n-1){
                    cout << arr[j]; 
		}
		else{
		    cout << arr[j] << " ";
		}
            }
            ns = false;
            break; 
        }
    }while (next_permutation(arr, arr+n));  

   if(ns){cout << "NO SOLUTION";} 
}