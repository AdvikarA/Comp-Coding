#include <iostream>
using namespace std;
int main(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        cout << "*"; 
        for(int c = 0; c < y*3; c++){
            cout << "*"; 
        }
        cout << "\n"; 
        for(int rows = 0; rows < x; rows++){
            for(int p  = 0; p < 2; p++){
                cout << "*";
                for(int col = 0; col < y; col++){
                    cout << "..*"; 
                }
                cout << "\n";
            }
            cout << "*";
            for(int c = 0; c < y*3; c++){
                cout << "*"; 
            }
            cout << "\n";
        }
    }
}