#include <fstream>
#include <vector>
using namespace std; 
int main() {
    ifstream fin ("gymnastics.in");
    ofstream fout ("gymnastics.out");
    int rows, pos;
    int ans = 0; 
    fin>> rows >> pos;
    int ranks[rows][pos]; 
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < pos; j++){
            fin>> ranks[i][j]; 
        }
    }
    for(int i = 0; i < pos; i++){
        for(int j = 0; j < pos; j++){
            int cow1 = ranks[0][i];
            int cow2 = ranks[0][j]; 
            int pairs = 0; 
            for(int k = 0; k < rows; k++){
                int cowindex1 = 0; 
                int cowindex2 = 0; 
                for(int z =0; z < pos; z++){
                    if(ranks[k][z]==cow1){
                        cowindex1 = z;
                    }
                    if(ranks[k][z]==cow2){
                        cowindex2 = z;
                    }
                }
                if(cowindex1 < cowindex2){
                    pairs++; 
                }
            }
            if(pairs == rows){
                ans++; 
            }
        }
    }
    fout<<ans; 
    
}