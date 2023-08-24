#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("cardgame.in");
    ofstream fout ("cardgame.out");
    int n; fin >> n; 
    vector<int> elsie_first_half;
    bool used[n*2]; 
    for(int i = 0; i < n*2; i++){
        used[i] = false; 
    }
    vector<int> elsie_second_half;
    vector<int> bessie_first_half;
    vector<int> bessie_second_half; 
    for(int i = 0; i < n/2; i++){
        int a; fin >> a;
        elsie_first_half.push_back(a); 
        used[a-1] = true;
    }
    for(int i = 0; i < n/2; i++){
        int a; fin >> a;
        elsie_second_half.push_back(a);
        used[a-1] = true; 
    }
    for(int i = 0; i < n*2; i++){
        if(!used[i]){
            //cout << i+1 << " " << n/2 << "\n";
            if(bessie_second_half.size() < n/2){
                bessie_second_half.push_back(i+1); 
            }
            else{
                bessie_first_half.push_back(i+1);
            }
        }
    }
    for(int i = 0; i < n/2; i++){
        //cout << elsie_first_half[i] << " "; 
        //cout << "\n";
    }
    for(int i = 0; i < n/2; i++){
        //cout << elsie_second_half[i] << " "; 
        //cout << "\n";
    }
    for(int i = 0; i < n/2; i++){
        //cout << bessie_first_half[i] << " "; 
        //cout << "\n";
    }
    sort(bessie_first_half.begin(), bessie_first_half.end());
    sort(elsie_first_half.begin(), elsie_first_half.end());
    sort(elsie_second_half.rbegin(), elsie_second_half.rend());
    sort(bessie_second_half.rbegin(), bessie_second_half.rend());

    for(int i = 0; i < n/2; i++){
        //cout << bessie_second_half[i] << " "; 
        //cout << "\n";
    }
    int wins = 0;
    int bessie_index = n/2-1; 
    for(int i = n/2-1; i >= 0; i--){
        if(bessie_first_half[bessie_index] > elsie_first_half[i]){
            bessie_index--; 
            wins++; 
        }
    }
    //cout << wins;
    int elsie_index = 0; 
    for(int i = 0; i < n/2; i++){
        if(bessie_second_half[i] < elsie_second_half[elsie_index]){
            elsie_index++; 
            wins++; 
        }
    }
    //cout << "WINZ " << wins << "\n";
    fout << wins;
}