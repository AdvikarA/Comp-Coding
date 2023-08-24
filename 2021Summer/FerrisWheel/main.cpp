#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
    long long n, x, temp; 
    long long ans = 0; 
    vector<long long> weights; 
    cin >> n >> x; 
    for(int i = 0; i < n; i++){
        cin >> temp; 
        weights.push_back(temp);
    }
    sort(weights.begin(), weights.end());
    for (size_t i = 0; i < weights.size(); ++i) {
        if (weights[i] + weights[i+1] <= x){ 
            i++; 
            ans++; 
        }
        else{
            ans++; 
        }
    } 
    cout << ans; 
}