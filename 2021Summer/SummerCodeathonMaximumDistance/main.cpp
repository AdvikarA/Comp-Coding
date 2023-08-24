#include <iostream>
#include <algorithm>
using namespace std;
int distance(int x1, int x2, int y1, int y2){
    int dist = (x2-x1)*(x2-x1) + (y1-y2)*(y1-y2);
    return dist; 
}
int main() {
    int maxd = 0; 
    int n;
    cin >> n; 
    int xs[n];
    int ys[n];  
    for(int i = 0; i < n; i++){
        cin >> xs[i]; 
    }
    for(int i = 0; i < n; i++){
        cin >> ys[i]; 
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            int dist = distance(xs[i], xs[j], ys[i], ys[j]); 
            maxd = max(maxd, dist); 
        }
    }
    cout << maxd; 

}