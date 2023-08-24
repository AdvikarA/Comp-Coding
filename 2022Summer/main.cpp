#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <set>
using namespace std; 
static int siz;
static string word;
static int ans = 0;
void recurse(string s){
    if(s.size() >= siz){
        //cout << "FINAL: " << s << "\n";
        if(word == s){
            ans++;
        }
    }
    else{
        string splitR = s;
        splitR.pop_back(); 
        string splitL = s;
        splitL.erase(0,1);
        string attachR1 = s + splitL;
        string attachR2 = s + splitR;
        string attachL1 = splitL + s; 
        string attachL2 = splitR + s; 
        //cout << splitR << " " << splitL << "\n";
        //cout << attachL1 << " " << attachL2 << " " << attachR1 << " " << attachR2 << "\n";
        //cout << "L1\n";
        recurse(attachL1);
        //cout << "R1\n";
        recurse(attachR1);
        //cout << "L2\n";
        recurse(attachL2);
        //cout<< "R2\n";
        recurse(attachR2);

    }
}
int main(){
    ifstream fin ("scode.in");
    ofstream fout ("scode.out");
    string s;
    fin >> s;
    siz = s.size();
    word = s; 
    string test = "AB";
    //cout << "TEST: " << test.substr(0, test.size()-1)<<"\n";
    vector<bool>arr;
    set<string> substrs; 
    int index = 0;
    for (int i = 0; i < s.size(); i++){
        for (int len = 2; len <= s.size() - i; len++){
            string a = s.substr(i, len);
            arr.push_back(false); 
            if(a.size() != siz){
                substrs.insert(a);
 
            }
            //cout << "NEW " << a << "\n\n\n";
        }
    }
    for(auto itr: substrs){
        recurse(itr);
    }
    for(int i = 0; i < arr.size(); i++){
        //cout << arr[i] << "\n";
    }
    fout << ans;

}