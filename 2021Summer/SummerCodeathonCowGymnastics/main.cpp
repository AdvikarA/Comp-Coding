#include <fstream>
using namespace std;
int main() {
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");
    int k ,n;
    fin  >> k >> n; 
    int cows[k][n]; 
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            fin  >> cows[i][j]; 
        }
    }
   
    int ans = 0; 
    for(int jo = 0; jo < n; jo++){
        for(int h = jo +1; h < n; h++){
            int cow1 = cows[0][jo]; 
            int cow2 = cows[0][h]; 
            int count = 0; 
             
            for(int a = 0; a < k; a++){
                int temp1 = -1; 
                int temp2 = -1;
                for(int b = 0; b < n; b++){
                    if(cows[a][b] == cow1){
                        temp1 = b;
                    }
                    if(cows[a][b] == cow2){
                        temp2 = b; 
                    }
                }
                if(temp1 < temp2){
                        count++; 
                }
            }
            if(count == k){
                ans++; 
            }
        }
    }
    fout << ans; 
}