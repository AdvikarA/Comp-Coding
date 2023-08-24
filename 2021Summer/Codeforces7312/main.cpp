#include <iostream>
#include <string.h>
#include <string>
using namespace std; 


int main() {
    int N; 
    string alpha = "abcdefghijklmnopqrstuvwxyz"; 
    cin >> N;
     
    
    for(int b = 0; b < N; b++){
        int right = -1000;
        int left = -1000;
        bool done = false; 
        string s; 
        cin >> s; 
        int size = s.length();
        for(int j = 0; j < size; j++){
            if(s[j] == 'a'){
                int pos = j; 
                right = left = j; 
                break; 
            }
        }
        if(right == -1000){
            cout << "NO" << "\n";
            done = true; 

        }
        if(done == false){
            for(int i = 1; i < size; i++){
                
                char let = 'a' + i; 
                if(left != 0 && s[left-1] == let){
                    left--; 
                }
                else if(right != size-1 && s[right+1] == let){
                    right++;
                }
                else{
                    cout<< "NO" << "\n"; 
                    done = true; 
                }
                
            }
        }
        if(done == false){
            cout << "YES" << "\n"; 
        }

    }
    
}