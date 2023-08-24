#include <iostream>
#include <algorithm>
using namespace std;
bool check(int n, int arr[]){
    for(int i = 0; i < n-1; i++){
        if(abs(arr[i] - arr[i+1]) == 1){
            return false; 
        }
    }
    return true; 
}
int main() {
    int n; 
    int count = 0; 
    cin>>n;
    int arr[n]; 
    for(int i = 0; i < n; i++){
        arr[i] = i+1; 
    }
    do{
        if(check(n, arr)){
            for(int i = 0; i < n; i++){
                cout << arr[i] << " "; 
            }
            return 0; 
        }
    }
    while(next_permutation(arr, arr+n));
    cout << "NO SOLUTION"; 
}