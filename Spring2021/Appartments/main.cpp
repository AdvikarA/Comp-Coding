#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;
int main(){
    int numofapplicants; 
    int numofapparts; 
    int difference; 
    int ans = 0; 
    vector<int> want; 
    multiset<int> price;
    int x; 

    for(int i = 0; i< numofapparts; i++){
        cin >> want[i]; 
    }
    for(int i = 0; i< numofapplicants; i++){
        cin >> x; 
        price.insert(x); 
    }
    sort(want.begin(), want.end()); 
    for(int i = 0; i < numofapparts; i++ ){
        auto y = price.lower_bound(want[i]-difference);
        if(y == price.end()){
            continue;
        }
        else if(*y > want[i]+difference ){
            continue;
        }
        else{
            ans++;
            price.erase(*y);
        }
    }
}