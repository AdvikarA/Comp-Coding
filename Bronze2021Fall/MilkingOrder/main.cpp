#include <fstream>
#include <vector>
using namespace std; 
int main() {
    ifstream fin("milkorder.in");
    ofstream fout("milkorder.out"); 
    int N, K, M; 
    bool inorder = false; 
    bool isfixed = false;
    fin >> N >> M >> K; 
    vector <int> cows; 
    for(int i = 0; i < N; i++){
        cows.push_back(0); 
    }
    vector <int> order; 
    for(int i = 0; i < M; i++){ 
        int a;
        fin >> a;
        if (a == 1){
            inorder = true; 
        }
        order.push_back(a);
    }
    for(int i = 0; i < K; i++){
        int a, b;
        fin >> a >> b;
        if(a == 1){
            isfixed = true;
            fout << b;
            break; 
        }
        cows[b-1] = a; 
    }
    int p1 = N-1;
    int p2 = M-1; 
    if(!isfixed && !inorder){
        while(p2 >= 0 ){
            bool done = false;
            for(int a=0; a<N; a++){
                if(cows[a] == order[p2]){
                    done = true;
                    p1 = a-1;
                    p2 -= 1;
                    break;
                }   
            }   
            if(!done){
                if(cows[p1] == 0){
                    cows[p1] = order[p2];
                    p1 -= 1;
                    p2 -=1;
                } else {
                    p1 -= 1;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(cows[i] == 0){
                fout << i+1;
                break; 
            }
        }
    }   
    else{
        p1 = 0;
        p2 = 0; 
        while(p2 < N){
            bool done = false;
            for(int a=0; a<N; a++){
                if(cows[a] == order[p2]){
                    done = true;
                    p1 = a+1;
                    p2 += 1;
                    break;
                }   
            }   
            if(!done){
                if(cows[p1] == 0){
                    cows[p1] = order[p2];
                    p1 += 1;
                    p2 +=1;
                } else {
                    p1 += 1;
                }
            }
        }
        for(int i = 0; i < N; i++){
            if(cows[i] == 1){
                fout << i+1;
                break; 
            }
        }
    }
} 