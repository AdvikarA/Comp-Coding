#include <fstream>
using namespace std;


int main(){
    int answer = 0;
    ifstream fin ("cowtip.in");
    ofstream fout("cowtip.out"); 
    int n; 
    fin >> n; 
    char arr[n][n]; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            fin >> arr[i][j]; 
        }
    }
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(arr[i][j] == '1'){
                answer++; 
                for(int a = 0; a <= i; a++){
                    for(int b = 0; b <= j; b++){
                        if(arr[a][b] == '1'){
                            arr[a][b] = '0';
                        }
                        else{
                            arr[a][b] = '1'; 
                        }
                    }
                }
            }
        }
    }
    fout << answer;
            
}