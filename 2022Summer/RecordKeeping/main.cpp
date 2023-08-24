#include<iostream>
#include<fstream>
#include<set>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main(){
    ifstream fin ("records.in");
    ofstream fout ("records.out");
    int n; fin >> n;
    set<string> words;
    string arr[n][3];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            string a;
            fin >> a;
            arr[i][j] = a;
            words.insert(a);
        }
    }
    map<string, string>m;
    int index = 0;
    for(auto itr = words.begin(); itr != words.end(); itr++){
        string str = to_string(index);
        m[*itr]=str; 
        index++;
        //cout << str << "\n";
    }
    vector<string> num; 
    for(int i = 0; i < n; i++){
        string a, b, c; 
        a = arr[i][0];
        b = arr[i][1];
        c = arr[i][2];

        vector<string>s;
        //cout << m[a] << " " << m[b] << " " << m[c] << "\n";
        s.push_back(m[a]);
        s.push_back(m[b]);
        s.push_back(m[c]);
        sort(s.begin(), s.end()); 
        string comb = ""; 
        comb += s[0];
        comb += s[1];
        comb += s[2];
        num.push_back(comb);
    }
    map<string, int>final;
    for(int i = 0; i < n; i++){
        final[num[i]] = 0;
    }
    for(int i = 0; i < n; i++){
        final[num[i]]++;
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, final[num[i]]);
    }
    fout << ans;
}