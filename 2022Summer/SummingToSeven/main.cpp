#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("div7.in");
    ofstream fout ("div7.out");
    int n;
    fin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        fin >> arr[i];
        arr[i] = arr[i]%7;
        //cout << arr[i] << " ";
    }
    long long psumA[n+1];
    psumA[0] = 0;
    for(int i = 0; i < n; i++){
        psumA[i+1] = (psumA[i] + arr[i])%7;
    }
    
    
    int biggest = 0;
    int sev[7];
    int big[7];
    int smol[7];
    for(int i = 0; i < 7; i++){
        smol[i] = 10000000;
    }
    for(int i = 0; i < 7; i++){
        big[i] = 0;
    }
    for(int i = 0; i <= n; i++){
        int a = smol[psumA[i]];
        smol[psumA[i]] = min(i, a);
        big[psumA[i]] = i;
    }
    for(int i = 0; i < 7; i++){
        //cout << big[i] << " " <<  smol[i] << "\n";
        int a = big[i] - smol[i];
        biggest = max(biggest, a);
    }
    
    fout << biggest;
}

/**Farmer John's N cows are standing in a row, as they have a tendency to do from time to time. Each cow is labeled with a distinct integer ID number so FJ can tell them apart. FJ would like to take a photo of a contiguous group of cows but, due to a traumatic childhood incident involving the numbers 1…6, he only wants to take a picture of a group of cows if their IDs add up to a multiple of 7.
Please help FJ determine the size of the largest group he can photograph.

INPUT FORMAT (file div7.in):
The first line of input contains N (1≤N≤50,000). The next N lines each contain the N integer IDs of the cows (all are in the range 0…1,000,000).
OUTPUT FORMAT (file div7.out):
Please output the number of cows in the largest consecutive group whose IDs sum to a multiple of 7. If no such group exists, output 0.
You may want to note that the sum of the IDs of a large group of cows might be too large to fit into a standard 32-bit integer. If you are summing up large groups of IDs, you may therefore want to use a larger integer data type, like a 64-bit "long long" in C/C++.

SAMPLE INPUT:
7
3
5
1
6
2
14
10
SAMPLE OUTPUT:
5
In this example, 5+1+6+2+14 = 28.**/