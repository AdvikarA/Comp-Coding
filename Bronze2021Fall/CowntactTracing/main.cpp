#include <string>
#include <fstream>
using namespace std;
bool check(int i, int T, int t[], int x[], int y[], int N, int cows[], string end, int k){
    ofstream fout("traffin.out");
    fout << "k " << k;
    cows[i] = 1; 
    int handshakesleft[N];
    string cowsstring = "";                
    for(int l = 0; l < N; l++){
        handshakesleft[i] = k;
    }
    for(int time = 0; time <= 250; time++){
        for(int event = 0; event < T; event++){
            if(t[event] == time){     
                if(cows[x[event]-1] == 1){
                    if(handshakesleft[x[event]] -1 >= 0){
                        cows[y[event]-1] = 1; 
                        handshakesleft[event[x]]--;
                    }
                }
                else if(cows[y[event]-1] == 1){
                    if(handshakesleft[y[event]]-1 >= 0){
                        cows[x[event]-1] = 1; 
                        handshakesleft[event[y]]--;
                    }
                }
                for(int cow = 0; cow < N; cow++){
                    fout << cows[cow] << " ";
                }
                fout << "\n";
                
            }
        }
    }
    for(int cow = 0; cow < N; cow++){
        string j = to_string(cows[cow]); 
        cowsstring += j; 
        fout << cowsstring;
    }
    fout << cowsstring;
    for(int cow = 0; cow < N; cow++){
        cows[cow] = 0;
    }
    for(int jk = 0; jk < N; jk++){
        if(cowsstring[jk] == end[jk]){
            continue;
        }
        else{
            return false; 
        }
    }
    return true; 
}
int main(){
    ifstream fin("tracing.in");
    ofstream fout("tracing.out");
    int N, T;
    fin >> N >> T; 
    string end;
    fin >> end;
    int t[T];
    int x[T];
    int y[T];
    
    for(int i = 0; i < T; i++){
        fin >> t[i] >> x[i] >> y[i]; 
    }
    int ans = 0; 
    int mians = 1000000; 
    int mans = 0;
    int cows[N] = {0};
    bool aa = false;
    bool seen[N] = {false};
    for(int i = 0; i < N; i++){
        cows[i] = 1; 
        for(int k = 1; k < T+1; k++){
            if(check(i, T, t, x, y, N, cows, end, k)){
                fout << "W" << "\n";
                if(k == T){
                    //fout<<"ddddddddddd";
                    aa = true;
                }
                if(seen[i]){
                    continue;
                }
                else{
                    ans++; 
                    seen[i] = true;
                }
                if(k < mians){
                    mians = k;
                } 
                if(k > mans){
                    mans = k; 
                }
                
                //fout <<"k " <<k << " ";
            }
            fout << i << " " << k << " " << ans << " " << mians << "\n";
        }
    }
    if(aa){
        fout << ans << " " << mians <<  " " << "Infinity"; 
    }
    else{
        fout << ans << " " << mians <<  " " << mans; 
    }
}