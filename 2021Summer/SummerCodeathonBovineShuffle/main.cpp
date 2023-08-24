#include <fstream>
using namespace std; 
int main() {
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int numcows;
    fin >> numcows; 
    int cows[numcows]; 
    int temp[numcows]; 
    int order[numcows];
    for(int i = 1; i <= numcows; i++){
        fin >> order[i]; 
    }
    for(int i = 1; i <= numcows; i++){
        fin >> cows[i]; 
        temp[i] = cows[i]; 
    }
    for(int k = 0; k < 3; k++){
        for(int i = 1; i <= numcows; i++){
            temp[i] = cows[i]; 
        }
        for(int i = 1; i <= numcows; i++){
            cows[i] = temp[order[i]];
        }
    }
    for(int i = 1; i <= numcows; i++){
        fout << cows[i] << "\n"; 
    }
}
