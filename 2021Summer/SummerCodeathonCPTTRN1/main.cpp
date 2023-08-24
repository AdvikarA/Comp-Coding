#include <iostream>
using namespace std;
int main(){
    int n; 
    cin >> n; 
    for(int i = 0; i < n; i++){
        int x, y; 
        bool aa; 
        cin >> x >> y; 
        for(int rows = 0; rows < x; rows++){
            if(rows % 2 == 1){
                aa = true; 
            }
            else{
                aa = false;
            }
            for(int col = 0; col < y; col++){
                if(aa == false){
                    if(col % 2 == 0){
                        cout << '*';
                    }
                    else{
                        cout << '.'; 
                    }
                }
                else{
                    if(col % 2 == 1){
                        cout << '*';
                    }
                    else{
                        cout << '.'; 
                    }
                }
            }
            cout << "\n"; 
        }
    }
}