#include <iostream>
using namespace std; 

int main() {
    int N; 
    cin >> N; 
    for(int j = 0; j < N; j++){
        long long ans = 0; 
        long long num; 
        cin >> num; 
        int r = num+1; 
        ans = r/10; 
        cout << ans << "\n"; 
    }
}