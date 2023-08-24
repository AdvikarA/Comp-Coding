#include <iostream>
using namespace std;
 
int main(void) {
    int a = 1, b = 1000000, mid;
    string v;
    for(; a != b;){
        mid = (a+b+1)/2;
        cout << mid << flush;
        cin >> v;
        if (v[0] == '>'){
            a = mid;
        }
        else{
            b = mid-1;
        }
    }
    cout << "! " << a << endl;
    return 0;
}