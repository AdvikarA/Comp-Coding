#include <fstream>
#include <vector>
#include <string.h>
using namespace std;
int main(){
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int n;s
    fin >> n;
    string s;
    fin >> s;
    vector<string> arr[n];
    //while(true){
        for(int starting1 = 0; starting1 < n; starting1++){
            for(int ending =3; ending < n; ending++){
                string a = s.substr(starting1, ending);
                int aa = strlen(a);
                arr[aa].push_back(a);
            }
        }
    //}
}

