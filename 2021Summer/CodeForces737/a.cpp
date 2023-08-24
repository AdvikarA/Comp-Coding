#include <iostream>
#include <iomanip>
#include <vector>
using namespace std; 
int main(){
    int t; 
    cin >> t;
    for(int l = 0; l < t; l++){
        double ans = -10000000;
        int n; 
        cin >> n;
        int arr[n];
        for(int p = 0; p < n; p++){
            cin >> arr[p]; 
        }
        

        for (int i=0; i <n; i++)
        {
            for (int j=i; j<n; j++)
            {
                double sum1, sum2; 
                sum1 = 0; 
                sum2 = 0; 
                vector<int>sub1;
                vector<int>sub2;
                bool seen[n] = {false}; 
                
                for (int k=i; k<=j; k++){
                    sub1.push_back(arr[k]); 
                    sum1+=arr[k]; 
                    seen[k] = true;
                }
                for(int o = 0; o < n; o++){
                    if(seen[o] == false){
                        sub2.push_back(arr[o]); 
                        sum2 += arr[o]; 
                    }
                }
                if(sub1.size() != 0 && sub1.size() != n){
                    sum1 /= sub1.size();
                    sum2 /= sub2.size();  
                    ans = max(ans, sum1+sum2); 
                }
              
                
            }
        }
        cout << setprecision(8) << fixed << ans << "\n"; 
    }
}