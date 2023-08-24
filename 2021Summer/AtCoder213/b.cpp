#include <iostream>
using namespace std;
int main(){
    int n; 
    cin >> n; 
    int num[n];
    for(int i = 0; i < n; i++){
        cin>>num[i]; 
    }
    int big = 0;
    for(int i = 0; i < n; i++){
        if(num[i] > big){
            big = num[i]; 
        }
    }
    int big2 = 0;
    int ans;  
    for(int i = 0; i < n; i++){
        if(num[i] != big){
            if(num[i] > big2){
                big2 = num[i]; 
                ans = i; 
            }
        }
    }
    cout << ans+1;
}