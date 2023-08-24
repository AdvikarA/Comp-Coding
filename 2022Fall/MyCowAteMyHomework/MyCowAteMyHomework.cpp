#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
#define double long double
main(){
    ifstream fin ("homework.in");
    ofstream fout ("homework.out");
    int n;
    fin >> n;
    vector<int> scores;
    vector<int> sorted;
    double prefix[n+1];
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        double a; fin >> a;
        scores.push_back(a);
        sorted.push_back(a);
        prefix[i] = (prefix[i-1]) + a;
    }
    double bigprefix[n+1];
    bigprefix[n] = 2147483647;
    for(int i = n-1; i >= 0; i--){
        if(scores[i] < bigprefix[i+1]){
            bigprefix[i] = scores[i];
        }
        else{
            bigprefix[i] = bigprefix[i+1];
        }
    }
    for(int i = 0; i < n+1; i++){
        //cout << bigprefix[i] << " ";
    }
    
    sort(sorted.begin(), sorted.end()); 
    double final = 0;
    double ans = 0;
    int as = 0;
    int ASFR = 0;
    int sortind = 0;
    vector<int> answers; 
    for(int i = 1; i < n-1; i++){
        //cout << prefix[n] - prefix[i] << " " << bigprefix[i] << "\n";
        ans = (prefix[n] - prefix[i] - bigprefix[i])/(n-(i+1));
        //cout << ans << "\n";
        if(ans >= final){
            final = ans; 
        }
    }
    cout << "FINAL: " << final<<"\n";
    for(int i = 1; i < n-1; i++){
        //cout << prefix[n] - prefix[i] << " " << bigprefix[i] << "\n";
        ans = (prefix[n] - prefix[i] - bigprefix[i])/(n-(i+1));
        cout << ans <<  " " << final << "\n";
        if(ans == final){
            answers.push_back(i);
        }
    }
    for(int i = 0; i < answers.size(); i++){
        if(i == 0){
            fout << answers[i];
        }
        else{
            fout << "\n" << answers[i];
        }
    }
}