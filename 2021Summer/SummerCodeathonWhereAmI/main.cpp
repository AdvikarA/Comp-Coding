#include <fstream>
#include <string>
using namespace std; 
int main() {
    ifstream fin("whereami.in");
    ofstream fout("whereami.out"); 
    int n; 
    fin >> n; 
    string s;
    fin >> s; 
    int l = 1; 
    for(int i = 0; i < l; i++){
        for(int j = 0; j < n-l+1; j++){
            string sub = s.substr(j, l); 
            for(int k = j+1; k < n-l+1; k++){
                string sub2 = s.substr(k, l);
                //cout << "str1: " << sub <<" "<< "str2: " << sub2 << "\n";
                //cout << j << "\n";
                if(sub == sub2){
                    //cout<<sub<<sub2<<"\n";
                    l++; 
                    break; 
                }
            }
        }
    }
    fout << l; 
}