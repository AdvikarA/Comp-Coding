#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    char s[n];
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    int ans = 0;
    for(int start = 0; start <= n-3; start++){
        string a = "";
        int h = 0;
        int g = 0;
        for(int j = start; j<n; j++){
            if(s[j] == 'G'){
                g++;
            }
            else{
                h++;
            }
            a+=s[j];
            if(a.size() >= 3 && (g == 1 || h == 1)) ans++; 
            
        }
    }
    cout << ans;
}