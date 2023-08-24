#include <fstream>
#include <vector>
#include <utility>
#include <map>
using namespace std;
int main(){
    ifstream fin("blocks.in");
    ofstream fout("blocks.out"); 
    int n; 
    fin >> n; 
    vector <pair<string, string>> words; 
    for(int i = 0; i < n; i++){
        string a, b; 
        fin >> a; 
        fin >> b;
        words.push_back(make_pair(a,b));

    }
    map <char, int> alphaneeded; 
    map <char, int> ans; 
    string alpha = "abcdefghijklmnopqrstuvwxyz"; 
    for(int i = 0; i < alpha.size(); i++){
            ans[alpha[i]] = 0; 
    }
    for (int i = 0; i < n; i++)
    {
        for(int i = 0; i < alpha.size(); i++){
            alphaneeded[alpha[i]] = 0; 
        }
        for(int o = 0; o < alpha.size(); o++){
            for(int j = 0; j < words[i].first.size(); j++){
                if(alpha[o] == words[i].first[j]){
                    alphaneeded[alpha[o]] += 1; 
                }
            }
        }
        for(int o = 0; o < alpha.size(); o++){
            int test = 0; 

            for(int j = 0; j < words[i].second.size(); j++){
                if(alpha[o] == words[i].second[j]){
                    test++; 
                    if(test > alphaneeded[alpha[o]]){
                        alphaneeded[alpha[o]] += 1; 

                    }
                }
            }
        }
        for(int i = 0; i < alpha.size(); i++){
            if(alphaneeded[alpha[i]] != 0){
                //fout << alpha[i] << " " << alphaneeded[alpha[i]] << "\n";
            }
        }
        for(int i = 0; i < alpha.size(); i++){
            ans[alpha[i]] += alphaneeded[alpha[i]]; 
        }
        //fout << "\n\n";
        
    }
    for(int i = 0; i < alpha.size(); i++){
        fout << ans[alpha[i]] << "\n";
    }
    
    
    
}