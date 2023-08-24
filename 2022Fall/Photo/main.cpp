#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int main(){
    ifstream fin ("photo.in");
    ofstream fout ("photo.out");
    int N, K;
    fin >> N >> K;
    vector<int> starts;
    vector<int> ends;
    for(int i = 0; i < K; i++){
        int a, b;
        fin >> a >> b;
        if(a < b){
            starts.push_back(a);
            ends.push_back(b);
        }
        else{
            starts.push_back(b);
            ends.push_back(a);
        }
         
    }
    int first = 1; 
    int last = N; 
    int pics = 0;
    while(first <= N){
        last = N;
        for(int i = 0; i < K; i++){
            if(starts[i] >= first && ends[i] < last){
                last = ends[i]-1; 
            }
        }
        first = last + 1; 
        pics++; 
        //cout << first << "\n";
    }
    fout << pics;
}