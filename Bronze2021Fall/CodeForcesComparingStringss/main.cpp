#include <iostream>
using namespace std;
typedef long long ll;
int main(){
    string a, b;
    cin >> a >> b;
    ll asize = a.length();
    ll bsize = b.length();
    if(asize != bsize){
        cout << ("NO");
        return 0;
    }
    ll x = 0; 
    int t = 0; 
    bool test = false; 
    int aa, bb;
    for(ll i = 0; i < asize; i++){
        if(a[i] == b[i]){
            x++; 
        }
        else{
            t++;
            if(t == 1){
                aa = a[i];
                bb = b[i];

            }
            if(t == 2){
                if(a[i] == bb && b[i] == aa){
                    test = true;
                } 
            }
        }
    }
    if(x == asize-2 && test == true){
        cout << ("YES");
    }else{
        cout << ("NO");
    }
}
