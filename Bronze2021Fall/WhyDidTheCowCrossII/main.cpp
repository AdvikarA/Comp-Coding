#include <fstream>
using namespace std;
int main(){
    ifstream fin ("circlecross.in");
    ofstream fout ("circlecross.out");
    string s; 
    fin >> s;
    int ans = 0;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for(int i = 0; i < 26; i++){
        for(int j = 0; j< 26; j++){
            if(i != j){
                int start1 = -1;
                int end1 = -1; 
                int start2 = -1; 
                int end2 = -1; 
                for(int k = 0; k < 52; k++){
                    if(s[k] == alpha[i]){
                        if(start1 != -1){
                            end1 = k; 
                        }
                        else{
                            start1 = k; 
                        }
                    }
                    if(s[k] == alpha[j]){
                        if(start2 != -1){
                            end2 = k;
                        }
                        else{
                            start2 = k;
                        }
                    }
                }
                if(start1 < start2 && start2 < end1 && end1 < end2){
                    ans++;  
                }
            }
        }
    }
    fout << ans;        
}