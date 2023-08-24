#include<iostream>
#include<fstream>
#include<vector>
#include<utility> 
#include<map>
#include<string>
#include<algorithm>
using namespace std; 
int main(){
    int n, g;
    ifstream fin ("measurement.in");
    ofstream fout ("measurement.out");
    fin >> n >> g;
    map<int, int>cows;    
    vector<pair<int, int>>values;

    vector<pair<int, pair<int, string>>>info;
    for(int i = 0; i < n; i++){
        int a,b;
        string s;
        fin >> a >> b >> s;
        cows[b] = 10; 
        values.push_back(make_pair(b, 10));
        info.push_back(make_pair(a, make_pair(b, s))); 
    }
    sort(info.begin(), info.end()); 
    int biggest = g;
    int ans = 0;
    int second_biggest = g;        
    for(int i = 0; i < n; i++){
        int id = info[i].second.first; 
        string change = info[i].second.second;
        string number = change.substr(1, change.size()-1); 
        int num = stoi(number);
        char sign = change[0]; 
        bool isbiggest = false;
        if(cows[id] == biggest){
            isbiggest = true;
        }
        if(sign == '+'){
            cows[id]+=num;
        }
        else{
            cows[id]-=num; 
        }
        if(isbiggest){
            if(biggest != second_biggest){
                if(cows[id] <= second_biggest){
                    ans++; 
                    biggest = second_biggest;
                }
            }
            else{
                if(cows[id] < second_biggest){
                    ans++; 
                    biggest = second_biggest;
                }
            }
        }

    }
}