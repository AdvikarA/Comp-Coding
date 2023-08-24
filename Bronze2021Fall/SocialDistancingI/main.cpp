#include <fstream>
#include <vector>
#include <math.h>
#include <map>
using namespace std;
int main(){
    ifstream fin("socdist1.in");
    ofstream fout("socdist1.out");
    int n; 
    fin >> n; 
    string s; 
    fin >> s; 
    int gapstart = -1;
    int highestgap = 0; 
    int topaddtwo = 0; 
    int topone = 0;
    int toptwo = 0; 
    int ans = 10000000000; 
    for(int i = 0; i < n; i++){
        bool isone = s[i] == '1'; 
        if(isone){
            if(gapstart == -1){
                topone = i; 
                topaddtwo = i/2; 
                gapstart = i;
            }
            else{
                int test = (i-gapstart)/2;
                if (test >= topone){
                    toptwo = topone; 
                    topone = test;
                }
                else if(test>toptwo){
                    toptwo = test;
                }
                topaddtwo = max(topaddtwo,(i-gapstart)/3);
                ans = min(ans, i-gapstart);
                gapstart = i;
            }
        }
    }
    if(gapstart == -1){
        topaddtwo = max(topaddtwo, n-1); 
    }
    else{
        int test = n-gapstart-1;
        if (test >= topone){
            toptwo = topone;
            topone = test;
        }
        else if(test>toptwo){
            toptwo = test;
        }
    }
    topaddtwo = max(topaddtwo, (n-gapstart-1)/2);
    fout << min(max(min(toptwo, topone), topaddtwo), ans);
   //min(max(, topaddtwo), ans);
}