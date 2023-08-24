#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std; 
int main() {
    int n; 
    cin >> n;
    float arr[n];
    for(int i = 0; i<n; i++){
        cin >> arr[i]; 
    }
    float ans = 0; 
    for(int i = 0; i < n; i++){
        int sum = 0; 
        int avg = 0; 
        for(int j = 0; j < n; j++){
            if(i != j){
                sum+=arr[j];
            }
            avg = sum*10/(n-1);
            float a = float(avg)/10; 
            //cout << a << "\n";
            if(a > ans){
                ans = a; 
            }
        }
    }
    
    cout << fixed << setprecision(1) << float(ans); 
}
