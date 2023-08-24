#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
int main(){
    int n; 

    cin >> n;
    string s;
    cin >> s;
    vector<string>lengthtree;
    int end = n-3;
    int ans= 0;
    for(int i = 0; i <n; i++){
        int timesinloop = 0;
        int numgs= 0;
        int numhs= 0;
        for(int j = i; j< n; j++){
            timesinloop++;
            if(s[j] == 'G'){
                numgs++;
            }
            if(s[j] == 'H'){
                numhs++; 
            }
            if(numgs >= 2 && numhs >= 2){
                break; 
            }
            if(timesinloop >=3){
                lengthtree.push_back(s.substr(i, timesinloop)); 
            }            
            //cout << "til " <<timesinloop<<" numg "<<numgs<<" numhs "<<numhs<<" i "<<i<<" j "<<j <<" ans "<<ans<<endl;

        }
    }
    for(int i= 0; i < lengthtree.size(); i++){
        int numofgs = 0;
        int numofhs = 0;
        string a = lengthtree[i];
        bool uhoh = true;
        for(int j=0; j < a.size(); j++){
            //fout << a[j] << endl;
            if(a[j] == 'G'){
                numofgs++;
            }
            else{
                numofhs++;
            }
            if(numofhs > 1 && numofgs > 1){
                uhoh = false;
                break;
            }
        }
        if(uhoh){
            ans++;
        }
        
    }

    
    cout << 3;
}