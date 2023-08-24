#include <iostream>
using namespace std; 
typedef long long ll;
int main() {
    ll n; 
    cin >> n; 
    for(ll i = 0; i < n; i++){
        ll p; 
        cin >> p;
        int k = 2; 
        int ans1 = 0; 
        int ans2 = 0; 
        while (true){
            if((p-1) % k == 0){
                if(ans1 == 0){
                    ans1 = k;
                    k++; 
                }
                else if(ans2 == 0){
                    ans2 = k; 
                    break; 
                }
                
            }
            k++; 
        }
        cout << ans1 << " " << ans2 << "\n";  
    }
}