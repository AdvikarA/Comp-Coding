#include <iostream>
#include <string>
using namespace std; 
bool seen(char a, bool arrseen[26]){
    string alpha = "abcdefghijklmnopqrstuvwxyz"; 
    for(int i = 0; i < 26; i++){
        if(a == alpha[i]){
            if(arrseen[i] == true){
                return true;
            }
            else{
                arrseen[i] = true; 
                return false; 
            }
        }
    }
    return true; 
}
int main() {
    int t; 
    cin >> t;
    for(int i = 0; i < t; i++){
        float k = 0; 
        int colorr = 0;
        int colorg = 0;  
        bool redseen[26] = {0}; 
        bool greenseen[26] = {0}; 
        string s; 
        cin >> s; 
        int len = s.length();

        for(int j = 0; j < len; j++){
            
            if(colorr <= colorg){
                if(seen(s[j], redseen) == false){
                    colorr++; 
                }
                else if(seen(s[j], greenseen) == false){
                    colorg++; 
                }
                else{
                    continue; 
                }
            }
            else{
                if(seen(s[j], greenseen) == false){
                    colorg++; 
                }
                else if(seen(s[j], redseen) == false){
                    colorr++; 
                    
                }
                else{
                    continue; 
                }
            }
            
            //cout << "letter" << " "<<s[j] << " " << "cr: " << colorr << "cg: " << colorg << "\n"; 
        }
        if(colorg == colorr){
            cout << colorr << "\n"; 
        }
        else{
            cout << (abs(colorr + colorg))/2 << "\n"; 
        }
    }
 }