#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
int n; 
int ans; 
vector<int> currenttemp;
vector<int> desiredtemp; 
vector<int> maxelements;
vector<int> fixedindexs;
int maxelement;
bool solved(){
    for(int i = 0; i < n; i++){
        if(currenttemp[i] == desiredtemp[i]){
            
        }
        else{
            return false;
        }
    }
    return true; 
}
int findmaxelement(){
    maxelement = 0;
    for(int i = 0; i < maxelements.size(); i++){
        maxelement = max(maxelement, maxelements[i]);
    }
    int maxindex = 0; 
    for(int i = 0; i < n; i++){
        if(desiredtemp[i] == maxelement){
            maxindex = i;
        }
    }    
    maxelements.erase(maxelements.begin() + maxindex);
    return maxindex;
}
void findfixed(){
    fixedindexs.clear(); 
    for(int i = 0; i <n; i++){
        if(currenttemp[i] == desiredtemp[i]){
            fixedindexs.push_back(i); 
        }
    }
}
void changevector(){    
    int maxindex = findmaxelement(); 
    bool add;
    for(int i = 0; i < n; i++){
        if(maxelement > currenttemp[maxindex]){
            add = true;
        }
        else{
            add = false;
        }
    }
    for(int j = 0; j < fixedindexs.size()-1; j++){
        if(add){
            for(int k = fixedindexs[j]; k < fixedindexs[j+1]; k++){
                currenttemp[k]+= maxelement - currenttemp[maxindex]; 
            }
            ans += maxelement - currenttemp[maxindex];
        }
        else{
            for(int k = fixedindexs[j]; k < fixedindexs[j+1]; k++){
                currenttemp[k]-= currenttemp[maxindex] - maxelement; 
            }
            ans += currenttemp[maxindex] - maxelement; 
        }
        
    }
    cout << "aa";
}
int main(){
    cin >> n;
    ans = 0;
    
    for(int i = 0; i <n; i++){
        int a; 
        cin>> a;
        desiredtemp.push_back(a); 
        maxelements.push_back(a);
    }

    for(int i = 0; i <n; i++){
        int a;
        cin>>a;
        currenttemp.push_back(a);
        if(a == desiredtemp[i]){
            fixedindexs.push_back(i); 
        }
        
    }
    while(!solved()){
        findfixed();
        changevector();
    }
    cout << ans; 
}

