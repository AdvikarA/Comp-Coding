#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    vector <int> numbers;
    for(int i = 0; i < 7; i++){
        int a;
        cin >> a; 
        numbers.push_back(a); 
    }
    sort(numbers.begin(), numbers.end());
    int A = numbers[0];
    int B = numbers[1];
    int C = numbers[6] - (A + B); 
    cout << A << " " << B << " " << C; 
}