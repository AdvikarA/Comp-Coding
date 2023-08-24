#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
using namespace std;
static int n, m;
bool test(vector<string> spottedcows, vector<string> plaincows, int i, int j, int k){
    bool arr[n];
    for(int c = 0; c < n; c++){
        arr[c] = false;
    }
    for(int ii = 0; ii < n; ii++){
        int test = 0;
        for(int jj = 0; jj < n; jj++){
            string a = "";
            a+=spottedcows[ii][i];
            a+=spottedcows[ii][j];
            a+=spottedcows[ii][k];
            string b = "";
            b+=plaincows[jj][i];
            b+=plaincows[jj][j];
            b+=plaincows[jj][k];
            //string a = spottedcows[ii][i]+spottedcows[ii][j]+spottedcows[ii][k]; 
            //string b = plaincows[ii][i]+plaincows[ii][j]+plaincows[ii][k];
            /**if(spottedcows[ii][i]==plaincows[jj][i]&&spottedcows[ii][j]==plaincows[jj][j]&&spottedcows[ii][k]==plaincows[jj][k]){
                return false;
            }
            else{
                cout << spottedcows[ii][i]+spottedcows[ii][j]+spottedcows[ii][k] << " " << plaincows[ii][i]+plaincows[ii][j]+plaincows[ii][k]<<"\n";
            }**/
            if(a.compare(b) == 0){
                //cout << a << "   " << b <<  "\n";
                return false;            

            }
            else{
                //cout << a  << " " << b <<  " " << ii << " " << jj <<"\n";

            }
            
            
        }
    }
    //cout << a  << " " << b << "\n";
    return true;
    
    
}
int main(){
    ifstream fin ("cownomics.in");
    ofstream fout ("cownomics.out");
    fin >> n >> m;
    vector<string> spottedcows;
    vector<string> plaincows;

    for(int i = 0; i < n; i++){
        string a;
        fin >> a;
        spottedcows.push_back(a);
    }
    for(int i = 0; i < n; i++){
        string a;
        fin >> a;  
        plaincows.push_back(a);  
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            for(int k = j + 1; k < m; k++){
                if(test(spottedcows, plaincows, i, j, k)){
                    ans++;
                    //cout << i << " " << j << " " << k << "\n";
                }
                else{
                    //cout << "FAILED\n";
                }
                
            }
        }
        
    }
    fout <<ans;
}