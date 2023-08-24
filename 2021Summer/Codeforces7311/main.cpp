#include <iostream>
using namespace std; 
int main() {
    int N;
    cin >> N; 
    for(int i = 0; i < N; i++){
        int a1, a2, b1, b2, f1, f2;
        cin >> a1 >> a2; 
        cin >> b1 >> b2; 
        cin >> f1 >> f2; 
        if(f1 == a1 && a1 == b1){
            if(f2 > a2 && f2 < b2){
                //cout << "w";
                cout << abs(b2-a2)+2 << "\n"; 
            }
            else if(f2 > b2 && f2 < a2){
                //cout << "u";
                cout << abs(b2-a2)+2 << "\n"; 
            }
            else{
                //cout << "o";
                cout << abs(b1-a1) + abs(b2-a2) << "\n";
            }
            //cout << "w";
        }
        else if(f2 == a2 && a2 == b2){
            if(f1 > a1 && f1 < b1){
                cout << abs(b1-a1)+2 << "\n"; 
            }
            else if(f1 > b1 && f1 < a1){
                cout << abs(b1-a1)+2 << "\n"; 
            }
            else{
                cout << abs(b1-a1) + abs(b2-a2) << "\n";
            }
        }
        else{
            cout << abs(b1-a1) + abs(b2-a2) << "\n"; 
        }
    }
}