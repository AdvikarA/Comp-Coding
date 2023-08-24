#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    int n; 
    fin >> n;
    vector <int> cows;
    vector <int> temp;
    for(int i = 0; i < n; i++){
        int a; 
        fin >> a;
        cows.push_back(a); 
        temp.push_back(a);
    }
    int swap = 0; 
    sort(temp.begin(), temp.end()); 
    for(int i = 0; i < n; i++){
        int a = temp[i]; 
        for(int j = 0; j <n; j++){
            if(cows[j] == a){
                if(j != n-1){
                    if(cows[j] == cows[j+1]){
                        continue;
                    }
                    else{
                        for(int k = 0; k < n; k++){
                            if(cows[k] > cows[j] && k < j){
                                //fout << j << " " << k << " " << cows[k] << " " << cows[j] << "\n";
                                int b = cows[k];
                                cows[k] = cows[j];
                                cows[j] = b; 
                                swap++; 
                                break; 
                            }
                        }
                    }
                }
                else{
                    for(int k = 0; k < n; k++){
                        if(cows[k] > cows[j] && k < j){
                            //fout << j << " " << k << " " << cows[k] << " " << cows[j] << "\n";
                            int b = cows[k];
                            cows[k] = cows[j];
                            cows[j] = b; 
                            swap++; 
                            break; 
                        }
                    }
                }
                //fout << j << "\n";
                
            }
        }
    }
    fout << swap; 
}