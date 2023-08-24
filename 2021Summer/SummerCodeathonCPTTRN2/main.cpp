#include <iostream>
using namespace std;
int main(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){
        int x, y; 
        cin >> x >> y;
        for(int rows = 0; rows < x; rows++){
            if(rows != 0 && rows != x-1){
                for(int col = 0; col < y; col++){
                    if(col != 0 && col != y-1){
                        cout << ".";
                    }
                    else{
                        cout << "*";
                    }
                }
            }
            else{
                for(int col = 0; col < y; col++){
                    cout << "*"; 
                }
            }
            cout << "\n";
        }
    }
}