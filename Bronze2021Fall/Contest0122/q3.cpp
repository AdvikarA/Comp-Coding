#include <iostream>
#include <algorithm> 
using namespace std;
int main(){
    long long t; 
    cin >> t;
    long long rations;
    for(long long fi = 0; fi < t; fi++){
        rations = 0;
        long long n; cin >> n;
        long long arr[n];
        for(long long j = 0; j < n; j++){
            cin >> arr[j]; 
        }
        bool solved = false;
        while(!solved){
            long long smallest = arr[0];
            long long largest = arr[0];
            long long smallestpog = 0;
            long long largestpog = 0;
            for(long long i = 0; i < n; i++){
                if(arr[i] < smallest){
                    smallest = arr[i];
                    smallestpog = i;
                }
                if (arr[i] > largest){
                    largest = arr[i];
                    largestpog = i; 
                }
            }
            long long test = (arr[largestpog] - arr[largestpog-1]);
            long long test2 = (arr[largestpog]-arr[largestpog+1]);
            if(largestpog != n-1 && largestpog != 0){
                if(arr[largestpog+1] > arr[largestpog-1]){
                    arr[largestpog+1]-= test;
                    arr[largestpog]-= test; 
                    rations+= 2*test;
                    //cout << "(arr[largestpog] - arr[largestpog-1])  " << test << "\n";
                }
                else{                    
                    arr[largestpog-1]-= test2;

                    arr[largestpog]-= test2;
                    rations+= 2*test2;
                    //cout << "(arr[largestpog]-arr[largestpog+1])   " << (test2) << "\n";
                }
            }
            else if(largestpog == 0){
                arr[largestpog]--;
                rations++;
                arr[largestpog+1]--;
                rations++;
            }
            else{
                arr[largestpog]--;
                rations++;
                arr[largestpog-1]--;
                rations++;
            }
            //for(int i = 0; i < n; i++){
                //cout << arr[i] << " ";
            //}
            //cout << "\n";
            long long a = arr[0]; 
            long long b = 0;
            for(int i = 0; i < n; i++){
                if(arr[i] == a){
                    b++;
                }
            }
            if(b == n){
                goto END;
            }
            if(n == 1){
                cout << -1 <<"\n";
                goto REALEND; 
            }
            for(long long i = 0; i < n; i++){
                if(arr[i] < 0){
                    cout << -1<<"\n";
                    goto REALEND;
                }
            }
            
        }
        END:
        ;
        cout << rations << "\n"; 
        REALEND: 
        ;
    }
}