#include <iostream>
using namespace std; 
int main() {
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){
        int size; 
        cin >> size; 
        string enem;
        string greg;
        int ans = 0;  
        cin >> enem; 
        cin >> greg; 
        for(int j = 0; j < size; j++){
            if(greg[j] == '1'){
                if(enem[j] == '0'){
                    enem[j] = '8'; 
                    ans++; 
                }
                else{
                    if(j == '0'){
                        if(enem[j+1] == '1'){
                            enem[j+1] = '8'; 
                            ans++; 
                        }
                    }
                    if(j == size-1){
                        if(enem[j-1] == '1'){
                            enem[j-1] = '8'; 
                            ans++; 
                        }
                    }
                    else{
                        if(enem[j-1] == '1'){
                            enem[j-1] = '8'; 
                            ans++; 
                        }
                        else if(enem[j+1] == '1'){
                            enem[j+1] = '8'; 
                            ans++; 
                        }
                    }
                }
            }
        }
        cout << ans << "\n"; 
    }
}