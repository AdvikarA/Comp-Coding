#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
int main() {
    int t; 
    cin >> t; 
    for(int i = 0; i < t; i++){
        int a; 
        vector<int>arr;
        vector<int>mins; 
        cin >> a; 
        for(int j = 0; j < a; j++){
            int input; 
            cin >> input;
            arr.push_back(input); 
        }
        int minimumtoputinarray = *min_element(arr.begin(), arr.end());
        mins.push_back(minimumtoputinarray); 
        while(arr.size() > 0){
            for(int k = 0; k < arr.size(); k++){
                //cout << arr[k] << "\n";  
            }
            int minimum = *min_element(arr.begin(), arr.end());
            mins.push_back(minimum); 
            arr.erase(remove(arr.begin(), arr.end(), minimum), arr.end()); 
            for(int k = 0; k < arr.size(); k++){
                arr[k] -= minimum; 
            }
        }
        int x = -10000000000; 
        for(int k = 0; k < mins.size(); k++){
            x = max(x, mins[k]);  
        }
        cout << x<< "\n"; 

        

    }
} 