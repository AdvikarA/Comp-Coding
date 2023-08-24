#include <fstream>
#include <vector>
#include <utility>
using namespace std;
int main(){
    ifstream fin ("reduce.in");
    ofstream fout ("reduce.out");
    int n; 
    fin >> n;
    vector <int> a; 
    int finalans = 2147483647; 
    int x[n];
    int y[n];
    for(int i = 0; i < n; i++){
        fin >> x[i] >> y[i];
    }
    int ans = 0; 
    int minx = 2147483647; 
    int maxx = 0; 
    int miny = 2147483647; 
    int maxy = 0; 

    for(int j = 0; j < n; j++){
        
        if(x[j] > maxx){
            maxx = x[j]; 
        }
        if(x[j]< minx){
            minx = x[j];
        }
        if(y[j] > maxy){
            maxy = y[j];
        }
        if(y[j] < miny){
            miny = y[j];
        }
    }
    for(int i = 0; i < n; i++){
        if(x[i] == maxx || x[i] == minx || y[i] == maxy || y[i] == miny){
            a.push_back(i);
        } 
    }
    for(int i = 0; i < a.size(); i++){
        int minx2 = 2147483647; 
        int maxx2 = 0; 
        int miny2 = 2147483647; 
        int maxy2 = 0; 
        for(int j = 0; j < n; j++){
            if(j != a[i]){
                if(x[j] > maxx2){
                    maxx2 = x[j]; 
                }
                if(x[j]< minx2){
                    minx2 = x[j];
                }
                if(y[j] > maxy2){
                    maxy2 = y[j];
                }
                if(y[j] < miny2){
                    miny2 = y[j];
                }
            }
        }
        ans = (maxx2 - minx2) * (maxy2 - miny2);
        finalans = min(ans, finalans);
    }    
    fout << finalans;
}