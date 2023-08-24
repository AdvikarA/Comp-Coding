#include <fstream>
using namespace std; 
bool check(string s, char letter1, char letter2){
    int start1, end1, start2, end2 = -1;
    int count2 = 0;
    int count1 = 0; 
    for(int i = 0; i < 52; i++){
        if(s[i] == letter1){
            count1++; 
            if(count1 == 1){
                start1 = i;
            }
            else{
                end1 = i; 
            } 
        }
        if(s[i] == letter2){
            count2++; 
            if(count2 == 1){
                start2 = i;
            }
            else{
                end2 = i; 
            }
        }
    }
    //cout << "letter 1: " << " " << letter1 << " " << start1 << " " << end1 << " " << "letter 2" << " " << letter2 << " " << start2 << " " << end2 << "\n"; 
    if(start1 < start2 && start2 < end1 && end1 < end2){
        return true; 
    }
    return false; 
}
int main() {
    ifstream fin("circlecross.in");
    ofstream fout("circlecross.out"); 
    int ans = 0; 
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
    string s; 
    fin >> s; 
    for(int i = 0; i < 26; i++){
        for(int j = 0; j < 26; j++){
	    if(i != j){
                if(check(s, alpha[i], alpha[j]) == true){
                    ans++; 
                }
	    }
        }
    }
    fout << ans; 
}