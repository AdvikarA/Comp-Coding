#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int main(){
    ifstream fin("guess.in");
    ofstream fout("guess.out");
    vector <set<string>> animals; 
    int n;
    fin >> n;
    animals.resize(n);
    for(int i = 0; i < n; i++){
        string animal; 
        int numoftraits;
        fin >> animal >> numoftraits; 
        for(int j = 0; j < numoftraits; j++){
            string a; 
            fin >> a;
            animals[i].insert(a); 
        }
    }

    int maxsame = 0; 
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            set <string> combination;
            merge(animals[i].begin(), animals[i].end(), animals[j].begin(), animals[j].end(), inserter(combination, combination.begin()));
            int same = animals[i].size() + animals[j].size() - combination.size();
            maxsame = max(same, maxsame); 
            //fout << same << " " << animals[i].size() << " " << animals[j].size()  << " "<< combination.size() << "\n";
        }

    }
    fout << maxsame + 1; 

   
}