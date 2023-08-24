#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main(){
    ifstream fin ("swap.in");
    ofstream fout ("swap.out");
    int N, M, K; 
    fin >> N >> M >> K;
    int Ls[100001]; 
    int Rs[100001];
    bool visited[100001];
    int p[N]; 
    for(int i = 1; i <= N; i++){
        p[i] = i; 
    }
    for(int i = 0; i < M; i++){
        fin >> Ls[i] >> Rs[i];
        int start = Ls[i]; 
        int end = Rs[i]; 
        for(int j = 0; j < (end-start+1)/2; j++){
            //cout << j << "\n";
            //cout << p[Ls[i]+j] << " " << p[Rs[i]-j] << "\n";
            int temp = p[Ls[i]+j];
            p[Ls[i]+j] = p[Rs[i]-j]; 
            p[Rs[i]-j] = temp; 
        }
    }
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            int start = p[i];
            vector<int> cycle; 
            cycle.push_back(i); 
            while(start != i){
                visited[start] = true;
                cycle.push_back(start);
                start = p[start];
            }
            for(int j = 0; j < cycle.size(); j++){
                //cout << cycle[j] << " ";
            }
            //cout << "\n";
            int step = K % cycle.size(); 
            for(int j = 0; j < cycle.size(); j++){
                p[cycle[j]] = cycle[(j+step)%cycle.size()]; 
            }
        }
    }
    
    for(int i = 1; i <= N; i++){
        if(i == N){
            fout << p[i];
        }
        else{
            fout << p[i] << "\n";
        }
    }
}