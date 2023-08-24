#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n; 
    cin >> n; 
    int ans = 0; 
    int flowers[n]; 
    for(int i= 0; i < n; i++){
        cin >> flowers[i];
    }
    for(int l = 0; l < n; l++){
        int sum = 0; 
        vector<bool> seen(1001); 
        for(int r = l; r < n; r++){
            sum+=flowers[r];
            seen[flowers[r]] = true; 
            int size = r-l+1; 
            if(sum % size == 0){
                int average = sum/size; 
                if(seen[average]){
                    ans++; 
                }
            }
        }
    }
    cout << ans; 
}