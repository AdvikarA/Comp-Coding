#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <math.h>
#include <set>
#include <algorithm>
using namespace std;
int main(){
    ifstream fin ("geteven.in");
    ofstream fout ("geteven.out");
    int n;
    fin >> n;
    long long ans = 0;
    int ans1=0;
    int ans2 = 0;
    int ans3 = 0;
    vector<int> B, E, S, I, G, O, M;
    bool Beven, Eeven, Seven, Ieven, Geven, Oeven, Meven;
    bool Bodd, Eodd, Sodd, Iodd, Godd, Oodd, Modd;
    vector<int> Be, Bo, Ee, Eo, Se, So, Ie, Io, Ge, Go, Oe, Oo, Me, Mo;
    //cout<<"TEST: "<<Be.size()<<"\n";
    for(int i = 0; i < n; i++){
        char a;
        int b;
        fin >> a >> b;
        
        if (a == 'B'){
            B.push_back(b);
            if(b % 2 == 0){
                Be.push_back(b);
            }
            else{
                Bo.push_back(b);
            }
        }
        if (a == 'E'){
            E.push_back(b);
            if(b % 2 == 0){
                Ee.push_back(b);
            }
            else{
                Eo.push_back(b);
            }
        }
        if (a == 'S'){
            S.push_back(b);
            if(b % 2 == 0){
                Se.push_back(b);
            }
            else{
                So.push_back(b);
            }
        }
        if (a == 'I'){
            I.push_back(b);
            if(b % 2 == 0){
                Ie.push_back(b);
            }
            else{
                Io.push_back(b);
            }
        }
        if (a == 'G'){
            G.push_back(b);
            if(b % 2 == 0){
                Ge.push_back(b);
            }
            else{
                Go.push_back(b);
            }
        }
        if (a == 'O'){
            O.push_back(b);
            if(b % 2 == 0){
                Oe.push_back(b);
            }
            else{
                Oo.push_back(b);
            }
        }
        if (a == 'M'){
            M.push_back(b);
            if(b % 2 == 0){
                Me.push_back(b);
            }
            else{
                Mo.push_back(b);
            }
        }
    }
    int even = 0;
    int odd = 0;
    for(int b = 1; b < 3; b++){
        for(int e = 1; e < 3; e++){
            for(int s = 1; s < 3; s++){
                for(int i = 1; i < 3; i++){
                    for(int g = 1; g < 3; g++){
                        for(int o = 1; o < 3; o++){
                            for(int m = 1; m < 3; m++){
                                long long c = 1;
                                int expression = (b+e+s+s+i+e)*(g+o+e+s)*(m+o+o); 
                                if(expression % 2 == 0){
                                    if(b==1){
                                        c*= Bo.size();
                                        //cout<<Bo.size()<<"\n";
                                    }
                                    if(e==1){
                                        c*= Eo.size();
                                        //cout<<Eo.size()<<"\n";
                                    }
                                    if(s==1){
                                        c*= So.size();
                                        //cout<<Eo.size()<<"\n";
                                    }
                                    if(i==1){
                                        c*= Io.size();
                                        //cout<<Io.size()<<"\n";
                                    }
                                    if(g==1){
                                        c*= Go.size();
                                        //cout<<Go.size()<<"\n";
                                    }
                                    if(o==1){
                                        c*= Oo.size();
                                        //cout<<Oo.size()<<"\n";
                                    }
                                    if(m==1){
                                        c*= Mo.size();
                                        //cout<<Mo.size()<<"\n";
                                    }
                                    if(b==2){
                                        c*= Be.size();
                                        //cout<<Be.size()<<"\n";
                                    }
                                    if(e==2){
                                        c*= Ee.size();
                                        //cout<<Ee.size()<<"\n";
                                    }
                                    if(s==2){
                                        c*= Se.size();
                                        //cout<<Se.size()<<"\n";
                                    }
                                    if(i==2){
                                        c*= Ie.size();
                                        //cout<<Ie.size()<<"\n";
                                    }
                                    if(g==2){
                                        c*= Ge.size();
                                        //cout<<Ge.size()<<"\n";
                                    }
                                    if(o==2){
                                        c*= Oe.size();
                                        //cout<<Oe.size()<<"\n";
                                    }
                                    if(m==2){
                                        c*= Me.size();
                                        //cout<<Me.size()<<"\n";
                                    }
                                    //cout<<"C: "<<c<<"\n";
                                    ans += c;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
   
    
    
    
    fout<<ans<<"\n";
}
    

   