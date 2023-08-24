#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
bool works(vector<int> lights, int r, int k, int n){
    bool worka = false;
    //cout << "R:" << r << "\n";
    for(int i = 0; i < n - r-1; i++){
        int start = i;
        int end = i+r+1;
        //cout << lights[end] << " " << lights[start] << "\n";
        if(lights[end]-lights[start] >= k){        
            //cout << lights[end]-lights[start] << "\n";

            worka = true;
        }
    }
    return worka; 
}
main(){
    ifstream fin ("maxcross.in");
    ofstream fout ("maxcross.out");
    int n, k, N;
    fin >> n >> k >> N;
    //cout<<"N: "<<N;
    vector<int> lights;
    for(int i = 0; i < N; i++){
        int a; 
        fin >> a;
        lights.push_back(a);
    }
    int mid = 0;
    sort(lights.begin(), lights.end());
    int a = 0, b = N;
    while (a != b) {
        mid = (a+b)/2;
        cout << mid << " ";
        if (works(lights, mid, k, N)) {
            b = mid;
        }
        else {
            a = mid+1;
        }
    }
    fout << a;

}