#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main(){
    ifstream fin ("moobuzz.in");
    ofstream fout ("moobuzz.out");
    long long n; 
    fin>>n;
    long long arr[8] = {1, 2, 4, 7, 8, 11, 13, 14}; 
    long long factor = n/8; 
    long long remainder = n%8; 
    long long ans = factor*15 + arr[remainder-1];
    fout << ans; 
}