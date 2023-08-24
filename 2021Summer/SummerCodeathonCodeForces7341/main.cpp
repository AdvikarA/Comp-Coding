#include <iostream>
using namespace std; 
int main() {
    int t; 
    cin >> t; 
    long long ansx; 
    long long ansy; 
    long long x = 1; 
    long long y = 2; 
    for(int i = 0; i < t; i++){
        int n; 
        cin >> n; 
        int aa = n/3; 
        int bb = aa;
        int modd = n % 3; 
        while(modd > 0){
            if(modd > 1){
                modd -= 2; 
                bb++; 
            }
            if(modd == 1){
                modd--; 
                aa++; 
            }
        }
        cout << aa << " " << bb << "\n"; 
    }
   
}