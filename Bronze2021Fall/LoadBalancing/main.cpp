#include <fstream>
#include <algorithm>
using namespace std;
int nw(int a, int b, int n, int x[], int y[]){
    int nwcount = 0; 
    for(int i = 0; i < n; i++){
        if(x[i] < a && y[i] > b){
            nwcount++;
        }
        else if(x[i] == a || y[i] == b){
            return 0; 
        }
    }
    return nwcount;
}
int sw(int a, int b, int n, int x[], int y[]){
    int swcount = 0; 
    for(int i = 0; i < n; i++){
        if(x[i] < a && y[i] < b){
            swcount++;
        }
        else if(x[i] == a || y[i] == b){
            return 0; 
        }
    }
    return swcount;
}
int ne(int a, int b, int n, int x[], int y[]){
    int necount = 0; 
    for(int i = 0; i < n; i++){
        if(x[i] > a && y[i] > b){
            necount++;
        }
        else if(x[i] == a || y[i] == b){
            return 0; 
        }
    }
    return necount;
}
int se(int a, int b, int n, int x[], int y[]){
    int secount = 0; 
    for(int i = 0; i < n; i++){
        if(x[i] > a && y[i] < b){
            secount++;
        }
        else if(x[i] == a || y[i] == b){
            return 0; 
        }
    }
    return secount;
}
int main(){
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int n, B; 
    fin >> n >> B; 
    int x[n];
    int y[n]; 
    int mmx = 10000000; 
    int mmy = 10000000; 
    int mx = 0; 
    int my = 0; 

    for(int i = 0; i < n; i++){
        fin >> x[i] >> y[i]; 
        mmx = min(x[i], mmx);
        mmy = min(y[i], mmy);
        mx = max(x[i], mx);
        my = max(y[i], my);

    }
    int ans = 0;
    int answer = 10000000; 
    for(int a = 0; a < n-1; a++){
        for(int b = 0; b < n-1; b++){
                int nww = nw(x[a]+1, y[b]+1, n, x, y);
                int nee = ne(x[a]+1, y[b]+1, n, x, y);
                int sww = sw(x[a]+1, y[b]+1, n, x, y); 
                int see = se(x[a]+1, y[b]+1, n, x, y); 
                int m = max(nww, sww);
                int l = max(nee, see);
                ans = max(m, l);   
                //fout << "A " <<  x[a]+1 << " " << "B " <<y[b]+1 << " " <<nww << nee << sww << see << ans << "\n";
                answer = min(ans, answer); 

            
        }
    }
    fout << answer;
}