#include <iostream>
using namespace std;
bool checkifparity(bool arr[], int l){
    for(int i = 0; i < l-1; i++){
        if(arr[i]%2 == arr[i+1]%2){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    for(int p = 0; p < n; p++){
        int l;
        cin >> l; 
        bool arr[l];
        for(int i = 0; i < l; i++){
            int temp;
            cin >> temp; 
            if(temp % 2 == 0){
                arr[i] = 2;
            }
            else{
                arr[i] = 1; 
            }
        }
        int ans1 = 0;
        while(checkifparity(arr, l) == false){
            bool swap = false; 
            for(int j = 1; j < l; j++){
                if(swap){
                    if(arr[j]%2 != arr[j-1]%2){
                        int temp = arr[j];
                        arr[j] = arr[j-1];
                        arr[j-1] = temp;
                        ans1++; 
                    }
                    swap = false;
                }
                else if(swap2){
                    if(arr[j]%2 == arr[j-1]%2){
                        int temp = arr[j-1];
                        arr[j-1] = arr[j-2];
                        arr[j-2] = temp;
                        ans1++; 
                    }
                    swap = false;
                }
                if(arr[j]%2 == arr[j-1]%2){
                    swap = true;
                }
                else{
                    swap2 = true;
                }
            }
        }
        cout << ans1 << "\n"; 

    }
}
