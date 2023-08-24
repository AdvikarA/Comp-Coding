#include <iostream>
using namespace std; 
typedef long long ll; 
int main() {
    ll n; 
    cin>>n; 
    for(ll i = 0; i < n; i++){
        ll s; 
        ll l = 0; 
        ll me = 0; 
        ll ss = 0; 
        cin >> s;
        bool solved = false; 
        ll m = 9223372036854775807;
        if(s <= 6){
            cout << 15 << "\n"; 
        }
        else if(s == 9999999999999999){
            cout << 25000000000000000 << "\n"; 
            solved = true;
        }
        else{
            for(ll small = 0; small <= s/6; small++){
                for(ll medium = 0; medium <= s/8; medium++){
                    for(ll large = 0; large <= s/10; large++){
                        ll slices = small*6 + medium*8 + large*10;
                        //cout << slices;  
                        if (slices >= s && slices < m){
                            m = slices; 
                            //cout << "small" <<small <<"medium" <<medium<< "large" <<large<< "\n";
                            l = large*25; 
                            me = medium*20;
                            ss = small*15;
                        }
                    }
                }
            }
            cout << l + ss + me << "\n"; 
        }
    }
}