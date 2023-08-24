#include <iostream>
#include <map>
#include <string>
using namespace std; 
int main() {
    string s; 
    int n; 
    cin >> n; 
    cin >> s; 
    map<int, char>m; 
    m[0] = 'A';
    m[1] = 'B';
    m[2] = 'C'; 
    int ans = 0;
    for(int i = 0; i < 3; i++ ){
        int count = 0; 
        for(int j = 0; j <= n; j++){
            string sub = s.substr(0, j); 
            int acount = 0; 
            int bcount = 0; 
            int ccount = 0; 
            for(int k = 0; k < j; k++){
                if(sub[k] == 'A'){
                    acount++;
                }
                else if(sub[k] == 'B'){
                    bcount++;
                }
                else if(sub[k] == 'C'){
                    ccount++; 
                }
            }
            if(m[i] == 'A'){
                if(acount>=bcount && acount >= ccount){
                    count++; 
                }
            }
            else if(m[i] == 'B'){
                if(bcount >= acount &&  bcount >= ccount){
                    count++; 
                }
            }
            else if(m[i] == 'C'){
                if(ccount >= acount && ccount >= bcount){
                    count++;
                }
            }
            cout << count << "\n";
        }
        if(count > ans){
            ans = count; 
        }
    }
    cout << ans-1; 
}