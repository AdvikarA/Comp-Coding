#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
bool works(vector<int>arrivetime, int num, int numbus, int buspas, int mid){
    int buscounter = 1;
    int counter = 0;
    int start = arrivetime[0];
    bool waittime = true;
    //cout<<"MID: " << mid << "\n";
    for(int i = 1; i < num; i++){
        if(arrivetime[i] - start > mid || i - counter + 1 > buspas){
            buscounter++;
            start = arrivetime[i];
            counter = i;
        }        
    }
    //cout<<"COUNTER: " << counter << " " << num<<"\n";
    if(buscounter <= numbus){
        return true;
    }
    return false;
    /**for(int i = buspas-1; i < num; i++){
        if(buscounter == numbus){
            break;
        }
        if(passcounter == buspas){
            i++;
            passcounter = 1;
            buscounter++;
        }
        //cout << "WORKS: " << arrivetime[i] - arrivetime[i-1] << " " << mid << "\n";
        if(arrivetime[i] - arrivetime[i-buspas+1] > mid){
            waittime = false;
        }
        passcounter++;
    }
    return waittime;**/
}
int main(){
    ifstream fin ("convention.in");
    ofstream fout ("convention.out");
    int num, numbus, buspas;
    fin >> num >> numbus >> buspas; 
    vector<int> arrivetime;
    for(int i = 0; i < num; i++){
        int a; 
        fin >> a;
        arrivetime.push_back(a);
    }
    sort(arrivetime.begin(), arrivetime.end());
    long long a = 0, b = 1000000000;
    while (a != b) {
        int mid = (a+b)/2;
        if (works(arrivetime, num, numbus, buspas, mid)) {
            //cout << "mid: " << mid << " " << works(arrivetime, num, numbus, buspas, mid)<< "\n";
            b = mid;
        }
        else {
            //cout << "mid: " << mid << " " << works(arrivetime, num, numbus, buspas, mid)<< "\n";

            a = mid+1;
        }
    }
    fout << a ;

}