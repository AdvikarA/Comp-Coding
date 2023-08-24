#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("reduce.in");
    ofstream fout ("reduce.out");
    int n;
    fin >> n;
    vector<int>x;
    vector<int>y;
    vector<int>xunsort;
    vector<int>yunsort;
    for(int i = 0; i < n; i++){
        int a, b;
        fin>>a>>b;
        x.push_back(a);
        y.push_back(b);
        xunsort.push_back(a);
        yunsort.push_back(b);
    }
    int area = 2147483647;
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    for(int i = 0; i < 4; i++){
        for(int j = n-1; j >= n-4; j--){
            for(int k = 0; k < 4; k++){
                for(int l = n-1; l >= n-4; l--){
                    int xright = x[i];
                    int xleft = x[j];
                    int yup = y[k];
                    int ydown = y[l];
                    //cout<<xright << " "<<xleft << " "<<yup << " "<<ydown<<"\n";
                    int count = 0;
                    //cout<<"here";
                    for(int points=0; points<n; points++){
                        if(xleft <= xright && yup >= ydown){
                            if((xunsort[points] >= xleft) && (xunsort[points] <= xright) && (yunsort[points] >= ydown) && (yunsort[points] <= yup)){
                                //cout << "actual x: "<< x[points] << " \nLeft bound: "<< xleft << " \nRight bound: "<<xright<< " \nactual y: "<< y[points] << " \nup bound: "<< yup << " \ndown bound: "<<ydown<<"\n";
                                if(y[points] == 7){
                                    //cout << "AACTUAL X: "<<x[points]<<"\n";
                                }
                                count++;
                            }
                        }
                    }
                   // cout<<count<<"\n\n";
                    if(count >= n-3){
                        //cout<<"here";
                        int xdist = xright-xleft;
                        int ydist = yup - ydown;
                        //cout<<xright << " "<<xleft << " "<<yup << " "<<ydown<<"\n";
                        //cout << count<<"\n";
                        area = min(area, xdist*ydist);
                        //cout<<area<<"\n\n";
                    }
                }
            }
        }
    }
    fout << area;


}