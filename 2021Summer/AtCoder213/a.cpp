#include <iostream>
using namespace std;
int main(){
    int a, b;
    cin >> a >> b;
    for(int c = 0; c <= 255; c++){
        if((a^c) == b){
            cout << c; 
            return 0; 
        }
    }

}