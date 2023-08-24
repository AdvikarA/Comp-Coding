#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream fin("taming.in");
    ofstream fout("taming.out");
    int n; 
    fin >> n;
    vector<int> daysincebreak; 
    for(int i = 0; i < n; i++){
        int a;
        fin >> a; 
        daysincebreak.push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(daysincebreak[i] != -1){
            if (daysincebreak[i-daysincebreak[i]] == -1 || daysincebreak[i-daysincebreak[i]] == 0){
                daysincebreak[i-daysincebreak[i]]=0; 
            }
            else{
                fout << -1;
                return 0; 
            }
            
        }
    }
    daysincebreak[0] = 0;
    
    int min = 0; 
    for(int i = 0; i < n; i++){
        if(daysincebreak[i] == 0){
            min++; 
        }
    }
    
    for(int i = 0; i < n; i++){
        if(daysincebreak[i] != -1 && daysincebreak[i] != 0){
            for(int j = i; j >= i - daysincebreak[i]; j--){
                if(daysincebreak[j] == -1){
                    daysincebreak[j] = daysincebreak[j+1]-1; 
                }
            } 
        }
    }
    int max = 0; 
    for(int i = 0; i < n; i++){
        if(daysincebreak[i] == 0 || daysincebreak[i] == -1){
            max++; 
        }
    }
    
    fout << min << " " << max; 
}