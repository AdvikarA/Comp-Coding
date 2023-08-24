#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ifstream fin ("angry.in"); 
    ofstream fout ("angry.out");
    int n; 
    fin >> n; 
    vector <int> cows;
    vector <bool> exploded;
    for(int i = 0; i < n; i++){
        int a; 
        fin >> a;
        cows.push_back(a); 
        exploded.push_back(false); 
    }
    int answer = 0; 
    sort(cows.begin(), cows.end());
    for(int i = 0; i < n; i++){
        //fout << cows[i] << "\n";
    }
    for(int i = 0; i < cows.size(); i++){
        int radius = 1; 
        int cowhit = i; 
        int leastcowL = i; 
        int leastcowR = i;
        bool leftgoing = true;
        bool rightgoing = true; 
        while(leftgoing){
            if(cowhit-1 >= 0){
                if(cows[cowhit] - cows[cowhit-1]  <= radius && cowhit -1 >= 0){
                    int ogcow = cows[cowhit]; 
                    while(ogcow - cows[cowhit-1]  <= radius && cowhit -1 >= 0){
                        leastcowL = cowhit-1;
                        //fout << i << "hit" << "\n";
                        cowhit = leastcowL;
                    }
                    radius++;
                     
                }
                else{
                    leftgoing = false;
                }
            }
            else{
                leastcowL = 0; 
                leftgoing = false; 
            }
        }
        radius = 1;
        cowhit = i;
        while(rightgoing){
            if(cowhit+1 <= n-1){
                if(cows[cowhit+1] - cows[cowhit]  <= radius && cowhit+1 <= n-1){
                    int ogcow = cows[cowhit]; 
                    while(cows[cowhit+1] - ogcow  <= radius && cowhit+1 <= n-1){

                        //fout << cows[cowhit] << " " << cows[cowhit+1] << " " << cows[cowhit]+radius << "\n";

                        
                        leastcowR = cowhit+1;
                        //fout << i << "hit" << "\n";
                        cowhit = leastcowR;
                    }
                    radius++;
                }
                else{
                    rightgoing = false;
                }
            }
            else{
                leastcowR = n-1; 
                rightgoing = false; 
            }
        }
        //fout << cows[i] << " " << leastcowL << " " << leastcowR << "\n";
        //cout << leastcowL;
        //cout << leastcowR;
        int ans = leastcowR- leastcowL; 
        answer = max(answer, ans); 
        cout << "\n";
    }
    fout << answer+1;

}