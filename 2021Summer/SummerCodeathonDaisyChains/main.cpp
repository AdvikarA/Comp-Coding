#include <iostream>
using namespace std;
int main() {
    int n; 
    cin >> n; 
    int count = 0; 
    int flowers[n]; 
    for(int i = 0; i < n; i++){
        cin >> flowers[i]; 
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j<n;j++){
            float sum = 0; 
            for(int k = i; k <= j; k++){
                sum+= flowers[k]; 
            }
            float average = sum/(j-i+1);
            //cout << average; 
            for(int k = i; k <= j; k++){
                if(flowers[k] == average){
                    //cout << flowers[k] << " " << average << "\n"; 
                    count++; 
                    break; 
                } 
            } 
        }
            
    }
    cout << count+n; 
}