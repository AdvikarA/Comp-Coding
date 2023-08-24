#include<fstream>
#include<iostream>
#include<queue>

using namespace std;

bool works(int arr[10000], int mid, int n, int k){
    priority_queue<int, vector<int>, greater<int>> cows;
    int time = 0;
    for(int i = 0; i < n; i++){
        if(cows.size() == mid){
            time = cows.top();
            cows.pop();
        }
        if(time+arr[i] > k){
            return false;
        }
        cows.push(time + arr[i]);

    }
    return true;
}
int main(){
    ifstream fin ("cowdance.in");
    ofstream fout("cowdance.out");
    int n, t;
    fin >> n >> t; 
    int arr[10000];
    for(int i = 0; i < n; i++){
        fin >> arr[i];
    }
    int a = 1, b = n;
    while (a != b) {
        int mid = (a+b)/2;
        if (works(arr, mid, n, t)) {
            b = mid;
        }
        else {
            a = mid+1;
        }
    }
    fout << a; 

    
}