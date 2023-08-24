#include <iostream>
using namespace std;
int main() {
    int x, y; 
    cin >> x >> y; 
    int ans = 0; 
    for(int i = 0; i <= x; i++){
        for(int j = 0; j <= y; j++){
            if(j == i * j){
                ans++; 
            }
        }
    }
    cout << ans; 
}