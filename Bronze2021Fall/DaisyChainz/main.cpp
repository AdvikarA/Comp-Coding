#include <iostream>
#include <vector>
using namespace std;
vector <float> flowers;
int n; 
float avg(int i, int j){
    float sum = 0; 
    for(int a = i; a <= j; a++){
        sum+= flowers[a]; 
    }
    sum /= j-i+1; 
    return sum; 
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        float a; 
        cin >> a;
        flowers.push_back(a);
    }
    int ans = 0; 
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            //cout << i << " " << j << "\n";
            for(int k = i; k <= j; k++){
                if(flowers[k] == avg(i, j)){
                    //cout << "i: " << i << " j: " << j << " avg: " << avg(i,j) << "\n";
                    ans++; 
                    break; 
                }
            }
        }
    }
    cout << ans+n; 
}