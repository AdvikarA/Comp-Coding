#include<iostream>
#include <set>
using namespace std; 
int main(){
    int n; 
    set<int> x; 
    int element; 
    cin >> n; 
    for(int i = 0; i <n; i++){
        cin >> element; 
        x.insert(element); 
    }
    cout << x.size(); 
} // namespace std; 
