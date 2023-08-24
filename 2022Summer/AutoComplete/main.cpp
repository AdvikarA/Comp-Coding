#include<iostream>
#include<fstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
bool test(string s1, string s2){
    if(s1 <= s2){
        return true;
    }
    return false;
}
bool isSubstring(string s1, string s2)
{
    // using find method to check if s1 is
    // a substring of s2
    //cout << s1 << " " << s2 << "\n";
    if(s2 == s1){
        return true;
    }
    if (s2.find(s1) == 0)
        return true;
    return false;
}
bool my_compare(pair<string, int> aa, pair<string, int> bb)
{
    string a = aa.first; 
    string b = bb.first;
    // Check if a string is present as
    // prefix in another string, then
    // compare the size of the string
    // and return the larger size
    if (a.compare(0, b.size(), b) == 0
        || b.compare(0, a.size(), a) == 0)
        return a.size() < b.size();
 
    // Else return lexicographically
    // smallest string
    else
        return a < b;
}
int main(){
    ifstream fin ("auto.in");
    ofstream fout ("auto.out");
    int w; 
    int n;
    fin >> w >> n;
    vector<pair<string, int>> words; 
    for(int i = 0; i < w; i++){
        string a; 
        fin >> a;
        words.push_back(make_pair(a, i+1));
    }
    sort(words.begin(), words.end(), my_compare); 
    for(int i = 0; i < w; i++){
        cout << words[i].first << "\n";
    }
    
    for(int i = 0; i < n; i++){
        int num;
        string word;
        fin >> num>> word;    
        int a = 0, b = w-1;
    
        while (a != b) {
            int mid = (a+b)/2;
            if (test(word, words[mid].first)) {
                //cout << "IN BINARY " << word << " " << words[mid] << "\n";
                b = mid;
            }
            else {
                a = mid+1;
            }
        }
        
        //cout << "HERE " << word << " " << words[a+num-1].first<<"\n";
        if(((num + a-1) < w) && isSubstring(word, words[a+num-1].first)){
            fout << words[a+num-1].second<<"\n";
        }
        else{
            fout << "-1\n";
        }
    }
    
}




