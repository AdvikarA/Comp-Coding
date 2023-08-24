#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream fin ("csq.in");
	int n;
    fin >> n; 
    int arr[n+1];
    int prefix[n+1];
    arr[0] = 0;
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        fin>>arr[i];
        prefix[i] = prefix[i-1] + arr[i];
    }
    for(int i = 0; i < n+1; i++){
        cout<<prefix[i]<<"\n";
    }
    int q;
    fin>>q;
    for(int i = 0; i < q; i++){
        int a, b;
        fin >> a >> b;
        cout << prefix[b+1] - prefix[a]<<"\n";
    }

    
}