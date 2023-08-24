#include <iostream>
#include <fstream>
using namespace std; 
int main(){
    ifstream fin("bcount.in");
    ofstream fout("bcount.out");
    int N, Q;
    fin >> N >> Q;
    int arr[N];
    for(int i = 0; i < N; i++){
        fin >> arr[i];
    }
    int psumA[N+1];
    int psumB[N+1];
    int psumC[N+1];
    psumA[0] = 0; 
    psumB[0] = 0;
    psumC[0] = 0;
    for(int i = 0; i < N+1; i++){
        if(arr[i] == 1){
            psumA[i+1] = psumA[i] + 1;
        }
        else{
            psumA[i+1] = psumA[i];
        }
    }
    for(int i = 0; i < N+1; i++){
        if(arr[i] == 2){
            psumB[i+1] = psumB[i] + 1;
        }
        else{
            psumB[i+1] = psumB[i];
        }
    }
    for(int i = 0; i < N+1; i++){
        if(arr[i] == 3){
            psumC[i+1] = psumC[i] + 1;
        }
        else{
            psumC[i+1] = psumC[i];
        }
    }
    for(int i = 0; i < N+1; i++){
        //cout << psumA[i] << " ";
    }
    for(int i = 0; i < Q; i++){
        int a, b;
        fin >> a >> b; 
        
        fout << psumA[b] - psumA[a-1] << " " << psumB[b] - psumB[a-1] << " "  << psumC[b] - psumC[a-1] << "\n";
    }
}