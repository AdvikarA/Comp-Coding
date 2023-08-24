#include <iostream>
#include <fstream>
#include <utility>
#include<vector>
#include<math.h>
#include<algorithm>
typedef long long ll;
using namespace std;
int main(){
    ifstream fin ("slowdown.in");
    ofstream fout ("slowdown.out");
    ll n;
    fin>>n;
    vector<pair<ll, char>> event;
    vector<bool> taken;
    vector<ll>Ts;
    vector<ll>Ds;
    ll tcount, dcount;
    tcount = 0;
    dcount = 0;
    for(ll i = 0; i < n; i++){
        char a;
        ll b;
        fin>>a>>b;
        if(a == 'D'){
            Ds.push_back(b);
            dcount++;
        }
        else{
            Ts.push_back(b);
            tcount++;
        }
        event.push_back(make_pair(b, a));
        taken.push_back(false);
    }
    for(ll i = 0; i < Ts.size(); i++){
        //cout<<Ts[i]<<"\n";
    }
    long double ratediv = 1;
    long double rate = 1;
    long double time = 0;
    long double last = 0;
    long double dist = 0;
    sort(event.begin(), event.end());
    sort(Ds.begin(), Ds.end());
    sort(Ts.begin(), Ts.end());
    ll dindex = 0;
    ll tindex = 0;
    for(ll i = 0; i < n; i++){
        //fout<<time + (Ds[dindex]-dist)/rate<<" "<<Ts[tindex]<<"\n";
        if(time + (Ds[dindex]-dist)/rate < Ts[tindex]){
            //cout<<"D\n";
            time = time + (Ds[dindex]-dist)/rate;
            //cout<<"dist: "<<Ds[dindex]-dist<<" "<<"rate: "<<Ds[dindex]<<"\n";
            dist = Ds[dindex];
            Ds[dindex] = 2147483647;
            if(dindex != dcount-1){
                dindex++;
            }
            ratediv++;
            rate = 1.0/ratediv;
        }
        else{
            //cout<<"T\n";
            dist = dist+(Ts[tindex]-time)*rate;
            time = Ts[tindex];
            Ts[tindex] = 2147483647;
            //fout<<"time: "<<time<<"\n";
            if(tindex != tcount-1){
                tindex++;
            }            
            ratediv++;
            rate = 1.0/ratediv;
        }
        //cout << "dist: " << dist<<"\n";
        //cout<<"time: "<<time<<"\n";

    }
    float distremaining = 1000-dist;
    time+=distremaining/rate;
    //cout<<distremaining/rate<< " " <<time;
    int inttime = (int) time;
    if(time-inttime <0.5){
        inttime = inttime+0;
    }
    else{
        inttime++;
    }
    
    fout<<inttime;
}