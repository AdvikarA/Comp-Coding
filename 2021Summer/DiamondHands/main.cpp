#include <fstream>
#include <algorithm>
using namespace std;
int main() {
    ifstream fin ("diamond.in");
    ofstream fout ("diamond.out");
    long long n, k;
    fin>> n >> k;
    long long arr[n];
    for(int i = 0; i < n; i++){
        fin>> arr[i]; 
    }
    sort(arr, arr+n);
    
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int amt = 0;
        for(int j = 0; j < n; j++) {
            // loop over all diamonds, see if this diamond can be arranged with the selected one
            if(arr[j] >= arr[i] && arr[j] <= arr[i] + k) {
                amt++;
            }
        }
        // update our answer
        if(amt > ans) {
            ans = amt;
        }
    }
    // print the answer
    fout<< ans; 
}