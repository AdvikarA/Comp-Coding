#include <iostream>
using namespace std;
typedef long long ll; 
int main(){
    ll n; 
    cin >> n; 
    ll ans = 0; 
    while(n > 0){
        if(n >= 100){
            ans++;
            n-=100;
        }
        else if(n >= 20){
            ans++;
            n-=20;
        }
        else if(n >= 10){
            ans++;
            n-=10;
        }
        else if(n >= 5){
            ans++;
            n-=5;
        }
        else if(n >= 1){
            ans++;
            n--; 
        }
    }
    cout << ans; 
}