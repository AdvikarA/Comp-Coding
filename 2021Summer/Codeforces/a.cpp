#include <iostream>
using namespace std;
int main(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        if(a == b && a == 0){
            cout << 0 << "\n";
        }
        else if(a == b){
            cout << 1 << "\n";
        }
        else if(abs(a-b)%2 == 0){
            cout << 2 << "\n";
        }
        else
        {
            cout << -1 << "\n";
        }
    }
}